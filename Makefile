all:
	g++ -std=c++20 TestApp2.cpp database.h -o a.out
clean:
	rm a.out
