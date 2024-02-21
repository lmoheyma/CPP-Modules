/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:52:24 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 01:07:14 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Contact.hpp"
# include "../inc/PhoneBook.hpp"

int main(int argc, char **argv)
{
	PhoneBook phoneBook;
	std::string	buffer = "";
	(void)argc;
	(void)argv;
	
	phoneBook.info();
	while(buffer != "EXIT" && !std::cin.eof())
	{
		std::cout << "> ";
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
			phoneBook.addContact();
		else if (buffer == "SEARCH")
		{
			phoneBook.showPhoneBook();
			phoneBook.searchContact();
		}
		else if (buffer != "ADD" && buffer != "SEARCH" && buffer != "EXIT" && !std::cin.eof())
			phoneBook.info();
	}
}
