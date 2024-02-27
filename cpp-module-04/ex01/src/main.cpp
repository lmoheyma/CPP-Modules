/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:28 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 23:52:55 by lmoheyma         ###   ########.fr       */
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
		std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
		std::cout << "/*                    LEAKS TESTS                    */" << std::endl;
		std::cout << "/* ************************************************* */\033[0m" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		const Animal *animal[5]; 
		for (int i = 0; i < 5; i++)
			if (i % 2 == 0)
				animal[i] = new Dog();
			else
				animal[i] = new Cat();
		for (int i = 0; i < 5; i++)
			delete animal[i];
	}
	{
		std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
		std::cout << "/*                  DEEP COPY TESTS                  */" << std::endl;
		std::cout << "/* ************************************************* */\033[0m" << std::endl;
		Dog Rex;
		Rex.getBrain()->setIdea("Food", 0);
		std::cout << "\033[1m\033[36m(Rex) Idea 0 : " << Rex.getBrain()->getIdea(0) << std::endl;
		Dog Medor(Rex);
		Medor.getBrain()->setIdea("Chips", 0);
		std::cout << "\033[1m\033[36m(Rex) Idea 0 : " << Rex.getBrain()->getIdea(0) << std::endl;
		std::cout << "(Medor) Idea 0 : " << Medor.getBrain()->getIdea(0) << "\033[0m" << std::endl;
	}
	return (0);
}