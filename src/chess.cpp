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
			string color = is_white(piece)?"White":"Black";
			cout << color::rize(piece_string, color, "Default");
			cout << " ";
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
	cout << "   A B C D E F G H" << endl;
}


// TODO: allow algebraic notation.
int main(){
	Color whos_turn = Color::WHITE;
	array<PieceType, 120> my_board;
	copy(DEFAULT_BOARD.begin(), DEFAULT_BOARD.end(),
			my_board.begin());

	vector<int> all_moves = {};
	vector<string> all_moves_notation = {};

	while (true){
		all_moves = {};
		all_moves_notation = {};
		
		// Gets all moves for color who's turn it is.
		if (whos_turn == Color::WHITE){
			get_all_white_moves(&my_board, &all_moves);
		} else {
			get_all_black_moves(&my_board, &all_moves);
		}

		print_board(my_board);
		// Gets a string from cin called input
		string input;
		getline(cin, input);
		// Quits
		if (input == "q"){
			break;
		}
		
		// Gets all moves and stores them in a notation list
		// TODO make into own function
		bool move_exec = false;
		int move_to_exec = 0;
		for (int move : all_moves){
			string move_notation = to_notation(move, &my_board);
			all_moves_notation.push_back(move_notation);
			if (move_notation == input){
				move_exec = true;
				move_to_exec = move;
				break;
			}
		}
		// If the input did not match any legal move.
		if (!move_exec){
			cout << "These are the only valid moves: ";
			for (string notation : all_moves_notation){
				cout << notation << " ";
			}
			cout << endl;
		// If the input did match a legal move.
		} else {
			my_board = dumb_move(move_to_exec, my_board);
			whos_turn = rev_color(whos_turn);
		}
	}
	return 0;
}
