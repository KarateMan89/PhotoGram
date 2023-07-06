
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Photo.h"

using namespace std;


template <typename T>
class Array {

	template <typename V>
	friend ostream& operator<<(ostream& ost, const Array<V>& arr);

	public:
		//constructor
		Array();
				
		//destructor
		~Array();

		//operators
		T& operator[](int index);
		const T& operator[](int index) const;
		Array<T>& operator+=(T t);
		Array<T>& operator-=(T t);
		Array<T>operator=(const Array<T>& other); // we want to make a deep copy of the array
		bool operator==(const Array<T>& other);

		//other
		void clear();
		void add(T);
		void remove(T);
		T& get(int index) const;
		int size() const;
		bool isFull();
	
	private:
		int numElements;
		T* elements;
	
};

template <typename T>
ostream& operator<<(ostream& ost, const Array<T>& arr){
	for (int i = 0; i < arr.numElements; ++i){
		ost<<arr.elements[i]<<endl;
	}
	return ost;
}

template <typename T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	numElements = 0;
}

template <typename T>
Array<T>::~Array(){
	delete [] elements;
}

template <typename T>
T& Array<T>::operator[](int index){
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <typename T>
Array<T>& Array<T>::operator+=(T t){
	add(t); // reuse add function, return *this(the array));
	return *this;
}

template <typename T>
Array<T>& Array<T>::operator-=(T t){
	remove(t); // reuse remove function, return *this(the array));
	return *this;
}

// make a deep copy of the array
template <typename T>
Array<T> Array<T>::operator=(const Array<T>& other){
	if (this == &other) return *this;
	clear();
	for(int i = 0; i < other.numElements; ++i){
		add(other.elements[i]);
	}
	return *this;
}

template <typename T>
bool Array<T>::operator==(const Array<T>& other){
	if (numElements != other.numElements) return false;
	for (int i = 0; i < numElements; ++i){
		if (elements[i] != other.elements[i]) return false;
	}
	return true;
}

template <typename T>
void Array<T>::clear(){
	for(int i = 0; i < numElements; ++i){
		elements[i] = nullptr;
	}
	numElements = 0;
}

template <typename T>
void Array<T>::add(T t){
	if (numElements >= MAX_ARRAY) return;
	elements[numElements++] = t;
}

template <typename T>
void Array<T>::remove(T t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
}

template <typename T>
int Array<T>::size() const {
	return numElements;
}

template <typename T>
bool Array<T>::isFull(){
	return numElements >= MAX_ARRAY;
}

template <typename T>
T& Array<T>::get(int index) const {
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

#endif
