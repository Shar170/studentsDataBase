all:
	g++ -std=c++20 TestApp3.cpp database.h -o a.out
clean:
	rm a.out
