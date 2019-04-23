#include "constants.h"
#include <unordered_set>
#include <array>
#include <iostream>

const std::array<int, 4> ROOK_PIECE_OFFSETS = {-1, -10, 1, 10};
const std::array<int, 4> BISHOP_PIECE_OFFSETS = {-11, -9, 9, 11};
const std::array<int, 8> KNIGHT_PIECE_OFFSETS = {-12, -21, -19, -8, 8, 12, 19, 21};
const std::array<int, 8> KING_PIECE_OFFSETS = {-11, -10, -9, -1, 1, 9, 10, 11};


inline Position _pair_to_pos_unsafe(int x, int y){
	return static_cast<Position>(std::abs(y-7)*8 + x);
}

// This function returns true if the color of the piece on tile (x,y) is the Color c 
bool _xy_is_color(int pos, std::array<PieceType, 120>* board, Color c){
	return c==Color::WHITE ? is_white((*board)[pos]) : is_black((*board)[pos]);
}

Color _rev_color(Color c){
	return c==Color::WHITE ? Color::BLACK : Color::WHITE;
}

// This function will set the boolean guarding it to false if it is blocked, thus stopping it from running.
void _add_if_not_blocked(int pos, int from, std::unordered_set<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite, bool *is_not_blocked){
	if (*is_not_blocked){
		if (!is_valid_position(pos)){
			*is_not_blocked = false;
		} else {
			if (_xy_is_color(pos, board, color_of_piece)){
				*is_not_blocked = false;
			} else if (_xy_is_color(pos, board, color_of_opposite)){
				pns->insert(make_move(from, pos));
				*is_not_blocked = false;
			} else {
				pns->insert(make_move(from, pos));
			}
		}
	}
}
// This function is for non-ray types only, as it ignores the 'ray rules', and just jumps over stuff (e.g. knight), or only moves one space generally (e.g. king)
void _add_if_not_blocked(int pos, int from, std::unordered_set<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite){
	if (!is_valid_position(pos) ||
		_xy_is_color(pos, board, color_of_piece)){
		return;
	} else {
		pns->insert(make_move(from, pos));
	}
}

// This is a specialized function for the pawn's diagonal takes.
// It will only to pns if there is a piece of opposite color on it.
void _pawn_diag_add_if_not_blocked(int pos, int from, std::unordered_set<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite, int en_passant){
	if (is_valid_position(pos) && (_xy_is_color(pos, board, color_of_opposite) ||
			pos == en_passant)){
		pns->insert(make_move(from, pos));
	}
}
// This is a specialized functions for the pawn's inability to take going forward.
// Notice the lack of insertion where there usually is when (x,y) is a different color.
void _pawn_add_if_not_blocked(int pos, int from, std::unordered_set<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite, bool *is_not_blocked){
	if (*is_not_blocked){
		if ((*board)[pos] != PieceType::NONE ||
			(*board)[pos] == PieceType::INV){
			*is_not_blocked = false;
		} else {
			pns->insert(make_move(from, pos));
		}
	}
}


void _get_all_moves_rook(int pos, std::unordered_set<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc){
	for (int rk_off : ROOK_PIECE_OFFSETS){
		bool* not_blocked = new bool(true);
		for (int offset=1; offset<8; offset++){
			_add_if_not_blocked(pos+(rk_off*offset), pos, pns, board, pc, rc, not_blocked);
		}
	}
	
	/*
	bool* not_blocked_addx = new bool(true);
	bool* not_blocked_minx = new bool(true);
	bool* not_blocked_addy = new bool(true);
	bool* not_blocked_miny = new bool(true);
	for (int offset=1; offset<8; offset++){
		_add_if_not_blocked(x+offset, y, pns, board, pc, rc, not_blocked_addx);
		_add_if_not_blocked(x, y+offset, pns, board, pc, rc, not_blocked_addy);
		_add_if_not_blocked(x-offset, y, pns, board, pc, rc, not_blocked_minx);
		_add_if_not_blocked(x, y-offset, pns, board, pc, rc, not_blocked_miny);
	}
	*/
}

