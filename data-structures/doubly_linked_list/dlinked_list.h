#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H
#include "dnode.h"

class dlinked_list
{
public:
	dlinked_list();
	dnode* front();
	dnode* end();
	dnode* find(const int& value);
	const size_t get_size();
	void push_front(const int& value);
	void push_back(const int& value);
	void insert(dnode*& element, const int& value);
	void insert_after(dnode*& element, const int& value);
	void erase(dnode*& element);
	void assign(const int& value);
	void assign(const size_t& n_size, const int& value);
	void resize(const size_t& new_size);
	void pop_front();
	void pop_back();
	void clear();
	void display();
	void display_r();
	bool empty();
private:
	dnode* first;
	size_t size;
};

#endif

