#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H


class sort_algorithm
{
public:
	static void heap_sort(int* arr, const size_t& size);
	static void bubble_sort(int* arr, const size_t& size);
	static void insertion_sort(int* arr, const size_t& size);
	static void quick_sort(int* arr, const size_t& low, const size_t& high);
	static void selection_sort(int* arr, const size_t& size);
	static void counting_sort(int* arr, const size_t& size);
private:
	sort_algorithm() = delete;
	static void swap(int& a, int& b);
	static int partition(int* arr, const int& low, const int& high);
};

#endif