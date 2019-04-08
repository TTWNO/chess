#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "test_boards.h"
#include "valid_moves.h"
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
	// This overrides vectors of positions. I want it to print a board with the positions that are selected so we can see a representation of what positions are selected.
	template<>
	struct StringMaker<std::unordered_set<Position>> {
		static std::string convert(std::unordered_set<Position> const& uo_poss){
			std::vector<Position> poss(uo_poss.begin(), uo_poss.end());
			std::stringstream ss;
			std::string files = "  A B C D E F G H";
			ss << "{ {" << std::endl;
			ss << files << std::endl;
			for (int i = 0; i < 8; ++i){
				ss << 8-i << "|";
				for (int j = 0; j < 8; ++j){
					int index = (i*8)+j;
					// This part loops through all positions in the list and checks if it contains the current index.
					bool part_of_poss = false;
					for (Position p : poss){
						if (index == p) {
							part_of_poss = true;
							break;
						}
					}
					// Justin, this is how this oporator works.
					// (if) part_of_poss ?(then) do this :(else) do that.
					part_of_poss ? ss << "* " : ss << "  ";
				}
				ss << "|" << 8-i;
				ss << std::endl;
			}
			ss << files << std::endl;
			ss << "}" << std::endl;
		        ss << "," << std::endl;
		        ss << "{ ";
			for (int pi = 0; pi < poss.size(); ++pi){
				pi == poss.size()-1 ? ss << poss[pi] << "(" << POSITION_STRING[poss[pi]] << ")" : ss << poss[pi] << "(" << POSITION_STRING[poss[pi]] << "), ";
			}
			ss << " } }" << std::endl;
			return ss.str();
		}
	};
		
}

const std::array<PieceType, 64> TEST_MOVES = {
	W_QUEEN, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, B_KNIGHT
};

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

TEST_CASE("Test what pieces may move where functon", "[get_possible_movers]"){
	std::unordered_set<Position> H1_possible_movers = {Position::H2, Position::G1};
	CHECK(get_possible_movers(BISHOP_BLOCKED1_KING_POS, BISHOP_BLOCKED1_BOARD) == BISHOP_BLOCKED1_CAN_MOVE_TO_B_KING);
	CHECK(get_possible_movers(Position::H3, DEFAULT_BOARD) == H1_possible_movers);
}

TEST_CASE("Test where this piece may move to", "[get_possible_moves]"){
	std::unordered_set<Position> white_right_knight_possible_moves = {Position::H3, Position::F3};
	std::unordered_set<Position> black_A_pawn_possible_moves = {Position::A6,Position::A5};
	CHECK(get_possible_moves(Position::G1, DEFAULT_BOARD) == white_right_knight_possible_moves);
	CHECK(get_possible_moves(Position::A7, DEFAULT_BOARD) == black_A_pawn_possible_moves);
	CHECK(get_possible_moves(KNIGHT_BLOCKED1_POS, KNIGHT_BLOCKED1_BOARD) == KNIGHT_BLOCKED1_MOVES);
	CHECK(get_possible_moves(BISHOP_BLOCKED1_POS, BISHOP_BLOCKED1_BOARD) == BISHOP_BLOCKED1_MOVES);
}

TEST_CASE("Test all possible and impossible moves for black pieces", "[get_all_moves][black]"){
	CHECK(get_all_moves(B_KING_POS, B_KING_BOARD) == B_KING_ALL_MOVES);
	CHECK(get_all_moves(B_QUEEN_POS, B_QUEEN_BOARD) == B_QUEEN_ALL_MOVES);
	CHECK(get_all_moves(B_ROOK_POS, B_ROOK_BOARD) == B_ROOK_ALL_MOVES);
	CHECK(get_all_moves(B_BISHOP_POS, B_BISHOP_BOARD) == B_BISHOP_ALL_MOVES);
	CHECK(get_all_moves(B_KNIGHT_POS, B_KNIGHT_BOARD) == B_KNIGHT_ALL_MOVES);
	CHECK(get_all_moves(B_PAWN_POS, B_PAWN_BOARD) == B_PAWN_ALL_MOVES);
}
TEST_CASE("Test all possible and impossible moves for whtie pieces", "[get_all_moves][white]"){
	CHECK(get_all_moves(W_KING_POS, W_KING_BOARD) == W_KING_ALL_MOVES);
	CHECK(get_all_moves(W_QUEEN_POS, W_QUEEN_BOARD) == W_QUEEN_ALL_MOVES);
	CHECK(get_all_moves(W_ROOK_POS, W_ROOK_BOARD) == W_ROOK_ALL_MOVES);
	CHECK(get_all_moves(W_BISHOP_POS, W_BISHOP_BOARD) == W_BISHOP_ALL_MOVES);
	CHECK(get_all_moves(W_KNIGHT_POS, W_KNIGHT_BOARD) == W_KNIGHT_ALL_MOVES);
	CHECK(get_all_moves(W_PAWN_POS, W_PAWN_BOARD) == W_PAWN_ALL_MOVES);
}

TEST_CASE("Test all moves for white in edge cases.", "[get_all_moves][white]"){
	CHECK(get_all_moves(W_KNIGHT_SIDE1_POS, W_KNIGHT_SIDE1_BOARD) == W_KNIGHT_SIDE1_ALL_MOVES);
	CHECK(get_all_moves(W_KING_SIDE1_POS, W_KING_SIDE1_BOARD) == W_KING_SIDE1_ALL_MOVES);
	CHECK(get_all_moves(W_PAWN_SIDE1_POS, W_PAWN_SIDE1_BOARD) == W_PAWN_SIDE1_ALL_MOVES);
}
TEST_CASE("Test all moves for black in edge cases.", "[get_all_moves][black]"){
	CHECK(get_all_moves(B_KNIGHT_SIDE1_POS, B_KNIGHT_SIDE1_BOARD) == B_KNIGHT_SIDE1_ALL_MOVES);
	CHECK(get_all_moves(B_KING_SIDE1_POS, B_KING_SIDE1_BOARD) == B_KING_SIDE1_ALL_MOVES);
	CHECK(get_all_moves(B_PAWN_SIDE1_POS, B_PAWN_SIDE1_BOARD) == B_PAWN_SIDE1_ALL_MOVES);
}


