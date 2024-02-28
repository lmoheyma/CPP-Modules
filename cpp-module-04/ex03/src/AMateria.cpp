/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:10:55 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 18:50:31 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria")
{
	// std::cout << "\033[1m\033[33mAMateria default constructor called\033[0m" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "\033[1m\033[33mAMateria type constructor called\033[0m" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	// std::cout << "\033[1m\033[33mAMateria copy constructor called\033[0m" << std::endl;
	_type = other._type;
}

AMateria::~AMateria()
{
	// std::cout << "\033[1m\033[31mAMateria destructor called\033[0m" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	// std::cout << "\033[1m\033[36mAMateria copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

std::string const & AMateria::getType(void) const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	return ;
}