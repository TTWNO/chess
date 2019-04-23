#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTOPMS_H
#include <vector>

std::vector<int> get_from_squares(std::vector<int> moves);
std::vector<int> get_to_squares(std::vector<int> moves);
std::vector<int> get_captured_pieces(std::vector<int> moves);
std::vector<int> get_promoted_pieces(std::vector<int> moves);
std::vector<int> get_en_passant_flags(std::vector<int> moves);
std::vector<int> get_pawn_start_flags(std::vector<int> moves);
std::vector<int> get_castle_flags(std::vector<int> moves);
#endif
