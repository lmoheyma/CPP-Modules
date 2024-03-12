/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:40:43 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/12 03:08:07 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NotFoundException : public std::exception{
    public:
        const char* what() const throw () { return ("\033[1m\033[31mInteger not found!\033[0m");}};

template<typename T>
int easyfind(T& intContainer, int toFind)
{
    if (std::find(intContainer.begin(), intContainer.end(), toFind) == intContainer.end())
        return (throw NotFoundException(), 0);
    return (1);
}

#endif