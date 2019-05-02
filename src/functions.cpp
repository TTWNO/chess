#include "bitwise.h"
#include "functions.h"
#include "all_moves_functions.cpp"
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

/*
 *
 * 	These functions use an int to pass a lot of information.
 * 	The notation is like this:
 * 	0000 0000 0000 0000 0111 1111 -> position of piece
 * 	0000 0000 0000 0111 1000 0000 -> piece type
 * 	0000 0000 0111 1000 0000 0000 -> piece of opposite type (eg. opposite of W_KING, is B_KING; B_ROOK, W_ROOK etc...)
 * 	0000 0000 1000 0000 0000 0000 -> team of the piece (1=white, 0=black)
 * 	0111 1111 0000 0000 0000 0000 -> new position (if applicable)
 *	
**/

/*
 *	These functions also use an int for king info. This is so:
 *		a) I don't have to recompute the info each time I nedd it in a functoin.
 *		b) So that I don't have the overhead of a struct. (I know, "micro optimizations are the root of all evil", I can't help myself)
 *	The notation is as follows:
 * 	0000 0000 0000 0000 0111 1111 -> position of piece
 * 	0000 0000 0000 0111 1000 0000 -> piece type
 * 	0000 0011 1111 1000 0000 0000 -> opposite piece position
 * 	0011 1100 0000 0000 0000 0000 -> piece of opposite type
 * 	0100 0000 0000 0000 0000 0000 -> team of the piece (1=white, 0=black)
 */

inline int get_piece_pos(int pieceinfo){
	return (pieceinfo & 0x7f);
}
inline int get_piece_type(int pieceinfo){
	return ((pieceinfo << 7) & 0xf);
}
inline int get_opposite_piece_type(int pieceinfo){
	return ((pieceinfo << 11) & 0xf);
}
// TO find out if white/black use:
// get_team_of_piece_type == Color::WHITE/BLACK
inline int get_team_of_piece_type(int pieceinfo){
	return ((pieceinfo << 15) & 0x1);
}
inline int get_new_position_of_piece(int pieceinfo){
	return ((pieceinfo << 16) & 0xf); 	
}


/*	Move ints contain a lot of information as well. However, these are DIFFERENt from the other dense ints. Moves are universalyl passed by reference (&) to a vector of ints, whereas the above is passed only is 1 int by itself.
 *	Here is the notation for moves (although it is obscured by the make_move(), get_to/from_sq(), get_captured_pc() etc... functions.
 *
 * From (Position): 7 bits (2^7 == 128) possibilities
 * To (Position): same as above
 * Captured piece, if any: 4 bits (16) possibilities
 * Promoted to, if any: 4 bits (16) possibilities
 * en passant flag: 1 bit
 * pawn starting move flag: 1 bit
 * castle move flag: 1 bit
 *
 *	0000 0000 0000 0000 0000 0111 1111 -> From square position (& 0x7F)
 *	0000 0000 0000 0011 1111 1000 0000 -> To square position (>> 7 & 0x7F)
 *	0000 0000 0011 1100 0000 0000 0000 -> captured piece, if any (>> 14 & 0xF)
 *	0000 0011 1100 0000 0000 0000 0000 -> if prmoted, what to? (>> 18 & 0xF)
 *	0000 0100 0000 0000 0000 0000 0000 -> en passant (>> 22 &0x1)
 *	0000 1000 0000 0000 0000 0000 0000 -> pawn starting move (>> 23 &0x1)
 *	0001 0000 0000 0000 0000 0000 0000 -> castle move (>> 24 0x1)
 * 	0010 0000 0000 0000 0000 0000 0000 -> check flag (>> 25 &0x1) 
 * */

//const std::array<int, 4> ROOK_PIECE_OFFSETS = {-1, -10, 1, 10};
//const std::array<int, 4> BISHOP_PIECE_OFFSETS = {-11, -9, 9, 11};
const std::vector<int> QUEEN_PIECE_OFFSETS = {-1, -10, 1, 10, -11, -9, 9, 11};

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

Color get_color(int pn, const std::array<PieceType, 120>& board){
	return get_color(board[pn]);
}

