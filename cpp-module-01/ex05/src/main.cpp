/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:59:11 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/22 18:12:49 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int check = 0;
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
		{
			std::cout << lvl[i] << " : " << std::endl;
			harl.complain(lvl[i]);
		}
		else
			std::cout << "Wrong parameters" << std::endl;
	}
	else
		std::cout << "Format : ./Harl <level>" << std::endl;
}