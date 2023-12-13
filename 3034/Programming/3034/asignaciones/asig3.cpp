/* === data.hpp === */
// #pragma once

/* esto es el equivalente a:
 * typedef Node* nodePtr;
 * pero reescrito como:
 * pointer<Node>
 * que despues se le puede otorgar qualifier const mas facilmente y menos
 * ambiguo:
 * pointer<const Node>
 * const pointer<Node>
 */
template <typename T> using pointer = T*;

/* lo mismo pero con reference:
 * reference<List>
 * reference<const List>
 */
template <typename T> using reference = T&;

/* === node.hpp === */
// #pragma once
// #include "data.hpp"

struct Node {
	pointer<Node> link;
	int info;

	Node(int data, pointer<Node> ptr = nullptr) : link(ptr), info(data)
	{
	}
};

/* === list.hpp === */
// #pragma once
// #include "data.hpp"
// #include "node.hpp"
#include <iostream>

class List {
      public:
	/* === constructors and destructors === */
	List();
	List(reference<const List> rhs);
	~List();

	/* === non-modifying member functions === */
	[[nodiscard]] auto empty() const -> bool;
	[[nodiscard]] auto search(int value) const -> bool;
	[[nodiscard]] auto length() const -> size_t;
	[[nodiscard]] auto cbegin() const -> pointer<const Node>;
	[[nodiscard]] auto begin() const -> pointer<Node>;
	auto print() const -> void;

	/* === modifying member functions === */
	auto clear() -> void;
	auto copy(reference<const List> rhs) -> void;
	auto prepend(int value) -> void;
	auto append(int value) -> void;
	auto remove(int value) -> void;

	/* === operators === */
	auto operator=(reference<const List> rhs) -> reference<const List>;
	friend auto operator<<(std::ostream& lhs, reference<const List> rhs)
	    -> std::ostream&;
	friend auto operator>>(std::istream& lhs, reference<List> rhs)
	    -> std::istream&;

      protected:
	pointer<Node> m_head;
	size_t m_size;
};

/* === list.cpp === */
// #include "list.hpp"
// #include "data.hpp"
#include <iostream>

/* == Constructors/Destructors == */
List::List() : m_head(nullptr), m_size(0lu)
{
}

List::List(const List& l) : m_head(nullptr), m_size(l.m_size)
{
	pointer<const Node> curr = l.cbegin();
	pointer<Node> end = m_head;

	while (curr != nullptr) {
		end = new Node(curr->info);
		end = end->link;
		curr = curr->link;
	}
}

List::~List()
{
	clear();
}

/* == non-modifying member functions == */
[[nodiscard]] auto List::empty() const -> bool
{
	return m_head == nullptr;
}

[[nodiscard]] auto List::length() const -> std::size_t
{
	return m_size;
}

[[nodiscard]] auto List::search(int value) const -> bool
{
	pointer<const Node> curr = m_head;

	while (curr != nullptr) {
		if (curr->info == value)
			return true;
		else
			curr = curr->link;
	}

	return false;
}

[[nodiscard]] auto List::cbegin() const -> pointer<const Node>
{
	return m_head;
}

[[nodiscard]] auto List::begin() const -> pointer<Node>
{
	return m_head;
}

/* == modifying member functions == */
auto List::clear() -> void
{
	pointer<Node> kod = m_head;

	while (kod != nullptr) {
		m_head = m_head->link;
		delete kod;
		kod = m_head;
	}

	m_size = 0lu;
}

auto List::copy(reference<const List> rhs) -> void
{
	if (rhs.cbegin() != m_head) {
		clear();
		pointer<const Node> curr = rhs.cbegin();
		pointer<Node> end = m_head;

		while (curr != nullptr) {
			end = new Node(curr->info);
			end = end->link;
			curr = curr->link;
		}

		m_size = rhs.m_size;
	}
}

auto List::append(int value) -> void
{
	if (!search(value)) {
		if (m_head == nullptr) {
			m_head = new Node(value);
			return;
		}

		pointer<Node> curr = m_head;

		while (curr->link != nullptr)
			curr = curr->link;

		curr->link = new Node(value);
		m_size += 1;
	}
}

auto List::prepend(int value) -> void
{
	if (!search(value)) {
		pointer<Node> nn = new Node(value, m_head);
		m_head = nn;
		m_size += 1;
	}
}

auto List::remove(int value) -> void
{
	if (empty()) {
		std::cout << "\tEmpty list. Could not remove: " << value
			  << std::endl;

	} else if (!search(value)) {
		std::cout << "Item: " << value << " not found in list.\n";

	} else if (m_head->info == value) {
		pointer<Node> kod = m_head;
		m_head = m_head->link;
		delete kod;
		m_size -= 1;

	} else {
		pointer<Node> prev = m_head;
		pointer<Node> curr = m_head->link;

		while (curr != nullptr) {
			if (curr->info == value) {
				prev->link = curr->link;
				delete curr;
				break;
			}
			prev = curr;
			curr = prev->link;
		}
		m_size -= 1;
	}
}

auto List::print() const -> void
{
	std::cout << *this << std::endl;
}

/* modifying operators */
auto List::operator=(reference<const List> rhs) -> reference<const List>
{
	if (m_head != rhs.cbegin()) {
		if (not empty())
			clear();

		copy(rhs);
	}

	return *this;
}

