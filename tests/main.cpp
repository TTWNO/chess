#include "catch.hpp"
#include "test_boards.h"
#include "valid_moves.h"
#include "custom_printing.cpp"
#include <sstream>
#include <functions.h>

const std::array<PieceType, 120> DUMB_MOVE_1 = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,INV,	
	INV, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, W_PAWN, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, W_PAWN, NONE, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN,INV, 
	INV, W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK, INV, 
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};

TEST_CASE("Test that the get_to_squares works, this is required!", "[get_to_squares]"){
	std::unordered_set<int> to_squares = {Position::H1};
	std::unordered_set<int> moves = {0b11000100000000};
	REQUIRE(get_to_squares(moves) == to_squares);
}

TEST_CASE("Test that an unordered set of positions are returned when looking for a piece type through a board", "[get_pos_of]"){
	CHECK(get_poss_of(PieceType::B_PAWN, &DEFAULT_BOARD) == B_PAWNS_SQUARES);
}

TEST_CASE("Test that a color can be gotten from a given square on the board", "[get_color]"){
	CHECK(get_color(2, 7, &DUMB_MOVE_1) == Color::BLACK);
	CHECK(get_color(3, 3, &DUMB_MOVE_1) == Color::NO_COLOR);
	CHECK(get_color(2, 1, &DUMB_MOVE_1) == Color::WHITE);
	CHECK(get_color(Position::C8, &DUMB_MOVE_1) == Color::BLACK);
	CHECK(get_color(Position::F4, &DUMB_MOVE_1) == Color::NO_COLOR);
	CHECK(get_color(Position::C2, &DUMB_MOVE_1) == Color::WHITE);
}
TEST_CASE("Test that a color can be gotten from a PieceType", "[get_color]"){
	CHECK(get_color(PieceType::NONE) == Color::NO_COLOR);
	CHECK(get_color(PieceType::W_KING) == Color::WHITE);
	CHECK(get_color(PieceType::B_KING) == Color::BLACK);
}

TEST_CASE("Test reversing color", "[rev_color]"){
	CHECK(rev_color(Color::NO_COLOR) == Color::NO_COLOR);
	CHECK(rev_color(Color::WHITE) == Color::BLACK);
	CHECK(rev_color(Color::BLACK) == Color::WHITE);
}

TEST_CASE("Test that is_black, and is_white are working", "[is_black][is_white]"){
	CHECK(is_white(DUMB_MOVE_1[Position::A2]));
	CHECK(is_black(DUMB_MOVE_1[Position::F7]));
	CHECK_FALSE(is_white(DUMB_MOVE_1[Position::B2]));
	CHECK_FALSE(is_black(DUMB_MOVE_1[Position::B5]));

	// Test that NONE squares return false
	CHECK_FALSE(is_white(DUMB_MOVE_1[Position::F4]));
	CHECK_FALSE(is_black(DUMB_MOVE_1[Position::F4]));
}

TEST_CASE("Test that dumb moves can be made.", "[dumb_move]"){
	int move_int = Position::B2 + (Position::B5 << 7);
	CHECK(dumb_move(move_int, DEFAULT_BOARD) == DUMB_MOVE_1);
}

TEST_CASE("Test convert method to go from X and Y to board position", "[pair_to_pos]"){
	CHECK(pair_to_pos(std::make_pair(2, 3)) == Position::C4);
	CHECK(pair_to_pos(std::make_pair(7, 0)) == Position::H1);
	CHECK(pair_to_pos(std::make_pair(0, 0)) == Position::A1);
	CHECK(pair_to_pos(std::make_pair(7, 7)) == Position::H8);
	CHECK_THROWS(pair_to_pos(std::make_pair(8, 2)));
	CHECK_THROWS(pair_to_pos(std::make_pair(-1, 1)));

	CHECK(pair_to_pos(2, 3) == Position::C4);
	CHECK(pair_to_pos(7, 0) == Position::H1);
	CHECK(pair_to_pos(0, 0) == Position::A1);
	CHECK(pair_to_pos(7, 7) == Position::H8);
	CHECK_THROWS(pair_to_pos(8, 2));
	CHECK_THROWS(pair_to_pos(-1, 1));

}

TEST_CASE("Test convert method to go from a board position to an x and y", "[pos_to_pair]"){
	CHECK(pos_to_pair(Position::A3) == std::make_pair(0, 2));
	CHECK(pos_to_pair(Position::A4) == std::make_pair(0, 3));
	CHECK(pos_to_pair(Position::B2) == std::make_pair(1, 1));
	CHECK(pos_to_pair(Position::H8) == std::make_pair(7, 7));
}

