/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:42:15 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/05 17:13:00 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern::~Intern()
{

}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm* shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* presidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	int i = 0;
	
	pf tab[] = {&shrubbery, &robotomy, &presidential};
	std::string formTab[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	while (i < 4 && name != formTab[i])
		i++;
	if (i < 4)
	{
		AForm* temp = (*tab[i])(target);
		std::cout << "\033[1m\033[37mIntern creates " << name << "\033[0m" << std::endl;
		return temp;
	}
	else
	{
		std::cout << "\033[1m\033[30m" << name << " form doesn't exist!\033[0m" << std::endl;
	}
	return (NULL);
}