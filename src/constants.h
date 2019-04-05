#include <vector>
#include <array>
#include <string>

// Access with PieceType::ANY_FOLLOWING_OPTION
enum PieceType {
	NONE,
	W_PAWN,
	W_KNIGHT,
	W_BISHOP,
	W_ROOK,
	W_QUEEN,
	W_KING,
	B_PAWN,
	B_KNIGHT,
	B_BISHOP,
	B_ROOK,
	B_QUEEN,
	B_KING
};

// Access with CHESS_CHARS[PieceType] to get the character for the piece.
const char CHESS_CHARS[13] = {
	' ',
	'p', 'n', 'b', 'r', 'q', 'k',
	'P', 'N', 'B', 'R', 'Q', 'K'
};

// This allows reference to DEFAULT_BOARD (or more likely, a copy of it.
enum Position{
	A8, B8, C8, D8, E8, F8, G8, H8, A7, B7, C7, D7, E7, F7, G7, H7, A6, B6, C6, D6, E6, F6, G6, H6, A5, B5, C5, D5, E5, F5, G5, H5, A4, B4, C4, D4, E4, F4, G4, H4, A3, B3, C3, D3, E3, F3, G3, H3, A2, B2, C2, D2, E2, F2, G2, H2, A1, B1, C1, D1, E1, F1, G1, H1
};

// This allows the printing of Position enum variables in the tests. It matches the variables to strings.
// Variable names are discarded at compile time to optimize.
// Access with POSITION_STRING[Position]
const std::vector<std::string> POSITION_STRING = {
	"A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1"
};

// Access with normal ways of accessing an array.
// OR lie so DEFAULT_BOARD[Position::G1] would equal PieceType::W_KNIGHT
// TODO make function to convert x and y to board num, and vis versa.
const std::array<PieceType, 64> DEFAULT_BOARD = {
	B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,	
	B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, 
	W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK 
};


namespace Rank{
	const int A[8] = {A1, A2, A3, A4, A5, A6, A7, A8};
        const int B[8] = {B1, B2, B3, B4, B5, B6, B7, B8};
        const int C[8] = {C1, C2, C3, C4, C5, C6, C7, C8};
	const int D[8] = {D1, D2, D3, D4, D5, D6, D7, D8};
	const int E[8] = {E1, E2, E3, E4, E5, E6, E7, E8};
	const int F[8] = {F1, F2, F3, F4, F5, F6, F7, F8};
	const int G[8] = {G1, G2, G3, G4, G5, G6, G7, G8};
	const int H[8] = {H1, H2, H3, H4, H5, H6, H7, H8};
}

namespace File{
	const int ONE[8] = {A1, B1, C1, D1, E1, F1, G1, H1};
	const int TWO[8] = {A2, B2, C2, D2, E2, F2, G2, H2};
	const int THREE[8] = {A3, B3, C3, D3, E3, F3, G3, H3};
	const int FOUR[8] = {A4, B4, C4, D4, E4, F4, G4, H4};
	const int FIVE[8] = {A5, B5, C5, D5, E5, F5, G5, H5};
	const int SIX[8] = {A6, B6, C6, D6, E6, F6, G6, H6};
	const int SEVEN[8] = {A7, B7, C7, D7, E7, F7, G7, H7};
	const int EIGHT[8] = {A8, B8, C8, D8, E8, F8, G8, H8};
}
