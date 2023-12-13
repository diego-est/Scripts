#include <iostream>
#include "../bst.hpp"

int main()
{
	auto b = bst<int>();
	b.insert(5);
	b.insert(4);
	b.insert(5);
	b.insert(6);
	b.insert(12);
	b.remove(5);
	b.insert(5);
	b.insert(14);
	b.insert(6);
	b.insert(10);
	b.graph();
}