void _get_all_moves_bishop(int pos, std::unordered_set<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc){
	for (int bs_off : BISHOP_PIECE_OFFSETS){
		bool* not_blocked = new bool(true);
		for (int offset=1; offset<8; offset++){
			_add_if_not_blocked(pos+(bs_off*offset), pos, pns, board, pc, rc, not_blocked);
		}
	}
	/*
	bool* not_blocked_addx_addy = new bool(true);
	bool* not_blocked_addx_miny = new bool(true);
	bool* not_blocked_minx_addy = new bool(true);
	bool* not_blocked_minx_miny = new bool(true);
	
	for (int offset=1; offset<8; offset++){
		int xpoff = x+offset;
		int ypoff = y+offset;
		int xnoff = x-offset;
		int ynoff = y-offset;
		_add_if_not_blocked(xpoff, ypoff, pns, board, pc, rc, not_blocked_addx_addy);
		_add_if_not_blocked(xpoff, ynoff, pns, board, pc, rc, not_blocked_addx_miny);
		_add_if_not_blocked(xnoff, ypoff, pns, board, pc, rc, not_blocked_minx_addy);
		_add_if_not_blocked(xnoff, ynoff, pns, board, pc, rc, not_blocked_minx_miny);	
	}
	*/
}
void _get_all_moves_knight(int pos, std::unordered_set<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc){
	for (int kn_off : KNIGHT_PIECE_OFFSETS){
		bool* not_blocked = new bool(true);
		_add_if_not_blocked(pos+kn_off, pos, pns, board, pc, rc);
	}
	/*
	for (int xo=1;xo<=2;xo++){
		int yo=(xo==1)?2:1;
		_add_if_not_blocked(x+xo, y+yo, pns, board, pc, rc);
		_add_if_not_blocked(x-xo, y+yo, pns, board, pc, rc);
		_add_if_not_blocked(x+xo, y-yo, pns, board, pc, rc);
		_add_if_not_blocked(x-xo, y-yo, pns, board, pc, rc);
	}
	*/
}

void _get_all_moves_king(int pos, std::unordered_set<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc){
	for (int kn_off : KING_PIECE_OFFSETS){
		bool* not_blocked = new bool(true);
		_add_if_not_blocked(pos+kn_off, pos, pns, board, pc, rc);
	}


	/*
	_add_if_not_blocked(x+1, y+1, pns, board, pc, rc);
	_add_if_not_blocked(x+1, y-1, pns, board, pc, rc);
	_add_if_not_blocked(x-1, y+1, pns, board, pc, rc);
	_add_if_not_blocked(x-1, y-1, pns, board, pc, rc);
	_add_if_not_blocked(x, y+1, pns, board, pc, rc);
	_add_if_not_blocked(x, y-1, pns, board, pc, rc);
	_add_if_not_blocked(x+1, y, pns, board, pc, rc);
	_add_if_not_blocked(x-1, y, pns, board, pc, rc);
	*/
}

void _get_all_moves_pawn(int pos, std::unordered_set<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc, int en_passant){
	
	// if it's white use different offsets, and pawn starting rank
	int offset2 = pc==Color::WHITE?-20:20;
	int offset1 = pc==Color::WHITE?-10:10;
	int default_pawn_rank = pc==Color::WHITE?Rank::RANK2:Rank::RANK7;

	bool *free_to_double_move = new bool(true);
	_pawn_add_if_not_blocked(pos+offset1, pos, pns, board, pc, rc, free_to_double_move);
	if (get_rank(pos) == default_pawn_rank){ // If on second/seventh rank
		_pawn_add_if_not_blocked(pos+offset2, pos, pns, board, pc, rc, free_to_double_move);
	}
	// pos+offset1 is 1 rank up (or down) depending on color.
	// Adding, or removing one will shift it over by one square, hence diagnoals.
	_pawn_diag_add_if_not_blocked(pos+offset1+1, pos, pns, board, pc, rc, en_passant);
	_pawn_diag_add_if_not_blocked(pos+offset1-1, pos, pns, board, pc, rc, en_passant);
}
