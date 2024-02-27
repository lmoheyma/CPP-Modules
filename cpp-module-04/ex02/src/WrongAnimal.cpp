/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:27:39 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 17:07:17 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "\033[1m\033[33mWrongAnimal default constructor called\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[1m\033[31mWrongAnimal destructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "\033[1m\033[33mWrongAnimal copy constructor called\033[0m" << std::endl;
	_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "\033[1m\033[36mWrongAnimal copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "\033[1m\033[35mWrongAnimal sound... ?\033[0m" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}