#include "../functions.hpp"
#include <algorithm>
#include <numeric>

template<typename T>
using ref = T&;

auto mean(ref<const std::vector<double>> arr) -> double
{
	return std::reduce(arr.cbegin(), arr.cend()) / double(arr.size());
}

auto selection_sort(ref<std::vector<int>> arr) -> void
{
	auto current = arr.begin();
	while (current != arr.end()) {
		auto min = std::min_element(current, arr.end());
		if (*current < *min)
			std::iter_swap(current, min);
		std::advance(current, 1);
	}
}

auto bubble_sort(ref<std::vector<int>> arr) -> void
{

}
