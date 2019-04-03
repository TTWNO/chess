#include "functions.h"

// TODO implement functions.h functions.
// NOTE tests will NOT run unless you implement these functions.

std::pair<int, int> pos_to_pair(Position pn){
	// TODO replace with real code. Just implementing for running the tests.
	return std::make_pair(-1, -1);
}

Position pair_to_pos(std::pair<int, int> pr){
	return Position::A1;
}

std::vector<Position> get_possible_movers(Position pn, std::vector<PieceType> board){
	std::vector<Position> pns = {Position::A1};
	return pns;
}

std::vector<Position> get_possible_moves(Position pn, std::vector<PieceType> board){
	std::vector<Position> pns = {Position::A1};
	return pns;
}
