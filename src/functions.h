#include "constants.h"
#include <utility>
#include <vector>

// Convert pair of x y coordinates to Position enum member.
// If pr contains values above 7, or below 0 it will fail with an InvalidArgument exception.
Position pair_to_pos(std::pair<int, int> pr);

// Convert a Position number into a pair of x y coordiinates
std::pair<int, int> pos_to_pair(Position pn);

// Get all positions of pieces which can move to this square
// This may require helper functions for each individual peice.
// TODO rename to something less stupid.
std::vector<Position> get_possible_movers(Position pn, std::vector<PieceType> pt);

// Get all possible moved for piece in Position pn.
// This may require helper functions for each individual piece.
std::vector<Position> get_possible_moves(Position pn, std::vector<PieceType> pt);
