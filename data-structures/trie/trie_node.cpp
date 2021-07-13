#include "trie_node.h"

trie_node::trie_node(const char& c)
{
	m_Char = c;
	m_IsWord = false;
	m_Children = new trie_node * [26]{};
}

trie_node::~trie_node()
{
// 	for (size_t i = 0; i < 26; i++)
// 	{
// 		delete m_Children[i];
// 	}
	delete[] m_Children;
}

