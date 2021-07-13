#ifndef MAX_HEAP_H
#define MAX_HEAP_H

class max_heap
{
public:
	max_heap(const size_t& capacity);
	~max_heap();
	size_t parent(const size_t& index);
	size_t left(const size_t& index);
	size_t right(const size_t& index);
	void swap(int& x, int& y);
	int get_max(); // gets minimum value in heap (root)
	int extract_max(); // gets and removes minimum value in heap (root)
	void insert_key(const int& key); // inserts new key in heap
	void decrease_key(const size_t& index, const int& new_value);
	void delete_key(const size_t& index);
	void max_heapify(const size_t& index);
	bool search(const int& value); // returns true if value is in heap
	void print_heap();
	int height();
private:
	int* m_Data; // pointer to array of elements in heap
	size_t m_Capacity; // maximum possible number of elements in heap
	size_t m_HeapSize; // current number of elements in heap
};

#endif