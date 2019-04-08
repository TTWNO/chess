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

	cout << "poly X" << endl;
	cout << "(1," << poly_knight_offset_x(1) << ")" << endl;
	cout << "(2," << poly_knight_offset_x(2) << ")" << endl;
	cout << "(3," << poly_knight_offset_x(3) << ")" << endl;
	cout << "(4," << poly_knight_offset_x(4) << ")" << endl;
	cout << "(5," << poly_knight_offset_x(5) << ")" << endl;
	cout << "(6," << poly_knight_offset_x(6) << ")" << endl;
	cout << "(7," << poly_knight_offset_x(7) << ")" << endl;
	cout << "(8," << poly_knight_offset_x(8) << ")" << endl;
	cout << "(9," << poly_knight_offset_x(9) << ")" << endl;
	cout << "poly Y" << endl;
	cout << "(1," << poly_knight_offset_y(1) << ")" << endl;
	cout << "(2," << poly_knight_offset_y(2) << ")" << endl;
	cout << "(3," << poly_knight_offset_y(3) << ")" << endl;
	cout << "(4," << poly_knight_offset_y(4) << ")" << endl;
	cout << "(5," << poly_knight_offset_y(5) << ")" << endl;
	cout << "(6," << poly_knight_offset_y(6) << ")" << endl;
	cout << "(7," << poly_knight_offset_y(7) << ")" << endl;
	cout << "(8," << poly_knight_offset_y(8) << ")" << endl;
	cout << "(9," << poly_knight_offset_y(9) << ")" << endl;
	
}
