/* ========================================================================
 *
 *     Filename:
 *  Description:
 *       Author:
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

auto getRow(int rowIndex) -> std::vector<int>;

auto main() -> int
{
	for (size_t i = 0; i < 34; i++) {
		for (const auto& e : getRow(i))
			std::cout << e << std::endl;
		std::cout << std::endl;
	}
	return 0;
}

auto getRow(int rowIndex) -> std::vector<int>
{
	auto a = std::vector{1};
	while (rowIndex--) {
		std::adjacent_difference(a.begin(), a.end(), a.begin(),
					 [](auto x, auto y) { return x + y; });
		a.push_back(1);
	}
	return a;
}
