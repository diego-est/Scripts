#if 0
#include "../binary_tree.hpp"
#include <iostream>

template<typename T>
btree<T>::btree()
	: root(nullptr)
{
}

template<typename T>
btree<T>::btree(ref<const btree> original)
{
	root->copy_branch(original.root);
}

template<typename T>
btree<T>::~btree()
{
	root.reset();
}

template<typename T>
auto btree<T>::operator = (ref<const btree> rhs) -> ref<const btree>
{
	if (this != &rhs) {
		root.reset();

                root = BinaryNode<T>(rhs.root->data);
		root->copy_branch(rhs.root);
	}
	return *this;
}

template<typename T>
[[nodiscard]] auto btree<T>::empty() const -> bool
{
	return root.get() == nullptr;
}

template<typename T>
auto btree<T>::height() const -> int
{
	return root ? root->height() : -1;
}

template<typename T>
auto btree<T>::leaves() const -> size_t
{
	return root ? root->count_children() : 0;
}

template<typename T>
auto btree<T>::print_ascending() const -> void
{
	if (empty())
		std::cout << "\tEmpty tree, cannot display.\n";
	else {
		std::cout << "\tDisplaying tree in descending order.\n";
		root->print_inorder();
	}
}

template<typename T>
auto btree<T>::print_descending() const -> void
{
	if (empty())
		std::cout << "\tEmpty tree, cannot display.\n";
	else {
		std::cout << "\tDisplaying tree in descending order.\n";
		root->print_preorder();
	}
}

template<typename T>
auto btree<T>::graph() const -> void
{
	if (empty())
		std::cout << "\tEmpty tree. cannot graph.\n";
	else
		root->graph(0);
}
#endif
