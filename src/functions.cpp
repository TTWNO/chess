#include "bitwise.h"
#include "functions.h"
#include "all_moves_functions.cpp"
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

bool is_white(PieceType pt){
	for (auto pn : Pieces::WHITE){
		if (pn == pt) return true;
	}
	return false;
}
bool is_black(PieceType pt){
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

Color get_color(Position pn, std::array<PieceType, 120> const *board){
	return get_color((*board)[pn]);
}

Color rev_color(Color c){
	if (c==Color::NO_COLOR) return Color::NO_COLOR;
	return c==Color::WHITE?Color::BLACK:Color::WHITE;
}

std::unordered_set<int> get_possible_movers(Position pn, std::array<PieceType, 120> board){
	std::unordered_set<int> pns = {Position::A1};
	return pns;
}

std::unordered_set<int> get_possible_moves(Position pn, std::array<PieceType, 120> board){
	std::unordered_set<int> pns = {Position::A1};
	get_all_moves(pn, &board, &pns);
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

std::unordered_set<int> get_poss_of(PieceType pt, std::array<PieceType, 120> const *board){
	std::unordered_set<int> results;
	for (int pn = Position::A8; pn!=Position::H1; pn++){
		if ((*board)[pn] == pt){
			results.insert(pn);
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

//TODO: Make faster by running from king squar eonly, instead of running on every piece of opposite team.
void filter_checked_moves(PieceType pt, std::array<PieceType, 120> *board, std::unordered_set<int> *pns){
	PieceType my_king = is_white(pt)?PieceType::W_KING:PieceType::B_KING;
	int my_king_pos = get_pos_of(my_king, board);
	int attackers = 0;
	for (auto p_pn= pns->begin(); p_pn!=pns->end();){
		// Make move
		std::array<PieceType, 120> moved_board = dumb_move(*p_pn, *board);
		// Get all piecetypes of other team
		std::array<PieceType, 6> other_team = is_white(pt)?Pieces::BLACK:Pieces::WHITE;
		bool checks_king = false;
		// go through each piece of other team
		for (PieceType other_p : other_team) {
			checks_king = false;
			// For every place the piecetype is
			// NEW CODE
//			for (Position psn : get_all_moves(my_king_pos, moved_board, false)){
//					
//					}
			// \NEW CODE
			std::vector<int> psns;
			get_poss_of(other_p, &moved_board, &psns);
			for (auto psn : psns){
				std::unordered_set<int> other_moves;
				get_all_moves(psn, &moved_board, &other_moves, false);
				// for every position the piece can mvoe to
				for (int cp : other_moves){
					if (get_to_sq(cp) == my_king_pos){
						checks_king = true;
						attackers++;
						break;
					}
				}
				if (checks_king){
					break;
				}
			}
			if (checks_king){
				break;
			}
		}
		if (checks_king){
			p_pn = pns->erase(p_pn);
		} else {
			++p_pn;
		}
	}
}

void get_all_moves(int pos, std::array<PieceType, 120>* board, std::unordered_set<int>* moves, bool recursive, int en_passant){
	PieceType pt = (*board)[pos];
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
			_get_all_moves_king(pos, moves, board, color_of_piece, color_of_opponent);
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
	}
}

std::unordered_set<int> get_all_moves(int pos, std::array<PieceType, 120> board, bool recursive, int en_passant){
	std::unordered_set<int> moves;
	get_all_moves(pos, &board, &moves, recursive, en_passant);
	return moves;
}

std::array<PieceType, 120> dumb_move(int move, std::array<PieceType, 120> board){
	int from = get_from_sq(move);
	int to = get_to_sq(move);
	PieceType piece = board[from];
	board[to] = piece;
	board[from] = PieceType::NONE;
	return board;
}
