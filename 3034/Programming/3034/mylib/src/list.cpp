#include "../list.hpp"
#include "../data.hpp"
#include <iostream>
#include <optional>

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
	std::optional<int> new_int = std::nullopt;

	do {
		lhs >> new_int.value();
	} while (not new_int.has_value());

	rhs.append(new_int.value());
	return lhs;
}
