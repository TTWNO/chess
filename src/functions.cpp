#include "functions.h"
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <math.h>

// TODO implement functions.h functions.
// NOTE tests will NOT run unless you implement these functions.

std::pair<int, int> pos_to_pair(Position pn){
	int x,y = 0;
	for (x = pn; x >= 8; x = x-8){
		++y;
	}
	return std::make_pair(x, std::abs(y-7));
}

// TODO find way to make function arbitary to board size as to allow wide game chess variants. Do much later. Not important now.
Position pair_to_pos(std::pair<int, int> pr){
	if (pr.first > 7 || pr.first < 0
	||  pr.second > 7 || pr.second < 0) {
		throw std::invalid_argument("Cannot use any pairs with values > 7 or < 0.");
	}
	int int_val = std::abs(pr.second - 7)*8 + pr.first;
	if (int_val >= 0 && int_val < 64) {
		return static_cast<Position>(int_val);
	} else {
		std::stringstream ss;
		ss << "Something went terribly wrong. x and y < 8 && x and y >= 0 but abs(y-7)*8 + x < 0 or >= 64. It equalled: " << int_val; 
		throw std::invalid_argument(ss.str());
	}
}
std::vector<Position> get_possible_movers(Position pn, std::array<PieceType, 64> board){
	std::vector<Position> pns = {Position::A1};
	return pns;
}

std::vector<Position> get_possible_moves(Position pn, std::array<PieceType, 64> board){
	std::vector<Position> pns = {Position::A1};
	return pns;
}

int poly_knight_offset_x(int x) {
       	return  -2.1500176772557799*pow(10,2)*pow(x,0) +
	        +5.0175460279545990*pow(10,2)*pow(x,1) +
	    	-4.3971301635198080*pow(10,2)*pow(x,2) +
     		+1.9251081929895420*pow(10,2)*pow(x,3) +
     		-4.6354931502296793*pow(10,1)*pow(x,4) +
     		+6.2293079395174518*pow(10,0)*pow(x,5) +
     		-4.3751543665888198*pow(10,1)*pow(x,6) +
    		+1.2500918807028260*pow(10,2)*pow(x,7) +
     		-2.2939912578846349*pow(10,8)*pow(x,8);
}

std::vector<Position> get_all_moves(Position pn, std::array<PieceType, 64> board){
	PieceType pt = board[pn];
	std::vector<Position> pns;
	int x = pos_to_pair(pn).first;
	int y = pos_to_pair(pn).second;
	std::vector<int> knt_dx = {-1,1,-2,2,0,-2,2,-1,1};
	std::vector<int> knt_dy = {2,2,1,1,0,-1,-1,-2,-2};
	std::vector<int> kg_dx  = {-1,0,1,-1,0,1,-1,0,1};
	std::vector<int> kg_dy  = {1,1,1,0,0,0,-1,-1,-1};
	std::vector<int> Bpa_dx = {0,-1,0,1,0,0};
	std::vector<int> Bpa_dy = {-1,0,0,0,1,2};
	std::vector<int> Wpa_dx = {0,0,-1,0,1,0};
	std::vector<int> Wpa_dy = {2,1,0,0,0,-1};
	switch(pt){
		case PieceType::B_ROOK:
		case PieceType::W_ROOK:
			for (int j = 7; j >= 0; j--){
				if (j != y){
			pns.push_back(pair_to_pos(std::make_pair(x,j)));
				}
				for (int i = 0; i < 8; i++){
					if (j == y){
				pns.push_back(pair_to_pos(std::make_pair(i,y)));
					}
		}
		}
		break;
		case PieceType::B_BISHOP:
		case PieceType::W_BISHOP:
			for (int r = 7; r >= 0; r--){
				for (int f = 0; f < 8; f++){
					for (int i=0; i<8; i++){
						if ((f-i == x && r-i == y) ||
						    (f+i == x && r+i == y) ||
						    (f-i == x && r+i == y) ||
						    (f+i == x && r-i == y)){
							pns.push_back(pair_to_pos(std::make_pair(f, r)));
							break;
						}
					}
				}
			}
		break;
		case PieceType::B_KNIGHT:
		case PieceType::W_KNIGHT:
			for (int j = 7; j >= 0; j--){
			for (int i = 0; i < 8; i++){
			for (int k = 0; k < 9; k++){
			if (std::make_pair(x+knt_dx[k],y+knt_dy[k]) == std::make_pair(i,j))
				pns.push_back(pair_to_pos(std::make_pair(i,j)));
			}	
			}
		}
		break;
		case PieceType::B_KING:
		case PieceType::W_KING:
			for (int j = 7; j >= 0; j--){
			for (int i = 0; i < 8; i++){
			for (int k = 0; k < 9; k++){
			if (std::make_pair(x+kg_dx[k],y+kg_dy[k]) == std::make_pair(i,j))
				pns.push_back(pair_to_pos(std::make_pair(i,j)));
			}
			}
		}
		break;
		case PieceType::B_PAWN:
			for (int j = 7; j >= 0; j--){
			for (int i = 0; i < 8; i++){
			for (int k = 0; k < 6; k++){
			if (std::make_pair(x+Bpa_dx[k],y+Bpa_dy[k]) == std::make_pair(i,j))
				pns.push_back(pair_to_pos(std::make_pair(i,j)));
			}
			}
		}
		break;
		case PieceType::W_PAWN:
			for (int j = 7; j >= 0; j--){
			for (int i = 0; i < 8; i++){
			for (int k = 0; k < 6; k++){
			if (std::make_pair(x+Wpa_dx[k],y+Wpa_dy[k]) == std::make_pair(i,j))
				pns.push_back(pair_to_pos(std::make_pair(i,j)));
			}
			}
		}
		break;
		default:
			break;
	}
	return pns;
}

std::array<PieceType, 64> dumb_move(Position from, Position to, std::array<PieceType, 64> board){
	PieceType piece = board[from];
	board[to] = piece;
	board[from] = PieceType::NONE;
	return board;
}
