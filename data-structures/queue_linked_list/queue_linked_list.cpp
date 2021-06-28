#include "queue_linked_list.h"
#include "../node/node.h"

queue_linked_list::queue_linked_list()
{
	m_Last = nullptr;
	m_Size = 0;
}

void queue_linked_list::enqueue(const int& value)
{
	if (m_Size == 0)
	{
		m_Data.push_front(value);
		m_Last = m_Data.front();
	}
	else
	{
		m_Data.insert_after(m_Last, value);
		m_Last = m_Data.end();
	}
	m_Size++;
}

int queue_linked_list::dequeue()
{
	m_Size--;
	return m_Data.pop_front();
}

void queue_linked_list::display()
{
	m_Data.display();
}

