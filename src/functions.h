#include "constants.h"
#include <string>
#include <vector>
#include <utility>
#include <vector>
#include <math.h>

// Returns a list of positions with PieceType pt
int get_pos_of(PieceType pt, std::array<PieceType, 120> const *board);
std::vector<int> get_poss_of(PieceType pt, std::array<PieceType, 120> const *board);

// Convert a Position number into a pair of x y coordiinates
std::pair<int, int> pos_to_pair(Position pn);

// Check if int is a valid position in enum of Position
// Allow ints, and pairs to be checked.
bool is_valid_position(int pos);

// Returns rank enum value for given pos
Rank get_rank(int pos);

// Checks if given piece matches a certain color.
bool is_white(int pt);
bool is_black(int pt);

Color get_color(int pn, std::array<PieceType, 120> const *board);
Color get_color(PieceType pt);
// NO_COLOR returns NO_COLOR
// WHITE returns BLACK
// BLACK returns WHITE
Color rev_color(Color c);
PieceType rev_color(PieceType pt);

// Get all positions of pieces which can move to this square
// This may require helper functions for each individual peice.
// TODO rename to something less stupid.
void get_possible_movers(Position pn, std::array<PieceType, 120> *pt,std::vector<int> *moves);

// Get all possible moved for piece in Position pn.
// This may require helper functions for each individual piece.
void get_possible_moves(Position pn, std::array<PieceType, 120> *pt,std::vector<int> *moves);

// This functions removes moves that put your own king in check.
void filter_checked_moves(int pos, std::array<PieceType, 120> *board, std::vector<int> *moves);

// This function is like get_all_moves, except it doesn't check pos and base the piecetype on that,
// ... but instead acts as if the PieceType pt is on pos, and returns possible move sbased on that.
void get_all_moves_as_if(int pos, PieceType pt, std::array<PieceType, 120> *board, std::vector<int> *moves, bool recursvie=true, int en_passant=Position::NA, int castle_perms=0);

// Get all moves for piece in Position pn.
void get_all_moves(int pos, std::array<PieceType, 120> *pt, std::vector<int> *moves, bool recursive=true, int en_passant=Position::NA, int castle_perms=0);
std::vector<int> get_all_moves(int pos, std::array<PieceType, 120> board, bool recursive=true, int en_passant=Position::NA, int castle_perms=0);


// Dumb function to do board moves.
// Does not check if move is valid, just does it.
std::array<PieceType, 120> dumb_move(int move, std::array<PieceType, 120> board);

// Decides if there this piece in position is in check
bool is_checked(int pos, std::array<PieceType, 120> board);

// Convert move (and board becuase notation needs more info than the move itself)
// ...into algbraic notation.
std::string to_notation(int move, std::array<PieceType, 120> *board);

// These functions are just for printing (for now) so they are not included in the tests.
void get_all_moves_for_pieces(std::array<PieceType, 6> pieces, std::array<PieceType, 120> *board, std::vector<int> *moves, int en_passant, int castle_perms);
void remove_chars_from_string(std::string &std, std::string to_remove);
