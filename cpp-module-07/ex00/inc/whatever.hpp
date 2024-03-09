/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 02:53:04 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/09 02:57:12 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = b;
    b = a;
    a = temp;
}

template <typename T>
T max(T a, T b)
{
    return (a > b ? a : b);
}

template <typename T>
T min(T a, T b)
{
    return (a < b ? a : b);
}


#endif