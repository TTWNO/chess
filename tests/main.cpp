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

TEST_CASE("Test reversing color on pieve", "[rev_color]"){
	CHECK(rev_color(PieceType::B_KING) == W_KING);
	CHECK(rev_color(PieceType::B_QUEEN) == W_QUEEN);
	CHECK(rev_color(PieceType::B_ROOK) == W_ROOK);
	CHECK(rev_color(PieceType::B_BISHOP) == W_BISHOP);
	CHECK(rev_color(PieceType::B_KNIGHT) == W_KNIGHT);
	CHECK(rev_color(PieceType::B_PAWN) == W_PAWN);
	CHECK(rev_color(PieceType::W_KING) == B_KING);
	CHECK(rev_color(PieceType::W_QUEEN) == B_QUEEN);
	CHECK(rev_color(PieceType::W_ROOK) == B_ROOK);
	CHECK(rev_color(PieceType::W_BISHOP) == B_BISHOP);
	CHECK(rev_color(PieceType::W_KNIGHT) == B_KNIGHT);
	CHECK(rev_color(PieceType::W_PAWN) == B_PAWN);
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

TEST_CASE("Test that the captures moves are returned", "[get_all_moves]"){
	auto knight_moves = get_all_moves(KNIGHT_BLOCKED1_POS, KNIGHT_BLOCKED1_BOARD);
	auto bishop_moves = get_all_moves(BISHOP_BLOCKED1_POS, BISHOP_BLOCKED1_BOARD);
	auto rook_moves = get_all_moves(ROOK_BLOCKED1_POS, ROOK_BLOCKED1_BOARD);
	auto pawn_moves = get_all_moves(PAWN_DIAG_TEST1_POS, PAWN_DIAG_TEST1_BOARD);
	auto king_moves = get_all_moves(KING_CHECK_TEST_POS, KING_CHECK_TEST_BOARD);
	CHECK(get_captured_pieces(knight_moves) == KNIGHT_BLOCKED1_CAPTS);
	CHECK(get_captured_pieces(bishop_moves) == BISHOP_BLOCKED1_CAPTS);
	CHECK(get_captured_pieces(rook_moves) == ROOK_BLOCKED1_CAPTS);
	CHECK(get_captured_pieces(pawn_moves) == PAWN_DIAG_TEST1_CAPTS);
	CHECK(get_captured_pieces(king_moves) == KING_CHECK_TEST_CAPTS);
}

TEST_CASE("Test that being blocked, stops moves from generating", "[get_all_moves]"){
	auto knight_moves = get_all_moves(KNIGHT_BLOCKED1_POS, KNIGHT_BLOCKED1_BOARD);
	auto bishop_moves = get_all_moves(BISHOP_BLOCKED1_POS, BISHOP_BLOCKED1_BOARD);
	auto rook_moves = get_all_moves(ROOK_BLOCKED1_POS, ROOK_BLOCKED1_BOARD);
	CHECK(get_to_squares(knight_moves) == KNIGHT_BLOCKED1_MOVES);
	CHECK(get_to_squares(bishop_moves) == BISHOP_BLOCKED1_MOVES);
	CHECK(get_to_squares(rook_moves) == ROOK_BLOCKED1_MOVES);
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
	// Check that castling moves are not allowed when the rook is blocked.
	auto blocked_castling_moves = get_all_moves(CASTLE_BLOCKED_POS, CASTLE_BLOCKED_BOARD, true, 0, 0xF);
	CHECK(get_to_squares(blocked_castling_moves) == CASTLE_BLOCKED_MOVES);
	auto blocked_castling_qmoves = get_all_moves(CASTLE_BLOCKED_QPOS, CASTLE_BLOCKED_QBOARD, true, 0, 0xF);
	CHECK(get_to_squares(blocked_castling_qmoves) == CASTLE_BLOCKED_QMOVES);
}

TEST_CASE("Test that en passant moves are properly handled by dumb_move", "dumb_move"){
	CHECK(dumb_move(make_move(EN_PASSANT_CHECK_POS, EN_PASSANT_EN_PASSANT_SQUARE, PieceType::B_PAWN, PieceType::NONE, 1), EN_PASSANT_CHECK_BOARD) == EN_PASSANT_CHECK_MOVED_BOARD);
	CHECK(dumb_move(make_move(EN_PASSANT_CHECK_POS1, EN_PASSANT_EN_PASSANT_SQUARE1, PieceType::B_PAWN, PieceType::NONE, 1), EN_PASSANT_CHECK_BOARD1) == EN_PASSANT_CHECK_MOVED_BOARD1);
	CHECK(dumb_move(make_move(EN_PASSANT_CHECK_POS2, EN_PASSANT_EN_PASSANT_SQUARE2, PieceType::B_PAWN, PieceType::NONE, 1), EN_PASSANT_CHECK_BOARD2) == EN_PASSANT_CHECK_MOVED_BOARD2);
	CHECK(dumb_move(make_move(EN_PASSANT_CHECK_POS3, EN_PASSANT_EN_PASSANT_SQUARE3, PieceType::B_PAWN, PieceType::NONE, 1), EN_PASSANT_CHECK_BOARD3) == EN_PASSANT_CHECK_MOVED_BOARD3);
}

TEST_CASE("Test that castle moves are poperly handled by dumb_mobe", "[dumb_move]"){
	CHECK(dumb_move(make_move(CASTLE_FROM_POS, CASTLE_TO_POS, PieceType::NONE, PieceType::NONE, 0, 0, 1), CASTLE_BOARD) == CASTLE_BOARD_WK);
	CHECK(dumb_move(make_move(CASTLE_FROM_QPOS, CASTLE_TO_QPOS, PieceType::NONE, PieceType::NONE, 0, 0, 1), CASTLE_BOARD) == CASTLE_BOARD_WQ);
	CHECK(dumb_move(make_move(BCASTLE_FROM_POS, BCASTLE_TO_POS, PieceType::NONE, PieceType::NONE, 0, 0, 1), CASTLE_BOARD) == CASTLE_BOARD_BK);
	CHECK(dumb_move(make_move(BCASTLE_FROM_QPOS, BCASTLE_TO_QPOS, PieceType::NONE, PieceType::NONE, 0, 0, 1), CASTLE_BOARD) == CASTLE_BOARD_BQ);
}

TEST_CASE("Test that algebraic notation conversion is working.", "[to_notation]"){
	auto knight_moves = get_all_moves(KNIGHT_BLOCKED1_POS, KNIGHT_BLOCKED1_BOARD);
	auto bishop_moves = get_all_moves(BISHOP_BLOCKED1_POS, BISHOP_BLOCKED1_BOARD);
	auto rook_moves = get_all_moves(ROOK_BLOCKED1_POS, ROOK_BLOCKED1_BOARD);
	auto pawn_moves = get_all_moves(PAWN_DIAG_TEST1_POS, PAWN_DIAG_TEST1_BOARD);
	auto king_moves = get_all_moves(KING_CHECK_TEST_POS, KING_CHECK_TEST_BOARD);
	auto king_castle_moves = get_all_moves(CASTLING_POS, CASTLE_BOARD, true, 0, 0xF);
	auto king_bcastle_moves = get_all_moves(BCASTLING_POS, CASTLE_BOARD, true, 0, 0xF);
	auto en_passant_moves = get_all_moves(EN_PASSANT_TEST_POS, EN_PASSANT_TEST_BOARD, true, EN_PASSANT_SQUARE, 0);
	auto pawn_prom_moves = get_all_moves(PROM_PAWN_POS, PROM_PAWN_BOARD);
	auto bpawn_prom_moves = get_all_moves(PROM_BPAWN_POS, PROM_BPAWN_BOARD);

	CHECK(get_notations(knight_moves, KNIGHT_BLOCKED1_BOARD) == KNIGHT_BLOCKED1_NOTATION);
	CHECK(get_notations(bishop_moves, BISHOP_BLOCKED1_BOARD) == BISHOP_BLOCKED1_NOTATION);
	CHECK(get_notations(rook_moves, ROOK_BLOCKED1_BOARD) == ROOK_BLOCKED1_NOTATION);
	CHECK(get_notations(pawn_moves, PAWN_DIAG_TEST1_BOARD) == PAWN_DIAG_TEST1_NOTATION);
	CHECK(get_notations(king_moves, KING_CHECK_TEST_BOARD) == KING_CHECK_TEST_NOTATION);
	CHECK(get_notations(king_castle_moves, CASTLE_BOARD) == CASTLING_MOVES_NOTATION);
	CHECK(get_notations(king_bcastle_moves, CASTLE_BOARD) == BCASTLING_MOVES_NOTATION);
	CHECK(get_notations(en_passant_moves, EN_PASSANT_TEST_BOARD) == EN_PASSANT_TEST_NOTATION);
	CHECK(get_notations(pawn_prom_moves, PROM_PAWN_BOARD) == PROM_PAWN_NOTATION);
	CHECK(get_notations(bpawn_prom_moves, PROM_BPAWN_BOARD) == PROM_BPAWN_NOTATION);
}

TEST_CASE("Test for disambiguating moves in algebraic notation", "[to_notation]"){
	auto brook1_moves = get_all_moves(DISAMB_BROOK1_POS, DISAMB_BOARD);
	auto brook2_moves = get_all_moves(DISAMB_BROOK2_POS, DISAMB_BOARD);
	auto wrook1_moves = get_all_moves(DISAMB_WROOK1_POS, DISAMB_BOARD);
	auto wrook2_moves = get_all_moves(DISAMB_WROOK2_POS, DISAMB_BOARD);
	auto bishop1_moves = get_all_moves(DISAMB_BISHOP1_POS, DISAMB_BOARD);
	auto bishop2_moves = get_all_moves(DISAMB_BISHOP2_POS, DISAMB_BOARD);
	auto queen1_moves = get_all_moves(DISAMB_QUEEN1_POS, DISAMB_BOARD);
	auto queen2_moves = get_all_moves(DISAMB_QUEEN2_POS, DISAMB_BOARD);
	auto queen3_moves = get_all_moves(DISAMB_QUEEN3_POS, DISAMB_BOARD);
	
	CHECK(get_notations(brook1_moves, DISAMB_BOARD) == DISAMB_BROOK1_NOTATION);
	CHECK(get_notations(brook2_moves, DISAMB_BOARD) == DISAMB_BROOK2_NOTATION);
	CHECK(get_notations(wrook1_moves, DISAMB_BOARD) == DISAMB_WROOK1_NOTATION);
	CHECK(get_notations(wrook2_moves, DISAMB_BOARD) == DISAMB_WROOK2_NOTATION);
	CHECK(get_notations(bishop1_moves, DISAMB_BOARD) == DISAMB_BISHOP1_NOTATION);
	CHECK(get_notations(bishop2_moves, DISAMB_BOARD) == DISAMB_BISHOP2_NOTATION);
	CHECK(get_notations(queen1_moves, DISAMB_BOARD) == DISAMB_QUEEN1_NOTATION);
	CHECK(get_notations(queen2_moves, DISAMB_BOARD) == DISAMB_QUEEN2_NOTATION);
	CHECK(get_notations(queen3_moves, DISAMB_BOARD) == DISAMB_QUEEN3_NOTATION);
}

TEST_CASE("Test for disambiguating moves, and checkmate mark (#)", "[to_notation]"){
	auto check_rook_moves = get_all_moves(CHECKMATE_ROOK_POS, CHECKMATE_ROOK_BOARD);

	CHECK(get_notations(check_rook_moves, CHECKMATE_ROOK_BOARD) == CHECKMATE_ROOK_NOTATION);
}

TEST_CASE("Do extra (random board tests) on notation and move generation", "[to_notation][get_all_moves]"){
	auto knight_moves = get_all_moves(KNIGHT_EXTRA1_POS, EXTRA1_BOARD);
	auto knight_moves2 = get_all_moves(KNIGHT_EXTRA2_POS, EXTRA2_BOARD);
	CHECK(get_notations(knight_moves, EXTRA1_BOARD) == KNIGHT_EXTRA1_NOTATION);
	CHECK(get_notations(knight_moves2, EXTRA2_BOARD) == KNIGHT_EXTRA2_NOTATION);
	CHECK(get_to_squares(knight_moves2) == KNIGHT_EXTRA2_MOVES);
}

TEST_CASE("Test for promotions on empty squares", "[get_all_moves]"){
	auto pawn_prom = get_all_moves(PAWN_PROM_BLANK_POS, PAWN_PROM_BLANK_BOARD);
	CHECK(get_notations(pawn_prom, PAWN_PROM_BLANK_BOARD) == PAWN_PROM_BLANK_NOTATION);
}

TEST_CASE("Tests for check on square of queenside capture", "[get_all_moves]"){
	auto cannot_queenside = get_all_moves(CASTLE_CHECK1_POS, CASTLE_CHECK1_BOARD, true, 0, 0xF);
	auto cannot_queenside2 = get_all_moves(CASTLE_CHECK2_POS, CASTLE_CHECK2_BOARD, true, 0, 0xF);
	auto cannot_queenside3 = get_all_moves(CASTLE_CHECK3_POS, CASTLE_CHECK3_BOARD, true, 0, 0xF);
	auto cannot_queenside4 = get_all_moves(CASTLE_CHECK4_POS, CASTLE_CHECK4_BOARD, true, 0, 0xF);

	CHECK(get_notations(cannot_queenside, CASTLE_CHECK1_BOARD) == CASTLE_CHECK1_NOTATION);
	CHECK(get_notations(cannot_queenside2, CASTLE_CHECK2_BOARD) == CASTLE_CHECK2_NOTATION);
	CHECK(get_notations(cannot_queenside3, CASTLE_CHECK3_BOARD) == CASTLE_CHECK3_NOTATION);
	CHECK(get_notations(cannot_queenside4, CASTLE_CHECK4_BOARD) == CASTLE_CHECK4_NOTATION);
}
