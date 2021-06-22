#include "node.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class linked_list
{
public:
	linked_list();
	node* front();
	node* end();
	node* find(const int& value);
	const size_t get_size() const;
	bool empty();
	void clear();
	void assign(const int& value);
	void assign(const int& value, const size_t& number);
	void resize(const size_t& size_to);
	void push_front(const int& value);
	void pop_front();
	void insert_after(node*& element, const int& value);
	void erase_after(node*& element);
	void display();
private:
	node* first;
	size_t size;
};

#endif

