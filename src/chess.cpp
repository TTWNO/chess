#include <iostream>
#include <stdio.h>
#include <string>
#include "constants.h"
#include "functions.h"
#include "color.hpp"

// See constants.h for CHESS_CHARS, and DEFAULT_BOARD

using namespace std;

void print_board(array<PieceType, 120> const& board){
	for (int i = 2; i < 10; ++i){
		cout << 10-i << " |";
		for (int j = 1; j < 9; ++j){
			int ix = (i*10) + j;
			int piece = board[ix];
			string piece_string = FANCY_CHESS_CHARS[piece];
			if (is_white(piece)){
				cout << color::rize(piece_string, "White", "Default");
			} else {
				cout << color::rize(piece_string, "Black", "Default");
			}
			cout << " ";
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
	cout << "   A B C D E F G H" << endl;
}


int main(){
	print_board(DEFAULT_BOARD);
	return 0;
}
