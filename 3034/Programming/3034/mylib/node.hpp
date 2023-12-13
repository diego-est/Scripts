#pragma once
#include "data.hpp"

struct Node {
	pointer<Node> link;
	int info;

	Node(int data, pointer<Node> ptr = nullptr) : link(ptr), info(data)
	{
	}
};
