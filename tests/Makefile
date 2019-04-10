defualt: build

catch_main.o:
	g++ -w -c -o catch_main.o catch_main.cpp

custom_printing.o:
	g++ -w -I../src/ -c -o custom_printing.o custom_printing.cpp

build: catch_main.o custom_printing.o
	g++ -std=c++11 -ggdb -w -I../src/ -o tests.out ../src/functions.cpp catch_main.o custom_printing.o tests_main.cpp
