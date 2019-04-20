#include "bitwise_constants.h"
#include <array>
#include <iostream>

int main(){
	for (int y=0;y<12;y++){
		for (int x=0;x<10;x++){
			int cord = (y*10) + x;
			int val = DEFAULT_BOARD[cord];
			val==-1?std::cout << '!':std::cout << CHESS_CHARS[val];
			std::cout << std::hex << y << "," << x << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
