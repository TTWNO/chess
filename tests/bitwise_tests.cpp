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
 * (32-bit int, room to exapnd if neccessary)
 *	0000 0000 0000 0000 0000 0000 0011 1111 -> From square position (& 0x3F)
 *	0000 0000 0000 0000 0000 1111 1100 0000 -> To square position (>> 6 & 0xFB)
 *	0000 0000 0000 0000 1111 0000 0000 0000 -> captured piece, if any (>> 12 & 0xF)
 *	0000 0000 0000 1111 0000 0000 0000 0000 -> if prmoted, what to? (>> 16 & 0xF)
 *	0000 0000 0001 0000 0000 0000 0000 0000 -> en passant (& 0x100000)
 *	0000 0000 0010 0000 0000 0000 0000 0000 -> pawn starting move (& 0x200000)
 *	0000 0000 0100 0000 0000 0000 0000 0000 -> castle move (& 0x400000)
 * */

// This is testing position H1
const unsigned int MOVE_G1 = 0x3f;

// This is testing position G1
const unsigned int MOVE_H1 = 0x3e;

// This is testing a move with no flags from G1 to H1
// // Want:
// 1111 1111 1110
// FFE
const unsigned int MOVE_G1_TO_H1 = 0xffe;

// This is testing a move with no flags from H1 to G1
// Want:
// 1111 1011 1111
// FBF
const unsigned int MOVE_H1_TO_G1 = 0b111110111111;

// Move from H1 to G1 and capture
const unsigned int MOVE_H1_TO_G1_get_captured_pcURE_B_KNIGHT = 0x8fbf;

// Move from H1 to G1 and promote
const unsigned int MOVE_H1_TO_G1_get_promoted_to_pcOTE_TO_QUEEN = 0xb0fbf;

// Move from H1 to G1 and en passant
const unsigned int MOVE_H1_TO_G1_EN_PASSANT = 0x100fbf;

// Move from H1 to G1 and its the starting move for a pawn
const unsigned int MOVE_H1_TO_G1_PAWN_START = 0x200fbf;

// Move from H1 to G1 and castle
const unsigned int MOVE_H1_TO_G1_AND_get_castle_flagLE = 0x400fbf;

// Want:
// From:		E3	(21)	[0x15]	[0x15]		<0x15>
// To:			D2	(12)	[0xB]	[0xB]		<0x3DF>
// (these 2 combine together)	(33)	[0x20]	[0x3DF]		<>
// Captures:		B_PAWM	(7)	[0x7]	[0x7000]	<0x73DF>
// Promoted:		NONE	(0)	[0x0]	[0x0]		<>
// en passant:		true	(1)	[0x1]	[0x100000]	<0x1003DF>
// pawn starting move:	false	(0)	[0x0]	[0x0]		<>
// castle move:		false	(0)	[0x0]	[0x0]		<>
// total value:			(?)	[?]	[?}		<0x1003DF>
const unsigned int GET_ALL_INT = 0x1003DF;

TEST_CASE("Test that bitwise operators return appropriate values. Move.from", "[bitwise_from_pos]"){
	CHECK(get_from_sq(MOVE_G1) == Position::H1);
	CHECK(get_from_sq(MOVE_H1) == Position::G1);
	CHECK(get_to_sq(MOVE_G1_TO_H1) == Position::H1);
	CHECK(get_from_sq(MOVE_G1_TO_H1) == Position::G1);
	
	CHECK(get_to_sq(MOVE_H1_TO_G1) == Position::G1);
	CHECK(get_from_sq(MOVE_H1_TO_G1) == Position::H1);

	CHECK(get_captured_pc(MOVE_H1_TO_G1_get_captured_pcURE_B_KNIGHT) == PieceType::B_KNIGHT);
	CHECK(get_promoted_to_pc(MOVE_H1_TO_G1_get_promoted_to_pcOTE_TO_QUEEN) == PieceType::B_QUEEN);

	CHECK(get_en_pass_flag(MOVE_H1_TO_G1_EN_PASSANT) == 1);
	CHECK(get_pawn_st_flag(MOVE_H1_TO_G1_PAWN_START) == 1);
	CHECK(get_castle_flag(MOVE_H1_TO_G1_AND_get_castle_flagLE) == 1);
}

TEST_CASE("Test that is_valid_position works properly", "[is_valid_position]"){
	CHECK(is_valid_position(0));
	CHECK(is_valid_position(63));
	CHECK_FALSE(is_valid_position(-1));
	CHECK_FALSE(is_valid_position(64));
}
