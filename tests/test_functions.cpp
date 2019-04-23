#include "test_functions.h"
#include <bitwise.h>
#include <unordered_set>
#include <algorithm>

std::unordered_set<int> get_to_squares(std::unordered_set<int> moves){
	std::unordered_set<int> transformed;
	for (int mv : moves){
		transformed.insert(get_to_sq(mv));
	}
	return transformed;
}
std::unordered_set<int> get_from_squared(std::unordered_set<int> moves){
	std::unordered_set<int> transformed;
	for (int mv : moves){
		transformed.insert(get_from_sq(mv));
	}
	return transformed;
}
std::unordered_set<int> get_captured_pieces(std::unordered_set<int> moves){
	std::unordered_set<int> transformed;
	for (int mv : moves){
		transformed.insert(get_captured_pc(mv));
	}
	return transformed;
}
std::unordered_set<int> get_promoted_pieces(std::unordered_set<int> moves){
	std::unordered_set<int> transformed;
	for (int mv : moves){
		transformed.insert(get_promoted_to_pc(mv));
	}
	return transformed;
}
std::unordered_set<int> get_en_passant_flags(std::unordered_set<int> moves){
	std::unordered_set<int> transformed;
	for (int mv : moves){
		transformed.insert(get_en_pass_flag(mv));
	}
	return transformed;
}
std::unordered_set<int> get_pawn_start_flags(std::unordered_set<int> moves){
	std::unordered_set<int> transformed;
	for (int mv : moves){
		std::cout << "MOVE: \n"; 
		transformed.insert(get_pawn_st_flag(mv));
	}
	return transformed;
}
std::unordered_set<int> get_castle_flags(std::unordered_set<int> moves){
	std::unordered_set<int> transformed;
	for (int mv : moves){
		transformed.insert(get_castle_flag(mv));
	}
	return transformed;
}

