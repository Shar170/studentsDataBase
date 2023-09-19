CXX = g++
CXXFLAGS = -std=c++20 -Wall -O0 -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov

all: a.out

a.out: Test.cpp DataBase.h
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f a.out *.gc* coverage.info
