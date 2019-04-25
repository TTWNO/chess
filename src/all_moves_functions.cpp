#include "constants.h"
#include <vector>
#include <array>
#include <iostream>

const std::array<int, 4> ROOK_PIECE_OFFSETS = {-1, -10, 1, 10};
const std::array<int, 4> BISHOP_PIECE_OFFSETS = {-11, -9, 9, 11};
const std::array<int, 8> KNIGHT_PIECE_OFFSETS = {-12, -21, -19, -8, 8, 12, 19, 21};
const std::array<int, 8> KING_PIECE_OFFSETS = {-11, -10, -9, 9, 10, 11};


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
void _add_if_not_blocked(int pos, int from, std::vector<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite, bool *is_not_blocked){
	if (*is_not_blocked){
		if (!is_valid_position(pos)){
			*is_not_blocked = false;
		} else {
			if (_xy_is_color(pos, board, color_of_piece)){
				*is_not_blocked = false;
			} else if (_xy_is_color(pos, board, color_of_opposite)){
				pns->push_back(make_move(from, pos, (*board)[pos]));
				*is_not_blocked = false;
			} else {
				pns->push_back(make_move(from, pos, (*board)[pos]));
			}
		}
	}
}

// Only for the king, using rays for left and right, and adding the castle flag if needed.
void _king_add_if_not_blocked(int pos, int from, std::vector<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite, bool *is_not_blocked, int castle_flag){
	if (*is_not_blocked){
		if (!is_valid_position(pos)){
			*is_not_blocked = false;
		} else {
			if (_xy_is_color(pos, board, color_of_piece)){
				*is_not_blocked = false;
			} else if (_xy_is_color(pos, board, color_of_opposite)){
				pns->push_back(make_move(from, pos, (*board)[pos], PieceType::NONE, 0, 0, castle_flag));
				*is_not_blocked = false;
			} else {
				pns->push_back(make_move(from, pos, (*board)[pos], PieceType::NONE, 0, 0, castle_flag));
			}
		}
	}
}


// This function is for non-ray types only, as it ignores the 'ray rules', and just jumps over stuff (e.g. knight), or only moves one space generally (e.g. king)
void _add_if_not_blocked(int pos, int from, std::vector<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite){
	if (!is_valid_position(pos) ||
		_xy_is_color(pos, board, color_of_piece)){
		return;
	} else {
		pns->push_back(make_move(from, pos, (*board)[pos]));
	}
}

// This is a specialized function for the pawn's diagonal takes.
// It will only to pns if there is a piece of opposite color on it.
void _pawn_diag_add_if_not_blocked(int pos, int from, std::vector<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite, int en_passant, int promoting){
	if (is_valid_position(pos)){
		if (_xy_is_color(pos, board, color_of_opposite)){
			if (promoting){
				if (color_of_piece == Color::WHITE){
					pns->push_back(make_move(from, pos, (*board)[pos], PieceType::W_KNIGHT));
					pns->push_back(make_move(from, pos, (*board)[pos], PieceType::W_BISHOP));
					pns->push_back(make_move(from, pos, (*board)[pos], PieceType::W_ROOK));
					pns->push_back(make_move(from, pos, (*board)[pos], PieceType::W_QUEEN));
				} else {
					pns->push_back(make_move(from, pos, (*board)[pos], PieceType::B_KNIGHT));
					pns->push_back(make_move(from, pos, (*board)[pos], PieceType::B_BISHOP));
					pns->push_back(make_move(from, pos, (*board)[pos], PieceType::B_ROOK));
					pns->push_back(make_move(from, pos, (*board)[pos], PieceType::B_QUEEN));	
				}
			} else {
				pns->push_back(make_move(from, pos, (*board)[pos]));
			}
		} else if (pos == en_passant){
			pns->push_back(make_move(from, pos, (*board)[en_passant], PieceType::NONE, 1));	
		}
	}
}

// This is a specialized functions for the pawn's inability to take going forward.
// Notice the lack of push_backion where there usually is when (x,y) is a different color.
void _pawn_add_if_not_blocked(int pos, int from, std::vector<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite, bool *is_not_blocked, bool double_move){
	if (*is_not_blocked){
		if ((*board)[pos] != PieceType::NONE ||
			(*board)[pos] == PieceType::INV){
			*is_not_blocked = false;
		} else {
			double_move?pns->push_back(make_move(from, pos, (*board)[pos], PieceType::NONE, 0, 1)):pns->push_back(make_move(from, pos, (*board)[pos]));
		}
	}
}


void _get_all_moves_rook(int pos, std::vector<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc){
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

void _get_all_moves_bishop(int pos, std::vector<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc){
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
void _get_all_moves_knight(int pos, std::vector<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc){
	for (int kn_off : KNIGHT_PIECE_OFFSETS){
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

void _get_all_moves_king(int pos, std::vector<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc, int castle_perms){
	for (int kn_off : KING_PIECE_OFFSETS){
		_add_if_not_blocked(pos+kn_off, pos, pns, board, pc, rc);
	}
	bool* left_castle = new bool(true);
	bool* right_castle = new bool(true);

	if (pc == Color::WHITE){
		_king_add_if_not_blocked(pos+1, pos, pns, board, pc, rc, right_castle, 0);
		_king_add_if_not_blocked(pos-1, pos, pns, board, pc, rc, left_castle, 0);
		if (castle_perms & CastlePerms::WKS){
			_king_add_if_not_blocked(pos+2, pos, pns, board, pc, rc, right_castle, 1);
		}
		if (castle_perms & CastlePerms::WQS && (*board)[pos-3] == PieceType::NONE){
			_king_add_if_not_blocked(pos-2, pos, pns, board, pc, rc, left_castle, 1);
		}
	} else {
		_king_add_if_not_blocked(pos+1, pos, pns, board, pc, rc, right_castle, 0);
		_king_add_if_not_blocked(pos-1, pos, pns, board, pc, rc, left_castle, 0);
		if (castle_perms & CastlePerms::BKS){
			_king_add_if_not_blocked(pos+2, pos, pns, board, pc, rc, right_castle, 1);
		}
		if (castle_perms & CastlePerms::BQS && (*board)[pos-3] == PieceType::NONE){
			_king_add_if_not_blocked(pos-2, pos, pns, board, pc, rc, left_castle, 1);
		}
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

void _get_all_moves_pawn(int pos, std::vector<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc, int en_passant){
	
	// if it's white use different offsets, and pawn starting rank
	int offset2 = pc==Color::WHITE?-20:20;
	int offset1 = pc==Color::WHITE?-10:10;
	int default_pawn_rank = pc==Color::WHITE?Rank::RANK2:Rank::RANK7;
	int promotion_rank = pc==Color::WHITE?Rank::RANK7:Rank::RANK2;
	int is_promoting_if_forward = get_rank(pos) == promotion_rank?1:0;

	bool *free_to_double_move = new bool(true);
	_pawn_add_if_not_blocked(pos+offset1, pos, pns, board, pc, rc, free_to_double_move, false);
	if (get_rank(pos) == default_pawn_rank){ // If on second/seventh rank
		_pawn_add_if_not_blocked(pos+offset2, pos, pns, board, pc, rc, free_to_double_move, true);
	}
	// pos+offset1 is 1 rank up (or down) depending on color.
	// Adding, or removing one will shift it over by one square, hence diagnoals.
	_pawn_diag_add_if_not_blocked(pos+offset1+1, pos, pns, board, pc, rc, en_passant, is_promoting_if_forward);
	_pawn_diag_add_if_not_blocked(pos+offset1-1, pos, pns, board, pc, rc, en_passant, is_promoting_if_forward);
}
