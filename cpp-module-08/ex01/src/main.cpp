/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:24:42 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/11 07:20:34 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    {
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
        std::vector<int> temp;
        Span sp = Span(50);
        for (int i = 0; i < 50; i++)
            temp.push_back(i);
        sp.addManyNumbers(temp.begin(), temp.end());
        std::cout << "\033[1m\033[37m" << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << "\033[0m" << std::endl;
    }
    return (0);
}