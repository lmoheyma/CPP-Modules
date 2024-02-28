/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:40:12 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 18:32:26 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inv[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		~Character();
		Character& operator=(const Character &other);
		std::string const & getName(void) const ;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif