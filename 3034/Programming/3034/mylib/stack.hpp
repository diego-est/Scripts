#pragma once
#include "data.hpp"
#include "list.hpp"
#include <optional>

class Stack : public List {
      public:
	/* === constructors and destructors === */
	Stack();
	Stack(reference<const Stack> rhs);
	~Stack();

	/* === non-modifying member functions === */
	[[nodiscard]] auto top() const -> std::optional<int>;

	/* === modifying member functions === */
	auto push(int value) -> void;
	auto pop() -> std::optional<int>;

	/* === operators === */
	auto operator=(reference<const Stack> rhs) -> reference<Stack>;

      protected:
	/* === alias m_top to m_head === */
	pointer<Node>& m_top = m_head;

      private:
	/* === private functions aren't usable by client === */
	auto prepend(int value) -> void;
	auto append(int value) -> void;
	auto remove(int value) -> void;
};
