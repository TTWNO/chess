
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
	A1, B1, C1, D1, E1, F1, G1, H1, A2, B2, C2, D2, E2, F2, G2, H2, A3, B3, C3, D3, E3, F3, G3, H3, A4, B4, C4, D4, E4, F4, G4, H4, A5, B5, C5, D5, E5, F5, G5, H5, A6, B6, C6, D6, E6, F6, G6, H6, A7, B7, C7, D7, E7, F7, G7, H7, A8, B8, C8, D8, E8, F8, G8, H8
};

// Access with normal ways of accessing an array.
// OR lie so DEFAULT_BOARD[Position::G1] would equal PieceType::W_KNIGHT
// TODO make function to convert x and y to board num, and vis versa.
const int DEFAULT_BOARD[64] = {
	W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK, 
	W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
	B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, 
	B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK	
};

