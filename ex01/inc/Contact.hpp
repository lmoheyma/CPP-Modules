/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:05:28 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 01:17:09 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
#include <iomanip>

class Contact
{
	private:
		int	index;
		std::string firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		Contact();
		~Contact();
		std::string readInput(std::string prompt);
		void initContact(int *flag);
		void setIndex(int i);
		void showContact(void) const ;
		std::string crop(std::string str) const ;
		void displayContact(void) const ;
};

# endif