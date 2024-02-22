/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:57 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/22 18:04:48 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{
	
}

Harl::~Harl()
{
	
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger !" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable !" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;
	
	pf tab[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && level != lvl[i])
		i++;
	if (i < 4)
		(this->*tab[i])();
}