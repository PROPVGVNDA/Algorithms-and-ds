#include "node.h"

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
}
