/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:28 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/28 21:35:59 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

int main(void)
{
	// AAnimal animal;
	AAnimal* dog = new Dog();
	dog->makeSound();
	// animal.makeSound();
	delete dog;
	return (0);
}