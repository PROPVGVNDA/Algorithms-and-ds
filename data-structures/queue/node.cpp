
#include "node.h"
#include <iostream>

int node::value()
{
	return data;
}

node*& node::get_next()
{
	return next;
}

node::node(const int& value /*= 0*/)
{
	data = value;
	next = nullptr;
}

node::~node()
{
	if (next != nullptr)
	{
		delete next;
		next = nullptr;
	}
	std::cout << "DELETED NODE WITH VALUE " << data << std::endl;
}