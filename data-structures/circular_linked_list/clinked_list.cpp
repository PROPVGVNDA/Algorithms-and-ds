#include "clinked_list.h"
#include <iostream>

clinked_list::clinked_list()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}

clinked_list::~clinked_list()
{
	clear();
}

node* clinked_list::front()
{
	return first;
}

node* clinked_list::end()
{
	if (empty()) return nullptr;
	return last;
}

node* clinked_list::find(const int& value)
{
	if (empty()) return nullptr;
	node* temp = first;
	do 
	{
		if (temp->value() == value) return temp;
		temp = temp->get_next();
	} while (temp != first);
	return nullptr;
}

const size_t clinked_list::get_size() const
{
	return size;
}

bool clinked_list::empty()
{
	return first == nullptr;
}

void clinked_list::clear()
{
	if (empty()) return;
	node* temp;
	last->get_next() = nullptr;
	while (first != nullptr)
	{
		temp = first->get_next();
		first->get_next() = nullptr;
		delete first;
		first = temp;
	}
	size = 0;
}

void clinked_list::assign(const int& value)
{
	if (empty()) return;
	size_t temp_size = size;
	clear();
	for (size_t i = 0; i < temp_size; i++)
	{
		this->push_front(value);;
	}
}

void clinked_list::assign(const int& value, const size_t& number)
{
	clear();
	for (size_t i = 0; i < number; i++)
	{
		this->push_front(value);
	}
}

void clinked_list::resize(const size_t& size_to)
{
	if (empty()) return;
	if (size_to == 0)
	{
		clear();
		return;
	}
	if (size <= size_to) return;
	int n = 1;
	node* temp = first;
	while (n != size_to)
	{
		temp = temp->get_next();
		n++;
	}
	last->get_next() = nullptr;
	delete temp->get_next();
	last = temp;
	last->get_next() = first;
	size = size_to;
	return;
}

void clinked_list::push_front(const int& value)
{
	node* new_node = new node(value);
	if (empty())
	{
		first = new_node;
		last = first;
		last->get_next() = first;
	}
	else
	{
		new_node->get_next() = first;
		first = new_node;
		last->get_next() = first;
	}
	size++;
}

void clinked_list::pop_front()
{
	if (empty()) return;
	node* next = first->get_next();
	first->get_next() = nullptr;
	delete first;
	first = next;
	last->get_next() = first;
	size--;
}

void clinked_list::insert_after(node*& element, const int& value)
{
	node* new_node = new node(value);
	if (element == last)
	{
		new_node->get_next() = first;
		last->get_next() = new_node;
		last = new_node;
	}
	else
	{
		new_node->get_next() = element->get_next();
		element->get_next() = new_node;
	}
	size++;
}

void clinked_list::erase_after(node*& element)
{
	node* temp_addr = element->get_next()->get_next();
	if (element->get_next() == first)
	{
		first->get_next() = nullptr;
		delete first;
		first = temp_addr;
		last->get_next() = first;
	}
	else if (element->get_next() == last)
	{
		last->get_next() = nullptr;
		delete last;
		last = element;
		last->get_next() = first;
	}
	else
	{
		element->get_next()->get_next() = nullptr;
		delete element->get_next();
		element->get_next() = temp_addr;
	}
	size--;
}

void clinked_list::display()
{
	if (empty()) return;
	node* temp = first;
	do 
	{
		std::cout << temp->value() << std::endl;
		temp = temp->get_next();
	} while (temp != first);
}
