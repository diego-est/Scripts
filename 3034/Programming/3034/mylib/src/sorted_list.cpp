#include "../sorted_list.hpp"
#include <utility>

SortedList::SortedList() : List()
{
}

SortedList::SortedList(reference<const SortedList> sl)
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
