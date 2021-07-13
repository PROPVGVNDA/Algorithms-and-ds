#include "node.h"

int node::node::value()
{
	return data;
}

node::node*& node::node::get_next()
{
	return next;
}

node::node::node(const int& value /*= 0*/)
{
	data = value;
	next = nullptr;
}

node::node::~node()
{
	if (next != nullptr)
	{
		delete next;
		next = nullptr;
	}
}
