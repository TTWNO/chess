#include "functions.h"
#include "all_moves_functions.cpp"
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
Position pair_to_pos(int x, int y){
	return pair_to_pos(std::make_pair(x, y));
}

bool is_valid_position(int pos){
	return (pos >= 0 && pos < 64);
}
bool is_valid_position(std::pair<int, int> pos){
	return (pos.first < 8 && pos.second < 8 &&
			pos.first >= 0 && pos.second >=0);
}
bool is_valid_position(int x, int y){
	return (x < 8 && x >= 0 &&
			y < 8 && y >= 0);
}

bool is_white(PieceType pt){
	for (auto pn : Pieces::WHITE){
		if (pn == pt) return true;
	}
	return false;
}
bool is_black(PieceType pt){
	for (auto pn : Pieces::BLACK){
		if (pn == pt) return true;
	}
	return false;	
}

Color get_color(PieceType pt){
	if (is_white(pt)) return Color::WHITE;
	if (is_black(pt)) return Color::BLACK;
	return Color::NO_COLOR;
}
Color get_color(int x, int y, std::array<PieceType, 64> board){
	return get_color(board[pair_to_pos(x, y)]);
}
Color get_color(Position pn, std::array<PieceType, 64> board){
	return get_color(board[pn]);
}

Color rev_color(Color c){
	if (c==Color::NO_COLOR) return Color::NO_COLOR;
	return c==Color::WHITE?Color::BLACK:Color::WHITE;
}

std::unordered_set<Position> get_possible_movers(Position pn, std::array<PieceType, 64> board){
	std::unordered_set<Position> pns = {Position::A1};
	return pns;
}

std::unordered_set<Position> get_possible_moves(Position pn, std::array<PieceType, 64> board){
	std::unordered_set<Position> pns = {Position::A1};

	return get_all_moves(pn, board);
}

std::unordered_set<Position> get_all_moves(Position pn, std::array<PieceType, 64> board){
	PieceType pt = board[pn];
	std::unordered_set<Position> pns;
	int x = pos_to_pair(pn).first;
	int y = pos_to_pair(pn).second;
	Color color_of_piece = get_color(pt);
	Color color_of_opponent = rev_color(color_of_piece);
	switch(pt){
		case PieceType::B_QUEEN:
		case PieceType::W_QUEEN:
			_get_all_moves_rook(x, y, &pns, board, color_of_piece, color_of_opponent);
			_get_all_moves_bishop(x, y, &pns, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_ROOK:
		case PieceType::W_ROOK:
			_get_all_moves_rook(x, y, &pns, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_BISHOP:
		case PieceType::W_BISHOP:
			_get_all_moves_bishop(x, y, &pns, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_KNIGHT:
		case PieceType::W_KNIGHT:
			_get_all_moves_knight(x, y, &pns, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_KING:
		case PieceType::W_KING:
			_get_all_moves_king(x, y, &pns, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_PAWN:
		case PieceType::W_PAWN:
			_get_all_moves_pawn(x, y, &pns, board, color_of_piece, color_of_opponent);
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
