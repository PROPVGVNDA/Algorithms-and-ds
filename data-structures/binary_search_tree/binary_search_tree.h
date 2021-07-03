#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH TREE
#include "binary_search_node.h"

class binary_search_tree
{
public:
	binary_search_tree();
	binary_search_tree(const int& value);
	~binary_search_tree();
	const bool empty() const;
	void insert(const int& value);
	void display();
	const node* find(const int& value);
private:
	node* m_Root;
	size_t m_Size;
	void _insert(node* nd, const int& value);
	void _inorder(node* nd);
	const node* _find(node* nd, const int& value);
};

#endif // BINARY_SEARCH_TREE
