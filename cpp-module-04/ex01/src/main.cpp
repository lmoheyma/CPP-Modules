/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:28 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 17:09:44 by lmoheyma         ###   ########.fr       */
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
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << "\033[1m\033[37m";
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\033[0m";
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		
		std::cout << "\033[1m\033[37m";
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\033[0m";
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		delete meta;
		delete i;
	}
	return (0);
}