#include "hash_table.h"
#include <iostream>

size_t hash_table::hash(const std::string& key)
{
	size_t hash = 0;
	for (size_t i = 0; i < key.length(); i++)
	{
		 hash += key[i];
	}
	return hash % m_TableSize;
}

size_t hash_table::items_at_index(const std::string& key)
{
	auto temp = m_Data[hash(key)];
	if (temp->m_Name == "empty") return 0;
	size_t size = 0;
	while (temp != nullptr)
	{
		size++;
		temp = temp->m_Next;
	}
	return size;
}

hash_table::hash_table()
{
	for (size_t i = 0; i < m_TableSize; i++)
	{
		m_Data[i] = new item();
	}
}

hash_table::~hash_table()
{
	for (size_t i = 0; i < m_TableSize; i++)
	{
		delete m_Data[i];
	}
}

int& hash_table::at(const std::string& key)
{
	if (m_Data[hash(key)]->m_Name == "empty") throw std::exception("No element with such index");
	return m_Data[hash(key)]->m_Number;
}

const std::string hash_table::search(const int& number) const
{
	item* temp;
	for (size_t i = 1; i < m_TableSize; i++)
	{
		temp = m_Data[i];
		if (temp->m_Name == "empty") continue;
		do 
		{
			if (temp->m_Number == number) return temp->m_Name;
			temp = temp->m_Next;
		} while (temp != nullptr);
	}
	return "";
}

void hash_table::add_item(const std::string& key, const int& number)
{
	size_t index = hash(key);
	if (m_Data[index]->m_Name == "empty")
	{
		m_Data[index]->m_Name = key;
		m_Data[index]->m_Number = number;
	}
	else
	{
		item* temp = m_Data[index];
		while (temp->m_Next != nullptr)
		{
			temp = temp->m_Next;
		}
		temp->m_Next = new item(key, number);
	}
}

void hash_table::print_table()
{
	for (size_t i = 0; i < m_TableSize; i++)
	{
		auto temp = m_Data[i];
		if (temp->m_Name == "empty") continue;
		print_at_index(temp->m_Name);
	}
}

void hash_table::print_at_index(const std::string& key)
{
	auto temp = m_Data[hash(key)];
	for (size_t i = 0; i < items_at_index(key); i++)
	{
		std::cout << temp->m_Number << "   ";
		temp = temp->m_Next;
	}
	std::cout << std::endl;
}

void hash_table::remove(const std::string& key)
{
	auto temp = m_Data[hash(key)];
	if (temp->m_Name == "empty") return;
	if (temp->m_Next == nullptr)
	{
		delete temp;
		m_Data[hash(key)] = new item();
		return;
	}
	item* prev;
	while (temp->m_Next != nullptr)
	{
		prev = temp;
		temp = temp->m_Next;
	}
	prev->m_Next = nullptr;
	delete temp;
}
