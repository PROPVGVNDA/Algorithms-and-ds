#ifndef QUEUE_H
#define QUEUE_H
#include "../node/node.h"

class queue
{
public:
	queue();
	~queue();
	const int front();
	const int back();
	const bool empty() const;
	size_t get_size() const;
	void push(const int& value);
	int pop();
private:
	node* top;
	size_t size;
};

#endif