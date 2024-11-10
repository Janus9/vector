/**
* \file vector.h
* \brief Dynamic array (replica of std::vector)
* 
* Defines the vector class, a template based dynamic array data structure
* Provides operations including element access, insertion, deletion, automatic resizing (no manual operation)
* 
* Visit https://github.com/Janus9/vector for README for instructions on usage
* 
* \author Joshua Bayt
* \date November 9th, 2024
*/

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
		// Pushes element to front of vector // 
		size++;
		if (size > capacity) {
			capacity *= 2;
		}
		T* tempArray = new T[capacity];
		tempArray[0] = data;
		for (int i = 0; i < size - 1; i++) {
			tempArray[i + 1] = array[i];
		}
		delete[] array;
		array = tempArray;
	}
	void push_back(T data) {
		// Pushes element to back of vector // 
		size++;
		if (size > capacity) {
			capacity *= 2;
			T* tempArray = new T[capacity];
			for (int i = 0; i < size - 1; i++) {
				tempArray[i] = array[i];
			}
			tempArray[size - 1] = data;
			delete[] array;
			array = tempArray;
		}
		else {
			array[size - 1] = data;
		}
				
	}
	T peek_front() {
		// Returns element at front of vector // 
		if (!empty()) {
			return array[0];
		}
		std::cerr << "\nError: Vector is empty";
		throw std::out_of_range("Vector incorrect index");
	}
	T peek_back() {
		// Returns element at end of vector d// 
		if (!empty()) {
			return array[size - 1];
		}
		std::cerr << "\nError: Vector is empty";
		throw std::out_of_range("Vector incorrect index");
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
	T pop_front() {
		// Removes element at front but also returns it for quick access //
		size--;
		T front = array[0];
		T* tempArray = new T[capacity];
		for (int i = 0; i < size; i++) {
			tempArray[i] = array[i+1];
		}
		delete[] array;
		array = tempArray;
		return front;
	}
	T pop_back() {
		// Removes element at end but also returns it for quick access // 
		size--;
		T back = array[size];
		T* tempArray = new T[capacity];
		for (int i = 0; i < size; i++) {
			tempArray[i] = array[i];
		}
		delete[] array;
		array = tempArray;
		return back;
	}
	T pop(unsigned int index) {
		// Removes element at index but also returns it for quick access //
		if (index == 0) {
			return pop_front();
		}
		if (index == size-1) {
			return pop_back();
		}
		size--;
		if (index < size && !empty()) {
			T element = array[index];
			T* tempArray = new T[capacity];
			for (int i = 0; i < index; i++) {
				tempArray[i] = array[i];
			}
			for (int i = index; i < size; i++) {
				tempArray[i] = array[i+1];
			}
			delete[] array;
			array = tempArray;
			return element;
		}
		std::cerr << "\nError: Index out of bounds";
		throw std::out_of_range("Bad Access");
	}
	T& at(unsigned int index) {
		// Read / Write of element at array[index] WITH protection // 
		if (index < size && !empty()) {
			return array[index];
		}
		std::cerr << "\nError: Index out of bounds";
		throw std::out_of_range("Bad Access");
	}
	T& operator[] (unsigned int index) {
		// Read / Write of element at array[index] WITHOUT protection // 
		return array[index];
	}
	unsigned int get_size() {
		// Size = # of elements IN array //
		return size;
	}
	unsigned int get_capacity() {
		// Capacity = number of elements possible for memory // 
		return capacity;
	}
};