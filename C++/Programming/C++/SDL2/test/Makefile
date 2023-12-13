.POSIX:

CXX=g++
CXXFLAGS=-Wall -Werror -Wextra
CXXLIBS=-lSDL2
SRC=src/main.cpp
BUILD=build

build: src/main.cpp
	$(CXX) $(SRC) -o $(BUILD)/a.out $(CXXFLAGS) $(CXXLIBS)

run: build
	./$(BUILD)/a.out

format:
	clang-format -i $(SRC)

.PHONY: build run format
