#include "catch.hpp"
#include "test_boards.h"
#include "valid_moves.h"
#include "custom_printing.cpp"
#include "test_functions.h"
#include <bitwise.h>
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
	std::vector<int> to_squares = {Position::H1};
	std::vector<int> moves = {0b11000100000000};
	REQUIRE(get_to_squares(moves) == to_squares);
}

TEST_CASE("Test that get_rank() works)", "[get_rank]"){
	CHECK(get_rank(Position::F3) == Rank::RANK3);
	CHECK(get_rank(Position::G1) == Rank::RANK1);
}

TEST_CASE("Test that an unordered set of positions are returned when looking for a piece type through a board", "[get_pos_of]"){
	CHECK(get_poss_of(PieceType::B_PAWN, &DEFAULT_BOARD) == B_PAWNS_SQUARES);
}

TEST_CASE("Test that a color can be gotten from a given square on the board", "[get_color]"){
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

TEST_CASE("Test that invalid position ints return false", "[is_valid_position]"){
	CHECK(is_valid_position(Position::A8));
	CHECK(is_valid_position(Position::H1));
	CHECK_FALSE(is_valid_position(((int) Position::H1) + 1));
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

TEST_CASE("Tests is_king_checked works", "[is_checked]"){
	auto king_checked_moves = get_all_moves(KING_CHECK_TEST_POS, KING_CHECK_TEST_BOARD); 
	auto rook_checked_moves = get_all_moves(ROOK_CHECK_TEST_POS, KING_CHECK_TEST_BOARD);
	CHECK(get_to_squares(king_checked_moves) == KING_CHECK_TEST_MOVES);
	CHECK(get_to_squares(rook_checked_moves) == KING_CHECK_ROOK_MOVES);
	CHECK(is_checked(KING_CHECK_TEST_POS, KING_CHECK_TEST_BOARD));
	CHECK(is_checked(BLACK_CHECK_POS1, BLACK_CHECK_BOARD1));
	CHECK(is_checked(BLACK_CHECK_POS2, BLACK_CHECK_BOARD2));
}

TEST_CASE("Test that moves that put king in check are not returned", "[get_all_moves]"){
	CHECK(get_to_squares(get_all_moves(ROOK_CHECK_TEST_POS, ROOK_CHECK_TEST_BOARD)) == ROOK_CHECK_TEST_MOVES);
	CHECK(get_to_squares(get_all_moves(PAWN_CHECK_TEST_POS, PAWN_CHECK_TEST_BOARD)) == PAWN_CHECK_TEST_MOVES);
	auto pawn_diag_moves = get_all_moves(PAWN_DIAG_TEST1_POS, PAWN_DIAG_TEST1_BOARD);
	std::vector<int> pawn_start_flags = {0, 1, 0};
	CHECK(get_to_squares(pawn_diag_moves) == PAWN_DIAG_TEST1_MOVES);
	CHECK(get_pawn_start_flags(pawn_diag_moves) == pawn_start_flags);
}

TEST_CASE("Tests for en pessant squares.", "[get_all_moves]"){
	auto en_pass_moves = get_all_moves(EN_PASSANT_TEST_POS, EN_PASSANT_TEST_BOARD, true, EN_PASSANT_SQUARE);
	std::vector<int> en_passant_flags = {0, 1};
	CHECK(get_to_squares(en_pass_moves) == EN_PASSANT_TEST_MOVES);
	CHECK(get_en_passant_flags(en_pass_moves) == en_passant_flags);
	CHECK(get_to_squares(get_all_moves(NO_EN_PASSANT_TEST_POS, NO_EN_PASSANT_TEST_BOARD)) == NO_EN_PASSANT_TEST_MOVES);
}

TEST_CASE("Test for pawn promotions.", "[get_all_moves]"){
	auto prom_moves = get_all_moves(PROM_PAWN_POS, PROM_PAWN_BOARD);
	CHECK(get_to_squares(prom_moves) == PROM_PAWN_MOVES);
	CHECK(get_promoted_pieces(prom_moves) == PROM_PAWN_PROMS);
	auto bprom_moves = get_all_moves(PROM_BPAWN_POS, PROM_BPAWN_BOARD);
	CHECK(get_to_squares(bprom_moves) == PROM_BPAWN_MOVES);
	CHECK(get_promoted_pieces(bprom_moves) == PROM_BPAWN_PROMS);
}

TEST_CASE("Test for castling moves.", "[get_all_moves]"){
	std::vector<int> cast_flags = {0, 0, 0, 0, 0, 1, 1};
	auto cast_moves = get_all_moves(CASTLING_POS, CASTLING_BOARD, true, 0, 0xF);
	CHECK(get_to_squares(cast_moves) == CASTLING_MOVES);
	CHECK(get_castle_flags(cast_moves) == cast_flags);
	auto bcast_moves = get_all_moves(BCASTLING_POS, CASTLING_BOARD, true, 0, 0xF);
	CHECK(get_to_squares(bcast_moves) == BCASTLING_MOVES);
	CHECK(get_castle_flags(bcast_moves) == cast_flags);
	// Check refuses castle
	std::vector<int> checked_cast_flags = {0, 0, 0};
	auto bcast_checked_moves = get_all_moves(BCASTLING_POS, CASTLING_CHECK_BOARD, true, 0, 0xF);
	CHECK(get_to_squares(bcast_checked_moves) == BCASTLING_CHECK_MOVES);
	CHECK(get_castle_flags(bcast_checked_moves) == checked_cast_flags);
}

TEST_CASE("Test that en passant moves are properly handled by dumb_move", "dumb_move"){
	CHECK(dumb_move(make_move(EN_PASSANT_CHECK_POS, EN_PASSANT_EN_PASSANT_SQUARE, PieceType::B_PAWN, PieceType::NONE, 1), EN_PASSANT_CHECK_BOARD) == EN_PASSANT_CHECK_MOVED_BOARD);
	CHECK(dumb_move(make_move(EN_PASSANT_CHECK_POS1, EN_PASSANT_EN_PASSANT_SQUARE1, PieceType::B_PAWN, PieceType::NONE, 1), EN_PASSANT_CHECK_BOARD1) == EN_PASSANT_CHECK_MOVED_BOARD1);
	CHECK(dumb_move(make_move(EN_PASSANT_CHECK_POS2, EN_PASSANT_EN_PASSANT_SQUARE2, PieceType::B_PAWN, PieceType::NONE, 1), EN_PASSANT_CHECK_BOARD2) == EN_PASSANT_CHECK_MOVED_BOARD2);
	CHECK(dumb_move(make_move(EN_PASSANT_CHECK_POS3, EN_PASSANT_EN_PASSANT_SQUARE3, PieceType::B_PAWN, PieceType::NONE, 1), EN_PASSANT_CHECK_BOARD3) == EN_PASSANT_CHECK_MOVED_BOARD3);
}
