#include "min_heap.h"
#include <iostream> // for printing heap
#include <math.h> // for calculating height of heap
#include <stdexcept> // for handling errors

min_heap::min_heap(const int& capacity)
{
	m_HeapSize = 0;
	m_Capacity = capacity;
	m_Data = new int[m_Capacity];
}

min_heap::~min_heap()
{
	delete m_Data;	
}

int min_heap::parent(const size_t& index)
{
	return (index - 1) / 2;
}

int min_heap::left(const size_t& index)
{
	return (index * 2) + 1;
}

int min_heap::right(const size_t& index)
{
	return (index * 2) + 2;
}

void min_heap::swap(int& x, int& y)
{
	auto temp = x;
	x = y;
	y = temp;
}

int min_heap::get_min()
{
	if (m_HeapSize == 0) throw std::exception("Heap is empty");
	return m_Data[0];
}

int min_heap::extract_min()
{
	if (m_HeapSize <= 0) throw std::exception("Heap is empty");
	if (m_HeapSize == 1)
	{
		m_HeapSize--;
		return m_Data[0];
	}
	auto root = m_Data[0];
	m_Data[0] = m_Data[m_HeapSize - 1];
	m_HeapSize--;
	min_heapify(0);
	return root;
}

void min_heap::insert_key(const int& key)
{
	if (m_HeapSize == m_Capacity) throw std::overflow_error("Heap full");
	m_HeapSize++;
	size_t index = m_HeapSize - 1;
	m_Data[index] = key;
	while (index != 0 && m_Data[parent(index)] > m_Data[index])
	{
		swap(m_Data[index], m_Data[parent(index)]);
		index = parent(index);
	}
}

void min_heap::decrease_key(const size_t& index, const int& new_value)
{
	size_t i = index;
	m_Data[i] = new_value;
	while (index != 0 && m_Data[parent(i) > m_Data[i]])
	{
		swap(m_Data[i], m_Data[parent(i)]);
		i = parent(i);
	}
}

void min_heap::delete_key(const size_t& index)
{
	if (m_HeapSize == 0 && index >= m_HeapSize) throw std::out_of_range("Index out of range");
	decrease_key(index, INT_MIN);
	extract_min();
}

void min_heap::min_heapify(const int& index)
{
	size_t l = left(index);
	size_t r = right(index);
	size_t smallest = index;
	if (l < m_HeapSize && m_Data[l] < m_Data[index]) smallest = l;
	if (r < m_HeapSize && m_Data[r] < m_Data[smallest]) smallest = r;
	if (smallest != index)
	{
		swap(m_Data[index], m_Data[smallest]);
		min_heapify(smallest);
	}

}

bool min_heap::search(const int& value)
{
	for (size_t i = 0; i < m_HeapSize; i++)
	{
		if (m_Data[i] == value) return true;
	}
	return false;
}

void min_heap::print_heap()
{
	for (size_t i = 0; i < m_HeapSize; i++)
	{
		std::cout << m_Data[i] << " ";
	}
	std::cout << std::endl;
}

int min_heap::height()
{
	return ceil(log2(m_HeapSize + 1)) - 1;
}