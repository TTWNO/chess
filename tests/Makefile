defualt: build

catch_main.o:
	g++ -w -c -o catch_main.o catch_main.cpp

build: catch_main.o
	g++ -std=c++11 -ggdb -w -I../src/ -o tests.out ../src/functions.cpp catch_main.o tests_main.cpp
