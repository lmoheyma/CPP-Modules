/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:17:33 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 19:01:34 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
	// std::cout << "\033[1m\033[33mIce default constructor called\033[0m" << std::endl;
}

Ice::Ice(const Ice &other)
{
	// std::cout << "\033[1m\033[33mIce copy constructor called\033[0m" << std::endl;
	_type = other._type;
}

Ice::~Ice()
{
	// std::cout << "\033[1m\033[31mIce destructor called\033[0m" << std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
	// std::cout << "\033[1m\033[36mIce copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

Ice* Ice::clone(void) const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "\033[1m\033[37m* shoots an ice bolt at " << target.getName() << " *\033[0m" << std::endl;
}