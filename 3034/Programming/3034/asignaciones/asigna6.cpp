/* === data.hpp === */
#include <cstdint>

template <typename T> using ptr = T*;
template <typename T> using ref = T&;
using size_t = std::size_t;

template <typename T> auto garbage() -> T
{
	auto kod = new T;
	auto tmp = *kod;
	delete kod;
	kod = nullptr;
	return tmp;
}

/* === Binary Node class === */
// #pragma once

template <typename T> struct BinaryNode {
	ptr<BinaryNode> right;
	ptr<BinaryNode> left;
	T data;

	BinaryNode(const T data, ptr<BinaryNode> left = nullptr,
		   ptr<BinaryNode> right = nullptr);

	/* non-modifying member functions */
	auto print_inorder() const -> void;
	auto print_preorder() const -> void;
	auto print_revorder() const -> void;
	auto graph(const int height) const -> void;
	auto height() const -> size_t;
	auto children_count() const -> size_t;
	auto leaves_count() const -> size_t;
	[[nodiscard]] auto is_leaf() const -> bool;

	/* modifying member functions */
	auto destroy_node() -> void;
	auto copy_branch(const ptr<const BinaryNode<T>> original) -> void;
};

// #include "binary_node_impl.hpp"

/* === Binary Node implementation === */
// #pragma once
// #include "binary_node.hpp"
#include <iomanip>
#include <iostream>

template <typename T>
BinaryNode<T>::BinaryNode(const T data, ptr<BinaryNode> left,
			  ptr<BinaryNode> right)
    : right(right), left(left), data(data)
{
}

template <typename T>
auto BinaryNode<T>::copy_branch(const ptr<const BinaryNode<T>> original) -> void
{
	if (!original) {
		if (right)
			right->destroy_node();
		if (left)
			left->destroy_node();
	} else {
		data = original->data;
		left->copy_branch(original->left);
		right->copy_branch(original->right);
	}
}

template <typename T> auto BinaryNode<T>::destroy_node() -> void
{
	if (right)
		right->destroy_node();
	if (left)
		left->destroy_node();
	if (right)
		delete right, right = nullptr;
	if (left)
		delete left, left = nullptr;
}

template <typename T> auto BinaryNode<T>::graph(const int height) const -> void
{
	if (right)
		right->graph(height + 8);
	std::cout << std::setw(height) << data << std::endl;
	if (left)
		left->graph(height + 8);
}

template <typename T> auto BinaryNode<T>::print_inorder() const -> void
{
	if (left)
		left->print_inorder();
	std::cout << "\t\t" << data << std::endl;
	if (right)
		right->print_inorder();
}

template <typename T> auto BinaryNode<T>::print_preorder() const -> void
{
	std::cout << "\t\t" << data << std::endl;
	if (left)
		left->print_preorder();
	if (right)
		right->print_preorder();
}

template <typename T> auto BinaryNode<T>::print_revorder() const -> void
{
	if (right)
		right->print_revorder();
	std::cout << "\t\t" << data << std::endl;
	if (left)
		left->print_revorder();
}

template <typename T> auto BinaryNode<T>::height() const -> size_t
{
	auto tmp = 0lu;
	if (right)
		tmp = 1lu + right->height();
	if (left)
		tmp = std::max(tmp, 1 + left->height());

	return tmp;
}

template <typename T> auto BinaryNode<T>::children_count() const -> size_t
{
	auto tmp = 0lu;
	if (right)
		tmp = right->children_count();
	if (left)
		tmp += left->children_count();

	return 1lu + tmp;
}

template <typename T> auto BinaryNode<T>::leaves_count() const -> size_t
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

template <typename T> [[nodiscard]] auto BinaryNode<T>::is_leaf() const -> bool
{
	return !left && !right;
}

/* === Binary Tree class === */
// #pragma once
// #include "binary_node.hpp"

template <typename T> class btree {
      protected:
	ptr<BinaryNode<T>> root;
	auto copy(ref<const btree> rhs) -> ref<const btree>;

      public:
	btree();
	btree(ref<const btree> original);
	~btree();

	/* non-modifying member functions */
	[[nodiscard]] auto empty() const -> bool;
	auto height() const -> long int;
	auto leaves() const -> size_t;
	auto nodes() const -> size_t;

	auto print_ascending() const -> void;
	auto print_descending() const -> void;
	auto print_inorder() const -> void;
	auto graph() const -> void;

	/* modifying member functions */
	auto operator=(ref<const btree> rhs) -> ref<const btree>;
	auto clear() -> void;
};

// #include "binary_tree_impl.hpp"

