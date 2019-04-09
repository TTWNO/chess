#include <unordered_set>
#include <constants.h>


/// This is for possible moves on a default board
const std::unordered_set<Position> DEFAULT_B_A_PAWN_POSSIBLE_MOVES = {
	A6, A5
};
const std::unordered_set<Position> DEFAULT_W_A_PAWN_POSSIBLE_MOVES = {
	A3, A4
};
const std::unordered_set<Position> DEFAULT_W_R_KNIGHT_POSSIBLE_MOVES = {
	H3, F3
};
// EMPTY
const std::unordered_set<Position> DEFAULT_W_R_ROOK_POSSIBLE_MOVES = {};

const std::vector<Position> B_PAWNS_SQUARES = {
	A7, B7, C7, D7, E7, F7, G7, H7
};

// END of default selections

const Position KNIGHT_BLOCKED1_POS = B8;
const std::array<PieceType, 64> KNIGHT_BLOCKED1_BOARD = {
	NONE, B_KNIGHT, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, B_PAWN, NONE, NONE, NONE, NONE, 	
	NONE, NONE, W_PAWN, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE
};
// Should NOT inclde D7
const std::unordered_set<Position> KNIGHT_BLOCKED1_MOVES = {
	A6, C6
};

const Position BISHOP_BLOCKED1_POS = D5;
const std::array<PieceType, 64> BISHOP_BLOCKED1_BOARD = {
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, B_QUEEN, NONE  , B_PAWN  , NONE, W_KING, NONE, NONE, 	
	NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, 	
	NONE, NONE   , W_ROOK, W_BISHOP, NONE, NONE, NONE, NONE, 	
	NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, 	
	NONE, NONE   , NONE  , NONE    , NONE, B_KING, NONE, NONE, 	
	NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, 	
	NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE
};
// Should NOT include A8, H8, G2, or H1
const std::unordered_set<Position> BISHOP_BLOCKED1_MOVES = {
	B7,
	C6,E6,
	C4,E4,
	B3,F3,
	A2
};
// Should NOT include B2 (black queen) as it is obstructed by the bishop on D5
const std::unordered_set<Position> BISHOP_BLOCKED1_CAN_MOVE_TO_B_KING = {
	D5
};
const Position BISHOP_BLOCKED1_KING_POS = F3;


const Position ROOK_BLOCKED1_POS = B7;
const std::array<PieceType, 64> ROOK_BLOCKED1_BOARD = {
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, W_ROOK, NONE  , B_PAWN  , NONE, B_KING, NONE, NONE, 	
	NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, 	
	NONE, NONE   , B_BISHOP, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, 	
	NONE, W_KING   , NONE  , NONE    , NONE, NONE, NONE, NONE, 	
	NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, 	
	NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE
};
// Should NOT include E-H2 or B3-1
const std::unordered_set<Position> ROOK_BLOCKED1_MOVES = {
	B8,
	A7, C7, D7,
	B6,B5,B4
};

const Position PAWN_DIAG_TEST1_POS = E7;
const std::array<PieceType, 64> PAWN_DIAG_TEST1_BOARD = {
	B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,	
	B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, 
	NONE, NONE, NONE, W_QUEEN, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, 
	W_ROOK, W_KNIGHT, W_BISHOP, NONE, W_KING, W_BISHOP, W_KNIGHT, W_ROOK 
};
const std::unordered_set<Position> PAWN_DIAG_TEST1_MOVES = {
	D6, E6, E5
};

// For testing the invalidating of moves because of putting own king in check
const Position ROOK_CHECK_TEST_POS = D5;
const std::array<PieceType, 64> ROOK_CHECK_TEST_BOARD = {
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, W_QUEEN, B_ROOK, NONE, B_KING, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 	
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE
};
const std::unordered_set<Position> ROOK_CHECK_TEST_MOVES = {
	C5, E5
};

const Position PAWN_CHECK_TEST_POS = E7;
const std::array<PieceType, 64> PAWN_CHECK_TEST_BOARD = {
	B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,	
	B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, 
	NONE, NONE, NONE, W_PAWN, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, W_QUEEN, NONE, NONE, NONE, 
	W_PAWN, W_PAWN, W_PAWN, NONE, W_PAWN, W_PAWN, W_PAWN, W_PAWN, 
	W_ROOK, W_KNIGHT, W_BISHOP, NONE, W_KING, W_BISHOP, W_KNIGHT, W_ROOK 
};
const std::unordered_set<Position> PAWN_CHECK_TEST_MOVES = {E6, E5};
