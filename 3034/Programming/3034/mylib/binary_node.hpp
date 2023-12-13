#pragma once
#include "data.hpp"
#include <cstdint>

template<typename T>
using ptr = T*;
template<typename T>
using ref = T&;

using size_t = std::size_t;

template<typename T>
struct BinaryNode {
	ptr<BinaryNode> right;
	ptr<BinaryNode> left;
	T data;

	BinaryNode(const T data, ptr<BinaryNode> left = nullptr, ptr<BinaryNode> right = nullptr);

	/* non-modifying member functions */
	auto print_inorder() const -> void;
	auto print_preorder() const -> void;
	auto graph(const int height) const -> void;
	auto height() const -> size_t;
	auto children_count() const -> size_t;
	auto leaves_count() const -> size_t;
	[[nodiscard]] auto is_leaf() const -> bool;

	/* modifying member functions */
	auto destroy_node() -> void;
	auto copy_branch(const ptr<const BinaryNode<T>> original) -> void;
};

#include "binary_node_impl.hpp"
