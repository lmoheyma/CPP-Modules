/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:20:49 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 16:19:40 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include <iostream> 
#include "Animal.hpp"          
 
class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);
		void makeSound(void) const ;
};

#endif