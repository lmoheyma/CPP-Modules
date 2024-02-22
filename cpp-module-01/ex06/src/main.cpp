/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:49:42 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/22 18:07:54 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int argc, char **argv)
{
	HarlFilter harl;
	std::string lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	check = 0;
	int i;
	
	if (argc == 2)
	{
		for (i = 0; i < 4; i++)
		{
			if (argv[1] == lvl[i])
			{
				check = 1;
				break;
			}
		}
		if (check)
			harl.complain(argv[1], i);
		else
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	else
		std::cout << "Format : ./HarlFilter <level>" << std::endl;
}