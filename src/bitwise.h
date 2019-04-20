#ifndef BITWISE_H
#define BITWISE_H

#include <unordered_set>
#include "constants.h"

// Using macros for ease of use, can also use functons, but I don't see the point.

/*
 * From (Position): 7 bits (2^7 == 128) possibilities
 * To (Position): same as above
 * Captured piece, if any: 4 bits (16) possibilities
 * Promoted to, if any: 4 bits (16) possibilities
 * en passant flag: 1 bit
 * pawn starting move flag: 1 bit
 * castle move flag: 1 bit
 *
 *	0000 0000 0000 0000 0000 0111 1111 -> From square position (& 0x7F)
 *	0000 0000 0000 0011 1111 1000 0000 -> To square position (>> 7 & 0x7F)
 *	0000 0000 0011 1100 0000 0000 0000 -> captured piece, if any (>> 14 & 0xF)
 *	0000 0011 1100 0000 0000 0000 0000 -> if prmoted, what to? (>> 18 & 0xF)
 *	0000 0100 0000 0000 0000 0000 0000 -> en passant (& 0x400000)
 *	0000 1000 0000 0000 0000 0000 0000 -> pawn starting move (& 0x800000)
 *	0001 0000 0000 0000 0000 0000 0000 -> castle move (& 0x1000000)
 * */

/* OLD, DO NOT USE
#define FROMSQ(m) ((m)     & 0x3f)
#define TOSQ(m)   ((m>>6)  & 0x3f)
#define CAPT(m)   ((m>>12) & 0xf )
#define PROM(m)   ((m>>16) & 0xf )
#define ENPASS(m) ((m>>20) & 0x1 )
#define PAWNST(m) ((m>>21) & 0x1 )
#define CAST(m)   ((m>>22) & 0x1 )
*/

// Redefine as functions for fun :shrug:
inline int get_from_sq(int mv){
	return (mv & 0x7f);
}
inline int get_to_sq(int mv){
	return ((mv >> 7) & 0x7f);
}
inline int get_captured_pc(int mv){
	return ((mv >> 14) & 0xf);
}
inline int get_promoted_to_pc(int mv){
	return ((mv >> 18) & 0xf);
}
inline int get_en_pass_flag(int mv){
	return ((mv >> 22) & 0x1);
}
inline int get_pawn_st_flag(int mv){
	return ((mv >> 23) & 0x1);
}
inline int get_castle_flag(int mv){
	return ((mv >> 24) & 0x1);
}
// Just trying to get working for now.
Rank get_rank(int pos){
	if (pos >30 && pos < 39){
		return Rank::RANK7;
	} else if (pos > 80 && pos < 89){
		return Rank::RANK2;
	}
	return Rank::RANK1;
}

inline bool is_valid_position(int position){
	return DEFAULT_BOARD[position] == PieceType::INV;
}
#endif
