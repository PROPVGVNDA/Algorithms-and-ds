#include "stack.h"
#include <stdexcept>
#include <iostream>

stack::stack()
{
	m_Top = nullptr;
	m_Size = 0;
}

const size_t stack::size() const
{
	return m_Size;
}

bool stack::empty() const
{
	return m_Size == 0;
}

const int stack::top() const
{
	return m_Top->value();
}

int stack::pop()
{
	if (empty()) throw std::out_of_range("Object is empty");
	auto value = m_Top->value(); // save value of top node
	node::node* next = m_Top->get_next(); // save pointer to next node of top node, if empty, saves nullptr
	m_Top->get_next() = nullptr; // set top node to nullptr in order to correctly free memory
	delete m_Top; 
	m_Top = next;
	m_Size--;
	return value;
}

void stack::push(const int& value)
{
	node::node* new_node = new node::node(value);
	if (empty())
	{
		m_Top = new_node;
	}
	else
	{
		new_node->get_next() = m_Top;
		m_Top = new_node;
	}
	m_Size++;
}

void stack::display() const
{
	if (empty()) throw std::out_of_range("Object is empty");
	node::node* temp = m_Top;
	while (temp != nullptr)
	{
		std::cout << temp->value() << std::endl;
		temp = temp->get_next();
	}
}

