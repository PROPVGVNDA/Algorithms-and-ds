#include "dlinked_list.h"
#include <iostream>

dlinked_list::dlinked_list()
{
	first = nullptr;
	size = 0;
}

dnode* dlinked_list::front()
{
	return first;
}

dnode* dlinked_list::end()
{
	dnode* temp = first;
	while (temp->get_next() != nullptr)
	{
		temp = temp->get_next();
	}
	return temp;
}

dnode* dlinked_list::find(const int& value)
{
	if (empty()) return nullptr;
	dnode* temp = first;
	while (temp != nullptr)
	{
		if (temp->value() == value)
			return temp;
		temp = temp->get_next();
	}
	return nullptr;
}

const size_t dlinked_list::get_size()
{
	return size;
}

void dlinked_list::push_front(const int& value)
{
	if (empty())
	{
		first = new dnode(value);
	}
	else
	{
		dnode* temp = first;
		first = new dnode(value);
		first->get_next() = temp;
		first->get_next()->get_previous() = first;
	}
	size++;
}

void dlinked_list::push_back(const int& value)
{
	dnode* temp = first;
	while (temp->get_next() != nullptr)
	{
		temp = temp->get_next();
	}
	temp->get_next() = new dnode(value);
	temp->get_next()->get_previous() = temp;
	size++;
}

void dlinked_list::insert(dnode*& element, const int& value)
{
	if (element == first)
	{
		dnode* new_node = new dnode(value);
		new_node->get_next() = element;
		element->get_previous() = new_node;
		first = new_node;
	}
	else
	{
		dnode* new_node = new dnode(value);
		new_node->get_previous() = element->get_previous();
		new_node->get_next() = element;
		new_node->get_next()->get_previous() = new_node;
		new_node->get_previous()->get_next() = new_node;
	}
	size++;
}

void dlinked_list::insert_after(dnode*& element, const int& value)
{
	if (element->get_next() == nullptr)
	{
		dnode* new_node = new dnode(value);
		new_node->get_previous() = element;
		element->get_next() = new_node;

	}
	else
	{
		dnode* new_node = new dnode(value);
		new_node->get_previous() = element;
		new_node->get_next() = element->get_next();
		element->get_next() = new_node;
		new_node->get_next()->get_previous() = new_node;
	}
	size++;
}

void dlinked_list::erase(dnode*& element)
{
	if (element == first)
	{
		pop_front();
		return;
	}
	if (element->get_next() == nullptr)
	{
		pop_back();
		return;
	}
	element->get_previous()->get_next() = element->get_next();
	element->get_next()->get_previous() = element->get_previous();
	element->get_next() = nullptr;
	element->get_previous() = nullptr;
	delete element;
}

void dlinked_list::assign(const int& value)
{
	if (empty()) return;
	dnode* temp = first;
	while (temp != nullptr)
	{
		temp->value() = value;
		temp = temp->get_next();
	}
}

void dlinked_list::assign(const size_t& n_size, const int& value)
{
	if (n_size == 0)
	{
		clear();
		return;
	}
	if (n_size == size)
	{
		assign(value);
		return;
	}
	if (n_size < size)
	{
		resize(n_size);
		assign(value);
		return;
	}
	assign(value);
	for (auto t = size; t <= n_size; t++)
	{
		push_back(value);
	}
}

void dlinked_list::resize(const size_t& new_size)
{
	if (new_size >= size) return;
	if (new_size == 0)
	{
		clear();
		return;
	}
	for (auto t = size - new_size; t != 0; t--)
	{
		pop_back();
	}
}

void dlinked_list::pop_front()
{
	if (empty()) return;
	dnode* temp = first->get_next(); // store second node
	first->get_next() = nullptr;
	delete first;
	first = temp; //  assign second node to first
	size--;
}

void dlinked_list::pop_back()
{
	if (empty()) return;
	dnode* temp = first;
	while (temp->get_next() != nullptr)
	{
		temp = temp->get_next();
	}
	temp->get_previous()->get_next() = nullptr;
	delete temp;
	size--;
}

void dlinked_list::clear()
{
	if (empty()) return;
	delete first; // delete first node, eventually deletes all the other nodes
	first = nullptr;
	size = 0;
}

void dlinked_list::display()
{
	if (empty()) return;
	dnode* temp = first;
	while (temp != nullptr)
	{
		std::cout << temp->value() << std::endl;
		temp = temp->get_next();
	}
}

void dlinked_list::display_r()
{
	if (empty()) return;
	dnode* temp = first;
	while (temp->get_next() != nullptr)
	{
		temp = temp->get_next();
	}
	while (temp != nullptr)
	{
		std::cout << temp->value() << std::endl;
		temp = temp->get_previous();
	}
}

bool dlinked_list::empty()
{
	return size == 0;
}
