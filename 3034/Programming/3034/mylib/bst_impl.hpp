#pragma once
#include "bst.hpp"
#include "binary_tree.hpp"
#include <iostream>

template<typename T>
auto bst<T>::search(T value) const -> const ptr<const BinaryNode<T>>
{
	auto current = this->root;

	while (current)
		if (value < current->data)
			current = current->left;
		else if (value > current->data)
			current = current->right;
		else
			return current;

	return nullptr;
}

template<typename T>
auto bst<T>::find_min() const -> T
{
	auto current = ptr<BinaryNode<T>>(this->root);
	while (current->left)
		current = current->left;

	return current->data;
}
template<typename T>
auto bst<T>::find_max() const -> T
{
	auto current = ptr<BinaryNode<T>>(this->root);
	while (current->right)
		current = current->right;

	return current->data;
}

template<typename T>
auto bst<T>::insert(const T item) -> void
{
	if (!this->root) {
		this->root = new BinaryNode<T>(item);
		return;
	}
	auto current = this->root;
	while (current) {
		if (item < current->data)
			if (!current->left) {
				current->left = new BinaryNode<T>(item);
				return;
			} else {
				current = current->left;
			}
		else if (item > current->data)
			if (!current->right) {
				current->right = new BinaryNode<T>(item);
					return;
			} else {
			current = current->right;
			}
		else {
			std::cout << item << ": already in tree.\n";
			return;
		}
	}
}

template<typename T>
auto bst<T>::remove(const T item) -> void
{
	if (! this->empty()) {
		if (! search(item)) {
			std::cerr << item << ": not in tree.\n";
			return;
		}

		auto prev = ptr<BinaryNode<T>>(nullptr);
		auto current = ptr<BinaryNode<T>>(this->root);

		while (current)
			if (item == current->data) {
				break;
			} else {
				prev = current;
				if (item < current->data)
					current = current->left;
				else if (item > current->data)
					current = current->right;
			}

		if (current == this->root)
			remove_from_tree(current);
		else if (current->data < prev->data)
			remove_from_tree(prev->left);
		else
			remove_from_tree(prev->right);
	} else {
		std::cerr << "Tree is empty.\n";
	}
}

template<typename T>
auto bst<T>::remove_from_tree(ptr<const BinaryNode<T>> ptr) -> void
{
	/* leaf */
	if (!ptr->right && !ptr->left) {
		auto kod = ptr;
		ptr = nullptr;
		delete kod;
	/* right is not null */
	} else if (!ptr->right) {
		auto kod = ptr;
		ptr = ptr->left;
		delete kod;
	/* left is not null */
	} else if (!ptr->left) {
		auto kod = ptr;
		ptr = ptr->right;
		delete kod;
	/* both children aren't null */
	} else {
		auto tmp = ptr->right;
		while (tmp->left)
			tmp = tmp->left;

		tmp->left = ptr->left;
		auto kod = ptr;
		ptr = ptr->right;
		delete kod;
	}


}
