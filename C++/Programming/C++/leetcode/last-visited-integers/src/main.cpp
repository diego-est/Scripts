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
#include <string>
#include <ranges>
#include <deque>
#include <cstdint>

auto lastVisitedIntegers(std::vector<std::string>& words) -> std::vector<int>;
auto main() -> int
{
	auto a = std::vector<std::string>();
	a.push_back("1");
	a.push_back("2");
	a.push_back("prev");
	a.push_back("prev");
	a.push_back("prev");
	auto v = lastVisitedIntegers(a);
	for (auto const& e : v)
		std::cout << e << std::endl;
	return 0;
}

auto lastVisitedIntegers(std::vector<std::string>& words) -> std::vector<int>
{
	auto solution = std::vector<int>();
	auto nums = std::vector<int>();
	auto rb = nums.rbegin();
	size_t k = 0;
	for (const auto& word : words) {
		rb = nums.rbegin();
		if (word == "prev")
			solution.push_back(k >= nums.size() ? -1 : *(rb + k)),
				k++;
		else
			nums.push_back(stoi(word)), k = 0;
	}
	return solution;
}

