/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 04:24:44 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/09 18:37:33 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>

template<typename T>
class Array
{
    private:
        T *_array;
        int _array_size;
    public:
        Array();
        Array(int n);
        Array(const Array &other);
        ~Array();
        Array<T>& operator=(Array const &other);
        int size(void) const ;
};

template<typename T>
Array<T>::Array()
{
    _array = new T[0]();
    _array_size = 0;
    std::cout << "\033[1m\033[33mArray default constructor called\033[0m" << std::endl;
}

template<typename T>
Array<T>::Array(int n) : _array(new T[n]()), _array_size(n)
{
    std::cout << "\033[1m\033[33mArray size default constructor called\033[0m" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &other) : _array(new T[other._array_size]()), _array_size(other._array_size)
{
    std::cout << "\033[1m\033[35mArray copy constructor called\033[0m" << std::endl;
}

template<typename T>
Array<T>& Array<T>::operator=(Array const &other)
{
    std::cout << "\033[1m\033[36mArray copy assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        _array = new T[other._array_size]();
        _array_size = other._array_size;
        for (int i = 0; i < other._array_size; i++)
            _array[i] = other._array[i];
    }
    return (*this);
} 

template<typename T>
Array<T>::~Array()
{
    delete []_array;
    std::cout << "\033[1m\033[36mArray copy assignment operator called\033[0m" << std::endl;
}

template<typename T>
int Array<T>::size(void) const
{
    return (_array_size);
}



#endif
