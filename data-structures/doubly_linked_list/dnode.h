#ifndef DNODE_H
#define DNODE_H

class dnode
{
public:
	int& value();
	dnode*& get_next();
	dnode*& get_previous();
	explicit dnode(const int& value = 0);
	~dnode();
private:
	int data;
	dnode* next;
	dnode* previous;
};

#endif
