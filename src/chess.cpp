#include <iostream>
#include <stdio.h>
#include <string>
#include "constants.h"
#include "functions.h"

// See constants.h for CHESS_CHARS, and DEFAULT_BOARD

using namespace std;

int main(){
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			int ix = (i*8) + j;
			cout << CHESS_CHARS[DEFAULT_BOARD[ix]];
		}
		cout << endl;
	}

	cout << "poly test" << endl;
	cout << "(1," << poly_knight_offset_x(1) << ")" << endl;
}
