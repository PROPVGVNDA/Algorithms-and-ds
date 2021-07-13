#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../linked_list/linked_list.h"
#include "item.h"
#include <string>

class hash_table
{
public:
	hash_table();
	~hash_table();
	int& at(const std::string& key);
	const std::string search(const int& number) const;
	void add_item(const std::string& key, const int& number);
	void print_table();
	void print_at_index(const std::string& key);
	void remove(const std::string& key);
private:
	const static size_t m_TableSize = 100;
	item* m_Data[m_TableSize];
	size_t hash(const std::string& key);
	size_t items_at_index(const std::string& key);
};

#endif