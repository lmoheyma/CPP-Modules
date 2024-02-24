/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:31:26 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/24 16:03:39 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(const Fixed &other)
{
	std::cout << "\033[1m\033[33mCopy constructor called\033[0m" << std::endl; 
	this->setRawBits(other.getRawBits());
}

Fixed::Fixed() : raw(0)
{
	std::cout << "\033[1m\033[33mDefault constructor called\033[0m" << std::endl; 
}

Fixed::~Fixed()
{
	std::cout << "\033[1m\033[31mDestructor called\033[0m" << std::endl; 
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "\033[1m\033[36mCopy assignment operator called\033[0m" << std::endl; 
	if (this != &other)
		this->raw = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "\033[1m\033[35mgetRawBits member function called\033[0m" << std::endl; 
	return (this->raw);
}

void  Fixed::setRawBits(int raw)
{
	this->raw = raw;
}
