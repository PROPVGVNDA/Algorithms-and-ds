#include "queue.h"
#include <stdexcept>

queue::queue()
{
	top = nullptr;
	size = 0;
}

queue::~queue()
{
	delete top;
}

const int queue::front()
{
	return top != nullptr ? top->value() : throw std::out_of_range("Object is empty");
}

const int queue::back()
{
	if (empty()) throw std::out_of_range("Object is empty");
	node::node* temp = top;
	// iterate through all element in the queue, until an element points to nullptr, which means it is the last element in the queue
	while (temp->get_next() != nullptr)
	{
		temp = temp->get_next();
	}
	return temp->value();
}

const bool queue::empty() const
{
	return size == 0;
}

size_t queue::get_size() const
{
	return size;
}

void queue::push(const int& value)
{
	node::node* new_node = new node::node(value);
	if (empty())
	{
		top = new_node;
	}
	else
	{
		// If queue is not empty, iterate to the last element, and set it to point to new node
		auto temp = top;
		while (temp->get_next() != nullptr)
		{
			temp = temp->get_next();
		}
		temp->get_next() = new_node;
	}
	size++;
}

int queue::pop()
{
	if (empty()) throw std::out_of_range("Object is empty");
	auto result = top->value(); // save int value of the top queue element
	auto temp = top->get_next(); // save next element in the queue
	top->get_next() = nullptr; // set to nullptr to correctly delete the element
	delete top; 
	top = temp; // set new top element in the queue
	size--;
	return result;
}

