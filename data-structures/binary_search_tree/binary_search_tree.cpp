#include "binary_search_tree.h"
#include "binary_search_node.h"
#include <iostream>
#include <stdexcept>

binary_search_tree::binary_search_tree(const int& value)
{
	m_Root = new node(value);
	m_Size = 1;
}

binary_search_tree::binary_search_tree()
{
	m_Root = nullptr;
	m_Size = 0;
}

binary_search_tree::~binary_search_tree()
{
	if (m_Root != nullptr) delete m_Root;
}

const bool binary_search_tree::empty() const
{
	return m_Size == 0;
}

void binary_search_tree::insert(const int& value)
{
	if (m_Root == nullptr)
	{
		m_Root = new node(value);
	}
	else
	{
		_insert(m_Root, value);
	}
	m_Size++;
}

void binary_search_tree::display()
{
	if (empty()) throw std::bad_exception();
	_inorder(m_Root);
}

const node* binary_search_tree::find(const int& value)
{
	if (empty()) throw std::bad_exception();
	return _find(m_Root, value);
}

void binary_search_tree::_insert(node* nd, const int& value)
{
	if (value == nd->m_Data) return; // if value is already in tree - skip
	if (value < nd->m_Data)
	{
		if (nd->m_Left == nullptr) nd->m_Left = new node(value);
		else
		{
			_insert(nd->m_Left, value);
		}
	}
	else
	{
		if (nd->m_Right == nullptr) nd->m_Right = new node(value);
		else
		{
			_insert(nd->m_Right, value);
		}
	}
}

void binary_search_tree::_inorder(node* nd)
{
	if (nd == nullptr) return;
	_inorder(nd->m_Left);
	std::cout << nd->m_Data << std::endl;
	_inorder(nd->m_Right);
}

const node* binary_search_tree::_find(node* nd, const int& value)
{
	if (nd == nullptr || nd->m_Data == value) return nd; // if nd == nullptr, then value is not in tree
	if (value < nd->m_Data) return _find(nd->m_Left, value);
	if (value > nd->m_Data) return _find(nd->m_Right, value);
	return nullptr;
}
