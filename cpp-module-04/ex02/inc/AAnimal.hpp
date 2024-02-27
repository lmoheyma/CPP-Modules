/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:11:07 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 18:57:45 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &other);
		std::string getType(void) const ;
		virtual void makeSound(void) const ;
};

#endif