CXX=g++
SRC=main.cpp
OUT=build/a.out
CXXFLAGS=-x c++ -g -O2 -std=gnu++20 -static

build:
	$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT)

run: build
	./$(OUT)

.PHONY: build run
