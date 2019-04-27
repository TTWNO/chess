#include "bitwise.h"
#include "functions.h"
#include "all_moves_functions.cpp"
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

// TODO implement functions.h functions.
// NOTE tests will NOT run unless you implement these functions.

Rank get_rank(int pos){
	int rank = 0;
	while (pos >= 0){
		pos -= 10;
		rank++;
	}
	return static_cast<Rank>(rank - 3);
}

bool is_white(int pt){
	for (auto pn : Pieces::WHITE){
		if (pn == pt) return true;
	}
	return false;
}
bool is_black(int pt){
	for (auto pn : Pieces::BLACK){
		if (pn == pt) return true;
	}
	return false;	
}

Color get_color(PieceType pt){
	if (is_white(pt)) return Color::WHITE;
	if (is_black(pt)) return Color::BLACK;
	return Color::NO_COLOR;
}

Color get_color(int pn, std::array<PieceType, 120> const *board){
	return get_color((*board)[pn]);
}

Color rev_color(Color c){
	if (c==Color::NO_COLOR) return Color::NO_COLOR;
	return c==Color::WHITE?Color::BLACK:Color::WHITE;
}
PieceType rev_color(PieceType pt){
	for (int i=0; i!=Pieces::WHITE.size(); i++){
		if (pt == Pieces::WHITE[i]){
			return Pieces::BLACK[i];
		}
	}
	for (int i=0; i!=Pieces::BLACK.size(); i++){
		if (pt == Pieces::BLACK[i]){
			return Pieces::WHITE[i];
		}
	}
	return PieceType::NONE;
}

std::vector<int> get_possible_movers(Position pn, std::array<PieceType, 120> board){
	std::vector<int> pns = {Position::A1};
	return pns;
}

int get_pos_of(PieceType pt, std::array<PieceType, 120> const *board){
	for (int pn = Position::A8; pn!=Position::H1; pn++){
		if ((*board)[pn] == pt){
			return pn;
		}
	}
	return Position::NA;
}

std::vector<int> get_poss_of(PieceType pt, std::array<PieceType, 120> const *board){
	std::vector<int> results;
	for (int pn = Position::A8; pn!=Position::H1; pn++){
		if ((*board)[pn] == pt){
			results.push_back(pn);
		}
	}
	return results;
}

void get_poss_of(PieceType pt, std::array<PieceType, 120>* board, std::vector<int>* pns){
	for (int pn = Position::A8; pn!=Position::H1; pn++){
		if ((*board)[pn] == pt){
			pns->push_back(pn);
		}
	}
}

bool is_checked(int pos, std::array<PieceType, 120> board){
	PieceType ptt = board[pos];
	Color pc = get_color(ptt);
	auto other_pieces = pc==Color::WHITE?Pieces::BLACK:Pieces::WHITE;
	for (PieceType pt : other_pieces){
		for (int pos_of_other : get_poss_of(pt, &board)) {
			for (int possible_takes : get_all_moves(pos_of_other, board, false)){
				if (get_to_sq(possible_takes) == pos) {
					return true;
				}
			}
		}
	}
	return false;
}

void add_checked_flags(PieceType pt, std::array<PieceType, 120> *board, std::vector<int> *pns){
	PieceType other_king = is_white(pt)?PieceType::B_KING:PieceType::W_KING;
	int other_king_pos = get_pos_of(other_king, board);
	for (auto move_pn=pns->begin(); move_pn!=pns->end();){
		auto moved_board = dumb_move(*move_pn, *board);
		if (is_checked(other_king_pos, moved_board)){
			*move_pn |= (1 << 25);
		}
		++move_pn;
	}
}

//TODO: Make faster by running from king squar eonly, instead of running on every piece of opposite team.
void filter_checked_moves(PieceType pt, std::array<PieceType, 120> *board, std::vector<int> *pns){
	PieceType my_king = is_white(pt)?PieceType::W_KING:PieceType::B_KING;
	int my_king_pos = get_pos_of(my_king, board);
	int attackers = 0;
	for (auto p_pn= pns->begin(); p_pn!=pns->end();){
		if (get_castle_flag(*p_pn) == 1){
			// If moved left
			// B1 - A1 = -1
			// A1 - B1 = +1
			if ((get_from_sq(*p_pn) - get_to_sq(*p_pn)) > 0){
				int right_move = make_move(get_from_sq(*p_pn), get_to_sq(*p_pn)+1);
				auto right_board = dumb_move(right_move, *board);
				if (is_checked(get_to_sq(*p_pn)+1, right_board)){
					p_pn = pns->erase(p_pn);	
				} else {
					++p_pn;
					break;
				}
			} else {
				int left_move = make_move(get_from_sq(*p_pn), get_to_sq(*p_pn)-1);
				auto left_board = dumb_move(left_move, *board);
				if (is_checked(get_to_sq(*p_pn)-1, left_board)){
					p_pn = pns->erase(p_pn);
				} else {
					++p_pn;
					continue;
				}
			}
		} else {
			// Make move
			std::array<PieceType, 120> moved_board = dumb_move(*p_pn, *board);
			// This is for when the king is the same piece that is moving.
			// If this is the case, reset to king position to the new position given by the get_to_sq() of the move.
			if (pt == my_king){
				my_king_pos = get_to_sq(*p_pn);
			}

			if (is_checked(my_king_pos, moved_board)){
				p_pn = pns->erase(p_pn);
			} else {
				++p_pn;
			}
		}
	}
}

