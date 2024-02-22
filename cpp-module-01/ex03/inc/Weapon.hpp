/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:21:19 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 08:27:15 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string getType(void) const ;
		void		setType(std::string type);
};

#endif