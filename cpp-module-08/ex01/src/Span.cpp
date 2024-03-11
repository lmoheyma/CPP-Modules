/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:24:43 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/11 07:14:33 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(10)
{   
    std::cout << "\033[1m\033[33mSpan default constructor called\033[0m" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
    std::cout << "\033[1m\033[33mSpan N paramater constructor called\033[0m" << std::endl;
}

Span::Span(const Span &other) : _N(other._N), _array(other._array)
{
    std::cout << "\033[1m\033[35mSpan copy constructor called\033[0m" << std::endl;
}

Span::~Span()
{
    std::cout << "\033[1m\033[31mSpan destructor called\033[0m" << std::endl;
}

Span& Span::operator=(const Span& other)
{
    std::cout << "\033[1m\033[36mSpan copy assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        _N = other._N;
        _array = other._array;
    }
    return (*this);
}

void Span::addNumber(int nb)
{
    if (_array.size() != _N)
        _array.push_back(nb);
    else
        throw Span::VectorIsFullException();
}

int Span::shortestSpan(void) const
{
    if (_array.size() < 2)
        throw Span::NotEnoughElementException();
    std::vector<int> temp = _array;
    std::sort(temp.begin(), temp.end());
    int shortestSpan = temp[1] - temp[0];
    for (int i = 2; i < (int)temp.size(); i++)
        if (temp[i] - temp[i - 1] < shortestSpan)
            shortestSpan = temp[i] - temp[i - 1];
    return (shortestSpan);
}

int Span::longestSpan(void) const
{
    if (_array.size() < 2)
        throw Span::NotEnoughElementException();
    return (*std::max_element(_array.begin(), _array.end()) - *std::min_element(_array.begin(), _array.end()));
}

void Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = begin; it < end; it++)
    {
        if (_array.size() != _N)
            _array.push_back(*it);
        else
            throw Span::VectorIsFullException(); 
    }   
}