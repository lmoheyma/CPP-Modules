/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:05:35 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 01:36:48 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	
}

PhoneBook::~PhoneBook()
{
	
}

int PhoneBook::readInputSearch(std::string prompt) const
{
	int running = 1;
	std::string res = "";
	int	check = 0;
	
	while (running && !std::cin.eof())
	{
		std::cout << prompt;
		std::getline(std::cin, res);
		if ((atoi(res.c_str()) >= 1 && atoi(res.c_str()) <= 8))
			running = 0;
		else if (std::cin.eof())
		{
			running = 0;
			check = 1;
		}
		else
		{
			std::cin.clear();
			// std::cin.ignore(10000, '\n');
			std::cout << "Invalid input, please retry :)" << std::endl;
		}
	}
	if (check)
		return (0);
	return (atoi(res.c_str()));
}

void	PhoneBook::info(void) const
{
	std::cout << "Commandes disponible :" << std::endl;
	std::cout << "\tADD : Ajouter un contact" << std::endl;
	std::cout << "\tSEARCH : Rechercher un contact" << std::endl;
	std::cout << "\tEXIT : Sortir du programme" << std::endl;
}

void	PhoneBook::addContact(void)
{
	static int i;
	int flag = 0;
	
	this->contacts[i % 8].initContact(&flag);
	if (flag)
		return ;
	this->contacts[i % 8].setIndex(i % 8);
	i++;
}

void	PhoneBook::showPhoneBook(void) const
{
	int j;

	j = 0;
	std::cout << "Index      | First Name | Last Name  | Nickname" << std::endl;
	while (j < 8)
		this->contacts[j++].showContact();
}

void	PhoneBook::searchContact(void) const
{
	int i;
	
	i = this->readInputSearch("Entrez l'index d'un contact a afficher : ");
	if (i == 0)
		return ;
	this->contacts[i - 1].displayContact();
}