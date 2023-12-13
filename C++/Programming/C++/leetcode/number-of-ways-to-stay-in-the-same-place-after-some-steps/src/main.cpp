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
#include <utility>
#include <unordered_map>
#include <cmath>

typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<std::vector<int>> vvi;

struct Solution {
	vvi memo;
	int mod = 1e9 + 7;
	int arrLen;

	auto numWays(int steps, int arrLen) -> int;
	auto dp(int curr, int remain) -> int;
};

auto main() -> int
{
	auto s = Solution();
	std::cout << s.numWays(1, 1) << std::endl;
	std::cout << "Expected: 1" << std::endl;

	std::cout << s.numWays(1, 2) << std::endl;
	std::cout << "Expected: 1" << std::endl;

	std::cout << s.numWays(2, 1) << std::endl;
	std::cout << "Expected: 1" << std::endl;

	std::cout << s.numWays(2, 2) << std::endl;
	std::cout << "Expected: 2" << std::endl;

	std::cout << s.numWays(3, 2) << std::endl;
	std::cout << "Expected: 4" << std::endl;

	std::cout << s.numWays(2, 4) << std::endl;
	std::cout << "Expected: 2" << std::endl;

	std::cout << s.numWays(4, 2) << std::endl;
	std::cout << "Expected: 8" << std::endl;

	std::cout << s.numWays(4, 3) << std::endl;
	std::cout << "Expected: 9" << std::endl;

	std::cout << s.numWays(27, 7) << std::endl;
	std::cout << "Expected: 9" << std::endl;
	return 0;
}

auto Solution::numWays(int steps, int arrLen) -> int
{
	arrLen = std::min(steps / 2 + 1, arrLen);
	this->arrLen = arrLen;
	memo = std::vector(arrLen, std::vector(steps + 1, -1));
	return dp(0, steps);
}

auto Solution::dp(int curr, int remain) -> int
{
	if (remain == 0)
		return curr == 0 ? 1 : 0;

	if (memo[curr][remain] != -1)
		return memo[curr][remain];

	int ans = dp(curr, remain - 1);
	if (curr > 0)
		ans += dp(curr - 1, remain - 1) % mod;
	ans %= mod;
	if (curr < arrLen - 1)
		ans += dp(curr + 1, remain - 1) % mod;
	ans %= mod;

	memo[curr][remain] = ans;
	return ans;
}
