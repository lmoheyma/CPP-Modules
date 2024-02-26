/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:28 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/26 17:20:39 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "\033[1m\033[33mScavTrap Default constructor called\033[0m" << std::endl; 
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	_name = "Bob";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[1m\033[33mScavTrap Name constructor called\033[0m" << std::endl; 
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	_name = name;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "\033[1m\033[33mScavTrap Copy constructor called\033[0m" << std::endl;
	hitPoints = other.getHitPoints();
	energyPoints = other.getEnergyPoints();
	attackDamage = other.getAttackDamage();
	_name = other.getName();
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[1m\033[31mScavTrap Destructor called\033[0m" << std::endl; 
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "\033[1m\033[36mScavTrap Copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		hitPoints = other.getHitPoints();
		attackDamage = other.getAttackDamage();
		energyPoints = other.getEnergyPoints();
		_name = other.getName();
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
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

void ScavTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is already dead !" << std::endl;
		return ;
	}
	else if (amount >= hitPoints)
	{
		hitPoints = 0;
		std::cout << "ScavTrap " << _name << " is dead !" << std::endl;
	}
	else
	{
		hitPoints-=amount;
		std::cout << "ScavTrap " << _name << " took " << amount << " damages !" << std::endl;
	}
		
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "ScavTrap " << _name << " can't attacks repair himself because he's dead !" << std::endl;
	else if (energyPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ScavTrap " << _name << " repairs himself and has now" << hitPoints << " hit points !" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " can't repairs himself because he don't have enough energyPoints !" << std::endl;
}

void ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode." << std::endl;
}