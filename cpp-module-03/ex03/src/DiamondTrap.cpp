/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:28 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/26 18:36:30 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap("Bob_clap_name"), FragTrap("Bob_clap_name")
{
	std::cout << "\033[1m\033[33mDiamondTrap Default constructor called\033[0m" << std::endl; 
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	_name = "Bob_clap_name";
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	std::cout << "\033[1m\033[33mDiamondTrap Name constructor called\033[0m" << std::endl; 
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	_name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.getName() + "_clap_name"), ScavTrap(other.getName() + "_clap_name"), FragTrap(other.getName() + "_clap_name")
{
	std::cout << "\033[1m\033[33mDiamondTrap Copy constructor called\033[0m" << std::endl;
	hitPoints = other.getHitPoints();
	energyPoints = other.getEnergyPoints();
	attackDamage = other.getAttackDamage();
	_name = other.getName();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[1m\033[31mDiamondTrap Destructor called\033[0m" << std::endl; 
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "\033[1m\033[36mDiamondTrap Copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		hitPoints = other.getHitPoints();
		attackDamage = other.getAttackDamage();
		energyPoints = other.getEnergyPoints();
		_name = other.getName();
	}
	return (*this);
}

std::string DiamondTrap::getName(void) const
{
	return (this->_name);
}

void DiamondTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attacks " << target << " because he's dead !" << std::endl;
		return ;
	}
	else if (energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " can't attacks " << target << ", because he don't have enough energyPoints !" << std::endl;

}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "DiamondTrap " << _name << " is already dead !" << std::endl;
		return ;
	}
	else if (amount >= hitPoints)
	{
		hitPoints = 0;
		std::cout << "DiamondTrap " << _name << " is dead !" << std::endl;
	}
	else
	{
		hitPoints-=amount;
		std::cout << "DiamondTrap " << _name << " took " << amount << " damages !" << std::endl;
	}
		
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "DiamondTrap " << _name << " can't attacks repair himself because he's dead !" << std::endl;
	else if (energyPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "DiamondTrap " << _name << " repairs himself and has now" << hitPoints << " hit points !" << std::endl;
	}
	else
		std::cout << "DiamondTrap " << _name << " can't repairs himself because he don't have enough energyPoints !" << std::endl;
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap name is " << _name << "." << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}