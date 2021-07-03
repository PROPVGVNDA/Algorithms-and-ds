#include "binary_search_node.h"

node::node(const int& value)
{
	m_Data = value;
	m_Left = nullptr;
	m_Right = nullptr;
}

node::~node()
{
	if (m_Left != nullptr) delete m_Left;
	if (m_Right != nullptr) delete m_Right;
}