#include <functions.h>
#include <constants.h>
#include <bitwise.h>
#include <chrono>
#include <iostream>
#include <vector>
#include <array>

using namespace std;
using namespace std::chrono;

// TODO make complete, add complex scenarios.
// Test every function on their edge cases.
int main(){
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < 10000000; i++){
		vector<int> moves = {};
		get_all_moves(Position::E8, DEFAULT_BOARD, moves);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();

	cout << "10,000,000 iterations of get_all_moves took " << duration << " micro seconds" << endl;
}
