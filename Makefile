all:
	g++ -std=c++17 -pthread -I/usr/include/gtest -L/usr/lib/x86_64-linux-gnu Tests/test.cpp -o program.out -lgtest -lpthread

clean:
	rm program.out