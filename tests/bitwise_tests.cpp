#include <constants.h>
#include <bitwise.h>
#include "catch.hpp"
/*
 * From (Position): 6 bits (2^6 == 64) possibilities
 * To (Position): same as above
 * Captured piece, if any: 4 bits (16) possibilities
 * Promoted to, if any: 4 bits (16) possibilities
 * en passant flag: 1 bit
 * pawn starting move flag: 1 bit
 * castle move flag: 1 bit
 *
 *	0000 0000 0000 0000 0011 1111 -> From square position (0x3F)
 *	0000 0000 0000 1111 1100 0000 -> To square position (>> 6 0xFB)
 *	0000 0000 1111 0000 0000 0000 -> captured piece, if any (>> 12 0xF)
 *	0000 1111 0000 0000 0000 0000 -> if prmoted, what to? (>> 16 0xF)
 *	0001 0000 0000 0000 0000 0000 -> en passant (0x100000)
 *	0010 0000 0000 0000 0000 0000 -> pawn starting move (0x200000)
 *	0100 0000 0000 0000 0000 0000 -> castle move (0x400000)
 * */

const unsigned int GET_FROM_PIECE_INT = 0x3f;
const unsigned int GET_FROM_PIECE_INT2 = 0x3e;
// Want:
// 1111 1111 1110
// FFE
const unsigned int GET_TO_FROM_PIECE_INT = 0xffe;
// Want:
// 1111 1011 1111
// FBF
const unsigned int GET_TO_FROM_PIECE_INT2 = 0xfbf;

TEST_CASE("Test that bitwise operators return appropriate values. Move.from", "[bitwise_from_pos]"){
	CHECK(FROMSQ(GET_FROM_PIECE_INT) == Position::H1);
	CHECK(FROMSQ(GET_FROM_PIECE_INT2) == Position::G1);
	CHECK(TOSQ(GET_TO_FROM_PIECE_INT) == Position::H1);
	CHECK(FROMSQ(GET_TO_FROM_PIECE_INT) == Position::G1);
	
	CHECK(TOSQ(GET_TO_FROM_PIECE_INT2) == Position::G1);
	CHECK(FROMSQ(GET_TO_FROM_PIECE_INT2) == Position::H1);
}