/* == friend member functions == */
auto operator<<(std::ostream& lhs, reference<const List> rhs) -> std::ostream&
{
	if (rhs.empty()) {
		std::cout << "\tEmpty list. Could not print.\n";

	} else {
		pointer<const Node> curr = rhs.cbegin();

		while (curr != nullptr) {
			lhs << curr->info << std::endl;
			curr = curr->link;
		}
	}

	return lhs;
}

auto operator>>(std::istream& lhs, reference<List> rhs) -> std::istream&
{
	int new_int;

	lhs >> new_int;

	rhs.append(new_int);
	return lhs;
}

/* === sorted_list.hpp === */
// #pragma once
// #include "data.hpp"
// #include "list.hpp"

class SortedList : public List {
      public:
	/* === constructors and destructors === */
	SortedList();
	SortedList(reference<const SortedList> sl);
	~SortedList();

	/* === non-modifying member functions === */
	[[nodiscard]] auto search(int value) const -> bool;

	/* === modifying member functions === */
	auto insert(int value) -> void;

      private:
	/* hide functionality from client in sorted list
	 * you should not be able to append or prepend in a sorted list
	 */
	auto prepend(int value) -> void;
	auto append(int value) -> void;
};

/* === sorted_list.cpp === */
// #include "sorted_list.hpp"
#include <utility>

SortedList::SortedList() : List()
{
}

SortedList::SortedList(reference<const SortedList> sl) : List()
{
	copy(sl);
}

SortedList::~SortedList()
{
	clear();
}

[[nodiscard]] auto SortedList::search(int value) const -> bool
{
	if (empty()) {
		std::cout << "\t Empty list, can not search.\n";

	} else {
		pointer<const Node> curr = m_head;

		while (curr != nullptr) {
			if (curr->info == value)
				return true;
			if (curr->info < value)
				curr = curr->link;
			else
				break;
		}
	}

	return false;
}

auto SortedList::insert(int value) -> void
{
	if (!empty() && search(value)) {
		std::cout << "\tItem already in list.\n";

	} else if (empty() || value < m_head->info) {
		m_head = new Node(value, m_head);
		m_size += 1;

	} else {
		pointer<Node> curr = m_head;

		while (curr->link != nullptr && curr->link->info < value)
			curr = curr->link;

		curr->link = new Node(value, curr->link);
		m_size += 1;
	}
}

/* === main.cpp === */
// #include "list.hpp"
// #include "sorted_list.hpp"
#include <cstdint>
#include <iomanip>
#include <iostream>

/* Menu options */
enum MenuOption {
	None = 0,
	Insert = 1,
	Remove = 2,
	Search = 3,
	Display = 4,
	Size = 5,
	Clear = 6,
	Exit = 7,
};

/* Function prototypes */
auto display_menu() -> MenuOption;
auto execute_option(MenuOption option, reference<SortedList> milista) -> void;

int main()
{
	auto option = MenuOption::None;
	auto lista = SortedList();
	do {
		option = display_menu();
		execute_option(option, lista);

	} while (option != MenuOption::Exit);

	return 0;
}

auto display_menu() -> MenuOption
{
	auto option = MenuOption::None;

	do {
		std::cout << "\n\t<<< LIST OPTIONS >>>\n\n"
			  << "\t1. Insert an item to the list\n"
			  << "\t2. Remove an item from the list\n"
			  << "\t3. Search an item in the list\n"
			  << "\t4. Display the list\n"
			  << "\t5. Display the length of the list\n"
			  << "\t6. Clear the list\n"
			  << "\t7. Exit the Program\n"
			  << "\n\tEnter your choice (1-7): ";

		auto a = 0u;
		if (std::cin >> a)
			option = (MenuOption)a;

		if (option <= MenuOption::None || option > MenuOption::Exit)
			std::cout << "\tERROR: Wrong option. Must be 1-7. Your "
				     "option: "
				  << option << std::endl;

	} while (option == MenuOption::None || option > MenuOption::Exit);

	return option;
}

auto execute_option(MenuOption option, reference<SortedList> sorted_list)
    -> void
{
	auto value = 0;
	switch (option) {
	case Insert:
		std::cout
		    << "What number would you like to append to the list?\n";
		std::cout << "\t> ";
		std::cin >> value;
		sorted_list.insert(value);
		break;
	case Remove:
		std::cout
		    << "What number would you like to remove from the list?\n";
		std::cout << "\t> ";
		std::cin >> value;
		sorted_list.remove(value);
		break;
	case Search:
		std::cout
		    << "What number would you like to search in the list?\n";
		std::cout << "\t> ";
		std::cin >> value;
		if (sorted_list.search(value))
			std::cout << value << " was found in the list.\n";
		else
			std::cout << value << " was not found in the list.\n";
		break;
	case Display:
		std::cout << "Displaying list:\n";
		sorted_list.print();
		break;
	case Size:
		std::cout << "The size of the list is: " << sorted_list.length()
			  << " elements long.\n";
		break;
	case Clear:
		std::cout << "Clearing the list.\n";
		sorted_list.clear();
		break;
	case Exit:
		std::cout << "Exiting. . .\n";
		break;
	case None:
	default:
		break;
	}
}
