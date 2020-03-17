#include <bitwise.h>
#include <constants.h>
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
 *	0000 0000 0000 0000 0000 0000 0111 1111 -> From square position (& 0x7F)
 *	0000 0000 0000 0000 0011 1111 1000 0000 -> To square position (>> 7 & 0x3F8)
 *	0000 0000 0000 0011 1100 0000 0000 0000 -> captured piece, if any (>> 14 & 0xF)
 *	0000 0000 0011 1100 0000 0000 0000 0000 -> if prmoted, what to? (>> 18 & 0xF)
 *	0000 0000 0100 0000 0000 0000 0000 0000 -> en passant (& 0x400000)
 *	0000 0000 1000 0000 0000 0000 0000 0000 -> pawn starting move (& 0x800000)
 *	0000 0001 0000 0000 0000 0000 0000 0000 -> castle move (& 0x1000000)
 * */

// This is testing position G1
const unsigned int MOVE_G1 = Position::G1;

// This is testing position H1
const unsigned int MOVE_H1 = Position::H1;

// This is testing a move with no flags from G1 to H1
const unsigned int MOVE_G1_TO_H1 = 0b1100010'1100001;

// This is testing a move with no flags from H1 to G1
const unsigned int MOVE_H1_TO_G1 = 0b1100001'1100010;

// Move from H1 to G1 and capture
const unsigned int MOVE_H1_TO_G1_CAPTURE_B_KNIGHT = 0b0010'1100001'1100010;

// Move from H1 to G1 and promote
const unsigned int MOVE_H1_TO_G1_PROMOTE_TO_QUEEN = 0b0101'0000'1100001'1100010;

// Move from H1 to G1 and en passant
const unsigned int MOVE_H1_TO_G1_EN_PASSANT = 0b1'0000'0000'1100001'1100010;

// Move from H1 to G1 and its the starting move for a pawn
const unsigned int MOVE_H1_TO_G1_PAWN_START = 0b1'0'0000'0000'1100001'1100010;

// Move from H1 to G1 and castle
const unsigned int MOVE_H1_TO_G1_AND_CASTLE = 0b1'0'0'0000'0000'1100001'1100010;

// Want:
// From:		E4	(65)
// To:			D3	(74)
// (these 2 combine together)	(33)
// Captures:		B_PAWM	(7)
// Promoted:		NONE	(0)
// en passant:		true	(1)
// pawn starting move:	false	(0)
// castle move:		false	(0)
// total value:			(?)
const unsigned int GET_ALL_INT = 0b0'0'1'0000'0001'1001010'1000001;

TEST_CASE("Test that bitwise operators return appropriate values. Move.from", "[bitwise_from_pos]"){
	CHECK(get_from_sq(MOVE_G1) == Position::G1);
	CHECK(get_from_sq(MOVE_H1) == Position::H1);
	CHECK(get_to_sq(MOVE_G1_TO_H1) == Position::H1);
	CHECK(get_from_sq(MOVE_G1_TO_H1) == Position::G1);
	
	CHECK(get_to_sq(MOVE_H1_TO_G1) == Position::G1);
	CHECK(get_from_sq(MOVE_H1_TO_G1) == Position::H1);

	CHECK(get_captured_pc(MOVE_H1_TO_G1_CAPTURE_B_KNIGHT) == PieceType::B_KNIGHT);
	CHECK(get_promoted_to_pc(MOVE_H1_TO_G1_PROMOTE_TO_QUEEN) == PieceType::B_QUEEN);

	CHECK(get_en_pass_flag(MOVE_H1_TO_G1_EN_PASSANT) == 1);
	CHECK(get_pawn_st_flag(MOVE_H1_TO_G1_PAWN_START) == 1);
	CHECK(get_castle_flag(MOVE_H1_TO_G1_AND_CASTLE) == 1);

	CHECK(get_from_sq(GET_ALL_INT) == Position::E4);
	CHECK(get_to_sq(GET_ALL_INT) == Position::D3);
	CHECK(get_captured_pc(GET_ALL_INT) == PieceType::B_PAWN);
	CHECK(get_promoted_to_pc(GET_ALL_INT) == PieceType::NONE);
	CHECK(get_en_pass_flag(GET_ALL_INT) == 1);
	CHECK(get_pawn_st_flag(GET_ALL_INT) == 0);
	CHECK(get_castle_flag(GET_ALL_INT) == 0);
}

TEST_CASE("Test that is_valid_position works properly", "[is_valid_position]"){
	CHECK_FALSE(is_valid_position(0));
	CHECK(is_valid_position(Position::A8));
	CHECK(is_valid_position(Position::H1));
}
