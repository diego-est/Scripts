#pragma once
#include "list.hpp"
#include "data.hpp"

class Queue : public List {
      public:
	Queue();
	Queue(reference<const Queue> rhs);
	~Queue();
	/* === non-modifying member functions === */
	// [[nodiscard]] auto empty() const -> bool;
	auto front() const -> int;
	auto back() const -> int;

	/* === modifying member functions === */
	auto clear() -> void;
	auto enqueue(int val) -> void;
	auto dequeue() -> void;

	/* === operators === */
	auto operator=(reference<const Queue> rhs) -> reference<const Queue>;
	auto operator==(reference<const Queue> rhs) -> bool;

      protected:
	pointer<Node>& m_front = m_head;
	pointer<Node> m_rear;

	auto copy(reference<const Queue> rhs) -> void;

      private:
	auto prepend(int val) -> void;
	auto append(int val) -> void;
	auto remove(int val) -> void;
};
