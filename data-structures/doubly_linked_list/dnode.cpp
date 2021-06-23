#include "dnode.h"
#include <iostream>

int& dnode::value()
{
	return data;
}

dnode*& dnode::get_next()
{
	return next;
}

dnode*& dnode::get_previous()
{
	return previous;
}

dnode::dnode(const int& value /*= 0*/)
{
	next = nullptr;
	data = value;
	previous = nullptr;
}

dnode::~dnode()
{
	if (next != nullptr)
	{
		delete next;
	}
	std::cout << "DELETED NODE WITH VALUE " << value() << std::endl;
}
