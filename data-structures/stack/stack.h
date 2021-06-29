#ifndef STACK_H
#define STACK_H
#include "../node/node.h"

class stack
{
public:
	stack();
	const size_t size() const;
	bool empty() const;
	int pop();
	const int top() const;
	void push(const int& value);
	void display() const;
private:
	node* m_Top;
	size_t m_Size;
};

#endif