/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:38:05 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 18:19:43 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "\033[1m\033[33mDog default constructor called\033[0m" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "\033[1m\033[31mDog destructor called\033[0m" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "\033[1m\033[33mDog copy constructor called\033[0m" << std::endl;
	_type = other._type;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "\033[1m\033[36mDog copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "\033[1m\033[35mWouaf!\033[0m" << std::endl;
}
