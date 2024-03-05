/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:30:33 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/05 17:17:50 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("Default")
{
	std::cout << "\033[1m\033[33mPresidentialPardonForm default constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[1m\033[33mPresidentialPardonForm target constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
	std::cout << "\033[1m\033[35mPresidentialPardonForm copy constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[1m\033[31mPresidentialPardonForm destructor called\033[0m" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (isSigned() == false)
			throw AForm::NotSignedException();
	}
	catch (const AForm::NotSignedException& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	try
	{
		if (executor.getGrade() > this->getExecuteGrade())
			throw AForm::GradeTooLowException();
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout << "\033[1m\033[32m" << _target << " has been pardonned by Zaphod Beeblebrox!\033[0m" << std::endl;
}
