/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:31:26 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/24 18:21:31 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(const Fixed &other)
{
	std::cout << "\033[1m\033[33mCopy constructor called\033[0m" << std::endl; 
	this->setRawBits(other.getRawBits());
}

Fixed::Fixed() : fixedValue(0)
{
	std::cout << "\033[1m\033[33mDefault constructor called\033[0m" << std::endl; 
}

Fixed::Fixed(const int nb) : fixedValue(nb << fractionalBits)
{
	std::cout << "\033[1m\033[32mInt constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const float nb) : fixedValue(roundf(nb * (1 << fractionalBits)))
{
	std::cout << "\033[1m\033[32mFloat constructor called\033[0m" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "\033[1m\033[31mDestructor called\033[0m" << std::endl; 
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "\033[1m\033[36mCopy assignment operator called\033[0m" << std::endl; 
	if (this != &other)
		this->fixedValue = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "\033[1m\033[35mgetRawBits member function called\033[0m" << std::endl; 
	return (this->fixedValue);
}

void  Fixed::setRawBits(int fixedValue)
{
	this->fixedValue = fixedValue;
}

float Fixed::toFloat(void) const
{
	return (fixedValue / (float)(1 << fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (fixedValue >> fractionalBits);
}

std::ostream& operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return (os);
}