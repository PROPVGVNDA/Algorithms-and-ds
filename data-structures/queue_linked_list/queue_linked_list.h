#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H
#include "../linked_list/linked_list.h"

class queue_linked_list
{
public:
	queue_linked_list();
	void enqueue(const int& value);
	int dequeue();
	void display();
private:
	linked_list m_Data;
	node::node* m_Last;
	size_t m_Size;
};

#endif