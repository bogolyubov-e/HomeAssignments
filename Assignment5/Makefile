CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Werror -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread

SOURCES = rational.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TEST_SOURCES = tests/test_rational.cpp tests/test_matrix.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

MAIN_OBJECT = tests/main_test.o

TARGET = matrix_tests

.PHONY: all test clean format help

all: test

test: $(TARGET)

$(TARGET): $(OBJECTS) $(TEST_OBJECTS) $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

rational.o: rational.cpp rational.h
	$(CXX) $(CXXFLAGS) -c rational.cpp -o rational.o

tests/test_rational.o: tests/test_rational.cpp rational.h
	$(CXX) $(CXXFLAGS) -c tests/test_rational.cpp -o tests/test_rational.o

tests/test_matrix.o: tests/test_matrix.cpp matrix.h rational.h
	$(CXX) $(CXXFLAGS) -c tests/test_matrix.cpp -o tests/test_matrix.o

tests/main_test.o: tests/main_test.cpp
	$(CXX) $(CXXFLAGS) -c tests/main_test.cpp -o tests/main_test.o

format:
	astyle -A1 -s4 --suffix=none *.cpp *.h tests/*.cpp tests/*.h

clean:
	rm -f *.o
	rm -f tests/*.o
	rm -f $(TARGET)

help:
	@echo "make          - build and run tests"
	@echo "make test     - build tests"
	@echo "make format   - format source files"
	@echo "make clean    - remove build artifacts"
