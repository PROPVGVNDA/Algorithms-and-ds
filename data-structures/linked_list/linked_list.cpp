#include "linked_list.h"
#include <iostream>
#include <stdexcept>

linked_list::linked_list()
{
	first = nullptr;
	size = 0;
}

node* linked_list::front()
{
	return first;
}

node* linked_list::end()
{
	if (empty()) return nullptr;
	node* temp = first;
	while (temp->get_next() != nullptr)
	{
		temp = temp->get_next();
	}
	return temp;
}

node* linked_list::find(const int& value)
{
	if (empty()) return nullptr;
	node* temp = first;
	while (temp != nullptr)
	{
		if (temp->value() == value) return temp;
		temp = temp->get_next();
	}
	return nullptr;
}

const size_t linked_list::get_size() const
{
	return size;
}

bool linked_list::empty()
{
	return first == nullptr;
}

void linked_list::clear()
{
	if (empty()) return;
	node* temp_next;
	while (first != nullptr)
	{
		temp_next = first->get_next();
		first->get_next() = nullptr;
		delete first;
		first = temp_next;
	}
	size = 0;
}

void linked_list::assign(const int& value)
{
	if (empty()) return;
	size_t temp_size = size;
	clear();
	for (size_t i = 0; i < temp_size; i++)
	{
		this->push_front(value);;
	}
}

void linked_list::assign(const int& value, const size_t& number)
{
	clear();
	for (size_t i = 0; i < number; i++)
	{
		this->push_front(value);
	}
}

void linked_list::resize(const size_t& size_to)
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
	delete temp->get_next();
	temp->get_next() = nullptr;
	size = size_to;
	return;
}

void linked_list::push_front(const int& value)
{
	node* nd = new node(value);
	if (empty())
	{
		first = nd;
		size++;
		return;
	}
	else
	{
		nd->get_next() = first;
		first = nd;
		size++;
		return;
	}
}

int linked_list::pop_front()
{
	if (empty()) throw std::exception("Object is empty");
	int value = first->value();
	node* next = first->get_next();
	first = nullptr;
	delete first;
	first = next;
	size--;
	return value;
}

void linked_list::insert_after(node*& element, const int& value)
{
	if (element->get_next() == nullptr)
	{
		element->get_next() = new node(value);
		element->get_next()->get_next() = nullptr;
		size++;
		return;
	}
	else
	{
		node* temp = element->get_next();
		element->get_next() = new node(value);
		element->get_next()->get_next() = temp;
		size++;
		return;
	}
}

void linked_list::erase_after(node*& element)
{
	if (element == first)
	{
		node* temp_addr = first->get_next()->get_next();
		delete first->get_next();
		first->get_next() = temp_addr;
		size--;
		return;
	}
	if (element->get_next() == nullptr) return;
	node* temp_addr = element->get_next()->get_next();
	delete element->get_next();
	element->get_next() = temp_addr;
	size--;
	return;
}

void linked_list::display()
{
	if (empty()) return;
	node* temp = first;
	while (temp != nullptr)
	{
		std::cout << temp->value() << std::endl;
		temp = temp->get_next();
	}
}
