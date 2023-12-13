.POSIX:

CXX=clang++
FILE=unit_tests.cpp
SRC=../src/*.cpp $(FILE)
BUILD=./build
CXXFLAGS=-Weverything -Werror -Wconversion --std=c++20 -Wno-c++98-compat -Wno-padded -Wno-documentation -Wno-unsafe-buffer-usage -Wno-shadow-field-in-constructor -Wno-unused-macros

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BUILD)/a.out

run: build
	./$(BUILD)/a.out

format:
	clang-format -i $(SRC)

.PHONY: build run format
