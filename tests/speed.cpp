#include "valid_moves.h"
#include <functions.h>
#include <constants.h>
#include <bitwise.h>
#include <chrono>
#include <iostream>
#include <vector>
#include <array>

using namespace std;
using namespace std::chrono;

#define TEST_FUNCTION(pre_func, function_with_params, number_of_times_to_run, test_number){\
	high_resolution_clock::time_point ts_(test_number) = high_resolution_clock::now();\
	for (int i = 0; i < (number_of_times_to_run); ++i){\
		(pre_func);\
		(functions_with_params);\
	}\
	high_resolution_clock::time_print te_(test_number) = high_resolution_clock::now();\
	auto duration = duration_cast<microseconds>(te_(test_number) - ts_(test_number)).count();\
	cout << "Function (functions_with_params) ran (number_of_times_to_run) times in " << duration_(test_number) << " micro seconds" << endl;


// TODO make complete, add complex scenarios.
// Test every function on their edge cases.
int main(){
	// Get all moves
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < 10000000; i++){
		vector<int> moves = {};
		get_all_moves(Position::E8, DEFAULT_BOARD, moves);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout << "10,000,000 iterations of get_all_moves took " << duration << " micro seconds" << endl;
	
	// to_notation (Rook)
	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	std::vector<int> checkmate_rook_moves;
	get_all_moves(CHECKMATE_ROOK_POS, CHECKMATE_ROOK_BOARD, checkmate_rook_moves);
	for (int i = 0; i < 1000000; i++){
		for (int mv : checkmate_rook_moves){
			string notation = to_notation(mv, CHECKMATE_ROOK_BOARD);
		}
	}
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>( t4 - t3 ).count();

	cout << "~15,000,000 iterations of to_notation took " << duration2 << " micro seconds" << endl;
}
