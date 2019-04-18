#ifndef BITWISE_H
#define BITWISE_H

#include <unordered_set>

// Using macros for ease of use, can also use functons, but I don't see the point.

/*
 * From (Position): 7 bits (2^6 == 64) possibilities
 * To (Position): same as above
 * Captured piece, if any: 4 bits (16) possibilities
 * Promoted to, if any: 4 bits (16) possibilities
 * en passant flag: 1 bit
 * pawn starting move flag: 1 bit
 * castle move flag: 1 bit
 *
 *	0000 0000 0000 0000 0011 1111 -> From square position (& 0x3F)
 *	0000 0000 0000 0111 1100 0000 -> To square position (>> 6 & 0x3F)
 *	0000 0000 1111 0000 0000 0000 -> captured piece, if any (>> 12 & 0xF)
 *	0000 1111 0000 0000 0000 0000 -> if prmoted, what to? (>> 16 & 0xF)
 *	0001 0000 0000 0000 0000 0000 -> en passant (& 0x100000)
 *	0010 0000 0000 0000 0000 0000 -> pawn starting move (& 0x200000)
 *	0100 0000 0000 0000 0000 0000 -> castle move (& 0x400000)
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
int get_from_sq(int mv);
int get_to_sq(int mv);
int get_captured_pc(int mv);
int get_promoted_to_pc(int mv);
int get_en_pass_flag(int mv);
int get_pawn_st_flag(int mv);
int get_castle_flag(int mv);

int get_rank(int position);
int get_file(int position);

bool is_valid_position(int position);

#endif
