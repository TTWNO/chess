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
int get_pos_of(PieceType pt, std::array<PieceType, 120> const *board);
std::unordered_set<int> get_poss_of(PieceType pt, std::array<PieceType, 120> const *board);

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

Color get_color(int x, int y, std::array<PieceType, 120> const *board);
Color get_color(Position pn, std::array<PieceType, 120> const *board);
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

// This functions removes moves that put your own king in check.
void filter_checked_moves(int pos, std::array<PieceType, 120> *board, std::unordered_set<int> *moves);

// Get all moves for piece in Position pn.
void get_all_moves(int pos, std::array<PieceType, 120> *pt,std::unordered_set<int> *moves, bool recursive=true, int en_passant=Position::NA);
std::unordered_set<int> get_all_moves(int pos, std::array<PieceType, 120> board, bool recursive=true, int en_passant=Position::NA);

// Dumb function to do board moves.
// Does not check if move is valid, just does it.
std::array<PieceType, 120> dumb_move(int move, std::array<PieceType, 120> board);

// Allow the developer to get only certain pieces of the part of a move in a list.
// This will return a vector (or unordered_set) of elements with only a certain part of the move revealed bit bit-switching.
std::unordered_set<int> get_from_squares(std::unordered_set<int> moves);
std::unordered_set<int> get_to_squares(std::unordered_set<int> moves);

