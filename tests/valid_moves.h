#include <vector>
#include <string>
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
const std::vector<int> KNIGHT_BLOCKED1_CAPTS = {
	NONE, W_PAWN
};
const std::vector<std::string> KNIGHT_BLOCKED1_NOTATION = {
	"Na6", "Nxc6"
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
	C6, B7,
	E6,
	C4, B3, A2,
	E4, F3
};
const std::vector<int> BISHOP_BLOCKED1_CAPTS = {
	NONE, B_QUEEN,
	NONE,
	NONE, NONE, NONE,
	NONE, B_KING,
};
const std::vector<std::string> BISHOP_BLOCKED1_NOTATION = {
	"Bc6+", "Bxb7+",
	"Be6",
	"Bc4", "Bb3", "Ba2",
	"Be4+", "Bxf3+"
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
	A7,
	B8,
	C7, D7,
	B6, B5, B4
};
const std::vector<int> ROOK_BLOCKED1_CAPTS = {
	NONE,
	NONE,
	NONE, B_PAWN,
	NONE, NONE, NONE
};
const std::vector<std::string> ROOK_BLOCKED1_NOTATION = {
	"Ra7",
	"Rb8",
	"Rc7", "Rxd7+",
	"Rb6", "Rb5", "Rb4"
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
const std::vector<int> PAWN_DIAG_TEST1_CAPTS = {
	NONE, NONE, W_QUEEN
};
const std::vector<std::string> PAWN_DIAG_TEST1_NOTATION = {
	"e6", "e5", "exd6"
};

// For testing the invalidating of moves because of putting own king in check
const int ROOK_CHECK_TEST_POS = D5;
const std::array<PieceType, 120> ROOK_CHECK_TEST_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, W_KING, NONE, NONE, NONE, NONE, NONE, INV,	
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
const std::vector<std::string> EN_PASSANT_TEST_NOTATION = {
	"d6", "dxe6e.p."
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
const std::vector<std::string> PROM_PAWN_NOTATION = {
	"gxh8=N","gxh8=B","gxh8=R","gxh8=Q",
	"gxf8=N","gxf8=B","gxf8=R","gxf8=Q"
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
const std::vector<std::string> PROM_BPAWN_NOTATION = {
	"bxc1=N","bxc1=B","bxc1=R","bxc1=Q",	
	"bxa1=N","bxa1=B","bxa1=R","bxa1=Q"	
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
const int BCASTLING_POS = E8;
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

const std::vector<int> CASTLING_MOVES = {
	D2, E2, F2, F1,
	D1, G1, C1
};
const std::vector<int> BCASTLING_MOVES = {
	D7, E7, F7, F8, D8, G8, C8
};
const std::vector<std::string> CASTLING_MOVES_NOTATION = {
	"Kd2", "Ke2", "Kf2", "Kf1",
	"Kd1", "O-O", "O-O-O"
};
const std::vector<std::string> BCASTLING_MOVES_NOTATION = {
	"Kd7", "Ke7", "Kf7",
	"Kf8", "Kd8", "O-O", "O-O-O"
};

const std::array<PieceType, 120> CASTLING_CHECK_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, NONE, NONE, NONE, B_KING, NONE, NONE, B_ROOK,  INV,	
	INV, NONE, NONE, NONE, NONE, W_BISHOP, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, W_ROOK, NONE, NONE, NONE, W_KING, NONE, NONE, W_ROOK, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::array<PieceType, 120> BLACK_CHECK_BOARD1 = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, NONE, NONE, NONE, NONE, B_KING, NONE, B_ROOK,  INV,	
	INV, NONE, NONE, NONE, NONE, W_BISHOP, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, W_ROOK, NONE, NONE, NONE, W_KING, NONE, NONE, W_ROOK, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::array<PieceType, 120> BLACK_CHECK_BOARD2 = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, NONE, NONE, B_KING, NONE, NONE, NONE, B_ROOK,  INV,	
	INV, NONE, NONE, NONE, NONE, W_BISHOP, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, W_ROOK, NONE, NONE, NONE, W_KING, NONE, NONE, W_ROOK, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const int BLACK_CHECK_POS1 = D8;
const int BLACK_CHECK_POS2 = F8;
const std::vector<int> BCASTLING_CHECK_MOVES = {
	D7, E7, F7
};
// Check that the dumb_move function actually moves the rook and the king to the right squares.
const int CASTLE_FROM_POS = E1;
const int CASTLE_TO_POS = G1;
const int BCASTLE_FROM_POS = E8;
const int BCASTLE_TO_POS = G8;

const int CASTLE_FROM_QPOS = E1;
const int CASTLE_TO_QPOS = C1;
const int BCASTLE_FROM_QPOS = E8;
const int BCASTLE_TO_QPOS = C8;

const std::array<PieceType, 120> CASTLE_BOARD = {
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
const std::array<PieceType, 120> CASTLE_BOARD_WK = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, NONE, NONE, NONE, B_KING, NONE, NONE, B_ROOK,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, W_ROOK, NONE, NONE, NONE, NONE, W_ROOK, W_KING, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::array<PieceType, 120> CASTLE_BOARD_BK = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, NONE, NONE, NONE, NONE, B_ROOK, B_KING, NONE,  INV,	
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
const std::array<PieceType, 120> CASTLE_BOARD_WQ = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, NONE, NONE, NONE, B_KING, NONE, NONE, B_ROOK,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, W_KING, W_ROOK, NONE, NONE, NONE, W_ROOK, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::array<PieceType, 120> CASTLE_BOARD_BQ = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, B_KING, B_ROOK, NONE, NONE, NONE, B_ROOK,  INV,	
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

// Check that castling is disallowed when there is a piece blocking the rook queenside.
const int CASTLE_BLOCKED_POS = E1;
const std::array<PieceType, 120> CASTLE_BLOCKED_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, NONE, NONE, NONE, B_KING, NONE, NONE, B_ROOK,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, W_ROOK, W_KNIGHT, NONE, NONE, W_KING, NONE, NONE, W_ROOK, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<int> CASTLE_BLOCKED_MOVES = {
	D2, E2, F2,
	F1, D1, G1
};

const int CASTLE_BLOCKED_QPOS = E8;
const std::array<PieceType, 120> CASTLE_BLOCKED_QBOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, B_ROOK, B_KNIGHT, NONE, NONE, B_KING, NONE, NONE, B_ROOK,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, W_ROOK, W_KNIGHT, NONE, NONE, W_KING, NONE, NONE, W_ROOK, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<int> CASTLE_BLOCKED_QMOVES = {
	D7, E7, F7,
	F8, D8, G8
};

// Check tests for king

const int KING_CHECK_TEST_POS = D6;
const int KING_CHECK_ROOK_POS = D5;
const std::array<PieceType, 120> KING_CHECK_TEST_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, W_KING, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, B_ROOK, NONE, NONE, B_KING, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV
};
const std::vector<int> KING_CHECK_TEST_MOVES = {
	C7, E7,
	D5,
	E6, C6
};
const std::vector<int> KING_CHECK_TEST_CAPTS = {
	NONE, NONE,
	B_ROOK,
	NONE, NONE
};
const std::vector<std::string> KING_CHECK_TEST_NOTATION = {
	"Kc7", "Ke7",
	"Kxd5",
	"Ke6", "Kc6"
};
const std::vector<int> KING_CHECK_ROOK_MOVES = {
	C5, B5, A5,
	D6, E5, F5,
	D4, D3, D2, D1
};

// This checks that en passant moves are handled correctly
// by the dumb_move method.
const int EN_PASSANT_EN_PASSANT_SQUARE = D7;
const int EN_PASSANT_CHECK_POS = E6;
const std::array<PieceType, 120> EN_PASSANT_CHECK_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, B_QUEEN, NONE, NONE, B_PAWN, W_PAWN, NONE, NONE, W_KING,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::array<PieceType, 120> EN_PASSANT_CHECK_MOVED_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, W_PAWN, NONE, NONE, NONE, NONE,  INV,	
	INV, B_QUEEN, NONE, NONE, NONE, NONE, NONE, NONE, W_KING,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<int> EN_PASSANT_CHECKED_MOVES = {
	E7
};

const int EN_PASSANT_EN_PASSANT_SQUARE1 = F7;
const int EN_PASSANT_CHECK_POS1 = E6;
const std::array<PieceType, 120> EN_PASSANT_CHECK_BOARD1 = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, W_PAWN, B_PAWN, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::array<PieceType, 120> EN_PASSANT_CHECK_MOVED_BOARD1 = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, W_PAWN, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};

const int EN_PASSANT_EN_PASSANT_SQUARE2 = D2;
const int EN_PASSANT_CHECK_POS2 = C3;
const std::array<PieceType, 120> EN_PASSANT_CHECK_BOARD2 = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, B_PAWN, W_PAWN, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::array<PieceType, 120> EN_PASSANT_CHECK_MOVED_BOARD2 = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, B_PAWN, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};

const int EN_PASSANT_EN_PASSANT_SQUARE3 = D2;
const int EN_PASSANT_CHECK_POS3 = E3;
const std::array<PieceType, 120> EN_PASSANT_CHECK_BOARD3 = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, W_PAWN, B_PAWN, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::array<PieceType, 120> EN_PASSANT_CHECK_MOVED_BOARD3 = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, B_PAWN, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};

// This tests for disambiguating moves with algebraic notation

const int DISAMB_BISHOP1_POS = D6;
const int DISAMB_BISHOP2_POS = A7;
const int DISAMB_BROOK1_POS = D8;
const int DISAMB_BROOK2_POS = H8;
const int DISAMB_WROOK1_POS = A5;
const int DISAMB_WROOK2_POS = A1;
const int DISAMB_QUEEN1_POS = E4;
const int DISAMB_QUEEN2_POS = H4;
const int DISAMB_QUEEN3_POS = H1;

const std::array<PieceType, 120> DISAMB_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, B_ROOK, NONE, NONE, NONE, B_ROOK,  INV,	
	INV, B_BISHOP, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, B_BISHOP, NONE, NONE, NONE, NONE,  INV,	
	INV, W_ROOK, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, W_QUEEN, NONE, NONE, W_QUEEN,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, W_ROOK, NONE, NONE, NONE, NONE, NONE, NONE, W_QUEEN, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};

