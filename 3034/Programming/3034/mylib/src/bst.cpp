#if 0
#include "../bst.hpp"
#include "../binary_tree.hpp"
#include <iostream>

template<typename T>
auto bst<T>::search(T value) const -> std::weak_ptr<BinaryNode<T>>
{
	auto current = std::weak_ptr(this->root);

	while (current.get())
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
auto bst<T>::insert(T item) -> void
{
	auto current = ptr<BinaryNode<T>>(this->root);
	while (current) {
		if (item < current->data)
			current = current->left;
		else if (item > current->data)
			current = current->right;
		else {
			std::cerr << item << ": already in tree.\n";
			return;
		}
	}
	current = std::make_unique(item);
}

template<typename T>
auto bst<T>::remove(T item) -> void
{
	if (this->empty()) {
		auto prev = BinaryNode<T>();
		auto current = ptr<BinaryNode<T>>(this->root);
		auto found = false;

		while (current && !found)
			if (item == current->data)
				found = true;
			else {
				prev = current;
				if (item < current->data)
					current = current->left;
				else if (item > current->data)
					current = current->right;
			}

		if(! found)
			std::cout << item << ": not in tree.\n";
		else {
			if (current == this->root)
				remove_from_tree(current);
			else if (current < prev->data)
				remove_from_tree(prev->left);
			else
				remove_from_tree(prev->right);
		}
	} else {
		std::cerr << item << ": not in tree.\n";
	}
}
#endif
