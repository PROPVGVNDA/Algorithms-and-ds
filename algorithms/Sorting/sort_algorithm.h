#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H


class sort_algorithm
{
public:
	static void heap_sort(int* arr, const size_t& size);
	static void bubble_sort(int* arr, const size_t& size);
private:
	sort_algorithm() = delete;
	static void swap(int& a, int& b);
};

#endif