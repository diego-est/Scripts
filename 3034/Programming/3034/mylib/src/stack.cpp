#include "../stack.hpp"
#include "../data.hpp"

/* === constructors and destructors === */
Stack::Stack() : List()
{
}

Stack::Stack(reference<const Stack> rhs)
{
	copy(rhs);
}

Stack::~Stack()
{
	clear();
}

/* === non-modifying member functions === */
[[nodiscard]] auto Stack::top() const -> std::optional<int>
{
	if (not empty())
		return m_top->info;
	else
		return std::nullopt;
}

/* === modifying member functions === */
auto Stack::push(int value) -> void
{
	m_top = new Node(value, m_top);
	m_size += 1;
}

auto Stack::pop() -> std::optional<int>
{
	if (not empty()) {
		auto ret = m_top->info;
		pointer<Node> kod = m_top;
		m_top = m_top->link;
		delete kod;
		m_size -= 1;
		return ret;
	}
	return std::nullopt;
}

/* === operator === */
auto Stack::operator=(reference<const Stack> rhs) -> reference<Stack>
{
	copy(rhs);
	return *this;
}
