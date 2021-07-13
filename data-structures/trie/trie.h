#ifndef TRIE_H
#define TRIE_H
#include "trie_node.h"
#include <string>

class trie
{
public:
	trie();
	~trie();
	void insert(const std::string& word);
	bool search(const std::string& word);
	bool starts_with(const std::string& prefix);
private:
	trie_node* m_Root;
	trie_node* _get_node(const std::string& word);

};

#endif