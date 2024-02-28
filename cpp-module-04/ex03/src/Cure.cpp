/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:17:35 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 19:01:37 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
	// std::cout << "\033[1m\033[33mCure default constructor called\033[0m" << std::endl;
}

Cure::Cure(const Cure &other)
{
	// std::cout << "\033[1m\033[33mCure copy constructor called\033[0m" << std::endl;
	_type = other._type;
}

Cure::~Cure()
{
	// std::cout << "\033[1m\033[31mCure destructor called\033[0m" << std::endl;
}

Cure& Cure::operator=(const Cure &other)
{
	// std::cout << "\033[1m\033[36mCure copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

Cure* Cure::clone(void) const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "\033[1m\033[37m* heals " << target.getName() << "'s wounds *\033[0m" << std::endl;
}