#pragma once
#include "data.hpp"
#include "node.hpp"
#include <iostream>

class List {
      public:
	/* === constructors and destructors === */
	List();
	List(reference<const List> rhs);
	~List();

	/* === non-modifying member functions === */
	[[nodiscard]] auto empty() const -> bool;
	[[nodiscard]] auto search(int value) const -> bool;
	[[nodiscard]] auto length() const -> size_t;
	[[nodiscard]] auto cbegin() const -> pointer<const Node>;
	[[nodiscard]] auto begin() const -> pointer<Node>;
	auto print() const -> void;

	/* === modifying member functions === */
	auto clear() -> void;
	auto copy(reference<const List> rhs) -> void;
	auto prepend(int value) -> void;
	auto append(int value) -> void;
	auto remove(int value) -> void;

	/* === operators === */
	auto operator=(reference<const List> rhs) -> reference<const List>;
	friend auto operator<<(std::ostream& lhs, reference<const List> rhs)
	    -> std::ostream&;
	friend auto operator>>(std::istream& lhs, reference<List> rhs)
	    -> std::istream&;

      protected:
	pointer<Node> m_head;
	size_t m_size;
};
