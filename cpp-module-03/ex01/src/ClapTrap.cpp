/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:28 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/26 17:26:48 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "\033[1m\033[33mClapTrap Default constructor called\033[0m" << std::endl; 
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	_name = "Bob";
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "\033[1m\033[33mClapTrap Name constructor called\033[0m" << std::endl; 
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "\033[1m\033[33mClapTrap Copy constructor called\033[0m" << std::endl;
	hitPoints = other.getHitPoints();
	energyPoints = other.getEnergyPoints();
	attackDamage = other.getAttackDamage();
	_name = other.getName();
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[1m\033[31mClapTrap Destructor called\033[0m" << std::endl; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "\033[1m\033[36mClapTrap Copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		hitPoints = other.getHitPoints();
		attackDamage = other.getAttackDamage();
		energyPoints = other.getEnergyPoints();
		_name = other.getName();
	}
	return (*this);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attacks " << target << " because he's dead !" << std::endl;
		return ;
	}
	else if (energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't attacks " << target << ", because he don't have enough energyPoints !" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead !" << std::endl;
		return ;
	}
	else if (amount >= hitPoints)
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is dead !" << std::endl;
	}
	else
	{
		hitPoints--;
		std::cout << "ClapTrap " << _name << " took " << amount << " damages !" << std::endl;
	}
		
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "ClapTrap " << _name << " can't attacks repair himself because he's dead !" << std::endl;
	else if (energyPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs himself and has now" << hitPoints << " hit points !" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't repairs himself because he don't have enough energyPoints !" << std::endl;
}