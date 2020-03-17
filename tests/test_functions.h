#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTOPMS_H
#include <string>
#include <vector>
#include <array>
#include <constants.h>

std::vector<int> get_from_squares(const std::vector<int>& moves);
std::vector<int> get_to_squares(const std::vector<int>& moves);
std::vector<int> get_captured_pieces(const std::vector<int>& moves);
std::vector<int> get_promoted_pieces(const std::vector<int>& moves);
std::vector<int> get_en_passant_flags(const std::vector<int>& moves);
std::vector<int> get_pawn_start_flags(const std::vector<int>& moves);
std::vector<int> get_castle_flags(const std::vector<int>& moves);
std::vector<int> get_checked_flags(const std::vector<int>& moves);
std::vector<std::string> get_notations(const std::vector<int>& moves, const std::array<PieceType, 120>& board);
#endif
