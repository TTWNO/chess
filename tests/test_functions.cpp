#include "test_functions.h"
#include <bitwise.h>
#include <vector>
#include <algorithm>
#include <array>
#include <constants.h>
#include <functions.h>

std::vector<int> get_to_squares(const std::vector<int>& moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_to_sq(mv));
	}
	return transformed;
}
std::vector<int> get_from_squared(const std::vector<int>& moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_from_sq(mv));
	}
	return transformed;
}
std::vector<int> get_captured_pieces(const std::vector<int>& moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_captured_pc(mv));
	}
	return transformed;
}
std::vector<int> get_promoted_pieces(const std::vector<int>& moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_promoted_to_pc(mv));
	}
	return transformed;
}
std::vector<int> get_en_passant_flags(const std::vector<int>& moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_en_pass_flag(mv));
	}
	return transformed;
}
std::vector<int> get_pawn_start_flags(const std::vector<int>& moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_pawn_st_flag(mv));
	}
	return transformed;
}
std::vector<int> get_castle_flags(const std::vector<int>& moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_castle_flag(mv));
	}
	return transformed;
}
std::vector<int> get_checked_flags(const std::vector<int>& moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_check_flag(mv));
	}
	return transformed;
}
std::vector<std::string> get_notations(const std::vector<int>& moves, const std::array<PieceType, 120>& board){
	std::vector<std::string> notations;
	for (int move : moves){
		notations.push_back(to_notation(move, board));
	}
	return notations;
}
