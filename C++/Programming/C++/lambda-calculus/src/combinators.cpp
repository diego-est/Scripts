#include <tuple>
namespace combinators
{
	/* \xyz.x(yz) */
	auto b = [](auto x, auto y, auto z){ return x(y(z)); };

	/* \xyz.xzy */
	auto c = [](auto x, auto y, auto z){ return x(z, y); };

	/* \abc.cba */
	auto f = [](auto a, auto b, auto c){ return c(b, a); };

	/* \a.a */
	auto i = [](auto i){ return i; };

	/* \abc.ac(bc) */
	auto s = [](auto a, auto b, auto c){ return a(c, b(c)); };

	/* \xy.x */
	auto k = [](auto x, auto y){ return x; };

	/* \xy.xyy */
	auto w = [](auto x, auto y){ return x(y, y); };

	namespace functions {
		auto _eq_ = [](auto x, auto y){ return x == y; };

		auto eq_ = [](auto x){ return [x](auto y){ return x == y; }; };

		auto _add_ = [](auto x, auto y){ return x + y; };

		auto add_ = [](auto x){ return [x](auto y){ return x + y; }; };

		auto fst_ = [](auto x){ return std::get<0>(x); };
		auto snd_ = [](auto x){ return std::get<1>(x); };
	}

}
