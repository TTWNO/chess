#include "bitwise.h"

// Get first 6 bits of int
int get_from_sq(int mv){
	return (mv & 0x3f);
}

// Get bits 7-12 of int
int get_to_sq(int mv){
	return ((mv >> 6) & 0x3f);
}

// Get bits 13-16 of int
int get_captured_pc(int mv){
	return ((mv >> 12) & 0xf);
}

// Get bits 17-20 of int
int get_promoted_to_pc(int mv){
	return ((mv >> 16) & 0xf);
}

// Get 21st bit of int
int get_en_pass_flag(int mv){
	return ((mv >> 20) & 0x1);
}

// Get 22nd bit of int
int get_pawn_st_flag(int mv){
	return ((mv >> 21) & 0x1);
}

// Get 23rd bit of int
int get_castle_flag(int mv){
	return ((mv >> 22) & 0x1);
}

// Get last 3 bits of number (the rank).
// Techincally this gets all bits 4-32/64 but I'm just assuming it won't be larger than 63 before the shift.
int get_rank(int position){
	return (position >> 3);
}

// Get first 3 bits of number
int get_file(int position){
	return (position & 7);
}

// if the position has a 7th bit we know it's off the board.
// it indicates that is it off the board.
// ASSUMING position <= 128 but if it was that big that'd be weird.
bool is_valid_position(int position){
	return !(position & 0x40);
}
