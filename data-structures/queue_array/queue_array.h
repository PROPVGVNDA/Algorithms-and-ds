#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
#include "../array/m_array.h"
#include <stdexcept>
#include <iostream>

template <typename T, size_t S>
class queue_array
{
public:
	void enqueue(const T& value);
	int deque();
	void display() const;
private:
	m_array<T, S> m_Data;
	size_t m_Size = 0;
};

template <typename T, size_t S>
void queue_array<T, S>::enqueue(const T& value)
{
	if (m_Size == S) throw std::exception("Object is out of space");
	if (m_Size == 0)
	{
		m_Data[0] = value;
	}
	else
	{
		for (size_t i = m_Size; i > 0; i--)
		{
			m_Data[i] = m_Data[i - 1];
		}
		m_Data[0] = value;
	}
	m_Size++;
}

template <typename T, size_t S>
int queue_array<T, S>::deque()
{
	if (m_Size == 0) throw std::exception("Object is empty");
	int value = m_Data[m_Size - 1];
	m_Size--;
	return value;
}

template <typename T, size_t S>
void queue_array<T, S>::display() const
{
	if (m_Size == 0) throw std::exception("Object is empty");
	for (size_t i = 0; i < m_Size; i++)
	{
		std::cout << m_Data[i] << " ";
	}
}
#endif
