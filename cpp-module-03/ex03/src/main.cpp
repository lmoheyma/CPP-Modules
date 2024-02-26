/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:39 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/26 18:36:57 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

int main(void)
{
	DiamondTrap Bob;
	DiamondTrap Ted("Ted");
	// DiamondTrap Ted(Bob);

	std::cout << "\033[1m\033[37m";
	for (int i = 0; i < 11; i++)
	{
		Bob.attack("Ted");
		Ted.takeDamage(20);
	}
	Ted.whoAmI();
	Bob.whoAmI();
	std::cout << "\033[0m";
	return (0);
}