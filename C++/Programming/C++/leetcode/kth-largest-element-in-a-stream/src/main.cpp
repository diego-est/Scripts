/* ========================================================================
 *
 *     Filename:
 *  Description:
 *       Author:
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>

class KthLargest {
      public:
	size_t m_k;
	std::priority_queue<int, std::vector<int>, std::greater<int>> m_nums;
	KthLargest(int k, std::vector<int>& nums)
		: m_k(k)
	{
		for (const auto& n : nums) m_nums.push(n);
		while (m_nums.size() > m_k) m_nums.pop();
	}

	int add(int val)
	{
		m_nums.push(val);
		if (m_nums.size() > m_k) m_nums.pop();
		return m_nums.top();
	}
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

auto main() -> int
{
	auto vec1 = std::vector{4, 5, 8, 2};
	KthLargest kthlargest = KthLargest(3, vec1);
	std::cout << kthlargest.add(3) << "\n";
	std::cout << kthlargest.add(5) << "\n";
	std::cout << kthlargest.add(10) << "\n";
	std::cout << kthlargest.add(9) << "\n";
	std::cout << kthlargest.add(4) << "\n";
	return 0;
}
