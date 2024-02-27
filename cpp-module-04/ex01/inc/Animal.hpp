/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:11:07 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 16:21:19 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
		Animal &operator=(const Animal &other);
		std::string getType(void) const ;
		virtual void makeSound(void) const ;
};

#endif