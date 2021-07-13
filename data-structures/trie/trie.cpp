#include "trie.h"

trie::trie()
{
	m_Root = new trie_node('\0');
}

trie::~trie()
{
	delete m_Root;
}

void trie::insert(const std::string& word)
{
	trie_node* current_node = m_Root;
	for (size_t i = 0; i < word.length(); i++)
	{
		char c = word[i];
		if (current_node->m_Children[c - 'a'] == nullptr)
			current_node->m_Children[c - 'a'] = new trie_node(c);
		current_node = current_node->m_Children[c - 'a'];
	}
	current_node->m_IsWord = true;
}

bool trie::search(const std::string& word)
{
	trie_node* node = _get_node(word);
	return node != nullptr && node->m_IsWord;
}

bool trie::starts_with(const std::string& prefix)
{
	return _get_node(prefix) != nullptr;
}

trie_node* trie::_get_node(const std::string& word)
{
	trie_node*& current_node = m_Root;
	for (size_t i = 0; i < word.length(); i++)
	{
		char c = word[i];
		if (current_node->m_Children[c - 'a'] == nullptr) return nullptr;
		current_node = current_node->m_Children[c - 'a'];
	}
	return current_node;
}

