#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <sstream>
#include <tuple>
#include <functions.h>

// For some retarted reason, I need to implement the printing of pairs, otherwise in the test outputs they show up as {?}
// TODO implement that functionality.

TEST_CASE("Test convert method to go from X and Y to board position", "[pair_to_pos]"){
	CHECK(pair_to_pos(make_pair(3, 5)) == Position::C3);
	CHECK(pair_to_pos(make_pair(7, 0)) == Position::H8);
	CHECK(pair_to_pos(make_pair(0, 0)) == Position::A8);
	CHECK(pair_to_pos(make_pair(7, 7)) == Position::H1);
	CHECK_THROWS(pair_to_pos(make_pair(8, 2)));
	CHECK_THROWS(pair_to_pos(make_pair(-1, 1)));
}

TEST_CASE("Test convert method to go from a board position to an x and y", "[pos_to_pair]"){
	CHECK(pos_to_pair(Position::A3) == make_pair(0, 5));
	CHECK(pos_to_pair(Position::B2) == make_pair(1, 1));
	CHECK(pos_to_pair(Position::H8) == make_pair(0, 7));
}
