/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:39:59 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 19:03:51 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Bob")
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
}

Character::Character(const Character &other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
		_inv[i] = other._inv[i];
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inv[i] != NULL)
			delete _inv[i];
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
			_inv[i] = other._inv[i];
	}
	return (*this);
}

std::string const & Character::getName(void) const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inv[i] == NULL)
		{
			_inv[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (_inv[idx] != NULL)
		_inv[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (_inv[idx] != NULL)
		_inv[idx]->use(target);
}
