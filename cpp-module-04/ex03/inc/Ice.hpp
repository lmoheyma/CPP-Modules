/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:17:38 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 16:39:26 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		
	public:
		Ice();
		Ice(const Ice &other);
		~Ice();
		Ice& operator=(const Ice &other);
		Ice* clone(void) const ;
		void use(ICharacter &target);
};

#endif