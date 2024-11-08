#pragma once
#include <iostream>

template <typename T>

class vector {
private:
	T* array;
	unsigned int size; // # of elements
	unsigned int capacity; // data allocated for array
public:
	vector(unsigned int size) {
		// Must construct vector of size > 0 or it defaults to capacity of 1 //
		if (size > 0) {
			this->size = size;
			capacity = size;
			array = new T(capacity);
		}
		else {
			this->size = 0;
			capacity = 1;
			array = new T(capacity);
		}
	}
	vector() {
		size = 0;
		capacity = 1;
	}
	~vector() {
		delete[] array;
	}
	void push_front(T data) {
		// Pushes element to front of array //
		size++;
		T* tempArray = array;
		if (size > capacity) {
			capacity *= 2;
		}
		array = new T[capacity];
		array[0] = data;
		for (int i = 1; i < size-1; i++) {
			array[i] = tempArray[i];
		}
		delete[] tempArray;
	}
	void push_back(T data) {
		size++;
		T* tempArray = array;
		if (size > capacity) {
			capacity *= 2;
		}
		array = new T(capacity);
		array[size-1] = data;
		for (int i = 0; i < size-1; i++) {
			array[i] = tempArray[i];
		}
		delete[] tempArray;
	}
	T peek_front() {
		if (!empty()) {
			return array[0];
		}
		return -1;
	}
	T peek_back() {
		if (!empty()) {
			return array[size-1];
		}
		return -1;
	}
	bool empty() {
		if (size <= 0) {
			return true;
		}
		return false;
	}
	void print_vector() {
		// Prints contents of vector to console for debugging // 
		std::cout << "\n";
		for (int i = 0; i < size; i++) {
			std::cout << array[i] << ", ";
		}
	}
	void print_debug() {
		// Prints size, capacity, vector, front, back, sizeof, to console for debugging // 
		std::cout << "\nData Type Size: " << sizeof(T) << " bytes";
		std::cout << "\nVector Size: " << sizeof(array) << " bytes";
		std::cout << "\nSize: " << size;
		std::cout << "\nCapacity: " << capacity;
	}
	//T pop_front() {
		// Removes element at front but also returns it for quick access // 
	//}
	//T pop_back() {
		// Removes element at end but also returns it for quick access // 

	//}
	unsigned int get_size() {
		// Size = # of elements IN array //
		return size;
	}
	unsigned int get_capacity() {
		// Capacity = number of elements possible for memory // 
		return capacity;
	}
};