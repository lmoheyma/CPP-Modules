/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:14:36 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 16:20:45 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "\033[1m\033[33mAAnimal default constructor called\033[0m" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "\033[1m\033[31mAAnimal destructor called\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "\033[1m\033[33mAAnimal copy constructor called\033[0m" << std::endl;
	_type = other._type;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	std::cout << "\033[1m\033[36mAAnimal copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void AAnimal::makeSound(void) const
{
	
}

std::string AAnimal::getType(void) const
{
	return (_type);
}