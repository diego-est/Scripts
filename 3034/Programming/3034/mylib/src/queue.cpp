#include "../queue.hpp"
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
