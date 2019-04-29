defualt: all.out
bitwise: bitwise.out
release: all_optimized.out

clean:
	rm all.out
distclean:
	rm *.o
	rm *.out

catch_main.o:
	g++ -w -c -o catch_main.o catch_main.cpp

custom_printing.o:
	g++ -Wall -I../src/ -c -o custom_printing.o custom_printing.cpp

bitwise.out: catch_main.o
	g++ -Wall -I../src -o bitwise.out catch_main.o bitwise_tests.cpp

# TODO: Allw all.out to contain bitwise tests
all.out: catch_main.o custom_printing.o
	g++ -std=c++11 -ggdb -Wall -I../src/ -o all.out ../src/functions.cpp catch_main.o custom_printing.o test_functions.cpp main.cpp

catch_main_optimized.o:
	g++ -w -O2 -c -o catch_main_optimized.o catch_main.cpp

custom_printing_optimized.o:
	g++ -Wall -O2 -I../src/ -c -o custom_printing_optimized.o custom_printing.cpp

bitwise_optimized.out: catch_main_optimized.o
	g++ -Wall -O2 -I../src -o bitwise_optimized.out catch_main_optimized.o bitwise_tests.cpp

all_optimized.out: catch_main_optimized.o custom_printing_optimized.o
	g++ -std=c++11 -O2 -Wall -I../src/ -o all_optimized.out ../src/functions.cpp catch_main_optimized.o custom_printing_optimized.o test_functions.cpp main.cpp
