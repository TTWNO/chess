#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include <functions.h>

// For some retarted reason, I need to implement the printing of pairs, otherwise in the test outputs they show up as {?}
// Also override default printing for Positions so it prints the value (e.g. 32), then, in parenthasies, the location (e.g. A4).
// Example: A4(32)
namespace Catch {
	template<>
	struct StringMaker<std::pair<int, int>> {
		static std::string convert(std::pair<int, int> const& p){
			std::stringstream ss;
			ss << "{ " << p.first << ", " << p.second << " }";
			return ss.str();
		}
	};
	template<> 
	struct StringMaker<Position> {
		static std::string convert(Position const& p){
			std::stringstream ss;
			ss << (int) p << "(" << POSITION_STRING[p] << ")";
			return ss.str();
		}
	};
	// This prints all board comparisons in a readable fashion. Using the string name of the pieces, and newlines to seperate them.
	template<>
	struct StringMaker<std::array<PieceType, 64>> {
		static std::string convert(std::array<PieceType, 64> const& board){
			std::stringstream ss;
			ss << "{" << std::endl;
			for (int i = 0; i < 8; ++i){
				for (int j = 0; j < 8; ++j){
					int index = (i*8)+j;
					ss << CHESS_CHARS[board[index]] << ", ";
				}
				ss << std::endl;
			}
			ss << "}" << std::endl;
			return ss.str();
		}
	};
}

const std::array<PieceType, 64> DUMB_MOVE_1 = {
	B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,	
	B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, W_PAWN, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	W_PAWN, NONE, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, 
	W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK 
};

TEST_CASE("Test that dumb moves can be made.", "[dumb_move]"){
	CHECK(dumb_move(Position::B2, Position::B5, DEFAULT_BOARD) == DUMB_MOVE_1);
}

TEST_CASE("Test convert method to go from X and Y to board position", "[pair_to_pos]"){
	CHECK(pair_to_pos(std::make_pair(2, 3)) == Position::C4);
	CHECK(pair_to_pos(std::make_pair(7, 0)) == Position::H1);
	CHECK(pair_to_pos(std::make_pair(0, 0)) == Position::A1);
	CHECK(pair_to_pos(std::make_pair(7, 7)) == Position::H8);
	CHECK_THROWS(pair_to_pos(std::make_pair(8, 2)));
	CHECK_THROWS(pair_to_pos(std::make_pair(-1, 1)));
}

TEST_CASE("Test convert method to go from a board position to an x and y", "[pos_to_pair]"){
	CHECK(pos_to_pair(Position::A3) == std::make_pair(0, 2));
	CHECK(pos_to_pair(Position::A4) == std::make_pair(0, 3));
	CHECK(pos_to_pair(Position::B2) == std::make_pair(1, 1));
	CHECK(pos_to_pair(Position::H8) == std::make_pair(7, 7));
}

TEST_CASE("Test what pieces may move where functon", "[get_possible_movers]"){
	std::vector<Position> H1_possible_movers = {Position::G1, Position::G2};
	CHECK(get_possible_movers(Position::H3, DEFAULT_BOARD) == H1_possible_movers);
}

TEST_CASE("Test where this piece may move to", "[get_possible_moves]"){
	std::vector<Position> black_right_knight_possible_moves = {Position::H3, Position::F3};
	std::vector<Position> white_a_pawn_possible_moves = {Position::A6};
	CHECK(get_possible_moves(Position::G1, DEFAULT_BOARD) == black_right_knight_possible_moves);
	CHECK(get_possible_moves(Position::A7, DEFAULT_BOARD) == white_a_pawn_possible_moves);
}
