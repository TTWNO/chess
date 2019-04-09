#include "constants.h"
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>

// Convert pair of x y coordinates to Position enum member.
// If pr contains values above 7, or below 0 it will fail with an InvalidArgument exception.
Position pair_to_pos(std::pair<int, int> pr);
Position pair_to_pos(int x, int y);

// Returns a list of positions with PieceType pt
std::vector<Position> get_pos_of(PieceType pt, std::array<PieceType, 64>);

// Convert a Position number into a pair of x y coordiinates
std::pair<int, int> pos_to_pair(Position pn);

// Check if int is a valid position in enum of Position
// Allow ints, and pairs to be checked.
bool is_valid_position(int pos);
bool is_valid_position(std::pair<int, int> pos);
bool is_valid_position(int x, int y);

// Checks if given piece matches a certain color.
bool is_white(PieceType pt);
bool is_black(PieceType pt);

Color get_color(int x, int y, std::array<PieceType, 64> board);
Color get_color(Position pn, std::array<PieceType, 64> board);
Color get_color(PieceType pt);
// NO_COLOR returns NO_COLOR
// WHITE returns BLACK
// BLACK returns WHITE
Color rev_color(Color c);

// Get all positions of pieces which can move to this square
// This may require helper functions for each individual peice.
// TODO rename to something less stupid.
std::unordered_set<Position> get_possible_movers(Position pn, std::array<PieceType, 64> pt);

// Get all possible moved for piece in Position pn.
// This may require helper functions for each individual piece.
std::unordered_set<Position> get_possible_moves(Position pn, std::array<PieceType, 64> pt);

// Get all moves for piece in Position pn. 
std::unordered_set<Position> get_all_moves(Position pn, std::array<PieceType, 64> pt, bool recursive=true);
// Get all moves for a list of Pieces given as std::vector<Position>
// I'm not testing this because it's literally just a for loop and the above function.
std::vector<std::unordered_set<Position>> get_all_moves_vec(std::vector<Position> v_pns, std::array<PieceType, 64> board);

// Dumb function to do board moves.
// Does NOT check for valid moves. Only moves PieceType of Pos1 to Pos2, then replaces Pos1 with Piecetype::NONE
std::array<PieceType, 64> dumb_move(Position from, Position to, std::array<PieceType, 64> board);
