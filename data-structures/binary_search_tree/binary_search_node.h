#ifndef BINARY_SEARCH_NODE
#define BINARY_SEARCH_NODE

struct node
{
	node(const int& value);
	~node();
	int m_Data;
	node* m_Left;
	node* m_Right;
};

#endif // BINARY_SEARCH_NODE
