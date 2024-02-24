/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:31:26 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/24 19:27:41 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "\033[1m\033[33mCopy constructor called\033[0m" << std::endl; 
	this->setRawBits(other.getRawBits());
}

Fixed::Fixed() : fixedValue(0)
{
	// std::cout << "\033[1m\033[33mDefault constructor called\033[0m" << std::endl; 
}

Fixed::Fixed(const int nb) : fixedValue(nb << fractionalBits)
{
	// std::cout << "\033[1m\033[32mInt constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const float nb) : fixedValue(roundf(nb * (1 << fractionalBits)))
{
	// std::cout << "\033[1m\033[32mFloat constructor called\033[0m" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "\033[1m\033[31mDestructor called\033[0m" << std::endl; 
}

Fixed& Fixed::operator=(const Fixed &other)
{
	// std::cout << "\033[1m\033[36mCopy assignment operator called\033[0m" << std::endl; 
	if (this != &other)
		this->fixedValue = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "\033[1m\033[35mgetRawBits member function called\033[0m" << std::endl; 
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

bool Fixed::operator>(Fixed const &other) const
{
	return (fixedValue > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const
{
	return (fixedValue < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (fixedValue >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (fixedValue <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const
{
	return (fixedValue == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (fixedValue != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other)
{
	Fixed res;
	res.setRawBits(fixedValue + other.getRawBits());
	return (res);
}

Fixed Fixed::operator-(Fixed const &other)
{
	Fixed res;
	res.setRawBits(fixedValue - other.getRawBits());
	return (res);
}

Fixed Fixed::operator*(Fixed const &other)
{
	Fixed res;
	res.setRawBits((fixedValue * other.getRawBits()) >> fractionalBits);
	return (res);
}

Fixed Fixed::operator/(Fixed const &other)
{
	if (other.getRawBits() == 0)
		return (0);
	Fixed res;
	res.setRawBits((fixedValue << fractionalBits) / other.getRawBits());
	return (res);
}

Fixed Fixed::operator++(int) //Post
{
	Fixed tmp(*this);
	fixedValue++;
	return (tmp);
}

Fixed& Fixed::operator++(void) //Pre
{
	++fixedValue;
	return (*this);
}

Fixed Fixed::operator--(int) //Post
{
	Fixed tmp(*this);
	fixedValue--;
	return (tmp);
}

Fixed& Fixed::operator--(void) //Pre
{
	--fixedValue;
	return (*this);
}

Fixed& Fixed::min(Fixed &nb1, Fixed &nb2)
{
	return (nb1 < nb2 ? nb1 : nb2);
}

const Fixed& Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	return (nb1 < nb2 ? nb1 : nb2);
}

Fixed& Fixed::max(Fixed &nb1, Fixed &nb2)
{
	return (nb1 > nb2 ? nb1 : nb2);
}

const Fixed& Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
	return (nb1 > nb2 ? nb1 : nb2);
}