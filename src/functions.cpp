#include "functions.h"
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <stdio.h>

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

std::vector<Position> get_all_moves(Position pn, std::array<PieceType, 64> board){
	PieceType pt = board[pn];
	std::vector<Position> pns;
	int x = pos_to_pair(pn).first;
	int y = pos_to_pair(pn).second;
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
