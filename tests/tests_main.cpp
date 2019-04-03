#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include <functions.h>

// For some retarted reason, I need to implement the printing of pairs, otherwise in the test outputs they show up as {?}
namespace Catch {
	template<>
	struct StringMaker<std::pair<int, int>> {
		static std::string convert(std::pair<int, int> const& p){
			std::stringstream ss;
			ss << "{ " << p.first << ", " << p.second << " }";
			return ss.str();
		}
	};
}


TEST_CASE("Test convert method to go from X and Y to board position", "[pair_to_pos]"){
	CHECK(pair_to_pos(std::make_pair(3, 5)) == Position::C3);
	CHECK(pair_to_pos(std::make_pair(7, 0)) == Position::H8);
	CHECK(pair_to_pos(std::make_pair(0, 0)) == Position::A8);
	CHECK(pair_to_pos(std::make_pair(7, 7)) == Position::H1);
	CHECK_THROWS(pair_to_pos(std::make_pair(8, 2)));
	CHECK_THROWS(pair_to_pos(std::make_pair(-1, 1)));
}

TEST_CASE("Test convert method to go from a board position to an x and y", "[pos_to_pair]"){
	CHECK(pos_to_pair(Position::A3) == std::make_pair(0, 5));
	CHECK(pos_to_pair(Position::B2) == std::make_pair(1, 1));
	CHECK(pos_to_pair(Position::H8) == std::make_pair(0, 7));
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
