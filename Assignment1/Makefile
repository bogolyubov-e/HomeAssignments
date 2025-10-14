CXX = g++
CXXFLAGS = -Wall -Wextra
SRC = main.cpp hello.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean

all: hello

hello: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f hello $(OBJ)