TEST_CASE("Test that invalid position ints return false", "[is_valid_position]"){
	CHECK(is_valid_position(0)); // 0=A8
	CHECK(is_valid_position(63)); // 63=H1
	CHECK_FALSE(is_valid_position(-1)); // -1 is out of bounds
	CHECK_FALSE(is_valid_position(64)); // 64 is out of bounds

	CHECK(is_valid_position(std::make_pair(0, 0))); // 0-7,0-7 should be valid
	CHECK(is_valid_position(std::make_pair(7, 7)));
	CHECK_FALSE(is_valid_position(std::make_pair(-1, 5))); // should fail
	CHECK_FALSE(is_valid_position(std::make_pair(5, 8))); // should fail

	CHECK(is_valid_position(0, 0)); // 0-7,0-7 should be valid
	CHECK(is_valid_position(7, 7));
	CHECK_FALSE(is_valid_position(-1, 5)); // should fail
	CHECK_FALSE(is_valid_position(5, 8)); // should fail
}

TEST_CASE("Test all possible and impossible moves for black pieces", "[get_all_moves][black]"){
	CHECK(get_to_squares(get_all_moves(B_KING_POS, B_KING_BOARD)) == B_KING_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(B_QUEEN_POS, B_QUEEN_BOARD)) == B_QUEEN_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(B_ROOK_POS, B_ROOK_BOARD)) == B_ROOK_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(B_BISHOP_POS, B_BISHOP_BOARD)) == B_BISHOP_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(B_KNIGHT_POS, B_KNIGHT_BOARD)) == B_KNIGHT_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(B_PAWN_POS, B_PAWN_BOARD)) == B_PAWN_ALL_MOVES);
}
TEST_CASE("Test all possible and impossible moves for whtie pieces", "[get_all_moves][white]"){
	CHECK(get_to_squares(get_all_moves(W_KING_POS, W_KING_BOARD)) == W_KING_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(W_QUEEN_POS, W_QUEEN_BOARD)) == W_QUEEN_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(W_ROOK_POS, W_ROOK_BOARD)) == W_ROOK_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(W_BISHOP_POS, W_BISHOP_BOARD)) == W_BISHOP_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(W_KNIGHT_POS, W_KNIGHT_BOARD)) == W_KNIGHT_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(W_PAWN_POS, W_PAWN_BOARD)) == W_PAWN_ALL_MOVES);
}

TEST_CASE("Test all moves for white in edge cases.", "[get_all_moves][white]"){
	CHECK(get_to_squares(get_all_moves(W_KNIGHT_SIDE1_POS, W_KNIGHT_SIDE1_BOARD)) == W_KNIGHT_SIDE1_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(W_KING_SIDE1_POS, W_KING_SIDE1_BOARD)) == W_KING_SIDE1_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(W_PAWN_SIDE1_POS, W_PAWN_SIDE1_BOARD)) == W_PAWN_SIDE1_ALL_MOVES);
}
TEST_CASE("Test all moves for black in edge cases.", "[get_all_moves][black]"){
	CHECK(get_to_squares(get_all_moves(B_KNIGHT_SIDE1_POS, B_KNIGHT_SIDE1_BOARD)) == B_KNIGHT_SIDE1_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(B_KING_SIDE1_POS, B_KING_SIDE1_BOARD)) == B_KING_SIDE1_ALL_MOVES);
	CHECK(get_to_squares(get_all_moves(B_PAWN_SIDE1_POS, B_PAWN_SIDE1_BOARD)) == B_PAWN_SIDE1_ALL_MOVES);
}

TEST_CASE("Test that moves that put king in check are not returned", "[get_all_moves]"){
	CHECK(get_to_squares(get_all_moves(ROOK_CHECK_TEST_POS, ROOK_CHECK_TEST_BOARD)) == ROOK_CHECK_TEST_MOVES);
	CHECK(get_to_squares(get_all_moves(PAWN_CHECK_TEST_POS, PAWN_CHECK_TEST_BOARD)) == PAWN_CHECK_TEST_MOVES);
	CHECK(get_to_squares(get_all_moves(PAWN_DIAG_TEST1_POS, PAWN_DIAG_TEST1_BOARD)) == PAWN_DIAG_TEST1_MOVES);
}

TEST_CASE("Tests for en pessant squares.", "[get_all_moves]"){
	CHECK(get_to_squares(get_all_moves(EN_PASSANT_TEST_POS, EN_PASSANT_TEST_BOARD, false, EN_PASSANT_SQUARE)) == EN_PASSANT_TEST_MOVES);
	CHECK(get_to_squares(get_all_moves(NO_EN_PASSANT_TEST_POS, NO_EN_PASSANT_TEST_BOARD)) == NO_EN_PASSANT_TEST_MOVES);
}
