/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:05:41 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/09 03:25:02 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void iter(T *adrr, int length, void(*f)(T&))
{
    for (int i = 0; i < length; i++)
        f(adrr[i]);
}

template<typename T>
void print_tab(T element)
{
    std::cout << element;
}

#endif