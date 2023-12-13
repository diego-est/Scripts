#pragma once
#include "binary_node.hpp"
#include <cstdint>

template<typename T>
using ptr = T*;

template<typename T>
using ref = T&; // nicer way to type reference variables

using size_t = std::size_t;

template<typename T>
class btree {
      protected:
	ptr<BinaryNode<T>> root;
	auto copy(ref<const btree> rhs) -> ref<const btree>;

      public:
	btree();
	btree(ref<const btree> original);
	~btree();

	/* non-modifying member functions */
	[[nodiscard]] auto empty() const -> bool;
	auto height() const -> int;
	auto leaves() const -> size_t;

	auto print_ascending() const -> void;
	auto print_descending() const -> void;
	auto print_inorder() const -> void;
	auto graph() const -> void;

	/* modifying member functions */
	auto operator = (ref<const btree> rhs) -> ref<const btree>;
	auto destroy_tree() -> void;

      private:
	/* helpers */
	auto inorder(const ptr<const BinaryNode<T>> ptr) const -> void;
	auto descending(const ptr<const BinaryNode<T>> ptr) const -> void;
	auto graph_aux(const int indent) const -> void;
	auto nodes_aux(const ptr<const BinaryNode<T>> ptr) const -> size_t;
	auto leaves_aux(const ptr<const BinaryNode<T>> ptr) const -> size_t;
};


#include "binary_tree_impl.hpp"
