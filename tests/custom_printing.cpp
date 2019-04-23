#include "catch.hpp"
#include <constants.h>
#include <sstream>
#include <unordered_set>

// override default printing for Positions so it prints the value (e.g. 32), then, in parenthasies, the location (e.g. A4).
// Example: A4(32)
namespace Catch {
	template<> 
	struct StringMaker<Position> {
		static std::string convert(Position const& p){
			std::stringstream ss;
			ss << (int) p << "(" << POSITION_STRING[p] << ")";
			return ss.str();
		}
	};
	// This override makes sure that Color enum variables are printed properly
	template<>
	struct StringMaker<Color> {
		static std::string convert(Color const& c){
			std::stringstream ss;
			if (c==Color::WHITE) ss << "white";
			if (c==Color::BLACK) ss << "black";
			if (c==Color::NO_COLOR) ss << "N/A";
			return ss.str();
		}
	};
	// This prints all board comparisons in a readable fashion. Using the string name of the pieces, and newlines to seperate them.
	template<>
	struct StringMaker<std::array<PieceType, 120>> {
		static std::string convert(std::array<PieceType, 120> const& board){
			std::stringstream ss;
			ss << "{" << std::endl;
			for (int i = 2; i < 10; ++i){
				for (int j = 1; j < 9; ++j){
					int index = (i*10)+j;
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
	struct StringMaker<std::unordered_set<int>> {
		static std::string convert(std::unordered_set<int> const& uo_poss){
			std::vector<int> poss(uo_poss.begin(), uo_poss.end());
			std::stringstream ss;
			std::string files = "  A B C D E F G H";
			ss << "{ {" << std::endl;
			ss << files << std::endl;
			for (int i = 2; i < 10; ++i){
				ss << i-1 << "|";
				for (int j = 1; j < 9; ++j){
					int index = (i*10)+j;
					// This part loops through all positions in the list and checks if it contains the current index.
					bool part_of_poss = false;
					for (int p : poss){
						if (index == p) {
							part_of_poss = true;
							break;
						}
					}
					// Justin, this is how this oporator works.
					// (if) part_of_poss ?(then) do this :(else) do that.
					part_of_poss ? ss << "* " : ss << "  ";
				}
				ss << "|" << i-1;
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

