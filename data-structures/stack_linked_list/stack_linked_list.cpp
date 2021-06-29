#include "stack_linked_list.h"
#include <stdexcept>

stack_linked_list::stack_linked_list()
{
	m_Data = linked_list{};
	m_Size = 0;
}

const size_t stack_linked_list::size() const
{
	return m_Size;
}

bool stack_linked_list::empty() const
{
	return m_Size == 0;
}

int stack_linked_list::top()
{
	if (empty()) throw std::out_of_range("Object is empty");
	return m_Data.front()->value();
}

int stack_linked_list::pop()
{
	if (empty()) throw std::out_of_range("Object is empty");
	m_Size--;
	return m_Data.pop_front();
}

void stack_linked_list::push(const int& value)
{
	m_Size++;
	m_Data.push_front(value);
}

void stack_linked_list::display()
{
	if (empty()) throw std::out_of_range("Object is empty");
	m_Data.display();
}

