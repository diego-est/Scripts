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

/*
auto b = [](auto a, auto b, auto c) {
	return a(b(c));
};

auto b1 = [](auto a, auto b, auto c, auto d) {
	return a(b(c, d));
};

auto b2 = [](auto a, auto b, auto c, auto d, auto e) {
	return [a, b, c, d, e](auto x) { return a(b(c(x), d(x), e(x))); };
};
auto b3 = [](auto a, auto b, auto c, auto d) {
	return [a, b, c, d](auto x) { return a(b(c(d(x)))); };
};
auto c = [](auto a, auto b, auto c) {
	return [a, b, c](auto x) { return a(c(x), b(x)); };
};
auto d = [](auto a, auto b, auto c, auto d) {
	return [a, b, c, d](auto x) { return a(b(x), c(d(x))); };
};
auto d1 = [](auto a, auto b, auto c, auto d, auto e) {
	return [a, b, c, d, e](auto x) { return a(b(x), c(x), d(e(x))); };
};
auto d2 = [](auto a, auto b, auto c, auto d, auto e) {
	return [a, b, c, d, e](auto x) { return a(b(c(x), d(e(x)))); };
};
auto e = [](auto a, auto b, auto c, auto d, auto e) {
	return [a, b, c, d, e](auto x) { return a(b(x), c(d(e(x)))); };
};
auto e_ = [](auto a, auto b, auto c, auto d, auto e, auto f, auto g) {
	return [a, b, c, d, e, f, g](auto x) {
		return a(b(c(x), d(x)), e(f(x), g(x)));
	};
};
auto f = [](auto a, auto b, auto c) {
	return [a, b, c](auto x) { return c(b(a(x))); };
};
auto g = [](auto a, auto b, auto c, auto d) {
	return [a, b, c, d](auto x) { return a(d(x)); };
};
auto h = [](auto a, auto b, auto c) {
	return [a, b, c](auto x) { return a(b(x), c(x), b(x)); };
};
auto i = [](auto a) { return a; };
auto j = 0;
auto k = [](auto a, auto b) { return [a](auto x) { return a(x); }; };
auto l = 0;
auto m = 0;
auto m2 = 0;
auto o = 0;
auto q = 0;
auto q1 = 0;
auto q2 = 0;
auto q3 = 0;
auto q4 = 0;
auto r = 0;
auto s = [](auto a, auto b, auto c) {
	return [a, b, c](auto x) { return a(c(x), b(c(x))); };
};
auto t = 0;
auto u = 0;
auto v = 0;
auto w = 0;
auto w1 = 0;
auto y = 0;
auto w_ = 0;
auto c_ = 0;
auto r_ = 0;
auto f_ = 0;
auto v_ = 0;
auto i__ = 0;
auto w__ = 0;
auto c__ = 0;
auto r__ = 0;
auto f__ = 0;
auto v__ = 0;
auto ki = 0;
auto omega = 0;
auto km = 0;
auto ckm = 0;
auto theta = 0;
*/

#include "combinators.cpp"
#include <algorithm>
#include <cmath>
#include <ranges>
#include <tuple>
#include <vector>

auto main() -> int
{
	namespace ra = std::ranges;
	namespace vi = std::views;

	constexpr auto pow16 = [](auto p) {
		auto [x, y] = p;
		return powl(16, x) * y;
	};

	constexpr auto add = [](auto a, auto b) { return a + b; };

	static constexpr auto to_hex = [pow16, add](auto range) {
		return ra::fold_left(range
			| vi::reverse
			| vi::enumerate
			| vi::transform(pow16), 0, add);
	};

	constexpr static auto v = {2, 5};
	std::cout << to_hex(v) << std::endl;

	return 0;
}
