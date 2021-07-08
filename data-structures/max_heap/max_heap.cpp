#include "max_heap.h"
#include <iostream>
#include <math.h>
#include <stdexcept>

max_heap::max_heap(const int& capacity)
{
	m_HeapSize = 0;
	m_Capacity = capacity;
	m_Data = new int[m_Capacity];
}

max_heap::~max_heap()
{
	delete[] m_Data;
}

int max_heap::parent(const size_t& index)
{
	return (index - 1) / 2;
}

int max_heap::left(const size_t& index)
{
	return (index * 2) + 1;
}

int max_heap::right(const size_t& index)
{
	return (index * 2) + 2;
}

void max_heap::swap(int& x, int& y)
{
	auto temp = x;
	x = y;
	y = temp;
}

int max_heap::get_max()
{
	if (m_HeapSize == 0) throw std::exception("Heap is empty");
	return m_Data[0];
}

int max_heap::extract_max()
{
	if (m_HeapSize == 0) throw std::exception("Heap is empty");
	if (m_HeapSize == 1)
	{
		m_HeapSize--;
		return m_Data[0];
	}
	auto root = m_Data[0];
	m_HeapSize--;
	m_Data[0] = m_Data[m_HeapSize];
	max_heapify(0);
	return root;
}

void max_heap::insert_key(const int& key)
{
	if (m_HeapSize == m_Capacity) throw std::overflow_error("Heap is full");
	m_HeapSize++;
	size_t index = m_HeapSize - 1;
	m_Data[index] = key;
	while (index != 0 && m_Data[parent(index)] < m_Data[index])
	{
		swap(m_Data[index], m_Data[parent(index)]);
		index = parent(index);
	}
}

void max_heap::decrease_key(const size_t& index, const int& new_value)
{
	auto i = index;
	m_Data[i] = new_value;
	while (i != 0 && m_Data[parent(i)] < m_Data[i])
	{
		swap(m_Data[parent(i)], m_Data[i]);
		i = parent(i);
	}
}

void max_heap::delete_key(const size_t& index)
{
	decrease_key(index, INT_MAX);
	extract_max();
}

void max_heap::max_heapify(const int& index)
{
	size_t l = left(index);
	size_t r = right(index);
	size_t highest = index;
	if (l < m_HeapSize && m_Data[l] > m_Data[highest]) highest = l;
	if (r < m_HeapSize && m_Data[r] > m_Data[highest]) highest = r;
	if (highest != index)
	{
		swap(m_Data[index], m_Data[highest]);
		max_heapify(highest);
	}
}

bool max_heap::search(const int& value)
{
	for (size_t i = 0; i < m_HeapSize; i++)
	{
		if (m_Data[i] == value) return true;
	}
	return false;
}

void max_heap::print_heap()
{
	for (size_t i = 0; i < m_HeapSize; i++)
	{
		std::cout << m_Data[i] << " ";
	}
	std::cout << std::endl;
}

int max_heap::height()
{
	return ceil(log2(m_HeapSize + 1)) - 1;
}