void get_all_moves_as_if(int pos, PieceType pt, std::array<PieceType, 120>* board, std::vector<int>* moves, bool recursive, int en_passant, int castle_perms){
	Color color_of_piece = get_color(pt);
	Color color_of_opponent = rev_color(color_of_piece);
	switch(pt){
		case PieceType::B_QUEEN:
		case PieceType::W_QUEEN:
			_get_all_moves_rook(pos, moves, board, color_of_piece, color_of_opponent);
			_get_all_moves_bishop(pos, moves, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_ROOK:
		case PieceType::W_ROOK:
			_get_all_moves_rook(pos, moves, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_BISHOP:
		case PieceType::W_BISHOP:
			_get_all_moves_bishop(pos, moves, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_KNIGHT:
		case PieceType::W_KNIGHT:
			_get_all_moves_knight(pos, moves, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_KING:
		case PieceType::W_KING:
			_get_all_moves_king(pos, moves, board, color_of_piece, color_of_opponent, castle_perms);
			break;
		case PieceType::B_PAWN:
		case PieceType::W_PAWN:
			_get_all_moves_pawn(pos, moves, board, color_of_piece, color_of_opponent, en_passant);
			break;
		default:
			break;
	}
	if (recursive){
		filter_checked_moves(pt, board, moves);
		add_checked_flags(pt, board, moves);
	}
}

void get_all_moves(int pos, std::array<PieceType, 120> *board, std::vector<int> *moves, bool recursive, int en_passant, int castle_perms){
	get_all_moves_as_if(pos, (*board)[pos], board, moves, recursive, en_passant, castle_perms);
}

std::vector<int> get_all_moves(int pos, std::array<PieceType, 120> board, bool recursive, int en_passant, int castle_perms){
	std::vector<int> moves;
	get_all_moves(pos, &board, &moves, recursive, en_passant, castle_perms);
	return moves;
}

std::array<PieceType, 120> dumb_move(int move, std::array<PieceType, 120> board){
	std::array<PieceType, 120> new_board;
	std::copy(std::begin(board), std::end(board), std::begin(new_board));
	int en_passant_flag = get_en_pass_flag(move);
	int castle_flag = get_castle_flag(move);
	int from = get_from_sq(move);
	int to = get_to_sq(move);
	PieceType piece = new_board[from];
	if (en_passant_flag == 1) {
		int diff = to-from;
		int other_pawn_pos = 0;
		if (diff == -11){
			other_pawn_pos = from-1;
		} else if (diff == -9){
			other_pawn_pos = from+1;
		} else if (diff == 11){
			other_pawn_pos = from+1;
		} else if (diff == 9){
			other_pawn_pos = from-1;
		}
		new_board[other_pawn_pos] = PieceType::NONE;
		new_board[to] = piece;
		new_board[from] = PieceType::NONE;
	} else if(castle_flag == 1){
		int diff = to-from;
		int rook_from_pos = 0;
		int rook_to_pos = 0;
		// If castling queenside
		if (diff == -2){
			rook_from_pos = to-2;
			rook_to_pos = from-1;
		// If caslting kingside
		} else if (diff == 2){
			rook_from_pos = to+1;
			rook_to_pos = from+1;
		}
		PieceType rook_pt = new_board[rook_from_pos];
		new_board[rook_from_pos] = PieceType::NONE;
		new_board[rook_to_pos] = rook_pt;
		new_board[from] = PieceType::NONE;
		new_board[to] = piece;
       	} else {
		new_board[to] = piece;
		new_board[from] = PieceType::NONE;
	}
	return new_board;
}

std::string to_notation(int move, std::array<PieceType, 120> *board){
	std::stringstream ss;
	
	auto moved_board = dumb_move(move, *board);
	int from = get_from_sq(move);
	PieceType piecetype = (*board)[from];	
	std::string from_string = POSITION_STRING[from];
	int to = get_to_sq(move);
	int captured_piece = get_captured_pc(move);
	int promoting_to = get_promoted_to_pc(move);
	// Blank if not pawn
	// file if pawn and capture move
	std::string pawn_file = "";
	// Blank if pawn
	// otherwise N/B/R/Q/K corresponding to each piece
	// same for black and white
	std::string piece_character = "";
	// Blank if not a capture
	// x if a capture move
	std::string capture_character = "";
	// Blank if not en passant move
	// otherwise e.p.
	std::string en_passant = "";
	// Black if no check,
	// + if check
	// # if checkmate
	std::string check = "";
	// Blank if only this piece can move to the to square
	// include file (a-h) if another piece can move to the to square
	// includes rank (1-8) if pieces have same file
	// includes both (f)(r) if 2+ identical piece can move to the to square
	std::string disambig = "";
	// Blank if not a pawn promotion move.
	// Otherwise is equal to "=P/N/B/R/Q".
	std::stringstream promotion;
	auto other_pieces = is_white(piecetype)?Pieces::BLACK:Pieces::WHITE;

	if (captured_piece != 0){
		capture_character = "x";
		if (piecetype == PieceType::W_PAWN ||
			piecetype == PieceType::B_PAWN){
			pawn_file = POSITION_STRING[from][0];
		}
	}
	if (piecetype != PieceType::W_PAWN &&
		piecetype != PieceType::B_PAWN){
			piece_character = CHESS_CHARS_INSENSITIVE[piecetype];
	}
	if (get_en_pass_flag(move) == 1){
		en_passant = "e.p.";
	}
	if (get_check_flag(move) == 1){
		check = "+";
		// This checks if the other team has any valid moves.
		// If not, the check sign changes to a hashtag (#).
		std::vector<int> other_moves = {};
		for (PieceType opt : other_pieces){
			for (int pos_of_opt : get_poss_of(opt, board)){
				get_all_moves(pos_of_opt, &moved_board, &other_moves);
			}
		}
		if (other_moves.empty()){
			check = "#";
		}
	}
	// Simulated a piece of the same type, and opposite coor moving from the to square
	// to check if any other pieces can also move here.
	PieceType opposite_piece = rev_color(piecetype);
	std::vector<int> moves = {};
	get_all_moves_as_if(to, opposite_piece, board, &moves, false);
	// Pawns do not require this, as their file is ALWAYS enough to identify them,
	// and the file is always speicified on a pawn capture.
	if (piecetype != PieceType::W_PAWN &&
		piecetype != PieceType::B_PAWN){
		for (auto move_pn=moves.begin(); move_pn!=moves.end();){
			if (get_captured_pc(*move_pn) == piecetype &&
				get_to_sq(*move_pn) != from){
				++move_pn;
			} else {
				move_pn = moves.erase(move_pn);
			}
		}
		if (moves.size() == 1){
			disambig = POSITION_STRING[from][0];
			int other_from = get_to_sq(moves.at(0));
			int min_from = other_from<from?other_from:from;
			int max_from = other_from>from?other_from:from;
			// If the remainder of the difference divided by 10 is 0
			// they are on the same file.
			// Use rank to disambiguate
			if ((max_from-min_from) % 10 == 0){
				disambig = POSITION_STRING[from][1];
			}
		} else if (moves.size() > 1){
			disambig = POSITION_STRING[from];
		}
	}

	if (promoting_to != PieceType::NONE){
		promotion << "=" << CHESS_CHARS_INSENSITIVE[promoting_to];
	}
	// end of checking for multiple pieces
	if (get_castle_flag(move) == 1){
		return to-from<0 ? "O-O-O" : "O-O";
	} else {
		ss << pawn_file << piece_character << disambig << capture_character << POSITION_STRING[to] << en_passant << promotion.str() << check;
	}
	return ss.str();
}

void get_all_white_moves(std::array<PieceType, 120> *board, std::vector<int> *moves){
	for (PieceType pt : Pieces::WHITE){
		for (int pos_of : get_poss_of(pt, board)){
			std::vector<int> local_moves = {};
			get_all_moves_as_if(pos_of, pt, board, &local_moves);
			moves->insert(moves->end(), local_moves.begin(), local_moves.end());
		}
	}
}
void get_all_black_moves(std::array<PieceType, 120> *board, std::vector<int> *moves){
	for (PieceType pt : Pieces::BLACK){
		for (int pos_of : get_poss_of(pt, board)){
			std::vector<int> local_moves = {};
			get_all_moves_as_if(pos_of, pt, board, &local_moves);
			moves->insert(moves->end(), local_moves.begin(), local_moves.end());
		}
	}
}
