/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <vector>

auto fib(int n) -> int
{
	static auto m = []{
		auto v = std::vector<int>();
		return v;
	}();
	return n;
}

auto main() -> int
{
	auto n = -1;
	while (++n <= 30) {
		std::cout << fib(n) << std::endl;
	}
	return 0;
}
