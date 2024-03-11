/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:24:42 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/11 17:03:15 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    {
        std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
		std::cout << "/*                    BASIC TEST                     */" << std::endl;
		std::cout << "/* ************************************************* */\033[0m" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "\033[1m\033[37m" << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << "\033[0m" << std::endl;
    }
    {
        std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
		std::cout << "/*                    FILL TEST                      */" << std::endl;
		std::cout << "/* ************************************************* */\033[0m" << std::endl;
        std::vector<int> temp;
        Span sp = Span(50);
        for (int i = 0; i < 50; i++)
            temp.push_back(i);
        sp.addManyNumbers(temp.begin(), temp.end());
        std::cout << "\033[1m\033[37m" << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << "\033[0m" << std::endl;
    }
    {
        std::cout << "\033[1m\033[32m/* ********************************************************************** */" << std::endl;
		std::cout << "/*                    EXCEPTIONS (NOT ENOUGH ELEMENTS)                     */" << std::endl;
		std::cout << "/* *********************************************************************** */\033[0m" << std::endl;
        Span sp = Span(2);
        sp.addNumber(6);
        try
        {
            std::cout << "\033[1m\033[37m" << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        std::cout << "\033[1m\033[32m/* *********************************************************************** */" << std::endl;
		std::cout << "/*                     EXCEPTIONS (TOO MUCH ELEMENTS)                      */" << std::endl;
		std::cout << "/* *********************************************************************** */\033[0m" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        try
        {
             sp.addNumber(20);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
		std::cout << "/*                     BIG TEST                      */" << std::endl;
		std::cout << "/* ************************************************* */\033[0m" << std::endl;
        Span sp = Span(10000);
        for (int i = 0; i < 10000; i++)
            sp.addNumber(i);
        std::cout << "\033[1m\033[37m" << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << "\033[0m" << std::endl;
    }
    return (0);
}