/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:43:54 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 07:09:58 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	std::cout << "Zombie sur la heap : " << std::endl;
	Zombie zombieHeap("Heap");
	
	std::cout << "Zombie sur la stack : " << std::endl;
	Zombie* zombieStack = newZombie("Stack");
	zombieStack->announce();
	delete zombieStack;

	std::cout << "Ramdom chump : " << std::endl;
	randomChump("CHUMPPP");
	return (0);
}