#include "../fast_stack.hpp"
#include <cstdio>

fstack::fstack()
	: size(0)
{
	data = new int[30004];
}

fstack::~fstack()
{
	delete[] data;
}

auto fstack::push(int val) -> void
{
	data[size] = val;
	size = size == 30004 ? size : size + 1;
}

auto fstack::pop() -> void
{
	size = size == 0 ? 0 : size - 1;
}

auto fstack::empty() -> bool
{
	return size == 0;
}

auto fstack::top() -> int
{
	return data[size == 0 ? 0 : size - 1];
}