/* === Binary Tree implementation === */
// #pragma once
// #include "binary_tree.hpp"
#include <iostream>

template <typename T> btree<T>::btree() : root(nullptr)
{
}

template <typename T> btree<T>::btree(ref<const btree> original)
{
	root->copy_branch(original.root);
}

template <typename T> btree<T>::~btree()
{
	if (root)
		root->destroy_node();
}

template <typename T>
auto btree<T>::operator=(ref<const btree> rhs) -> ref<const btree>
{
	if (this != &rhs) {
		if (root)
			root->destroy_node();

		root = BinaryNode<T>(rhs.root->data);
		root->copy_branch(rhs.root);
	}
	return *this;
}

template <typename T> auto btree<T>::clear() -> void
{
	if (root)
		root->destroy_node();
	delete root;
	root = nullptr;
}

template <typename T> [[nodiscard]] auto btree<T>::empty() const -> bool
{
	return root == nullptr;
}

template <typename T> auto btree<T>::height() const -> long int
{
	return root ? root->height() : -1;
}

template <typename T> auto btree<T>::leaves() const -> size_t
{
	return root ? root->leaves_count() : 0;
}

template <typename T> auto btree<T>::nodes() const -> size_t
{
	return root ? root->children_count() : 0;
}

template <typename T> auto btree<T>::print_ascending() const -> void
{
	if (empty())
		std::cout << "\tEmpty tree, cannot display.\n";
	else {
		std::cout << "\tDisplaying tree in descending order.\n";
		root->print_inorder();
	}
}

template <typename T> auto btree<T>::print_descending() const -> void
{
	if (empty())
		std::cout << "\tEmpty tree, cannot display.\n";
	else {
		std::cout << "\tDisplaying tree in descending order.\n";
		root->print_revorder();
	}
}

template <typename T> auto btree<T>::graph() const -> void
{
	if (empty())
		std::cout << "\tEmpty tree. cannot graph.\n";
	else
		root->graph(0);
}

/* === Binary Search Tree class === */
// #pragma once
// #include "binary_node.hpp"
// #include "binary_tree.hpp"

template <typename T> class bst : public btree<T> {
      public:
	/* non-modifying member functions */
	auto search(const T value) const -> ptr<const BinaryNode<T>>;
	auto find_min() const -> T;
	auto find_max() const -> T;

	/* modifying member functions */
	auto insert(const T item) -> void;
	auto remove(const T item) -> void;

      private:
	auto remove_from_tree(ref<ptr<BinaryNode<T>>> ptr) -> void;
};

// #include "bst_impl.hpp"

/* === Binary Search Tree implementation === */
// #pragma once
// #include "bst.hpp"
// #include "binary_tree.hpp"
#include <iostream>

template <typename T>
auto bst<T>::search(T value) const -> ptr<const BinaryNode<T>>
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

template <typename T> auto bst<T>::find_min() const -> T
{
	if (this->root) {
		auto current = ptr<BinaryNode<T>>(this->root);
		while (current->left)
			current = current->left;

		return current->data;
	}
	return garbage<int>();
}
template <typename T> auto bst<T>::find_max() const -> T
{
	if (this->root) {
		auto current = ptr<BinaryNode<T>>(this->root);
		while (current->right)
			current = current->right;

		return current->data;
	}
	return garbage<int>();
}

template <typename T> auto bst<T>::insert(const T item) -> void
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

