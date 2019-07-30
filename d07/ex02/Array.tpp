#ifndef ARRAY_TPP

# define ARRAY_TPP

#include <iostream>
#include <exception>

template <typename T>
class Array {

public: 

	Array(void) {this->_array = new T[0]; this->_size = 0;};
	Array(unsigned int n) {this->_array = new T[n]; this->_size = n;};
	Array(Array const & copy) : _array(new T[0]), _size(0) {*this = copy; return;};
	Array & operator=(Array const & b) {
		unsigned int i = 0;
		delete [] this->_array;
		this->_array = new T[b._size];
		while (i < b._size) {
			this->_array[i] = b._array[i];
			i++;
		} 
		this->_size = b._size; 
		return *this;
	};
	~Array(void) {delete [] _array;};
	unsigned int size(void) const {return this->_size; };

	T & operator[](unsigned int i) {
		if (i >= this->_size) {
			throw std::exception();
		}
		return this->_array[i];
	};

private:

	T * _array;
	unsigned int _size;

};

#endif
