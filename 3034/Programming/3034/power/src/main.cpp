/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <numeric>
#include <cmath>

auto powR(double base, int exp) -> double {
	if (base == 0.0) {
		if (exp == 0)
			return std::nan("");
		else
			return 0.0;
	} else if (exp == 0)
		return 1.0;
	else if (exp > 0)
		return base * powR(base, exp - 1);
	else
		return 1.0 / (base * powR(base, -1 * exp - 1));
}

auto powI(double base, int exp) -> double {
	auto result = std::nan("");

	return powR(base, exp);
}

auto main() -> int
{
	std::cout << powR(0, 0) << std::endl;
	std::cout << powR(3, 0) << std::endl;
	std::cout << powR(3, 1) << std::endl;
	std::cout << powR(3, 4) << std::endl;
	std::cout << powR(2, -3) << std::endl;
	return 0;
}
