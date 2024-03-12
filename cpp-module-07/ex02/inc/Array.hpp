/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 04:24:44 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/12 02:27:38 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
class Array
{
    private:
        T *_array;
        unsigned int _array_size;
    public:
        Array()
        {
            _array = new T();
            _array_size = 0;
            std::cout << "\033[1m\033[33mArray default constructor called\033[0m" << std::endl;
        }
        Array(unsigned int n) : _array(new T[n]()), _array_size(n)
        {
            std::cout << "\033[1m\033[33mArray size default constructor called\033[0m" << std::endl;
        }
        Array(const Array<T> &other) 
        {
            std::cout << "\033[1m\033[35mArray copy constructor called\033[0m" << std::endl;
            _array = new T[other._array_size]();
            _array_size = other._array_size;
            for (unsigned int i = 0; i < other._array_size; i++)
                _array[i] = other._array[i];
        }
        Array<T>& operator=(const Array<T> &other)
        {
            std::cout << "\033[1m\033[36mArray copy assignment operator called\033[0m" << std::endl;
            if (this != &other)
            {
                delete [] _array;
                _array = new T[other._array_size]();
                _array_size = other._array_size;
                for (unsigned int i = 0; i < other._array_size; i++)
                    _array[i] = other._array[i];
            }
            return (*this);
        }
        T& operator[](unsigned int n)
        {
            if (n >= _array_size)
                throw OutOfBoudsException();
            return _array[n];
        }
        ~Array()
        {
            delete [] _array;
            std::cout << "\033[1m\033[31mArray destructor called\033[0m" << std::endl;
        }
        unsigned int size(void) const
        {
            return (_array_size);
        }
        class OutOfBoudsException : public std::exception{
			public:
				const char* what() const throw () { return ("\033[1m\033[35mIndex out of bounds!\033[0m");}};
};

#endif