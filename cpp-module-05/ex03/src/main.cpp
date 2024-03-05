/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:25:00 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/05 17:19:24 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
		std::cout << "/*                  SHRUBBERY FORM                   */" << std::endl;
		std::cout << "/* ************************************************* */\033[0m" << std::endl;
		Bureaucrat Bob("Bob", 145);
		ShrubberyCreationForm SForm("Shrubbery");
		std::cout << SForm << std::endl;
		SForm.execute(Bob);
		Bob.signForm(SForm);
		std::cout << SForm << std::endl;
		SForm.execute(Bob);
		Bob.executeForm(SForm);	
	}
	{
		std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
		std::cout << "/*                   ROBOTOMY FORM                   */" << std::endl;
		std::cout << "/* ************************************************* */\033[0m" << std::endl;
		Bureaucrat Bob("Bob", 45);
		RobotomyRequestForm SForm("Robotomy");
		std::cout << SForm << std::endl;
		SForm.execute(Bob);
		Bob.signForm(SForm);
		std::cout << SForm << std::endl;
		SForm.execute(Bob);
		Bob.executeForm(SForm);
	}
	{
		std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
		std::cout << "/*                 PRESIDENTIAL FORM                 */" << std::endl;
		std::cout << "/* ************************************************* */\033[0m" << std::endl;
		Bureaucrat Bob("Bob", 5);
		PresidentialPardonForm SForm("Presidential");
		std::cout << SForm << std::endl;
		SForm.execute(Bob);
		Bob.signForm(SForm);
		std::cout << SForm << std::endl;
		SForm.execute(Bob);
		Bob.executeForm(SForm);
	}
	{
		std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
		std::cout << "/*                    INTERN TEST                    */" << std::endl;
		std::cout << "/* ************************************************* */\033[0m" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	return (0);
}