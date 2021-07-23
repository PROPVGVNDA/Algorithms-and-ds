#include "linked_list.h"
#include <iostream>
#include <stdexcept>

linked_list::linked_list()
{
	m_Head = nullptr;
	m_Size = 0;
}

linked_list::~linked_list()
{
	delete m_Head;
}

node::node* linked_list::front()
{
	return m_Head;
}

node::node* linked_list::end()
{
	if (empty()) throw std::exception("Object is empty");
	node::node* temp = m_Head;
	while (temp->get_next() != nullptr)
	{
		temp = temp->get_next();
	}
	return temp;
}

node::node* linked_list::find(const int& value)
{
	if (empty()) throw std::exception("Object is empty");
	node::node* temp = m_Head;
	while (temp != nullptr)
	{
		if (temp->value() == value) return temp;
		temp = temp->get_next();
	}
	return nullptr;
}

const size_t linked_list::size() const
{
	return m_Size;
}

bool linked_list::empty()
{
	return m_Head == nullptr;
}

void linked_list::clear()
{
	if (empty()) throw std::exception("Object is empty");
	node::node* temp_next;
	while (m_Head != nullptr)
	{
		temp_next = m_Head->get_next();
		m_Head->get_next() = nullptr;
		delete m_Head;
		m_Head = temp_next;
	}
	m_Size = 0;
}

void linked_list::assign(const int& value)
{
	if (empty()) throw std::exception("Object is empty");
	size_t temp_size = m_Size;
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
	if (empty()) throw std::exception("Object is empty");
	if (size_to == 0)
	{
		clear();
		return;
	}
	if (m_Size <= size_to) throw std::out_of_range("Specified size is less then current size");
	size_t n = 1;
	node::node* temp = m_Head;
	while (n != size_to)
	{
		temp = temp->get_next();
		n++;
	}
	delete temp->get_next();
	temp->get_next() = nullptr;
	m_Size = size_to;
	return;
}

void linked_list::push_front(const int& value)
{
	node::node* nd = new node::node(value);
	if (empty())
	{
		m_Head = nd;
		m_Size++;
		return;
	}
	else
	{
		nd->get_next() = m_Head;
		m_Head = nd;
		m_Size++;
		return;
	}
}

int linked_list::pop_front()
{
	if (empty()) throw std::exception("Object is empty");
	int value = m_Head->value();
	node::node* next = m_Head->get_next();
	m_Head = nullptr;
	delete m_Head;
	m_Head = next;
	m_Size--;
	return value;
}

void linked_list::insert_after(node::node*& element, const int& value)
{
	if (element->get_next() == nullptr)
	{
		element->get_next() = new node::node(value);
		element->get_next()->get_next() = nullptr;
		m_Size++;
		return;
	}
	else
	{
		node::node* temp = element->get_next();
		element->get_next() = new node::node(value);
		element->get_next()->get_next() = temp;
		m_Size++;
		return;
	}
}

void linked_list::erase_after(node::node*& element)
{
	if (element == m_Head)
	{
		node::node* temp_addr = m_Head->get_next()->get_next();
		delete m_Head->get_next();
		m_Head->get_next() = temp_addr;
		m_Size--;
		return;
	}
	if (element->get_next() == nullptr) throw std::exception("Specified element is last element in list");
	node::node* temp_addr = element->get_next()->get_next();
	delete element->get_next();
	element->get_next() = temp_addr;
	m_Size--;
	return;
}

void linked_list::display()
{
	if (empty()) throw std::exception("Object is empty");
	node::node* temp = m_Head;
	while (temp != nullptr)
	{
		std::cout << temp->value() << std::endl;
		temp = temp->get_next();
	}
}

void linked_list::reverse()
{
	if (empty()) throw std::runtime_error("Object is empty");
	if (m_Size == 1) return;
	node::node* prev = nullptr;
	node::node* next = nullptr;
	node::node* current = m_Head;
	while (current != nullptr)
	{
		next = current->get_next();
		current->get_next() = prev;
		prev = current;
		current = next;
	}
	m_Head = prev;
}
