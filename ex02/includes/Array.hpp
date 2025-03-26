/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urabex <urabex@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:30:11 by urabex            #+#    #+#             */
/*   Updated: 2025/03/26 15:50:39 by urabex           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
    public:
        Array();
    	Array(unsigned int i);
	    Array(Array<T> const &copy);
	    ~Array();
        Array<T>& operator=(Array<T> const &copy);
        T& operator[](unsigned int i);
	    void         display_array() const;
	    unsigned int size() const;

    private:
        unsigned int _size;
        T *_array;
};

template <class T>
Array<T>::Array() {
	_array = new T[0];
	_size = 0;
}

template<class T>
Array<T>::Array(unsigned int size) {
	this->_array = new T[size];
	_size = size;
}

template<class T>
Array<T>::~Array(void) {
	delete [] this->_array;
}

template<class T>
Array<T>::Array(const Array<T> &copy) {
	std::cout << "copy constractor" << std::endl;
	this->_size = copy._size;
	this->_array = NULL;
	*this = copy;
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &copy) {
	std::cout << "= operator" << std::endl;
	if (this != &copy) {
		this->_size = copy._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = copy._array[i];
	}
	return *this;
}

template<class T>
T &Array<T>::operator [](unsigned int i) {
	if (i >= _size) 
        throw std::out_of_range("Index out of range");
    return _array[i];
}

template<class T>
unsigned int Array<T>::size(void) const {
	return this->_size;
}

template<class T>
void Array<T>::display_array() const {
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout << i << "番目： " << _array[i] << std::endl;
	std::cout << "----------------------------------------"  << std::endl << std::endl;
}

#endif
