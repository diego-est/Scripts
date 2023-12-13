.POSIX:

CXX=clang++
CXXFLAGS=-Weverything -Werror -Wextra -O2 -Wno-c++98-compat -Wno-sign-conversion
SRC=src/main.cpp
BUILD=build

build: src/main.cpp
	$(CXX) $(SRC) -o $(BUILD)/a.out $(CXXFLAGS)

run: build
	./$(BUILD)/a.out

format:
	clang-format -i $(SRC)

.PHONY: build run format
