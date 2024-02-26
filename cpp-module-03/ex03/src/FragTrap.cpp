/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:28 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/26 17:32:51 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "\033[1m\033[33mFragTrap Default constructor called\033[0m" << std::endl; 
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	_name = "Bob";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[1m\033[33mFragTrap Name constructor called\033[0m" << std::endl; 
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	_name = name;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "\033[1m\033[33mFragTrap Copy constructor called\033[0m" << std::endl;
	hitPoints = other.getHitPoints();
	energyPoints = other.getEnergyPoints();
	attackDamage = other.getAttackDamage();
	_name = other.getName();
}

FragTrap::~FragTrap()
{
	std::cout << "\033[1m\033[31mFragTrap Destructor called\033[0m" << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "\033[1m\033[36mFragTrap Copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		hitPoints = other.getHitPoints();
		attackDamage = other.getAttackDamage();
		energyPoints = other.getEnergyPoints();
		_name = other.getName();
	}
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " can't attacks " << target << " because he's dead !" << std::endl;
		return ;
	}
	else if (energyPoints > 0)
	{
		energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage !" << std::endl;
	}
	else
		std::cout << "FragTrap " << _name << " can't attacks " << target << ", because he don't have enough energyPoints !" << std::endl;

}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is already dead !" << std::endl;
		return ;
	}
	else if (amount >= hitPoints)
	{
		hitPoints = 0;
		std::cout << "FragTrap " << _name << " is dead !" << std::endl;
	}
	else
	{
		hitPoints-=amount;
		std::cout << "FragTrap " << _name << " took " << amount << " damages !" << std::endl;
	}
		
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "FragTrap " << _name << " can't attacks repair himself because he's dead !" << std::endl;
	else if (energyPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "FragTrap " << _name << " repairs himself and has now" << hitPoints << " hit points !" << std::endl;
	}
	else
		std::cout << "FragTrap " << _name << " can't repairs himself because he don't have enough energyPoints !" << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << _name << " says HIGH FIVES !" << std::endl;
}