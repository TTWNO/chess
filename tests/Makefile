defualt: all.out
bitwise: bitwise.out

catch_main.o:
	g++ -w -c -o catch_main.o catch_main.cpp

custom_printing.o:
	g++ -w -I../src/ -c -o custom_printing.o custom_printing.cpp

bitwise.out: catch_main.o
	g++ -I../src/ -o bitwise.out catch_main.o bitwise_tests.cpp

# TODO: Allw all.out to contain bitwise tests
all.out: catch_main.o custom_printing.o
	g++ -std=c++11 -ggdb -w -I../src/ -o all.out ../src/functions.cpp catch_main.o custom_printing.o tests_main.cpp
