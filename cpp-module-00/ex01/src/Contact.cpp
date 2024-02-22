/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:05:33 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 01:16:44 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact()
{
	
}

Contact::~Contact()
{

}

void Contact::initContact(int *flag)
{
	this->firstName = this->readInput("First name : ");
	this->lastName = this->readInput("Last name : ");
	this->nickname = this->readInput("Nickname : ");
	this->phoneNumber = this->readInput("Phone number : ");
	this->darkestSecret = this->readInput("Darkest secret : ");
	if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty() || this->phoneNumber.empty() || this->darkestSecret.empty())
		*flag = 1;
	std::cout << std::endl;
}

void Contact::setIndex(int i)
{
	this->index = i;
}

std::string Contact::readInput(std::string prompt)
{
	int running = 1;
	std::string res = "";
	// int	check;
	
	while (running && !std::cin.eof())
	{
		std::cout << prompt;
		std::getline(std::cin, res);
		if (!res.empty() || std::cin.eof())
			running = 0;
		else if (res.empty())
			running = 0;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input, please retry :)" << std::endl;
		}
	}
	return (res);
}

std::string Contact::crop(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void	Contact::showContact(void) const
{	
	if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty() || this->phoneNumber.empty() || this->darkestSecret.empty())
		return ;
	std::cout << std::setw(10) << this->index + 1 << " | ";
	std::cout << std::setw(10) << this->crop(this->firstName) << " | ";
	std::cout << std::setw(10) << this->crop(this->lastName) << " | ";
	std::cout << std::setw(10) << this->crop(this->nickname) << std::endl;
}

void	Contact::displayContact(void) const
{
	if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty() || this->phoneNumber.empty() || this->darkestSecret.empty())
		return ;
	std::cout << "First Name : " << this->firstName << std::endl;
	std::cout << "Last Name : " << this->lastName << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone Number : " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret : " << this->darkestSecret << std::endl;
}