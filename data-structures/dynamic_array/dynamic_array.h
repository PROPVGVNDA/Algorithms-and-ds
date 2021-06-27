#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdexcept>

template <typename T>
class dynamic_array
{
public:
	dynamic_array();
	~dynamic_array();
	T& front();
	T& back();
	T& operator[](const size_t& index);
	void assign(const int& value, const size_t& quantity);
	void clear();
	void insert(const int& value, const size_t& index);
	void push_back(const int& value);
	void pop_back();
	void erase(const size_t& index);
	const T* data() const;
	const size_t size() const;
	const size_t capacity() const;
	const bool empty() const;
private:
	size_t m_Size;
	size_t m_Capacity;
	T* m_Data;
	void increase_capacity(const size_t& quantity);
	void copy(T* destination, T* source, const size_t& source_size, const int& value, const size_t& index_separator);
};

template <typename T>
dynamic_array<T>::dynamic_array()
{
	m_Size = 0;
	m_Capacity = 8;
	m_Data = new T[m_Capacity];
}

template <typename T>
dynamic_array<T>::~dynamic_array()
{
	delete m_Data;
}

template <typename T>
T& dynamic_array<T>::front()
{
	if (!(m_Size != 0)) throw std::out_of_range("Index out of range");
	return m_Data[0];
}

template <typename T>
T& dynamic_array<T>::back()
{
	if (!(m_Size != 0)) throw std::out_of_range("Index out of range");
	return m_Data[m_Size - 1];
}

template <typename T>
T& dynamic_array<T>::operator[](const size_t& index)
{
	if (!(index < m_Size)) throw std::out_of_range("Index out of range");
	return m_Data[index];
}

template <typename T>
void dynamic_array<T>::assign(const int& value, const size_t& quantity)
{
	if (m_Capacity <= quantity)
	{
		increase_capacity(quantity);
		delete m_Data;
		m_Data = new T[m_Capacity];
	}
	for (size_t i = 0; i < quantity; i++)
	{
		m_Data[i] = value;
	}
	m_Size = quantity;
}

template <typename T>
void dynamic_array<T>::clear()
{
	if (empty()) return;
	delete m_Data;
	m_Data = new T[8];
	m_Size = 0;
}

template <typename T>
void dynamic_array<T>::insert(const int& value, const size_t& index)
{
	if (!(index <= m_Size)) throw std::out_of_range("Index out of range");
	if (index == m_Size)
	{
		push_back(value);
		return;
	}
	T* new_data;
	if (m_Size + 1 == m_Capacity) m_Capacity *= 2;
	new_data = new T[m_Capacity];
	copy(new_data, m_Data, m_Size, value, index);
	delete m_Data;
	m_Data = new_data;
}

template <typename T>
void dynamic_array<T>::push_back(const int& value)
{
	if (m_Size + 1 >= m_Capacity) increase_capacity(m_Size + 1);
	m_Data[m_Size] = value;
	m_Size++;
}

template <typename T>
void dynamic_array<T>::pop_back()
{
	m_Size--;
}

template <typename T>
void dynamic_array<T>::erase(const size_t& index)
{
	if (!(index < m_Size)) throw std::out_of_range("Index out of range");
	if (index == m_Size - 1)
	{
		pop_back();
		return;
	}
	T* new_data = new T[m_Capacity];
	for (size_t i = 0, j = 0; i < m_Size; i++)
	{
		if (i == index) continue;
		new_data[j] = m_Data[i];
		j++;
	}
	m_Size--;
	delete m_Data;
	m_Data = new_data;
}

template <typename T>
const T* dynamic_array<T>::data() const
{
	return m_Data;
}

template <typename T>
const size_t dynamic_array<T>::size() const
{
	return m_Size;
}

template <typename T>
const size_t dynamic_array<T>::capacity() const
{
	return m_Capacity;
}

template <typename T>
const bool dynamic_array<T>::empty() const
{
	return m_Size == 0;
}

template <typename T>
void dynamic_array<T>::copy(T* destination, T* source, const size_t& source_size, const int& value, const size_t& index_separator)
{
	for (size_t i = 0; i < index_separator; i++)
	{
		destination[i] = m_Data[i];
	}
	destination[index_separator] = value;
	for (size_t i = index_separator; i < source_size; i++)
	{
		destination[i + 1] = m_Data[i];
	}
	m_Size++;
}

template <typename T>
void dynamic_array<T>::increase_capacity(const size_t& quantity)
{
	do
	{
		m_Capacity *= 2;
	} while (m_Capacity <= quantity);

	T* new_data = new T[m_Capacity];
	for (size_t i = 0; i < m_Size; i++)
	{
		new_data[i] = m_Data[i];
	}
	delete m_Data;
	m_Data = new_data;
}

#endif // DYNAMIC_ARRAY_H