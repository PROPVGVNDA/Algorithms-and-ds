#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H
#include "../linked_list/linked_list.h"

class stack_linked_list
{
public:
	stack_linked_list();
	const size_t size() const;
	bool empty() const;
	int top();
	int pop();
	void push(const int& value);
	void display();
private:
	linked_list m_Data;
	size_t m_Size;
};

#endif