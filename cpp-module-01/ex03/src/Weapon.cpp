/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:23:27 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 08:29:36 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "Destructor has been called !" << std::endl;
}

std::string	Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

