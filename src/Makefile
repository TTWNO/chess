#CC=g++-4.2
#
#chess.out: functions.o
#	g++ chess.o functions.o -std=c++11
#
#chess.o: chess.cpp
#	g++ -c -std=c++11 chess.cpp
#
#functions.o: functions.cpp functions.h
#	g++ -c -std=c++11 functions.cpp
#
default: build
release: optimized

optimized:
	g++ -std=c++11 -O2 -Wall -o chess.out functions.cpp chess.cpp

build:
	g++ -Wall -o chess_unoptimized.out functions.cpp chess.cpp -std=c++11
