/* === helpers === */
template <typename T> using pointer = T*;

template <typename T> using reference = T&;

/* === node.hpp === */
struct Node {
	pointer<Node> link;
	int info;

	Node(int data, pointer<Node> ptr = nullptr) : link(ptr), info(data)
	{
	}
};

/* === list.hpp === */
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
		pointer<const Node> other = rhs.cbegin();

		if (other == nullptr)
			m_head = nullptr;
		else {
			m_head = new Node(other->info);
			other = other->link;
		}

		pointer<Node> end = m_head;
		while (other != nullptr) {
			end->link = new Node(other->info);
			end = end->link;
			other = other->link;
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

/* === stack.hpp === */
// #include "list.hpp"

class Stack : public List {
      public:
	/* === constructors and destructors === */
	Stack();
	Stack(reference<const Stack> rhs);
	~Stack();

	/* === non-modifying member functions === */
	[[nodiscard]] auto top() const -> int;

	/* === modifying member functions === */
	auto push(int value) -> void;
	auto pop() -> int;

	/* === operators === */
	auto operator=(reference<const Stack> rhs) -> reference<Stack>;

      protected:
	/* === alias m_top to m_head === */
	pointer<Node>& m_top = m_head;

      private:
	/* === private functions aren't usable by client === */
	auto prepend(int value) -> void;
	auto append(int value) -> void;
	auto remove(int value) -> void;
};

/* === stack.cpp === */
// #include "stack.hpp"

/* === constructors and destructors === */
Stack::Stack() : List()
{
}

Stack::Stack(reference<const Stack> rhs)
	: List()
{
	copy(rhs);
}

Stack::~Stack()
{
	clear();
}

/* === non-modifying member functions === */
[[nodiscard]] auto Stack::top() const -> int
{
	if (not empty())
		return m_top->info;
	else
		return int();
}

/* === modifying member functions === */
auto Stack::push(int value) -> void
{
	m_top = new Node(value, m_top);
	m_size += 1;
}

auto Stack::pop() -> int
{
	if (not empty()) {
		auto ret = m_top->info;

		pointer<Node> kod = m_top;
		m_top = m_top->link;
		delete kod;
		m_size -= 1;

		return ret;
	}
	return int();
}

/* === operator === */
auto Stack::operator=(reference<const Stack> rhs) -> reference<Stack>
{
	copy(rhs);
	return *this;
}

/* === main.cpp === */
// #include stack.hpp
#include <string>

auto display_binary(Stack bs) -> void;
auto read_decimal() -> int;
auto repeated_division(int decimal) -> Stack;

auto main() -> int
{
	auto input = 0;
	auto answer = std::string("");
	do {
		std::cout << "Enter a number: ";
		input = read_decimal();
		auto binary = repeated_division(input);
		display_binary(binary);


		std::cout << "Continue (y/n): ";
		std::cin >> answer;
	} while (answer == "y" || answer == "Y");
	return 0;
}

auto display_binary(Stack bs) -> void
{
	std::cout << "Your number in decimal is: ";
	while (not bs.empty())
		std::cout << bs.pop();
	std::cout << std::endl;
}

auto read_decimal() -> int
{
	auto a = 0;
	std::cin >> a;
	return a;
}

auto repeated_division(int decimal) -> Stack
{
	auto tmp = Stack();
	if (decimal == 0) tmp.push(0);
	while (decimal != 0)
		tmp.push(decimal & 1), decimal >>= 1;
	return tmp;
}
