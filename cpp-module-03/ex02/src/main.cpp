/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:39 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/26 17:34:27 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

int main(void)
{
	FragTrap Bob;
	FragTrap Ted("Ted");

	std::cout << "\033[1m\033[37m";
	for (int i = 0; i < 11; i++)
	{
		Bob.attack("Ted");
		Ted.takeDamage(20);
	}
	Bob.highFivesGuys();
	std::cout << "\033[0m";
	return (0);
}