/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirokiurabe <hirokiurabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:30:11 by urabex            #+#    #+#             */
/*   Updated: 2025/03/27 18:02:09 by hirokiurabe      ###   ########.fr       */
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
		const T& operator[](unsigned int i) const;
	    void         display_array() const;
	    unsigned int size() const;

    private:
        unsigned int _size;
        T *_array;
};

template <typename T>
Array<T>::Array() {
	_array = new T[0];
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int size) {
	this->_array = new T[size]();
	_size = size;
}

template<typename T>
Array<T>::~Array(void) {
	delete [] this->_array;
}

template<typename T>
Array<T>::Array(const Array<T> &copy) {
	std::cout << "copy constractor" << std::endl;
	this->_size = copy._size;
	this->_array = NULL;
	*this = copy;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy) {
	std::cout << "= operator" << std::endl;
	if (this != &copy) {
		this->_size = copy._size;
		delete [] this->_array;
		this->_array = new T[this->_size]();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = copy._array[i];
	}
	return *this;
}

template<typename T>
T &Array<T>::operator [](unsigned int i) {
	if (i >= _size)
        throw std::out_of_range("Index out of range");
    return _array[i];
}

template<typename T>
const T &Array<T>::operator [](unsigned int i) const {
	if (i >= _size)
        throw std::out_of_range("Index out of range");
    return _array[i];
}

template<typename T>
unsigned int Array<T>::size(void) const {
	return this->_size;
}

template<typename T>
void Array<T>::display_array() const {
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout << i << "番目： " << _array[i] << std::endl;
	std::cout << "----------------------------------------"  << std::endl << std::endl;
}

#endif
