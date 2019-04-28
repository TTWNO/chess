#include <iostream>
#include <stdio.h>
#include <string>
#include "bitwise.h"
#include "constants.h"
#include "functions.h"
#include "color.hpp"

// See constants.h for CHESS_CHARS, and DEFAULT_BOARD

using namespace std;

void print_board(array<PieceType, 120> *board, vector<int> &highlighted_moves){
	for (int i = 2; i < 10; ++i){
		cout << 10-i << " |";
		for (int j = 1; j < 9; ++j){
			int ix = (i*10) + j;
			int piece = (*board)[ix];
			string piece_string = FANCY_CHESS_CHARS[piece];
			string foreground_color = is_white(piece)?"White":"Black";
			string background_color = "";
			string modifier = "";

			for (int move : highlighted_moves){
				if (get_to_sq(move) == ix){
					if (get_check_flag(move) == 1){
						background_color = "Light Red";
					} else if (get_captured_pc(move) != 0){
						background_color = "Green";
					// If a checkmate occors on this move
					// Doesn't appear to work in practoce.
					} else if (to_notation(move, board).find("#") != string::npos){
						background_color = "White";
						modifier = "Blink";
					} else {
						background_color = "Yellow";
					}
				}
			}

			cout << color::rize(" ", foreground_color, background_color, modifier);
			cout << color::rize(piece_string, foreground_color, background_color, modifier);
			cout << color::rize(" ", foreground_color, background_color, modifier);
		}
		cout << endl;
	}
	cout << "--------------------------" << endl;
	cout << "    A  B  C  D  E  F  G  H" << endl;
}


// TODO: allow algebraic notation.
int main(){

	cout << "Hit h for help!" << endl;

	Color whos_turn = Color::WHITE;
	array<PieceType, 120> my_board;
	copy(DEFAULT_BOARD.begin(), DEFAULT_BOARD.end(),
			my_board.begin());

	vector<int> all_moves = {};
	vector<string> all_moves_notation = {};

	int en_passant_square = 0;
	int castle_perms = 0xF;
	bool reset_en_passant = false;

	vector<int> highlighted_moves = {};

	while (true){

		all_moves = {};
		all_moves_notation = {};
		array<PieceType, 6> my_pieces = whos_turn==Color::WHITE?Pieces::WHITE:Pieces::BLACK;
		// Gets all moves for color who's turn it is.
		get_all_moves_for_pieces(my_pieces, &my_board, &all_moves, en_passant_square, castle_perms);

		print_board(&my_board, highlighted_moves);
		
		// If there are no moves. The game is over.
		// If the king is ALSO in check, then the other team won!
		if (all_moves.empty()){
			if (king_checked(&my_board, whos_turn)){
				string winning_team = rev_color(whos_turn)==Color::WHITE?"White":"Black";
				cout << "GG! " << winning_team << " won!" << endl;
				break;
			} else {
				cout << "Stalemate, too bad!" << endl;
				break;
			}
		}

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
			for (string notation : all_moves_notation){
				cout << notation << " ";
			}
			cout << endl;
			continue;
		} else if (input == "c"){
			highlighted_moves = {};
		} else if (input == "h"){
			cout << "Commands:" <<endl;
			cout << "    h for this help menu" << endl;
			cout << "    l to list all your moves" << endl;
			cout << "    l <position> to list all moves for a specific position." << endl;
			cout << "                 these will be highlighted on the board with various colors" << endl;
			cout << "                 Red: Checking move"<< endl;
			cout << "                 Blue: capturing move" << endl;
			cout << "                 Yellow: all other moves" << endl;
			cout << "    c to clear the highlights" << endl;
		}	
		// If the input did not match any legal move.
		if (!move_exec){
			int l_pos = input.find("l");
			// If input starts with "l".
			// It cannot equal only l because that case is taken care of above.
			// And it continues to the next loop.
			if (l_pos == 0){
				string possible_position = input.substr(2, 2);
				bool asking_for_specific_moves = false;
				for (string pos : POSITION_STRING){
					if(pos == possible_position){
						asking_for_specific_moves = true;
					}
				}
				// If input matches a position.
				if (asking_for_specific_moves){
					highlighted_moves = {};
					for (int move : all_moves){
						if (POSITION_STRING[get_from_sq(move)] == possible_position){
							highlighted_moves.push_back(move);
							cout << to_notation(move, &my_board) << " ";
						}
					}
					cout << endl;
				} else {
					cout << "Invalid move!" << std::endl;
					cout << "These are the only valid moves: ";
					for (string notation : all_moves_notation){
						cout << notation << " ";
					}
					cout << endl;
					continue;
				}
			}
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
					castle_perms -= CastlePerms::WQS;
				} else if (moving_from_pos == Position::H1 &&
						(castle_perms & CastlePerms::WKS == 1)){
					castle_perms -= CastlePerms::WKS;
				}
			} else if (moving_piece == B_ROOK){
				if (moving_from_pos == Position::H8 &&
						(castle_perms & CastlePerms::BKS == 1)){
					castle_perms -= CastlePerms::BKS;
				} else if (moving_from_pos == Position::A8 &&
						(castle_perms & CastlePerms::BQS == 1)){
					castle_perms -= CastlePerms::BQS;
				}	
			}
			// Removes castle perms after castling
			if (is_white(moving_piece) &&
					get_castle_flag(move_to_exec)){
				castle_perms -= CastlePerms::WQS;
				castle_perms -= CastlePerms::WKS;
			} else if (is_black(moving_piece) &&
					get_castle_flag(move_to_exec)) {
				castle_perms -= CastlePerms::BQS;
				castle_perms -= CastlePerms::BKS;
			}
			// This will keep the en passant sqaure for one whole turn.
			if (reset_en_passant){
				en_passant_square = 0;
				reset_en_passant = false;
			}
			if (en_passant_square != 0){
				reset_en_passant = true;
			}
			// This reverses the whos_turn variable.
			// and runs the move on the my_board variable.
			my_board = dumb_move(move_to_exec, my_board);
			whos_turn = rev_color(whos_turn);
			highlighted_moves = {};
		}
	}
	return 0;
}
