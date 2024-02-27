/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:28 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 18:54:56 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		const Animal *animal[10]; 
		for (int i = 0; i < 10; i++)
			if (i % 2 == 0)
				animal[i] = new Dog();
			else
				animal[i] = new Cat();
		for (int i = 0; i < 10; i++)
			delete animal[i];
	}
	{
		// test for deep copy
	}
	return (0);
}