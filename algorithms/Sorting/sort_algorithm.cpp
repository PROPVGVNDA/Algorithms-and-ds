#include "sort_algorithm.h"
#include "../../data-structures/max_heap/max_heap.h"

// Average Time Complexity - O(n * log(n))
void sort_algorithm::heap_sort(int* arr, const size_t& size)
{
	max_heap mx{ size }; // creates max heap with same size as passed array
	// adds all elements from array to heap
	for (size_t i = 0; i < size; i++)
	{
		mx.insert_key(arr[i]);
	}
	// extracts max(root) node from max heap and fills array backwards
 	for (int i = size - 1; i >= 0; i--)
 	{
 		arr[i] = mx.extract_max();
 	}
}

// Average Time Complexity - O(n^2)
void sort_algorithm::bubble_sort(int* arr, const size_t& size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

void sort_algorithm::swap(int& a, int& b)
{
	auto temp = a;
	a = b;
	b = temp;
}
