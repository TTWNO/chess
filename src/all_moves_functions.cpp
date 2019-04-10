#include "constants.h"
#include <unordered_set>
#include <iostream>

void _push_if_valid_pos(int x, int y, std::unordered_set<Position> *pns){
	if (is_valid_position(x, y)){
		pns->insert(pair_to_pos(x, y));
	}
}
// This function returns true if the color of the piece on tile (x,y) is the Color c 
bool _xy_is_color(int x, int y, std::array<PieceType, 64> board, Color c){
	return c==Color::WHITE ? is_white(board[pair_to_pos(x, y)]) : is_black(board[pair_to_pos(x, y)]);
}

Color _rev_color(Color c){
	return c==Color::WHITE ? Color::BLACK : Color::WHITE;
}

// This function will set the boolean guarding it to false if it is blocked, thus stopping it from running.
void _add_if_not_blocked(int x, int y, std::unordered_set<Position> *pns, std::array<PieceType, 64> board, Color color_of_piece, Color color_of_opposite, bool *is_not_blocked){
	if (*is_not_blocked && is_valid_position(x, y)){
		if (_xy_is_color(x, y, board, color_of_piece)){
			*is_not_blocked = false;
		} else if (_xy_is_color(x, y, board, color_of_opposite)){
			pns->insert(pair_to_pos(x, y));
			*is_not_blocked = false;
		} else {
			pns->insert(pair_to_pos(x, y));
		}
	}
}
// This function is for non-ray types only, as it ignores the 'ray rules', and just jumps over stuff (e.g. knight), or only moves one space generally (e.g. king)
void _add_if_not_blocked(int x, int y, std::unordered_set<Position> *pns, std::array<PieceType, 64> board, Color color_of_piece, Color color_of_opposite){
	if (is_valid_position(x, y)){
		if (_xy_is_color(x, y, board, color_of_piece)){
			return;
		} else {
			pns->insert(pair_to_pos(x, y));
		}
	}	
}

// This is a specialized function for the pawn's diagonal takes.
// It will only to pns if there is a piece of opposite color on it.
void _pawn_diag_add_if_not_blocked(int x, int y, std::unordered_set<Position> *pns, std::array<PieceType, 64> board, Color color_of_piece, Color color_of_opposite, Position en_passant){
	if (is_valid_position(x, y) && (_xy_is_color(x, y, board, color_of_opposite) ||
			pair_to_pos(x, y) == en_passant)){
		pns->insert(pair_to_pos(x, y));
	}
}
// This is a specialized functions for the pawn's inability to take going forward.
// Notice the lack of insertion where there usually is when (x,y) is a different color.
void _pawn_add_if_not_blocked(int x, int y, std::unordered_set<Position> *pns, std::array<PieceType, 64> board, Color color_of_piece, Color color_of_opposite, bool *is_not_blocked){
	if (*is_not_blocked && is_valid_position(x, y)){
		if (_xy_is_color(x, y, board, color_of_piece)){
			*is_not_blocked = false;
		} else if (_xy_is_color(x, y, board, color_of_opposite)){
			*is_not_blocked = false;
		} else {
			pns->insert(pair_to_pos(x, y));
		}
	}
}


void _get_all_moves_rook(int x, int y, std::unordered_set<Position> *pns, std::array<PieceType, 64> board, Color pc, Color rc){
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
}

void _get_all_moves_bishop(int x, int y, std::unordered_set<Position> *pns, std::array<PieceType, 64> board, Color pc, Color rc){
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
	
}
void _get_all_moves_knight(int x, int y, std::unordered_set<Position> *pns, std::array<PieceType, 64> board, Color pc, Color rc){
	for (int xo=1;xo<=2;xo++){
		int yo=(xo==1)?2:1;
		_add_if_not_blocked(x+xo, y+yo, pns, board, pc, rc);
		_add_if_not_blocked(x-xo, y+yo, pns, board, pc, rc);
		_add_if_not_blocked(x+xo, y-yo, pns, board, pc, rc);
		_add_if_not_blocked(x-xo, y-yo, pns, board, pc, rc);
	}
}

void _get_all_moves_king(int x, int y, std::unordered_set<Position> *pns, std::array<PieceType, 64> board, Color pc, Color rc){
	_add_if_not_blocked(x+1, y+1, pns, board, pc, rc);
	_add_if_not_blocked(x+1, y-1, pns, board, pc, rc);
	_add_if_not_blocked(x-1, y+1, pns, board, pc, rc);
	_add_if_not_blocked(x-1, y-1, pns, board, pc, rc);
	_add_if_not_blocked(x, y+1, pns, board, pc, rc);
	_add_if_not_blocked(x, y-1, pns, board, pc, rc);
	_add_if_not_blocked(x+1, y, pns, board, pc, rc);
	_add_if_not_blocked(x-1, y, pns, board, pc, rc);
}

void _get_all_moves_pawn(int x, int y, std::unordered_set<Position> *pns, std::array<PieceType, 64> board, Color pc, Color rc, Position en_passant){
	
	// if it's white use different offsets, and pawn starting rank
	int offset2 = pc==Color::WHITE?2:-2;
	int offset1 = pc==Color::WHITE?1:-1;
	int default_pawn_rank = pc==Color::WHITE?1:6;

	bool *free_to_double_move = new bool(true);
	_pawn_add_if_not_blocked(x, y+offset1, pns, board, pc, rc, free_to_double_move);
	if (y == default_pawn_rank){ // If on second/seventh rank
		_pawn_add_if_not_blocked(x, y+offset2, pns, board, pc, rc, free_to_double_move);
	}
	_pawn_diag_add_if_not_blocked(x+1, y+offset1, pns, board, pc, rc, en_passant);
	_pawn_diag_add_if_not_blocked(x-1, y+offset1, pns, board, pc, rc, en_passant);
}
