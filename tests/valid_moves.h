#include <vector>
#include <constants.h>


/// This is for possible moves on a default board
const std::vector<int> DEFAULT_B_A_PAWN_POSSIBLE_MOVES = {
	A6, A5
};
const std::vector<int> DEFAULT_W_A_PAWN_POSSIBLE_MOVES = {
	A3, A4
};
const std::vector<int> DEFAULT_W_R_KNIGHT_POSSIBLE_MOVES = {
	H3, F3
};
// EMPTY
const std::vector<int> DEFAULT_W_R_ROOK_POSSIBLE_MOVES = {};

const std::vector<int> B_PAWNS_SQUARES = {
	A7, B7, C7, D7, E7, F7, G7, H7
};

// END of default selections

const int KNIGHT_BLOCKED1_POS = B8;
const std::array<PieceType, 120> KNIGHT_BLOCKED1_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, B_KNIGHT, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, B_PAWN, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, W_PAWN, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
// Should NOT inclde D7
const std::vector<int> KNIGHT_BLOCKED1_MOVES = {
	A6, C6
};

const int BISHOP_BLOCKED1_POS = D5;
const std::array<PieceType, 120> BISHOP_BLOCKED1_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, B_QUEEN, NONE  , B_PAWN  , NONE, W_KING, NONE, NONE,  INV,	
	INV, NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE   , W_ROOK, W_BISHOP, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE   , NONE  , NONE    , NONE, B_KING, NONE, NONE,  INV,	
	INV, NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
// Should NOT include A8, H8, G2, or H1
const std::vector<int> BISHOP_BLOCKED1_MOVES = {
	B7,
	C6,E6,
	C4,E4,
	B3,F3,
	A2
};
// Should NOT include B2 (black queen) as it is obstructed by the bishop on D5
const std::vector<int> BISHOP_BLOCKED1_CAN_MOVE_TO_B_KING = {
	D5
};
const int BISHOP_BLOCKED1_KING_POS = F3;


const int ROOK_BLOCKED1_POS = B7;
const std::array<PieceType, 120> ROOK_BLOCKED1_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, W_ROOK, NONE  , B_PAWN  , NONE, B_KING, NONE, NONE, INV,	
	INV, NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE   , B_BISHOP, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, INV,	
	INV, NONE, W_KING   , NONE  , NONE    , NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE   , NONE  , NONE    , NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV
};
// Should NOT include E-H2 or B3-1
const std::vector<int> ROOK_BLOCKED1_MOVES = {
	B8,
	A7, C7, D7,
	B6,B5,B4
};

const int PAWN_DIAG_TEST1_POS = E7;
const std::array<PieceType, 120> PAWN_DIAG_TEST1_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,INV,	
	INV, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN,INV, 
	INV, NONE, NONE, NONE, W_QUEEN, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN,INV, 
	INV, W_ROOK, W_KNIGHT, W_BISHOP, NONE, W_KING, W_BISHOP, W_KNIGHT, W_ROOK, INV, 
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<int> PAWN_DIAG_TEST1_MOVES = {
	E6, E5, D6
};

// For testing the invalidating of moves because of putting own king in check
const int ROOK_CHECK_TEST_POS = D5;
const std::array<PieceType, 120> ROOK_CHECK_TEST_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, W_QUEEN, B_ROOK, NONE, B_KING, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV
};
const std::vector<int> ROOK_CHECK_TEST_MOVES = {
	C5, E5
};

const int PAWN_CHECK_TEST_POS = E7;
const std::array<PieceType, 120> PAWN_CHECK_TEST_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,INV,	
	INV, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN,INV, 
	INV, NONE, NONE, NONE, W_PAWN, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, W_QUEEN, NONE, NONE, NONE,INV, 
	INV, W_PAWN, W_PAWN, W_PAWN, NONE, W_PAWN, W_PAWN, W_PAWN, W_PAWN,INV, 
	INV, W_ROOK, W_KNIGHT, W_BISHOP, NONE, W_KING, W_BISHOP, W_KNIGHT, W_ROOK, INV, 
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<int> PAWN_CHECK_TEST_MOVES = {E6, E5};

// These boards tests for en pessent squares.

const int EN_PASSANT_SQUARE = E6;
const int EN_PASSANT_TEST_POS = D5;
const std::array<PieceType, 120> EN_PASSANT_TEST_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,INV,	
	INV, B_PAWN, B_PAWN, B_PAWN, NONE, B_PAWN, B_PAWN, B_PAWN, B_PAWN,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, W_PAWN, B_PAWN, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, W_PAWN, W_PAWN, W_PAWN, NONE, W_PAWN, W_PAWN, W_PAWN, W_PAWN,INV, 
	INV, W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK, INV, 
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<int> EN_PASSANT_TEST_MOVES = {
	D6, E6
};
// Test pawn promotion
const int PROM_PAWN_POS = G7;
const std::array<PieceType, 120> PROM_PAWN_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,INV,	
	INV, B_PAWN, B_PAWN, B_PAWN, NONE, B_PAWN, B_PAWN, W_PAWN, B_PAWN,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, W_PAWN, W_PAWN, W_PAWN, NONE, W_PAWN, W_PAWN, W_PAWN, W_PAWN,INV, 
	INV, W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK, INV, 
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<int> PROM_PAWN_MOVES = {
	H8, H8, H8, H8,
	F8, F8, F8, F8
};
const std::vector<int> PROM_PAWN_PROMS = {
	W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN,
	W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN
};

// Black pawn promotion
const int PROM_BPAWN_POS = B2;
const std::array<PieceType, 120> PROM_BPAWN_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,INV,	
	INV, B_PAWN, B_PAWN, B_PAWN, NONE, B_PAWN, B_PAWN, B_PAWN, B_PAWN,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,INV, 
	INV, W_PAWN, B_PAWN, W_PAWN, NONE, W_PAWN, W_PAWN, W_PAWN, W_PAWN,INV, 
	INV, W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK, INV, 
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<int> PROM_BPAWN_MOVES = {
	C1, C1, C1, C1,
	A1, A1, A1, A1
};

const std::vector<int> PROM_BPAWN_PROMS = {
	B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN,
	B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN
};

const int NO_EN_PASSANT_TEST_POS = D5;
const std::array<PieceType, 120> NO_EN_PASSANT_TEST_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK, INV,	
	INV, B_PAWN, B_PAWN, B_PAWN, NONE, B_PAWN, B_PAWN, B_PAWN, B_PAWN, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV, 
	INV, NONE, NONE, NONE, W_PAWN, B_PAWN, NONE, NONE, NONE, INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV, 
	INV, W_PAWN, W_PAWN, W_PAWN, NONE, W_PAWN, W_PAWN, W_PAWN, W_PAWN, INV, 
	INV, W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK, INV, 
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<int> NO_EN_PASSANT_TEST_MOVES = {D6};

// Castling tests
const int CASTLING_POS = E1;
const std::array<PieceType, 120> CASTLING_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, NONE, NONE, NONE, B_KING, NONE, NONE, B_ROOK,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, W_ROOK, NONE, NONE, NONE, W_KING, NONE, NONE, W_ROOK, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};

// Should NOT inclde D7
const std::vector<int> CASTLING_MOVES = {
	D1, D2, E2, F2, F1,
	C1, G1
};

