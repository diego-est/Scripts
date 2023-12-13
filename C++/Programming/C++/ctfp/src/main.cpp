/* ========================================================================
 *
 *     Filename:  main.cpp
 *  Description:  Category Theory for Programmers challenges
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <functional>
#include <cmath>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/* === Challenges 1 === */
auto id(auto x)
{
	return x;
}

template <class A>
auto compose(auto a, auto b, auto c)
{
	return a(b(c));
}

auto composition_test(auto f, auto id, auto compose, auto x)
{
	assert(compose(f, id, x) == f(x));
	assert(compose(id, f, x) == f(x));
}

/* === Challenges 2 === */
template <class D, class C>
auto memoize(auto const op)
{
	static auto mp = std::unordered_map<D, C>{};
	return [op](D x) { return mp.contains(x)? mp.at(x) : mp[x] = op(x); };
}

auto True([[maybe_unused]] bool _)
{
	return true;
}

auto False([[maybe_unused]] bool _)
{
	return false;
}

auto Negate(bool x)
{
	return not x;
}

auto Same(bool x)
{
	return x;
}

/* === Challenges 3 === */
/* identity */
template <class T>
auto mempty = T();

/* binary associative operator */
template <class T>
auto mappend(T, T) -> T = delete;

template <class M>
concept Monoid = requires (M m) {
	{ mempty<M> } -> std::same_as<M>;
	{ mappend(m, m) } -> std::same_as<M>;
};

template <>
auto mempty<bool> = true;

auto mappend(bool value1, bool value2) -> bool
{
	return value1 && value2;
}

auto kleisli_compose(auto m1, auto m2)
{
	return [m1, m2](auto x) {
		auto const p1 = m1(x);
		auto const p2 = m2(p1.first);
		return std::make_pair(p2.first, mappend(p1.second, p2.second));
	};
};

template <class A>
auto kleisli_id(A x)
{
	return std::make_pair(x, mempty<A>);
}

template <class A>
using optional = std::pair<A, bool>;

template <class A>
auto optional_id(A x) -> optional<A>
{
	return kleisli_id<A>(x);
}

auto optional_compose(auto m1, auto m2)
{
	return kleisli_compose(m1, m2);
}


auto safe_root(double x) -> optional<double>
{
	if (x < 0) return optional<double>{ x, not mempty<bool> };
	return optional_id<double>(sqrt(x));
}
auto safe_reciprocal(double x) -> optional<double>
{
	if (x == 0) return optional<double>{ x, not mempty<bool> };
	return optional_id<double>(1.0 / x);
}

auto safe_root_reciprocal(double x) -> optional<double>
{
	return optional_compose(safe_root, safe_reciprocal)(x);
}

/* === testing functions === */
auto fact(uint64_t x) -> uint64_t;
auto fib(uint64_t x) -> uint64_t;
auto mul(uint64_t x, uint64_t y) -> uint64_t;

auto main() -> int
{
	auto k = 0u;
	while (true) {
		std::cout << "Fibonacci of: #";
		std::cin >> k;
		std::cout << "is: " << memoize<uint64_t, uint64_t>(fib)(k) << "\n";
	}
	return 0;
}

auto mul(uint64_t x, uint64_t y) -> uint64_t
{
	return x * y;
}

auto fact(uint64_t x) -> uint64_t
{
	if (x <= 1) return 1;
	return x * fact(x - 1);
}

auto fib(uint64_t x) -> uint64_t
{
	if (x <= 1) return x;
	return memoize<uint64_t, uint64_t>(fib)(x - 1) + memoize<uint64_t, uint64_t>(fib)(x - 2);
}
