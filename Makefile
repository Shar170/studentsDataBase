all:
	g++ -std=c++20 DataBaseStudent.h Tests.cpp -o a.out -lgtest -pthread
clean:
	rm a.out