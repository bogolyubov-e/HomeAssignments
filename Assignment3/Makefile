CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread

SOURCES = transformer.cpp weapon.cpp vehicle.cpp autobot.cpp decepticon.cpp maximal.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TEST_SOURCES = tests/test_weapon.cpp tests/test_vehicle.cpp tests/test_autobot.cpp tests/test_decepticon.cpp tests/test_maximal.cpp tests/test_polymorphism.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
MAIN_OBJECT = tests/main_test.o

ALL_TESTS_TARGET = transformer_tests
TEST_TARGETS = test_weapon test_vehicle test_autobot test_decepticon test_maximal test_polymorphism

.PHONY: all test_all clean help format

all: test_all

test_all: $(ALL_TESTS_TARGET)

$(ALL_TESTS_TARGET): $(OBJECTS) $(TEST_OBJECTS) $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_weapon: weapon.o tests/test_weapon.o $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_vehicle: vehicle.o tests/test_vehicle.o $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_autobot: transformer.o weapon.o vehicle.o autobot.o tests/test_autobot.o $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_decepticon: transformer.o weapon.o vehicle.o decepticon.o tests/test_decepticon.o $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_maximal: transformer.o weapon.o vehicle.o maximal.o tests/test_maximal.o $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_polymorphism: $(OBJECTS) tests/test_polymorphism.o $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

transformer.o: transformer.cpp transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c transformer.cpp -o transformer.o

weapon.o: weapon.cpp weapon.h
	$(CXX) $(CXXFLAGS) -c weapon.cpp -o weapon.o

vehicle.o: vehicle.cpp vehicle.h
	$(CXX) $(CXXFLAGS) -c vehicle.cpp -o vehicle.o

autobot.o: autobot.cpp autobot.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c autobot.cpp -o autobot.o

decepticon.o: decepticon.cpp decepticon.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c decepticon.cpp -o decepticon.o

maximal.o: maximal.cpp maximal.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c maximal.cpp -o maximal.o

tests/test_weapon.o: tests/test_weapon.cpp weapon.h
	$(CXX) $(CXXFLAGS) -c tests/test_weapon.cpp -o tests/test_weapon.o

tests/test_vehicle.o: tests/test_vehicle.cpp vehicle.h
	$(CXX) $(CXXFLAGS) -c tests/test_vehicle.cpp -o tests/test_vehicle.o

tests/test_autobot.o: tests/test_autobot.cpp autobot.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c tests/test_autobot.cpp -o tests/test_autobot.o

tests/test_decepticon.o: tests/test_decepticon.cpp decepticon.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c tests/test_decepticon.cpp -o tests/test_decepticon.o

tests/test_maximal.o: tests/test_maximal.cpp maximal.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c tests/test_maximal.cpp -o tests/test_maximal.o

tests/test_polymorphism.o: tests/test_polymorphism.cpp autobot.h decepticon.h maximal.h
	$(CXX) $(CXXFLAGS) -c tests/test_polymorphism.cpp -o tests/test_polymorphism.o

tests/main_test.o: tests/main_test.cpp
	$(CXX) $(CXXFLAGS) -c tests/main_test.cpp -o tests/main_test.o

run_test_all: test_all
	./$(ALL_TESTS_TARGET)

run_test_autobot: test_autobot
	./test_autobot

run_test_decepticon: test_decepticon
	./test_decepticon

run_test_maximal: test_maximal
	./test_maximal

run_test_polymorphism: test_polymorphism
	./test_polymorphism

format:
	astyle -A1 -s4 --suffix=none *.cpp *.h tests/*.cpp tests/*.h

clean:
	rm -f *.o
	rm -f tests/*.o
	rm -f $(ALL_TESTS_TARGET) $(TEST_TARGETS)

help:
	@echo "make                - Build all tests"
	@echo "make test_all       - Build and run all tests"
	@echo "make test_autobot   - Build Autobot tests"
	@echo "make test_polymorphism - Build polymorphism test (9 objects)"
	@echo "make format         - Format all source files with astyle (-A1 -s4, no .orig)"
	@echo "make clean          - Clean project"
