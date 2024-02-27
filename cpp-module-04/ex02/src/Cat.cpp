/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:20:37 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 00:14:50 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "\033[1m\033[33mCat default constructor called\033[0m" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat()
{
	delete (_brain);
	std::cout << "\033[1m\033[31mCat destructor called\033[0m" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "\033[1m\033[33mCat copy constructor called\033[0m" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "\033[1m\033[36mCat copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "\033[1m\033[35mMeow!\033[0m" << std::endl;
}
