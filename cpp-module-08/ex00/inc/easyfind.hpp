/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:40:43 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/11 03:51:07 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

template<typename T>
int easyfind(T& intContainer, int toFind)
{
    for (int it = intContainer.begin(); it != intContainer.end(); it++)
    {
        if (*it == toFind)
            return (1);
    }
    return (0);
}

#endif