/* ========================================================================
 *
 *     Filename:
 *  Description:
 *       Author:
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

#include <execution>
#define PAR std::execution::par,

using u32 = uint32_t;
namespace ra = std::ranges;
namespace vi = std::views;

template <typename T> using ref = T&;

auto print(ref<const std::vector<u32>> v) -> void;
auto println(ref<const std::vector<u32>> v) -> void;

auto decompose(u32 n) -> std::vector<u32>;

auto is_cyclops(u32 n) -> bool;
auto first_cyclops(size_t n) -> std::vector<u32>;

auto is_disarium(u32 n) -> bool;
auto first_disarium(size_t n) -> std::vector<u32>;

auto main() -> int
{
	std::cout << std::boolalpha << is_disarium(1) << std::endl;
	std::cout << std::boolalpha << is_disarium(2) << std::endl;
	std::cout << std::boolalpha << is_disarium(3) << std::endl;
	auto const k = first_disarium(18);
	print(k);
	return 0;
}

auto print(ref<const std::vector<u32>> v) -> void
{
	for (auto const& e : v)
		std::cout << e << ' ';
	std::cout << std::endl;
}

auto println(ref<const std::vector<u32>> v) -> void
{
	for (auto const& e : v)
		std::cout << e << std::endl;
}

auto decompose(u32 n) -> std::vector<u32>
{
	auto v = std::vector<u32>(floor(log10(n)) + 1u, 0u);

	for (auto& e : v | vi::reverse)
		e = n % 10, n /= 10;

	return v;
}

auto is_cyclops(u32 n) -> bool
{
	if (n == 0)
		return true;
	auto last_digit = n % 10;
	auto ctr = 0;
	while (last_digit != 0) {
		++ctr;
		n /= 10;
		last_digit = n % 10;
	}
	n /= 10;
	last_digit = n % 10;
	while (last_digit != 0) {
		--ctr;
		n /= 10;
		last_digit = n % 10;
	}
	return n == 0 && ctr == 0;
}

auto first_cyclops(size_t n) -> std::vector<u32>
{
	auto v = std::vector(n, 0u);
	auto ctr = 1;
	for (auto& e : v) {
		while (!is_cyclops(ctr))
			++ctr;
		e = ctr;
		++ctr;
	}

	return v;
}

auto is_disarium(u32 n) -> bool
{
	auto const v = decompose(n);
	auto ctr = 1u;

	auto const transform = [&ctr](auto val) {
		return std::pow(val, ctr++);
	};

	return std::transform_reduce(PAR v.cbegin(), v.cend(), 0L, std::plus{},
				     transform) == n;
}

auto first_disarium(size_t n) -> std::vector<u32>
{
	auto v = std::vector(n, 0u);
	auto ctr = 1;
	for (auto& e : v) {
		while (!is_disarium(ctr))
			++ctr;
		e = ctr;
		++ctr;
	}
	return v;
}
