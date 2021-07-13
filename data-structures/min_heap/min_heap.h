#ifndef MIN_HEAP_H
#define MIN_HEAP_H

class min_heap
{
public:
	min_heap(const size_t& capacity);
	~min_heap();
	int parent(const size_t& index); 
	int left(const size_t& index);
	int right(const size_t& index);
	void swap(int& x, int& y);
	int get_min(); // gets minimum value in heap (root)
	int extract_min(); // gets and removes minimum value in heap (root)
	void insert_key(const int& key); // inserts new key in heap
	void decrease_key(const size_t& index, const int& new_value);
	void delete_key(const size_t& index);
	void min_heapify(const int& index);
	bool search(const int& value); // returns true if value is in heap
	void print_heap();
	int height();
private:
	int* m_Data; // pointer to array of elements in heap
	size_t m_Capacity; // maximum possible number of elements in heap
	size_t m_HeapSize; // current number of elements in heap
};

#endif