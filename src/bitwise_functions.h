#include "bitwise_constants.h"
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>

// Convert pair of x y coordinates to Position enum member.
// If pr contains values above 7, or below 0 it will fail with an InvalidArgument exception.
Position pair_to_pos(std::pair<int, int> pr);
Position pair_to_pos(int x, int y);

// Returns a list of positions with PieceType pt
std::vector<Position> get_pos_of(PieceType pt, std::array<PieceType, 120>);

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

Color get_color(int x, int y, std::array<PieceType, 120> *board);
Color get_color(Position pn, std::array<PieceType, 120> *board);
Color get_color(PieceType pt);
// NO_COLOR returns NO_COLOR
// WHITE returns BLACK
// BLACK returns WHITE
Color rev_color(Color c);

// Get all positions of pieces which can move to this square
// This may require helper functions for each individual peice.
// TODO rename to something less stupid.
void get_possible_movers(Position pn, std::array<PieceType, 120> *pt,std::unordered_set<int> *moves);

// Get all possible moved for piece in Position pn.
// This may require helper functions for each individual piece.
void get_possible_moves(Position pn, std::array<PieceType, 120> *pt,std::unordered_set<int> *moves);

// Get all moves for piece in Position pn.
void get_all_moves(Position pn, std::array<PieceType, 120> *pt,std::unordered_set<int> *moves, bool recursive=true, int en_passant=Position::NA);

// Dumb function to do board moves.
// Does not check if move is valid, just does it.
std::array<PieceType, 120> dumb_move(int move, std::array<PieceType, 120> *board);
