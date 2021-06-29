#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include "../array/m_array.h"
#include <stdexcept>
#include <iostream>

template <typename T, size_t S>
class stack_array
{
public:
	stack_array();
	const size_t size() const;
	bool empty() const;
	T pop();
	const T top() const;
	void push(const T& value);
	void display() const;
private:
	T m_Data[S];
	size_t m_Size;
};

template <typename T, size_t S>
void stack_array<T, S>::display() const
{
	if (empty()) throw std::out_of_range("Object is empty");
	for (int i = 0; i < m_Size; i++)
	{
		std::cout << m_Data[i] << std::endl;
	}
}

template <typename T, size_t S>
T stack_array<T, S>::pop()
{
	if (empty()) throw std::out_of_range("Object is empty");
	T result = m_Data[0];
	m_Size--;
	for (size_t i = 0; i < m_Size; i++)
	{
		m_Data[i] = m_Data[i + 1];
	}
	return result;
}

template <typename T, size_t S>
const T stack_array<T, S>::top() const
{
	if (empty()) throw std::out_of_range("Object is empty");
	return m_Data[0];
}

template <typename T, size_t S>
void stack_array<T, S>::push(const T& value)
{
	if (m_Size == S) throw std::out_of_range("Object is out of space");
	if (m_Size != 0)
	{
		for (size_t i = m_Size; i > 0; i--	)
		{
			m_Data[i] = m_Data[i - 1];
		}
	}
	m_Data[0] = value;
	m_Size++;
}

template <typename T, size_t S>
stack_array<T, S>::stack_array()
{
	m_Size = 0;
}

template <typename T, size_t S>
bool stack_array<T, S>::empty() const
{
	return m_Size == 0;
}

template <typename T, size_t S>
const size_t stack_array<T, S>::size() const
{
	return S;
}

#endif