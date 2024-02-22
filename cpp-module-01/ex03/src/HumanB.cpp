/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:23:39 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 09:01:56 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	
}

void	HumanB::attack(void) const
{
	if (weapon == NULL || weapon->getType() == "")
	{
		std::cout << name << " attacks with their hands" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}