#pragma once
#include "data.hpp"
#include "list.hpp"

class SortedList : public List {
      public:
	/* === constructors and destructors === */
	SortedList();
	SortedList(reference<const SortedList> sl);
	~SortedList();

	/* === non-modifying member functions === */
	[[nodiscard]] auto search(int value) const -> bool;

	/* === modifying member functions === */
	auto insert(int value) -> void;

	private:
	auto append(int value) -> void;
	auto prepend(int value) -> void;
};
