#include "binary_search_node.h"

node::node(const int& value)
{
	m_Data = value;
	m_Left = nullptr;
	m_Right = nullptr;
}

node::~node()
{
	delete m_Left;
	delete m_Right;
}