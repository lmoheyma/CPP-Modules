/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:23:52 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 09:00:35 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{

}

HumanA::~HumanA()
{
	
}

void	HumanA::attack(void) const
{
	if (weapon.getType() == "")
	{
		std::cout << name << " attacks with their hands" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}