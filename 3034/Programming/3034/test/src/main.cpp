/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <vector>
#include <iterator>
#include <iostream>

auto bsr(std::vector<int>& v, int i, size_t f, size_t l)
{
	auto m = f;

	while (f <= l) {
		m = f + (l - f) / 2;

		if (i == v[m])
			return m;
		else if (i < v[m])
			bsr(v, i, f, m - 1);
		else
			bsr(v, i, m + 1, l);
	}

	return v.size() + 1;
}

auto bs(std::vector<int>& v, int i)
{
	auto f = 0lu;
	auto l = v.size();
	auto m = f;

	while (f <= l) {
		m = f + (l - f) / 2;
		std::cout << "first: " << f << std::endl;
		std::cout << "middle: " << m << std::endl;
		std::cout << "last: " << l << std::endl;
		std::cout << std::endl;
		if (i == v[m])
			return m;
		else if (i < v[m])
			l = m - 1;
		else
			f = m + 1;
	}
	std::cout << std::endl;
	std::cout << "first: " << f << std::endl;
	std::cout << "middle: " << m << std::endl;
	std::cout << "last: " << l << std::endl;

	return v.size()+1;
}

auto main() -> int
{
	auto array = std::vector<int>{ 2, 3, 5, 7, 11, 13, 17, 19 };
	auto position = bs(array, 11);

	std::cout << "Position: " << position << std::endl;

	return 0;
}