Color rev_color(Color c){
	if (c==Color::NO_COLOR) return Color::NO_COLOR;
	return c==Color::WHITE?Color::BLACK:Color::WHITE;
}
PieceType rev_color(PieceType pt){
	//return static_cast<PieceType>((~pt) & 0xf);
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

std::vector<int> get_possible_movers(Position pn, const std::array<PieceType, 120>& board){
	std::vector<int> pns = {Position::A1};
	return pns;
}

int get_pos_of(PieceType pt, const std::array<PieceType, 120>& board){
	for (int pn = Position::A8; pn!=Position::H1; pn++){
		if (board[pn] == pt){
			return pn;
		}
	}
	return Position::NA;
}

std::vector<int> get_poss_of(PieceType pt, const std::array<PieceType, 120>& board){
	std::vector<int> results;
	for (int pn = Position::A8; pn!=Position::H1; pn++){
		if (board[pn] == pt){
			results.push_back(pn);
		}
	}
	return results;
}

void get_poss_of(PieceType pt, const std::array<PieceType, 120>& board, std::vector<int>& pns){
	for (int pn = Position::A8; pn!=Position::H1; pn++){
		if (board[pn] == pt){
			pns.push_back(pn);
		}
	}
}

bool would_be_attacked(int pos, PieceType piece, const std::array<PieceType, 120>& board){
	Color pc = get_color(piece);
	auto other_pieces = pc==Color::WHITE?Pieces::BLACK:Pieces::WHITE;
	for (PieceType opposite_color_piece : other_pieces){
		PieceType same_color_piece = rev_color(opposite_color_piece);
		std::vector<int> moves;
		get_all_moves_as_if(pos, same_color_piece, board, moves, false);
		for (int reverse_move : moves){
			if (get_captured_pc(reverse_move) == opposite_color_piece){
				return true;
			}
		}
	}
	return false;
	
}

bool is_attacked(int pos, const std::array<PieceType, 120>& board){
	return would_be_attacked(pos, board[pos], board);
}

bool king_checked(const std::array<PieceType, 120>& board, Color color_of_king){
	PieceType king = color_of_king==WHITE?W_KING:B_KING;
	int king_pos = get_pos_of(king, board);
	return is_attacked(king_pos, board);
}

void add_checked_flags(PieceType pt, const std::array<PieceType, 120>& board, std::vector<int>& pns){
	PieceType other_king = is_white(pt)?PieceType::B_KING:PieceType::W_KING;
	int other_king_pos = get_pos_of(other_king, board);
	// If the other team doesn't have a king, don't add any checked flags
	if (other_king_pos == Position::NA){
		return;
	}
	for (auto move_pn=pns.begin(); move_pn!=pns.end();){
		std::array<PieceType, 120> moved_board;
		dumb_move(*move_pn, board, moved_board);
		if (is_attacked(other_king_pos, moved_board)){
			*move_pn |= (1 << 25);
		}
		++move_pn;
	}
}

//TODO: Make faster by running from king squar eonly, instead of running on every piece of opposite team.
void filter_checked_moves(PieceType pt, const std::array<PieceType, 120>& board, std::vector<int>& pns){
	PieceType my_king = is_white(pt)?PieceType::W_KING:PieceType::B_KING;
	int my_king_pos = get_pos_of(my_king, board);
	bool remove_all_castles = false;
	// If this team doesn't have a king, don't do anything, jsut return.
	if (my_king_pos == Position::NA){
		return;
	}
	for (auto p_pn= pns.begin(); p_pn!=pns.end();){
		if (get_castle_flag(*p_pn) == 1){
			// If removing all castle flags is triggered
			// (by being in check)
			// remove all of them.
			if (remove_all_castles){
				p_pn = pns.erase(p_pn);
				++p_pn;
				break;
			}
			// TODO: Make this more effecient.
			// There is no way in hell, this is as complicated as it seems.
			// If moved left
			// Queenside
			if ((get_from_sq(*p_pn) - get_to_sq(*p_pn)) > 0){
				if(would_be_attacked(get_to_sq(*p_pn), my_king, board) ||
					would_be_attacked(get_to_sq(*p_pn)+1, my_king, board)){
					p_pn = pns.erase(p_pn);
				} else {
					++p_pn;
					break;
				}
			// Kingside
			} else {
				if(would_be_attacked(get_to_sq(*p_pn), my_king, board) ||
					would_be_attacked(get_to_sq(*p_pn)-1, my_king, board)){
					p_pn = pns.erase(p_pn);
				} else {
					++p_pn;
					break;
				}
			}
		} else {
			// if it is a king, that is in check
			// remove all castle moves
			if ((pt == PieceType::W_KING ||
					pt == PieceType::B_KING) &&
				is_attacked(get_from_sq(*p_pn), board)){
				remove_all_castles = true;
			}
			// Make move
			std::array<PieceType, 120> moved_board;
			dumb_move(*p_pn, board, moved_board);	
			// This is for when the king is the same piece that is moving.
			// If this is the case, reset to king position to the new position given by the get_to_sq() of the move.
			if (pt == my_king){
				my_king_pos = get_to_sq(*p_pn);
			}

			if (is_attacked(my_king_pos, moved_board)){
				p_pn = pns.erase(p_pn);
			} else {
				++p_pn;
			}
		}
	}
}

void _get_all_moves_as_if_ray_type(int pos, std::vector<int> offsets, std::vector<int>& moves, const std::array<PieceType, 120>& board, Color color_of_piece, Color color_of_opponent){
	for (int offset : offsets){
		for (int times = 1; times < 8; ++times){
			int true_offset = pos+(offset*times);
			if (get_color(board[true_offset]) == color_of_opponent){
				moves.push_back(make_move(pos, true_offset, board[true_offset]));
				break;
			} else if (get_color(board[true_offset]) == color_of_piece ||
					board[true_offset] == PieceType::INV){
				break;
			} else {
				moves.push_back(make_move(pos, true_offset, board[true_offset]));
			}
		}
	}
}

void _get_all_moves_as_if_not_ray(int pos, std::vector<int> offsets, std::vector<int>& moves, const std::array<PieceType, 120>& board, Color color_of_piece, Color color_of_opponent){
	for (int offset : offsets){
		int true_offset = pos+offset;
		if (board[true_offset] == PieceType::NONE ||
				get_color(board[true_offset]) == color_of_opponent){
			moves.push_back(make_move(pos, true_offset, board[true_offset]));
		}
	}
}

void get_all_moves_as_if(int pos, PieceType pt, const std::array<PieceType, 120>& board, std::vector<int>& moves, bool recursive, int en_passant, int castle_perms){
	int piece_info = 0;
	Color color_of_piece = get_color(pt);
	Color color_of_opponent = rev_color(color_of_piece);
	switch(pt){
		case PieceType::B_QUEEN:
		case PieceType::W_QUEEN:
			_get_all_moves_as_if_ray_type(pos, QUEEN_PIECE_OFFSETS, moves, board, color_of_piece, color_of_opponent);
			//_get_all_moves_rook(pos, moves, board, color_of_piece, color_of_opponent);
			//_get_all_moves_bishop(pos, moves, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_ROOK:
		case PieceType::W_ROOK:
			_get_all_moves_as_if_ray_type(pos, ROOK_PIECE_OFFSETS, moves, board, color_of_piece, color_of_opponent);
			//_get_all_moves_rook(pos, moves, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_BISHOP:
		case PieceType::W_BISHOP:
			_get_all_moves_as_if_ray_type(pos, BISHOP_PIECE_OFFSETS, moves, board, color_of_piece, color_of_opponent);
			//_get_all_moves_bishop(pos, moves, board, color_of_piece, color_of_opponent);
			break;
		case PieceType::B_KNIGHT:
		case PieceType::W_KNIGHT:
			_get_all_moves_as_if_not_ray(pos, KNIGHT_PIECE_OFFSETS, moves, board, color_of_piece, color_of_opponent);
			//_get_all_moves_knight(pos, moves, board, color_of_piece, color_of_opponent);
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

void get_all_moves(int pos, const std::array<PieceType, 120>& board, std::vector<int>& moves, bool recursive, int en_passant, int castle_perms){
	get_all_moves_as_if(pos, board[pos], board, moves, recursive, en_passant, castle_perms);
}
std::vector<int> get_all_moves(int pos, const std::array<PieceType, 120>& board, bool recursive, int en_passant, int castle_perms){
	std::vector<int> moves = {};
	get_all_moves_as_if(pos, board[pos], board, moves, recursive, en_passant, castle_perms);
	return moves;
}

void dumb_move(int move, const std::array<PieceType, 120>& board, std::array<PieceType, 120>& new_board){
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
}
std::array<PieceType, 120> dumb_move(int pos, const std::array<PieceType, 120>& board){
	std::array<PieceType, 120> new_board = {};
	dumb_move(pos, board, new_board);
	return new_board;
}

void _filter_unneeded_squares(std::vector<int>& moves, int piecetype, int origin){
	for (auto move_pn=moves.begin(); move_pn!=moves.end();){
		if (get_captured_pc(*move_pn) == piecetype &&
			get_to_sq(*move_pn) != origin){
			++move_pn;
		} else {
			move_pn = moves.erase(move_pn);
		}
	}

};

void _non_pawn_disambiguate(int from, int to, int piecetype, const std::vector<int>& moves, std::string& disambig){
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

std::string to_notation(int move, const std::array<PieceType, 120>& board){
	std::stringstream ss;
	
	std::array<PieceType, 120> moved_board;
	dumb_move(move, board, moved_board);
	int from = get_from_sq(move);
	PieceType piecetype = board[from];	
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

	if (captured_piece != PieceType::NONE){
		capture_character = "x";
		// Comment #6
		// if a pawn is capturing, have the disambiguation be the pawn's file
		// stored in a seperate variable because pawn disabiguation by file happens at the start of a notation. For example:
		// exf4 as opposed to Qh1xf4
		if (piecetype == PieceType::W_PAWN ||
			piecetype == PieceType::B_PAWN){
			pawn_file = POSITION_STRING[from][0];
		}
	}
	// Pawns do not require this, as their file is ALWAYS enough to identify them,
	// and the file is always speicified on a pawn capture.
	// (See comment #6)
	if (piecetype != PieceType::W_PAWN &&
		piecetype != PieceType::B_PAWN){
			// Simulated a piece of the same type, and opposite color moving from the to square
			// to check if any other pieces can also move here.
			// Basically it searches to see if there are duplicate pieces which can move to the same spot.
			// and stores any duplicates in the other_moves variable.
			PieceType opposite_piece = rev_color(piecetype);
			std::vector<int> other_moves = {};
			get_all_moves_as_if(to, opposite_piece, board, other_moves, false);
			// This takes out any mention of other squares involing blank pieces, or any peices that do not invole the current one.
			_filter_unneeded_squares(other_moves, piecetype, from);
			piece_character = CHESS_CHARS_INSENSITIVE[piecetype];
			_non_pawn_disambiguate(from, to, piecetype, other_moves, disambig);
	}
	if (get_en_pass_flag(move) == 1){
		en_passant = "e.p.";
	}
	if (get_check_flag(move) == 1){
		check = "+";
		// This checks if the other team has any valid moves.
		// If not, the check sign changes to a hashtag (#).
		std::vector<int> other_moves = {};
		get_all_moves_for_pieces(other_pieces, moved_board, other_moves);
		if (other_moves.empty()){
			check = "#";
		}
	}
	// If promoting, add an equals sign and the piece promoting to.
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

void get_all_moves_for_pieces(std::array<PieceType, 6> pieces, const std::array<PieceType, 120>& board, std::vector<int>& moves, int en_passant, int castle_perms){
	for (PieceType pt : pieces){
		for (int pos_of : get_poss_of(pt, board)){
			std::vector<int> local_moves = {};
			get_all_moves_as_if(pos_of, pt, board, local_moves, true, en_passant, castle_perms);
			moves.insert(moves.end(), local_moves.begin(), local_moves.end());
		}
	}
}
// From StackOverflow (https://stackoverflow.com/questions/5891610/how-to-remove-certain-characters-from-a-string-in-c#5891643)
void remove_chars_from_string(std::string &str, std::string charsToRemove ) {
   for ( unsigned int i = 0; i < charsToRemove.length(); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove.at(i)), str.end() );
   }
}

