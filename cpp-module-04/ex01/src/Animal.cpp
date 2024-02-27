/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:14:36 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 23:42:43 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "\033[1m\033[33mAnimal default constructor called\033[0m" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\033[1m\033[31mAnimal destructor called\033[0m" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "\033[1m\033[35mAnimal copy constructor called\033[0m" << std::endl;
	_type = other._type;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << "\033[1m\033[36mAnimal copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "\033[1m\033[35mAnimal sound... ?\033[0m" << std::endl;
}

std::string Animal::getType(void) const
{
	return (_type);
}