#ifndef BT_CONST_H
#define BT_CONST_H

#include <array>
#include <iostream>
#include <vector>

enum Color {
	NO_COLOR,
	WHITE,
	BLACK
};

enum PieceType {
	INV=-1,
	NONE,
	B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING,
	W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING
};

namespace Pieces{
	const std::array<PieceType, 6> WHITE = {W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING};
	const std::array<PieceType, 6> BLACK = {B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING};
}

enum Position {
	NA=-1,
	A8=21, B8, C8, D8, E8, F8, G8, H8,
	A7=31, B7, C7, D7, E7, F7, G7, H7,
	A6=41, B6, C6, D6, E6, F6, G6, H6,
	A5=51, B5, C5, D5, E5, F5, G5, H5,
	A4=61, B4, C4, D4, E4, F4, G4, H4,
	A3=71, B3, C3, D3, E3, F3, G3, H3,
	A2=81, B2, C2, D2, E2, F2, G2, H2,
	A1=91, B1, C1, D1, E1, F1, G1, H1
};

// Access with POSITION_STRING[Position]
const std::array<std::string, 120> POSITION_STRING = {
	"INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", 	
	"INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", 	
	"INV", "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "INV",
	"INV", "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "INV",
	"INV", "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "INV",
	"INV", "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "INV",
	"INV", "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "INV",
	"INV", "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "INV",
	"INV", "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "INV",
	"INV", "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "INV",
	"INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", 	
	"INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV", "INV"	
};

enum Rank{
	RANK1,
	RANK2,
	RANK3,
	RANK4,
	RANK5,
	RANK6,
	RANK7,
	RANK8
};

enum File {
	FILE1,
	FILE2,
	FILE3,
	FILE4,
	FILE5,
	FILE6,
	FILE7,
	FILE8
};

const std::array<PieceType, 120> DEFAULT_BOARD = {
	INV,INV,INV,INV,INV,INV,INV,INV,INV,INV,	
	INV,INV,INV,INV,INV,INV,INV,INV,INV,INV,	
	INV, B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK, INV,
	INV, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV, 
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, INV,
	INV, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, INV,
	INV, W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK, INV,
	INV,INV,INV,INV,INV,INV,INV,INV,INV,INV,
	INV,INV,INV,INV,INV,INV,INV,INV,INV,INV
};

const std::array<char, 13> CHESS_CHARS = {
	' ',
	'P', 'N', 'B', 'R', 'Q', 'K',
	'p', 'n', 'b', 'r', 'q', 'k'
};
#endif

