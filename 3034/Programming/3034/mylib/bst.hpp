#pragma once
#include "binary_node.hpp"
#include "binary_tree.hpp"

template<typename T>
class bst : public btree<T> {
	public:
	/* non-modifying member functions */
	auto search(const T value) const -> const ptr<const BinaryNode<T>>;
	auto find_min() const -> T;
	auto find_max() const -> T;

	/* modifying member functions */
	auto insert(const T item) -> void;
	auto remove(const T item) -> void;

	private:
	auto remove_from_tree(ptr<const BinaryNode<T>> ptr) -> void;
};

#include "bst_impl.hpp"
