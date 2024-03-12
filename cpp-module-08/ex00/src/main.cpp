/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:58:10 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/12 03:09:09 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::vector<int> intVector;
    std::vector<int>::iterator it;
    intVector.push_back(13);
    intVector.push_back(4);
    intVector.push_back(9);
    intVector.push_back(1);
    intVector.push_back(5);
    try
    {
        int found = easyfind(intVector, 13);
        if (found)
            std::cout << "\033[1m\033[32mInteger found!\033[0m" << std::endl;
        else
            throw NotFoundException();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        int found = easyfind(intVector, 130);
        if (found)
            std::cout << "\033[1m\033[32mInteger found!\033[0m" << std::endl;
        else
            throw NotFoundException();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}