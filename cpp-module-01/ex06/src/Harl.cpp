/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:45:12 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/22 18:06:55 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

HarlFilter::HarlFilter()
{
	
}

HarlFilter::~HarlFilter()
{
	
}

void HarlFilter::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do !" << std::endl << std::endl;
}

void HarlFilter::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger !" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
}

void HarlFilter::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void HarlFilter::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable !" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl << std::endl;
}

void HarlFilter::complain(std::string level, int i)
{
	std::string lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	(void)level;
	switch (i)
	{
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
		break;
	default:
		break;
	}
}