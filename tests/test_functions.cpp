#include "test_functions.h"
#include <bitwise.h>
#include <vector>
#include <algorithm>

std::vector<int> get_to_squares(std::vector<int> moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_to_sq(mv));
	}
	return transformed;
}
std::vector<int> get_from_squared(std::vector<int> moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_from_sq(mv));
	}
	return transformed;
}
std::vector<int> get_captured_pieces(std::vector<int> moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_captured_pc(mv));
	}
	return transformed;
}
std::vector<int> get_promoted_pieces(std::vector<int> moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_promoted_to_pc(mv));
	}
	return transformed;
}
std::vector<int> get_en_passant_flags(std::vector<int> moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_en_pass_flag(mv));
	}
	return transformed;
}
std::vector<int> get_pawn_start_flags(std::vector<int> moves){
	std::vector<int> transformed;
	for (int mv : moves){
		std::cout << "MOVE: \n"; 
		transformed.push_back(get_pawn_st_flag(mv));
	}
	return transformed;
}
std::vector<int> get_castle_flags(std::vector<int> moves){
	std::vector<int> transformed;
	for (int mv : moves){
		transformed.push_back(get_castle_flag(mv));
	}
	return transformed;
}

