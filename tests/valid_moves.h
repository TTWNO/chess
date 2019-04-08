#include <unordered_set>
#include <constants.h>

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
