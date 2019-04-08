#include "constants.h"
#include <unordered_set>

void _push_if_valid_pos(int x, int y, std::unordered_set<Position> *pns){
	if (is_valid_position(x, y)){
		pns->insert(pair_to_pos(x, y));
	}
}

void _get_all_moves_rook(int x, int y, std::unordered_set<Position> *pns){
	for (int offset=1; offset<8; offset++){
		_push_if_valid_pos(x+offset, y, pns);
		_push_if_valid_pos(x, y+offset, pns);
		_push_if_valid_pos(x-offset, y, pns);
		_push_if_valid_pos(x, y-offset, pns);
	}	
}

void _get_all_moves_bishop(int x, int y, std::unordered_set<Position> *pns){
	for (int offset=1; offset<8; offset++){
		int xpoff = x+offset;
		int ypoff = y+offset;
		int xnoff = x-offset;
		int ynoff = y-offset;
		_push_if_valid_pos(xpoff, ypoff, pns);
		_push_if_valid_pos(xpoff, ynoff, pns);
		_push_if_valid_pos(xnoff, ypoff, pns);
		_push_if_valid_pos(xnoff, ynoff, pns);	
	}
	
}
void _get_all_moves_knight(int x, int y, std::unordered_set<Position> *pns){
	for (int xo=1;xo<=2;xo++){
		int yo=(xo==1)?2:1;
		_push_if_valid_pos(x+xo, y+yo, pns);
		_push_if_valid_pos(x-xo, y+yo, pns);
		_push_if_valid_pos(x+xo, y-yo, pns);
		_push_if_valid_pos(x-xo, y-yo, pns);
	}
}

void _get_all_moves_king(int x, int y, std::unordered_set<Position> *pns){
	_push_if_valid_pos(x+1, y+1, pns);
	_push_if_valid_pos(x+1, y-1, pns);
	_push_if_valid_pos(x-1, y+1, pns);
	_push_if_valid_pos(x-1, y-1, pns);
	_push_if_valid_pos(x, y+1, pns);
	_push_if_valid_pos(x, y-1, pns);
	_push_if_valid_pos(x+1, y, pns);
	_push_if_valid_pos(x-1, y, pns);
}
void _get_all_moves_w_pawn(int x, int y, std::unordered_set<Position> *pns){
	_push_if_valid_pos(x, y+1, pns);
	_push_if_valid_pos(x, y+2, pns);
	_push_if_valid_pos(x+1, y+1, pns);
	_push_if_valid_pos(x-1, y+1, pns);
}
void _get_all_moves_b_pawn(int x, int y, std::unordered_set<Position> *pns){
	_push_if_valid_pos(x, y-1, pns);
	_push_if_valid_pos(x, y-2, pns);
	_push_if_valid_pos(x-1, y-1, pns);
	_push_if_valid_pos(x+1, y-1, pns);
}

