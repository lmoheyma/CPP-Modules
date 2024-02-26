/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:39 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/26 17:19:55 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int main(void)
{
	ClapTrap test;
	ScavTrap Bob;
	ScavTrap Ted("Ted");

	std::cout << "\033[1m\033[37m";
	for (int i = 0; i < 11; i++)
	{
		Bob.attack("Ted");
		Ted.takeDamage(20);
	}
	Ted.guardGate();
	std::cout << "\033[0m";
	return (0);
}