/* === data.hpp === */

template <typename T> using pointer = T*;

template <typename T> using reference = T&;

/* === node.hpp === */
// #include "data.hpp"

struct Node {
	pointer<Node> link;
	int info;

	Node(int data, pointer<Node> ptr = nullptr) : link(ptr), info(data)
	{
	}
};

/* === list.hpp === */
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
// #include "../list.hpp"
// #include "../data.hpp"
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
	auto num = 0;
	lhs >> num;
	rhs.append(num);
	return lhs;
}


/* === queue.hpp === */
// #include "list.hpp"
// #include "data.hpp"

class Queue : public List {
      public:
	Queue();
	Queue(reference<const Queue> rhs);
	~Queue();
	/* === non-modifying member functions === */
	// [[nodiscard]] auto empty() const -> bool;
	auto front() const -> int;
	auto back() const -> int;

	/* === modifying member functions === */
	auto clear() -> void;
	auto enqueue(int val) -> void;
	auto dequeue() -> void;

	/* === operators === */
	auto operator=(reference<const Queue> rhs) -> reference<const Queue>;
	auto operator==(reference<const Queue> rhs) -> bool;

      protected:
	pointer<Node>& m_front = m_head;
	pointer<Node> m_rear;

	auto copy(reference<const Queue> rhs) -> void;

      private:
	auto prepend(int val) -> void;
	auto append(int val) -> void;
	auto remove(int val) -> void;
};

/* === queue.cpp === */
// #include "../queue.hpp"
#include <utility>

Queue::Queue()
	: List()
	, m_rear(nullptr)
{
}

Queue::Queue(reference<const Queue> rhs)
	: List()
{
	copy(rhs);
}

Queue::~Queue()
{
	clear();
}

auto Queue::front() const -> int
{
	if (not empty())
		return m_front->info;
	else
		return int();
}

auto Queue::back() const -> int
{
	if(not empty())
		return m_rear->info;
	else
		return int();
}

/* === modifying member functions === */
auto Queue::clear() -> void
{
	List::clear();
	m_rear = nullptr;
}

auto Queue::copy(reference<const Queue> rhs) -> void
{
	List::copy(rhs);

	m_rear = m_front;
	if (m_front != nullptr and m_front->link == nullptr)
		while (m_rear != nullptr)
			m_rear = m_rear->link;
}

auto Queue::enqueue(int val) -> void
{
	if (not empty()) {
		m_rear->link = new Node(val);
		m_rear = m_rear->link;
	} else {
		m_rear = m_head = new Node(val);
	}
	m_size++;
}

auto Queue::dequeue() -> void
{
	if (not empty()) {
		if (length() == 1)
			m_rear = nullptr;

		pointer<Node> kod = m_front;
		m_front = m_front->link;
		delete kod;
	} else {
		m_rear = nullptr;
	}
	m_size--;
}

/* === operators === */
auto Queue::operator=(reference<const Queue> rhs) -> reference<const Queue>
{
	if (this != &rhs) {
		if(not empty())
			clear();
		copy(rhs);
	}

	return *this;
}

auto Queue::operator==(reference<const Queue> rhs) -> bool
{
	return this == &rhs;
}

/* === main.cpp === */

//	
//	Menu options
//
enum MenuOpt {
	None = 0,
	Enqueue,
	Dequeue,
	Front,
	Back,
	Size,
	Display,
	Clear,
	Exit
};

//	Function prototypes.

auto display_menu() -> MenuOpt;
//	NO recibe nada, presenta menu,
//	recoge y devuelve opcio
//	Se incluye más abajo.

auto execute_option(MenuOpt option, Queue& milista) -> void;
//	Recibe la opcion del menu y
//	la lista a manipular.
//	La lista puede ser UNLList o SOLList.
//	Le corresponde a usted codificarla.	

auto main() -> int {
	auto option = MenuOpt::None;
	auto lista = Queue();

	do {
		option = display_menu();
		execute_option(option, lista);
	} while (option != MenuOpt::Exit);

	return 0 ;
}

auto display_menu() -> MenuOpt
{
	auto option = 0;

	do {
		std::cout << "\n\t<<< QUEUE OPTIONS >>>\n\n"
			<< "\t1. Insert an item in the queue\n"
			<< "\t2. Remove an item from the queue\n"
			<< "\t3. First item in the queue\n"
			<< "\t4. Last item in the queue\n"
			<< "\t5. Length of the queue\n"
			<< "\t6. Display the queue\n"
			<< "\t7. Clear the queue\n"
			<< "\t8. Exit the Program\n"
			<< "\n\tEnter your choice (1-8): ";

	std::cin >> option;
		if (option < MenuOpt::Enqueue || option > MenuOpt::Exit)
			std::cout << "\tERROR: Wrong option. Must be 1-7.\n" ;

	} while (option < MenuOpt::Enqueue || option > MenuOpt::Exit);

	return (MenuOpt)option;
}

void execute_option(MenuOpt option, Queue& q)
{
	auto value = 0;
	switch (option) {
		case Enqueue:
			std::cout << "\n\tInput number to enqueue: ";
			std::cin >> value;
			q.enqueue(value);
			break;
		case Dequeue:
			q.dequeue();
			break;
		case Front:
			if (not q.empty()) {
				std::cout << "\n\tFront value is: " << q.front()
					<< "\n";
			} else {
				std::cout << "\n\tStack is empty, could not get"
					" front.\n";
			}
			break;
		case Back:
			if (not q.empty()) {
				std::cout << "\n\tBack value is: " << q.back()
					<< "\n";
			} else {
				std::cout << "\n\tStack is empty, could not get"
					" back.\n";
			}
			break;
		case Size:
			std::cout << "\n\tThe length of the queue is: "
				<< q.length() << "\n";
			break;
		case Display:
			q.print();
			break;
		case Clear:
			q.clear();
			break;
		default:
			break;

	}
}
