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
				pns->push_back(make_move(from, pos, (*board)[pos], PieceType::NONE));
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

void _add_pawn_promotions(int from, int to, PieceType capture, Color color_of_piece, std::vector<int> *pns){
	if (color_of_piece == Color::WHITE){
		pns->push_back(make_move(from, to, capture, PieceType::W_KNIGHT));
		pns->push_back(make_move(from, to, capture, PieceType::W_BISHOP));
		pns->push_back(make_move(from, to, capture, PieceType::W_ROOK));
		pns->push_back(make_move(from, to, capture, PieceType::W_QUEEN));
	} else {
		pns->push_back(make_move(from, to, capture, PieceType::B_KNIGHT));
		pns->push_back(make_move(from, to, capture, PieceType::B_BISHOP));
		pns->push_back(make_move(from, to, capture, PieceType::B_ROOK));
		pns->push_back(make_move(from, to, capture, PieceType::B_QUEEN));
	}

}

// This is a specialized function for the pawn's diagonal takes.
// It will only to pns if there is a piece of opposite color on it.
void _pawn_diag_add_if_not_blocked(int pos, int from, std::vector<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite, int en_passant, int promoting){
	if (is_valid_position(pos)){
		// Theoretically this is not run with en_passant because those flags should NEVER overlap, but if it does, my tests will alert me.
		if (_xy_is_color(pos, board, color_of_opposite)){
			if (promoting){
				_add_pawn_promotions(from, pos, (*board)[pos], color_of_piece, pns);
			} else {
				pns->push_back(make_move(from, pos, (*board)[pos]));
			}
		} else if (pos == en_passant){
			// If capturing from the left to the right, set the captured piece to directly right of current from pos (+1)
			// ...otherwise get to the right (-1)
			int captured_pos = from-pos>0?from+1:from-1;
			pns->push_back(make_move(from, pos, (*board)[captured_pos], PieceType::NONE, 1));
		}	
	}
}

// This is a specialized functions for the pawn's inability to take going forward.
// Notice the lack of push_backion where there usually is when (x,y) is a different color.
void _pawn_add_if_not_blocked(int pos, int from, std::vector<int> *pns, std::array<PieceType, 120> *board, Color color_of_piece, Color color_of_opposite, bool *is_not_blocked, bool double_move, bool promoted){
	if (*is_not_blocked){
		if ((*board)[pos] != PieceType::NONE ||
			(*board)[pos] == PieceType::INV){
			*is_not_blocked = false;
		} else if (double_move){
			pns->push_back(make_move(from, pos, PieceType::NONE, PieceType::NONE, 0, 1));	
		} else if (promoted){
			_add_pawn_promotions(from, pos, PieceType::NONE, color_of_piece, pns);
		} else {
			pns->push_back(make_move(from, pos, (*board)[pos]));
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
}

void _get_all_moves_bishop(int pos, std::vector<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc){
	for (int bs_off : BISHOP_PIECE_OFFSETS){
		bool* not_blocked = new bool(true);
		for (int offset=1; offset<8; offset++){
			_add_if_not_blocked(pos+(bs_off*offset), pos, pns, board, pc, rc, not_blocked);
		}
	}
}

void _get_all_moves_knight(int pos, std::vector<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc){
	for (int kn_off : KNIGHT_PIECE_OFFSETS){
		_add_if_not_blocked(pos+kn_off, pos, pns, board, pc, rc);
	}
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
		// THe right castle doesn't need to know if pos-/+ something is blank, because there is only
		// ... 2 blank squares between the king and the rook.
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
}

void _get_all_moves_pawn(int pos, std::vector<int> *pns, std::array<PieceType, 120>* board, Color pc, Color rc, int en_passant){
	
	// if it's white use different offsets, and pawn starting rank
	int offset2 = pc==Color::WHITE?-20:20;
	int offset1 = pc==Color::WHITE?-10:10;
	int default_pawn_rank = pc==Color::WHITE?Rank::RANK2:Rank::RANK7;
	int promotion_rank = pc==Color::WHITE?Rank::RANK7:Rank::RANK2;
	int is_promoting_if_forward = get_rank(pos) == promotion_rank?1:0;

	bool *free_to_double_move = new bool(true);
	_pawn_add_if_not_blocked(pos+offset1, pos, pns, board, pc, rc, free_to_double_move, false, is_promoting_if_forward);
	if (get_rank(pos) == default_pawn_rank){ // If on second/seventh rank
		_pawn_add_if_not_blocked(pos+offset2, pos, pns, board, pc, rc, free_to_double_move, true, is_promoting_if_forward);
	}
	// pos+offset1 is 1 rank up (or down) depending on color.
	// Adding, or removing one will shift it over by one square, hence diagnoals.
	_pawn_diag_add_if_not_blocked(pos+offset1+1, pos, pns, board, pc, rc, en_passant, is_promoting_if_forward);
	_pawn_diag_add_if_not_blocked(pos+offset1-1, pos, pns, board, pc, rc, en_passant, is_promoting_if_forward);
}
