/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:27:36 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 00:15:16 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "\033[1m\033[33mWrongCat default constructor called\033[0m" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[1m\033[31mWrongCat destructor called\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "\033[1m\033[33mWrongCat copy constructor called\033[0m" << std::endl;
	_type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << "\033[1m\033[36mWrongCat copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "\033[1m\033[35mMeow!\033[0m" << std::endl;
}
