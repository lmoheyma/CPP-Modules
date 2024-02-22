/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:43:54 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 08:16:04 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	Zombie* squad = zombieHorde(4, "Zombie");
	for (int i = 0; i < 4; i++)
		squad->announce();
	delete [] squad;
	return (0);
}