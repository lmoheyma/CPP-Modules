/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:05:30 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 00:56:22 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "../inc/Contact.hpp"
# include <iostream>
# include <stdlib.h>

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void info(void) const;
		void addContact(void);
		void showPhoneBook(void) const;
		void searchContact(void) const;
		int readInputSearch(std::string prompt) const;
};

#endif