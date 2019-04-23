#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTOPMS_H
#include <unordered_set>

std::unordered_set<int> get_from_squares(std::unordered_set<int> moves);
std::unordered_set<int> get_to_squares(std::unordered_set<int> moves);
std::unordered_set<int> get_captured_pieces(std::unordered_set<int> moves);
std::unordered_set<int> get_promoted_pieces(std::unordered_set<int> moves);
std::unordered_set<int> get_en_passant_flags(std::unordered_set<int> moves);
std::unordered_set<int> get_pawn_start_flags(std::unordered_set<int> moves);
std::unordered_set<int> get_castle_flags(std::unordered_set<int> moves);
#endif
