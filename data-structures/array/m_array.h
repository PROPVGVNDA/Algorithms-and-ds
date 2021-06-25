#ifndef M_ARRAY_H
#define M_ARRAY_H
#include <stdexcept>

template <typename T, size_t S>
class m_array
{
public:
	const size_t size() const;
	T& front();
	T& back();
	void fill(const int& value);
	T& operator[](const size_t& index);
	const T& operator[](const size_t& index) const;
	const T* data() const;
private:
	T array_data[S];
};

template <typename T, size_t S>
const size_t m_array<T, S>::size() const
{
	return S;
}

template <typename T, size_t S>
T& m_array<T, S>::front()
{
	return array_data[0];
}

template <typename T, size_t S>
T& m_array<T, S>::back()
{
	return array_data[S - 1];
}

template <typename T, size_t S>
T& m_array<T, S>::operator[](const size_t& index)
{
	if (!(index < S)) throw std::out_of_range("Out of range");
	return array_data[index];
}

template <typename T, size_t S>
const T& m_array<T, S>::operator[](const size_t& index) const
{
	if (!(index < S)) throw std::out_of_range("Index is out of range");
	return array_data[index];
}

template <typename T, size_t S>
void m_array<T, S>::fill(const int& value)
{
	for (size_t i = 0; i < S; i++)
	{
		array_data[i] = value;
	}
}

template <typename T, size_t S>
const T* m_array<T, S>::data() const
{
	return array_data;
}

#endif