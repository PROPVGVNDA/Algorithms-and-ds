#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "../node/node.h"

class linked_list
{
public:
	linked_list();
	node::node* front();
	node::node* end();
	node::node* find(const int& value);
	const size_t get_size() const;
	bool empty();
	void clear();
	void assign(const int& value);
	void assign(const int& value, const size_t& number);
	void resize(const size_t& size_to);
	void push_front(const int& value);
	int pop_front();
	void insert_after(node::node*& element, const int& value);
	void erase_after(node::node*& element);
	void display();
private:
	node::node* first;
	size_t size;
};

#endif

