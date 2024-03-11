/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:24:40 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/11 07:08:25 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _array;
    public: 
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        ~Span();
        Span& operator=(const Span &other);
        void addNumber(int nb);
        int shortestSpan(void) const ;
        int longestSpan(void) const ;
        void addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        class VectorIsFullException : public std::exception{
            public:
                const char* what() const throw () { return ("\033[1m\033[31mVector is already full!\033[0m");}};
        class NotEnoughElementException : public std::exception{
            public:
                const char* what() const throw () { return ("\033[1m\033[31mNot enough elements!\033[0m");}};
};

#endif