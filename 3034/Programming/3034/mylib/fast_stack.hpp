#pragma once
#include "data.hpp"
#include <cstdint>
using sz = std::size_t;

class fstack {
      public:
	fstack();
	~fstack();

	auto push(int val) -> void;
	auto pop() -> void;
	auto empty() -> bool;
	auto top() -> int;

      protected:
	pointer<int> data;
	sz size;
};
