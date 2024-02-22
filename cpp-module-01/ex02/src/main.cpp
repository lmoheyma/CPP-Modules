/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:48:38 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/22 16:58:47 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Adresse de string : " << &string << "    |    Valeur de string : " << string << std::endl;
	std::cout << "Adresse de stringPTR : " << stringPTR << "    |    Valeur de stringPTR : " << *stringPTR << std::endl;
	std::cout << "Adresse de stringRED : " << &stringREF << "    |    Valeur de stringREF : " << stringREF << std::endl;
	return (0);
}
