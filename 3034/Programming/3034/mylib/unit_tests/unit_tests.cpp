#include <cstdint>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
// #include "../functions.hpp"
#define NOTEST

auto print(auto const x) -> void
{
	std::cout << x;
}

auto println(auto const x) -> void
{
	std::cout << x << std::endl;
}

static auto mean(std::vector<double> array) -> double
{
	return std::reduce(array.cbegin(), array.cend()) / double(array.size());
}

auto main() -> int32_t
{
	#ifdef TEST
	println("<<< List tests: >>>");
	auto l = List();

	print("l.empty(): ");
	assert(l.empty());
	println("PASSED");

	print("l.search(1): ");
	assert(!l.search(1));
	println("PASSED");

	print("l.length() == 0: ");
	assert(l.length() == 0);
	println("PASSED");

	println("l.append(4)");
	l.append(4);
	print("l.length() == 1: ");
	assert(l.length() == 1);
	println("PASSED");

	println("l.append(4)");
	l.append(4);
	print("l.length() == 1: ");
	assert(l.length() == 1);
	println("PASSED");

	print("l.search(4): ");
	assert(l.search(4));
	println("PASSED");

	println("");

	println("<<< Stack tests: >>>");
	auto s = Stack();

	print("s.empty(): ");
	assert(s.empty());
	println("PASSED");

	print("s.search(1): ");
	assert(!s.search(1));
	println("PASSED");

	print("s.length() == 0: ");
	assert(s.length() == 0);
	println("PASSED");

	println("s.push(4)");
	s.push(4);
	print("s.length() == 1: ");
	assert(s.length() == 1);
	println("PASSED");

	println("s.push(4)");
	s.push(4);
	print("s.length() == 2: ");
	assert(s.length() == 2);
	println("PASSED");

	print("s.search(4): ");
	assert(s.search(4));
	println("PASSED");

	println("s.pop()");
	s.pop();
	print("s.length() == 1: ");
	assert(s.length() == 1);
	println("PASSED");
	#endif

	auto v = std::vector{ 25.0, 23.0, 44.0, 19.0, 31.0 };

	std::cout << mean(v) << std::endl;


	return 0;
}
