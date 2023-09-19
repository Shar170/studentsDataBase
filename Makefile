all:
	g++ -std=c++20 Test.cpp DataBase.h -o a.out -lgtest -lgmock -pthread
clean:
	rm a.out
