/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 04:24:44 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/09 04:53:37 by lmoheyma         ###   ########.fr       */
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
        
    public:
        Array();
        Array(int n);
};

template<typename T>
Array<T>::Array()
{
    std::cout << "\033[1m\033[33mArray default constructor called\033[0m" << std::endl;
}

template<typename T>
Array<T>::Array(int n)
{
    std::cout << "\033[1m\033[33mArray size default constructor called\033[0m" << std::endl;
}

// std::cout << "\033[1m\033[35mBureaucrat copy constructor called\033[0m" << std::endl;

// std::cout << "\033[1m\033[31mBureaucrat destructor called\033[0m" << std::endl;

// std::cout << "\033[1m\033[36mBureaucrat copy assignment operator called\033[0m" << std::endl;

#endif
