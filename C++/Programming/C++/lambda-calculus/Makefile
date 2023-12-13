.POSIX:

CXX=g++
CXXFLAGS=--std=c++2b -Wall -Wextra -O2 -Wno-unused -Wno-unused-parameter
SRC=src/main.cpp
BUILD=build

build: src/main.cpp
	$(CXX) $(SRC) -o $(BUILD)/a.out $(CXXFLAGS)

run: build
	./$(BUILD)/a.out

format:
	clang-format -i $(SRC)

.PHONY: build run format