template <typename T> auto bst<T>::remove(const T item) -> void
{
	if (!this->empty()) {
		if (!search(item)) {
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

template <typename T>
auto bst<T>::remove_from_tree(ref<ptr<BinaryNode<T>>> ptr) -> void
{
	auto kod = ptr;
	/* leaf */
	if (ptr->is_leaf())
		ptr = nullptr;
	/* right is not null */
	else if (!ptr->right)
		ptr = ptr->left;
	/* left is not null */
	else if (!ptr->left)
		ptr = ptr->right;
	/* both children aren't null */
	else {
		std::cout << "both null\n";
		auto tmp = ptr->right;
		while (tmp->left)
			tmp = tmp->left;

		tmp->left = ptr->left;
		kod = ptr;
		ptr = ptr->right;
	}

	delete kod;
	kod = nullptr;
}

/* === Client === */
enum class MenuOpt {
	None,
	Insert,
	Remove,
	FindMin,
	FindMax,
	Search,
	NodeCount,
	LeafCount,
	Height,
	IsEmpty,
	Graph,
	PrintAsc,
	PrintDes,
	Clear,
	Exit,
};

auto display_menu() -> MenuOpt;

template <typename T>
auto execute_option(MenuOpt option, ref<bst<T>> my_bst) -> void;

auto main() -> int
{
	auto option = MenuOpt::None;
	auto my_bst = bst<int>();
	my_bst.insert(4);
	my_bst.insert(2);
	my_bst.insert(6);
	my_bst.insert(1);
	my_bst.insert(3);
	my_bst.insert(5);
	my_bst.insert(7);
	my_bst.insert(10);

	do {
		option = display_menu();
		execute_option(option, my_bst);
	} while (option != MenuOpt::Exit);

	return 0;
}

auto display_menu() -> MenuOpt
{
	auto option = 0;
	do {
		std::cout
		    << "\n\t<<< BST OPTIONS >>>\n\n"
		    << "\t1. Insert an item into the binary search tree.\n"
		    << "\t2. Remove an item from the binary search tree.\n"
		    << "\t3. Find the smallest item in the binary search "
		       "tree.\n"
		    << "\t4. Find the largest item in the binary search tree.\n"
		    << "\t5. Search for an item in the binary search tree.\n"
		    << "\t6. Count nodes in the binary search tree.\n"
		    << "\t7. Count leaves in the binary search tree.\n"
		    << "\t8. Height of the binary search tree.\n"
		    << "\t9. Check if the binary search tree is empty.\n"
		    << "\t10. Graph the binary search tree.\n"
		    << "\t11. Print the binary search tree in inorder order.\n"
		    << "\t12. Print the binary search tree in reverse order.\n"
		    << "\t13. Clear the binary search tree.\n"
		    << "\t14. Exit the Program\n"
		    << "\n\tEnter your choice (1-8): ";
		std::cin >> option;

		switch (option) {
		case 1:
			return MenuOpt::Insert;
		case 2:
			return MenuOpt::Remove;
		case 3:
			return MenuOpt::FindMin;
		case 4:
			return MenuOpt::FindMax;
		case 5:
			return MenuOpt::Search;
		case 6:
			return MenuOpt::NodeCount;
		case 7:
			return MenuOpt::LeafCount;
		case 8:
			return MenuOpt::Height;
		case 9:
			return MenuOpt::IsEmpty;
		case 10:
			return MenuOpt::Graph;
		case 11:
			return MenuOpt::PrintAsc;
		case 12:
			return MenuOpt::PrintDes;
		case 13:
			return MenuOpt::Clear;
		case 14:
			return MenuOpt::Exit;
		default:
			std::cout << "\tERR: Wrong option. Must be 1-7.\n";
		}
	} while (true);
}

template <typename T>
auto execute_option(MenuOpt option, ref<bst<T>> my_bst) -> void
{
	switch (option) {
	case MenuOpt::Insert: {
		auto val = int();
		std::cout << "Insert value: ";
		std::cin >> val;
		my_bst.insert(val);
		break;
	}
	case MenuOpt::Remove: {
		auto val = int();
		std::cout << "Remove value: ";
		std::cin >> val;
		my_bst.remove(val);
		break;
	}
	case MenuOpt::FindMin: {
		std::cout << "Minimum value: " << my_bst.find_min()
			  << std::endl;
		break;
	}
	case MenuOpt::FindMax: {
		std::cout << "Maximum value: " << my_bst.find_max()
			  << std::endl;
		break;
	}
	case MenuOpt::Search: {
		auto val = int();
		std::cout << "Value to search for: ";
		std::cin >> val;
		auto node = my_bst.search(val);
		std::cout << "Node" << (node ? " was " : " not ")
			  << "found in tree.\n";
		break;
	}
	case MenuOpt::NodeCount: {
		std::cout << "Node count: " << my_bst.nodes() << std::endl;
		break;
	}
	case MenuOpt::LeafCount: {
		std::cout << "Leaf count: " << my_bst.leaves() << std::endl;
		break;
	}
	case MenuOpt::Height: {
		std::cout << "Height of binary search tree: " << my_bst.height()
			  << std::endl;
		break;
	}
	case MenuOpt::IsEmpty: {
		std::cout << "The tree is empty: " << std::boolalpha
			  << my_bst.empty() << std::endl;
		break;
	}
	case MenuOpt::Graph: {
		std::cout << "Graphing tree:\n";
		my_bst.graph();
		break;
	}
	case MenuOpt::PrintAsc: {
		std::cout << "Printing tree in ascending order\n";
		my_bst.print_ascending();
		break;
	}
	case MenuOpt::PrintDes: {
		std::cout << "Printing tree in descending order.\n";
		my_bst.print_descending();
		break;
	}
	case MenuOpt::Clear: {
		my_bst.clear();
		break;
	}
	default:
		break;
	}
}
