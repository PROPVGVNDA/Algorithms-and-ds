#include "item.h"

item::item()
{
	m_Name = "empty";
	m_Number = NULL;
	m_Next = nullptr;
}

item::item(const std::string& name, const int& number)
	: m_Name(name), m_Number(number)
{
	m_Next = nullptr;
}

item::~item()
{
	delete m_Next;
}
