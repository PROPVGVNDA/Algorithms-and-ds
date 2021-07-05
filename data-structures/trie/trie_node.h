#ifndef TRIE_NODE_H
#define TRIE_NODE_H

struct trie_node
{
	trie_node(const char& c);
	~trie_node();
	char m_Char;
	bool m_IsWord;
	trie_node** m_Children;
};

#endif