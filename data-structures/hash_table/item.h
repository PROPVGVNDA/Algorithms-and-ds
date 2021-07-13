#ifndef ITEM_H
#define ITEM_H

#include <string>

struct item
{
	item();
	item(const std::string& name, const int& number);
	~item();
	std::string m_Name;
	int m_Number;
	item* m_Next;
};

#endif // ifndef ITEM_H

