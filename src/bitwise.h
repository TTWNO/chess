#ifndef BITWISE_H
#define BITWISE_H

#include "constants.h"
#include <vector>

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
 * 	0010 0000 0000 0000 0000 0000 0000 -> check flag (& 0x2000000) 
 * */

// No offset becuase at beginning of int
#define FROM_MASK  0x7F

#define TO_MASK 0x7F
#define TO_SHIFT 7

#define CAPTURED_MASK 0xF
#define CAPTURED_SHIFT 14

#define PROMOTED_MASK 0xF
#define PROMOTED_SHIFT 18

#define EN_PASS_MASK 0x1
#define EN_PASS_SHIFT 22 

#define PAWN_ST_MASK 0x1
#define PAWN_ST_SHIFT 23

#define CASTLE_MASK 0x1
#define CASTLE_SHIFT 24

inline int get_from_sq(int mv){
	return (mv & FROM_MASK);
}
inline int get_to_sq(int mv){
	return ((mv >> TO_SHIFT) & TO_MASK);
}
inline int get_captured_pc(int mv){
	return ((mv >> CAPTURED_SHIFT) & CAPTURED_MASK);
}
inline int get_promoted_to_pc(int mv){
	return ((mv >> PROMOTED_SHIFT) & PROMOTED_MASK);
}
inline int get_en_pass_flag(int mv){
	return ((mv >> EN_PASS_SHIFT) & EN_PASS_MASK);
}
inline int get_pawn_st_flag(int mv){
	return ((mv >> PAWN_ST_SHIFT) & PAWN_ST_MASK);
}
inline int get_castle_flag(int mv){
	return ((mv >> CASTLE_SHIFT) & CASTLE_MASK);
}
inline int get_check_flag(int mv){
	return ((mv >> 25) & 0x1);
}

inline bool is_valid_position(int position){
	return DEFAULT_BOARD[position] != PieceType::INV;
}

// bitwise OR (|) with any int to "add" them together
inline int set_from_sq(int sq){
	return sq;
}
inline int set_to_sq(int sq){
	return (sq << 7);
}
inline int set_captured_pc(int pc){
	return (pc << 14);
}
inline int set_promoted_pc(int pc){
	return (pc << 16);
}
inline int set_en_passant_flag(){
	return (1 << 20);
}
inline int set_pawn_start_flag(){
	return (1 << 21);
}
inline int set_castle_flag(){
	return (1 << 22);
}

inline int make_move(int from){
	return from;
}
inline int make_move(int from, int to){
	return from | (to << 7);
}
inline int make_move(int from, int to, PieceType captured){
	return from | (to << 7) | ((int) captured << 14);
}
inline int make_move(int from, int to, PieceType captured, PieceType promotion){
	return from | (to << 7) | ((int) captured << 14) | ((int) promotion << 18);
}
inline int make_move(int from, int to, PieceType captured, PieceType promotion, int en_passant){
	return from | (to << 7) | ((int) captured << 14) | ((int) promotion << 18) | (en_passant << 22);
}
inline int make_move(int from, int to, PieceType captured, PieceType promotion, int en_passant, int pawn_start){
	return from | (to << 7) | ((int) captured << 14) | ((int) promotion << 18) | (en_passant << 22) | (pawn_start << 23);
}
inline int make_move(int from, int to, PieceType captured, PieceType promotion, int en_passant, int pawn_start, int castle_move){
	return from | (to << 7) | ((int) captured << 14) | ((int) promotion << 18) | (en_passant << 22) | (pawn_start << 23) | (castle_move << 24);
}
inline int make_move(int from, int to, PieceType captured, PieceType promotion, int en_passant, int pawn_start, int castle_move, int check_flag){
	return from | (to << 7) | ((int) captured << 14) | ((int) promotion << 18) | (en_passant << 22) | (pawn_start << 23) | (castle_move << 24) | (check_flag << 25);
}


#endif
