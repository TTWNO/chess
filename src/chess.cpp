#include <iostream>
#include <stdio.h>
#include <string>
#include "bitwise.h"
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

	int en_passant_square = 0;
	int castle_perms = 0xF;
	bool reset_en_passant = false;
	while (true){

		all_moves = {};
		all_moves_notation = {};
		array<PieceType, 6> my_pieces = whos_turn==Color::WHITE?Pieces::WHITE:Pieces::BLACK;
		// Gets all moves for color who's turn it is.
		get_all_moves_for_pieces(my_pieces, &my_board, &all_moves, en_passant_square, castle_perms);

		print_board(my_board);
		// Gets a string from cin called input
		string input;
		getline(cin, input);
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
		// Quits
		if (input == "q"){
			break;
		} else if (input == "l"){
			cout << "Listing moves: \n";
			for (string notation : all_moves_notation){
				cout << notation << " ";
			}
			cout << endl;
			continue;
		}	
		// If the input did not match any legal move.
		if (!move_exec){
			cout << "Invalid move!" << std::endl;
			cout << "These are the only valid moves: ";
			for (string notation : all_moves_notation){
				cout << notation << " ";
			}
			cout << endl;
			continue;
		// If the input did match a legal move.
		} else {
			int moving_from_pos = get_from_sq(move_to_exec);
			int moving_piece = my_board[moving_from_pos];
			// Depending on move, change castle perms, or en_passant square
			if (get_pawn_st_flag(move_to_exec) == 1){
				int en_pass_offset = whos_turn==Color::WHITE?10:-10;
				en_passant_square = get_to_sq(move_to_exec)+en_pass_offset;
				reset_en_passant = false;
			}
			if (moving_piece == W_ROOK){
				if (moving_from_pos == Position::A1 &&
						(castle_perms & CastlePerms::WQS == 1)){
					castle_perms - CastlePerms::WQS;
				} else if (moving_from_pos == Position::H1 &&
						(castle_perms & CastlePerms::WKS == 1)){
					castle_perms - CastlePerms::WKS;
				}
			} else if (moving_piece == B_ROOK){
				if (moving_from_pos == Position::H8 &&
						(castle_perms & CastlePerms::BKS == 1)){
					castle_perms - CastlePerms::BKS;
				} else if (moving_from_pos == Position::A8 &&
						(castle_perms & CastlePerms::BQS == 1)){
					castle_perms - CastlePerms::BQS;
				}
			
			}
			// This will keep the en passant sqaure for one whole turn.
			if (reset_en_passant){
				en_passant_square = 0;
				reset_en_passant = false;
			}
			if (en_passant_square != 0){
				cout << "En passant move at: " << POSITION_STRING[en_passant_square] << endl;
				reset_en_passant = true;
			}
			// This reverses the whos_turn variable.
			// and runs the move on the my_board variable.
			my_board = dumb_move(move_to_exec, my_board);
			whos_turn = rev_color(whos_turn);
		}
	}
	return 0;
}
