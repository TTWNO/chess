#include <iostream>
#include <stdio.h>

using namespace std;

enum Spaces {
	A8, B8, C8, D8, E8, F8, G8, H8, A7, B7, C7, D7, E7, F7, G7, H7, A6, B6, C6, D6, E6, F6, G6, H6, A5, B5, C5, D5, E5, F5, G5, H5, A4, B4, C4, D4, E4, F4, G4, H4, A3, B3, C3, D3, E3, F3, G3, H3, A2, B2, C2, D2, E2, F2, G2, H2, A1, B1, C1, D1, E1, F1, G1, H1
};

enum Piece {
	NONE,
	W_KING, W_QUEEN, W_ROOK, W_BISHOP, W_KNIGHT, W_PAWN,
	B_KING, B_QUEEN, B_ROOK, B_BISHOP, B_KNIGHT, B_PAWN
};

int main(){

	int board[64] = {
		Piece::W_ROOK, Piece::W_KNIGHT, Piece::W_BISHOP, Piece::W_QUEEN, Piece::W_KING, Piece::W_BISHOP, Piece::W_KNIGHT, B_ROOK,
		Piece::W_PAWN, Piece::W_PAWN, Piece::W_PAWN, Piece::W_PAWN, Piece::W_PAWN, Piece::W_PAWN, Piece::W_PAWN, Piece::W_PAWN, 	
		Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, 	
		Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, 	
		Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, 	
		Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, Piece::NONE, 	
	Piece::B_PAWN, Piece::B_PAWN, Piece::B_PAWN, Piece::B_PAWN, Piece::B_PAWN, Piece::B_PAWN, Piece::B_PAWN, Piece::B_PAWN, 	
		Piece::B_ROOK, Piece::B_KNIGHT, Piece::B_BISHOP, Piece::B_QUEEN, Piece::B_KING, Piece::B_BISHOP, Piece::B_KNIGHT, Piece::B_ROOK,
	};

	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			int bx = (i * 8) +j;
			cout << hex <<  board[bx];
		}
		cout << endl;
	}

	return 0;
}
