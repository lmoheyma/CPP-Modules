/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:27:52 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 16:39:18 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		
	public:
		Cure();
		Cure(const Cure &other);
		~Cure();
		Cure& operator=(const Cure &other);
		Cure* clone(void) const ;
		void use(ICharacter &target);
};

#endif