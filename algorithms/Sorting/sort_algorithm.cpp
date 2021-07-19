#include "sort_algorithm.h"
#include "../../data-structures/max_heap/max_heap.h"
#include <iostream>

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

// Average Time Complexity - O(n^2)
void sort_algorithm::insertion_sort(int* arr, const size_t& size)
{
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int j = i;
			do 
			{
				if (arr[j] < arr[j - 1])
					swap(arr[j], arr[j - 1]);
				j--;
			} while (j >= 0);
		}
	}
}

// Time Complexity - O(n * log(n))
void sort_algorithm::quick_sort(int* arr, const size_t& low, const size_t& high)
{
	if (low < high)
	{
		int index = partition(arr, low, high);
		quick_sort(arr, low, index - 1);
		quick_sort(arr, index + 1, high);
	}
}

// Time Complexity - O(n^2)
void sort_algorithm::selection_sort(int* arr, const size_t& size)
{
	for (size_t i = 0; i < size; i++)
	{
		int temp = arr[i], index = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[j] < temp)
			{
				temp = arr[j];
				index = j;
			}
		}
		swap(arr[i], arr[index]);
	}
}

// Time Complexity - O(n + r);
// n - number of elements
// r - range of input
void sort_algorithm::counting_sort(int* arr, const size_t& size)
{
	const size_t counter_size = 10;
	int counter[counter_size]{ 0 };
	int* temp_arr = new int[size] {0};
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > 9) throw std::exception("Value should be less than 10");
		counter[arr[i]]++;
	}
	for (size_t i = 1; i < counter_size; i++)
		counter[i] += counter[i - 1];
	for (size_t i = 0; i < size; i++)
	{
		temp_arr[counter[arr[i]] - 1] = arr[i];
		counter[arr[i]]--;
	}
	for (size_t i = 0; i < size; i++)
		arr[i] = temp_arr[i];
}

void sort_algorithm::swap(int& a, int& b)
{
	auto temp = a;
	a = b;
	b = temp;
}

int sort_algorithm::partition(int* arr, const int& low, const int& high)
{
	int pivot = arr[high];
	int index = low;
	for (int i = low; i < high; i++)
	{

		if (arr[i] <= pivot)
		{
			swap(arr[i], arr[index]);
			index++;
		}
	}
	swap(arr[index], arr[high]);
	return index;
}
