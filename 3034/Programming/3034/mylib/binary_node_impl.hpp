#pragma once
#include "binary_node.hpp"
#include <iostream>
#include <iomanip>

template<typename T>
BinaryNode<T>::BinaryNode(const T data, ptr<BinaryNode> left, ptr<BinaryNode> right)
	: right(right)
	, left(left)
	, data(data)
{
}

template<typename T>
auto BinaryNode<T>::copy_branch(const ptr<const BinaryNode<T>> original) -> void
{
	if (!original) {
		// TODO right.reset();
		// TODO left.reset();
	} else {
		data = original->data;
		left->copy_branch(original->left);
		right->copy_branch(original->right);
	}
}

template<typename T>
auto BinaryNode<T>::graph(const int height) const -> void
{
	if (right)
		right->graph(height + 8);
	std::cout << std::setw(height) << data << std::endl;
	if (left)
		left->graph(height + 8);
}

template<typename T>
auto BinaryNode<T>::print_inorder() const -> void
{
	if (left)
		left->print_inorder();
	std::cout << "\t\t" << data << std::endl;
	if (right)
		right->print_inorder();
}

template<typename T>
auto BinaryNode<T>::print_preorder() const -> void
{
	std::cout << "\t\t" << data <<std::endl;
	if (left)
		left->print();
	if (right)
		right->print();
}

template<typename T>
auto BinaryNode<T>::height() const -> size_t
{
	auto tmp = 0lu;
	if (right)
		tmp = 1lu + right->height();
	if (left)
		tmp = std::max(tmp, 1 + left->height());

	return tmp;
}

template<typename T>
auto BinaryNode<T>::children_count() const -> size_t
{
	auto tmp = 0lu;
	if (right)
		tmp = right->children_count();
	if (left)
		tmp += left->children_count();

	return 1lu + tmp;
}

template<typename T>
auto BinaryNode<T>::leaves_count() const -> size_t
{
	if (is_leaf())
		return 1lu;
	else {
		auto tmp = 0lu;
		if (right)
			tmp = right->leaves_count();
		if (left)
			tmp += left->leaves_count();

		return tmp;
	}
}

template<typename T>
[[nodiscard]] auto BinaryNode<T>::is_leaf() const -> bool
{
	return !left && !right;
}