const std::vector<std::string> DISAMB_BROOK1_NOTATION = {"Rc8", "Rb8", "Ra8", "Rde8", "Rdf8", "Rdg8", "Rd7"};
const std::vector<std::string> DISAMB_BROOK2_NOTATION = {"Rhg8", "Rhf8", "Rhe8", "Rh7", "Rh6", "Rh5", "Rxh4"};
const std::vector<std::string> DISAMB_WROOK1_NOTATION = {"Ra6", "Rxa7", "Rb5", "Rc5", "Rd5", "Re5", "Rf5", "Rg5", "Rh5", "R5a4", "R5a3", "R5a2"};
const std::vector<std::string> DISAMB_WROOK2_NOTATION = {"R1a2", "R1a3", "R1a4", "Rb1", "Rc1", "Rd1", "Re1", "Rf1", "Rg1"};
const std::vector<std::string> DISAMB_BISHOP1_NOTATION = {"Bc7", "Bdb8", "Be7", "Bf8", "Bdc5", "Bb4", "Ba3", "Be5", "Bf4", "Bg3", "Bh2"};
const std::vector<std::string> DISAMB_BISHOP2_NOTATION = {"Bab8", "Bb6", "Bac5", "Bd4", "Be3", "Bf2", "Bg1"};
const std::vector<std::string> DISAMB_QUEEN1_NOTATION = {"Qd4", "Qc4", "Qb4", "Qa4", "Qe5", "Qe6", "Qee7", "Qe8", "Qef4", "Qeg4", "Qe3", "Qe2", "Qe4e1", "Qd5", "Qc6", "Qb7", "Qa8", "Qf5", "Qg6", "Qeh7", "Qd3", "Qc2", "Qeb1", "Qef3", "Qeg2"};
const std::vector<std::string> DISAMB_QUEEN2_NOTATION = {"Qhg4", "Qhf4", "Qh5", "Qh6", "Qhh7", "Qxh8", "Q4h3", "Q4h2", "Qg5", "Qf6", "Qhe7", "Qxd8", "Qg3", "Qf2", "Qh4e1"};
const std::vector<std::string> DISAMB_QUEEN3_NOTATION = {"Qg1", "Qf1", "Qh1e1", "Qd1", "Qc1", "Qhb1", "Q1h2", "Q1h3", "Qhg2", "Qhf3"};


// CHeck that converting moves to algebraic notation have checkmate marks (#)
const int CHECKMATE_ROOK_POS = D8;
const std::array<PieceType, 120> CHECKMATE_ROOK_BOARD = {
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, NONE, NONE, NONE, B_ROOK, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, B_ROOK, NONE, NONE, NONE, NONE, NONE, NONE,  INV,	
	INV, NONE, NONE, NONE, NONE, NONE, NONE, W_KING, NONE, INV,
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV, 	
	INV, INV, INV, INV, INV, INV, INV, INV, INV, INV	
};
const std::vector<std::string> CHECKMATE_ROOK_NOTATION = {
	"Rc8", "Rdb8", "Ra8",
	"Re8", "Rf8", "Rg8+", "Rh8",
	"Rd7", "Rd6", "Rd5", "Rd4", "Rd3", "Rdd2", "Rd1#"
};

