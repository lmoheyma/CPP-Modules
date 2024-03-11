/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:40:43 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/11 06:18:03 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

template<typename T>
int easyfind(T& intContainer, int toFind)
{
    for (std::vector<int>::iterator it = intContainer.begin(); it != intContainer.end(); it++)
    {
        if (*it == toFind)
            return (1);
    }
    return (0);
}

class NotFoundException : public std::exception{
    public:
        const char* what() const throw () { return ("\033[1m\033[31mInteger not found!\033[0m");}};

#endif