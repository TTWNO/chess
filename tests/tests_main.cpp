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
	// This overrides vectors of positions. I want it to print a board with the positions that are selected so we can see a representation of what positions are selected.
	template<>
	struct StringMaker<std::vector<Position>> {
		static std::string convert(std::vector<Position> const& poss){
			std::stringstream ss;
			std::string files = "  A B C D E F G H";
			ss << "{ {" << std::endl;
			ss << files << std::endl;
			for (int i = 0; i < 8; ++i){
				ss << 8-i << "|";
				for (int j = 0; j < 8; ++j){
					int index = (i*8)+j;
					bool part_of_poss = false;
					for (Position p : poss){
						if (index == p) {
							part_of_poss = true;
							break;
						}
					}
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
			ss << " }" << std::endl;
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
}

TEST_CASE("Test convert method to go from a board position to an x and y", "[pos_to_pair]"){
	CHECK(pos_to_pair(Position::A3) == std::make_pair(0, 2));
	CHECK(pos_to_pair(Position::A4) == std::make_pair(0, 3));
	CHECK(pos_to_pair(Position::B2) == std::make_pair(1, 1));
	CHECK(pos_to_pair(Position::H8) == std::make_pair(7, 7));
}

TEST_CASE("Test what pieces may move where functon", "[get_possible_movers]"){
	std::vector<Position> H1_possible_movers = {Position::H2, Position::G1};
	CHECK(get_possible_movers(Position::H3, DEFAULT_BOARD) == H1_possible_movers);
}

TEST_CASE("Test where this piece may move to", "[get_possible_moves]"){
	std::vector<Position> white_right_knight_possible_moves = {Position::H3, Position::F3};
	std::vector<Position> black_A_pawn_possible_moves = {Position::A6,Position::A5};
	CHECK(get_possible_moves(Position::G1, DEFAULT_BOARD) == white_right_knight_possible_moves);
	CHECK(get_possible_moves(Position::A7, DEFAULT_BOARD) == black_A_pawn_possible_moves);
}

TEST_CASE("Test all possible and impossible moves", "[get_all_moves]"){
	std::vector<Position> white_right_knight_all_moves = {Position::F3, Position::H3, Position::E2, Position::G1};     	

	std::vector<Position> black_A_pawn_all_moves = {Position::A7, Position::A6, Position::B6, Position::A5};

	std::vector<Position> black_F_bishop_all_moves = {Position:F8, Position::E7, Position::G7, Position::D6, Position::H6, Position::C5, Position::B4, Position::A3};

	std::vector<Position> black_queen_all_moves = {Position::A8, Position::B8, Position::C8, Position::D8, Position::E8, Position::F8, Position::G8, Position::H8, Position::C7, Position::D7, Position::E7, Position::B6, Position::D6, Position::F6, Position::A5, Position::D5, Position::G5, Position::D4, Position::H4, Position::D3, Position::D2, Position::D1};

	std::vector<Position> white_A_rook_all_moves = {Position::A8, Position::A7, Position::A6, Position::A5, Position::A4, Position::A3, Position::A2, Position::A1, Position::B1, Position::C1, Position::D1, Position::E1, Position::F1, Position::G1, Position::H1};

	std::vector<Position> white_king_all_moves = {Position::D2, Position::E2, Position::F2, Position::D1, Position::E1, Position::F1}; 

	std::vector<Position> black_king_all_moves = {Position::D8, Position::E8, Position::F8, Position::D7, Position::E7, Position::F7};

	std::vector<Position> white_F_bishop_all_moves = {Position::A6, Position::B5, Position::C4, Position::D3, Position::H3, Position::E2, Position::G2, Position::F1};

	std::vector<Position> white_queen_all_moves = {Position::D8, Position::D7, Position::D6, Position::D5, Position::H5, Position::A4, Position::D4, Position::G4, Position::B3, Position::D3, Position::F3, Position::C2, Position::D2, Position::E2, Position::A1, Position::B1, Position::C1, Position::D1, Position::E1, Position::F1, Position::G1, Position::H1};

	std::vector<Position> left_black_knight_all_moves = {Position::B8, Position::D7, Position::A6, Position::C6};

	std::vector<Position> black_H_rook_all_moves = {Position::A8, Position::B8, Position::C8, Position::D8, Position::E8, Position::F8, Position::G8, Position::H8, Position::H7, Position::H6, Position::H5, Position::H4, Position::H3, Position::H2, Position::H1};
	

	CHECK(get_all_moves(Position::H8, DEFAULT_BOARD) == black_H_rook_all_moves);
	CHECK(get_all_moves(Position::G1, DEFAULT_BOARD) == white_right_knight_all_moves);
	CHECK(get_all_moves(Position::A7, DEFAULT_BOARD) == black_A_pawn_all_moves);
	CHECK(get_all_moves(Position::F8, DEFAULT_BOARD) == black_F_bishop_all_moves);
	CHECK(get_all_moves(Position::D8, DEFAULT_BOARD) == black_queen_all_moves);
	CHECK(get_all_moves(Position::A1, DEFAULT_BOARD) == white_A_rook_all_moves);
	CHECK(get_all_moves(Position::E1, DEFAULT_BOARD) == white_king_all_moves);
	CHECK(get_all_moves(Position::D1, DEFAULT_BOARD) == white_queen_all_moves);
	CHECK(get_all_moves(Position::B8, DEFAULT_BOARD) == left_black_knight_all_moves);
}

