/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 23:43:57 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/25 00:17:42 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed angleAPB = ((a.getX() - point.getX()) * (b.getY() - point.getY())) - ((a.getY() - point.getY()) * (b.getX() - point.getX()));
    Fixed angleBPC = ((b.getX() - point.getX()) * (c.getY() - point.getY())) - ((b.getY() - point.getY()) * (c.getX() - point.getX()));
    Fixed angleCPA = ((c.getX() - point.getX()) * (a.getY() - point.getY())) - ((c.getY() - point.getY()) * (a.getX() - point.getX()));

    if ((angleAPB > 0 && angleBPC > 0 && angleCPA > 0) || (angleAPB < 0 && angleBPC < 0 && angleCPA < 0))
        return (true);
    return (false);
}
