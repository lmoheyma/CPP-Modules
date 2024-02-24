/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 23:28:57 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/25 00:49:28 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point() : x(0), y(0)
{
    std::cout << "\033[1m\033[33mDefault constructor called\033[0m" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
    std::cout << "\033[1m\033[33mConstructor called\033[0m" << std::endl;
}

Point::Point(const Point &other)
{
    std::cout << "\033[1m\033[33mCopy constructor called\033[0m" << std::endl; 
	this->setX(other.getX());
    this->setY(other.getY());
}

Point::~Point()
{
    std::cout << "\033[1m\033[31mDestructor called\033[0m" << std::endl; 
}

Fixed Point::getX(void) const
{
    return (this->x);
}

Fixed Point::getY(void) const
{
    return (this->y);
}

void Point::setX(const Fixed x)
{
    this->x = x;
}

void Point::setY(const Fixed y)
{
    this->y = y;
}


Point& Point::operator=(const Point &other)
{
	std::cout << "\033[1m\033[36mCopy assignment operator called\033[0m" << std::endl; 
	if (this != &other)
    {
		this->x = other.getX();
        this->y = other.getY();
    }
	return (*this);
}