all:
	g++ -std=c++20 TestApp2 database.h -o a.out
clean:
	rm a.out
