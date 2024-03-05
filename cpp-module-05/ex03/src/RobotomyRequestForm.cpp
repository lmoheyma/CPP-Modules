/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:30:35 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/05 17:18:23 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("Default")
{
	std::cout << "\033[1m\033[33mRobotomyRequestForm default constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[1m\033[33mRobotomyRequestForm target constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
	std::cout << "\033[1m\033[35mRobotomyRequestForm copy constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[1m\033[31mRobotomyRequestForm destructor called\033[0m" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
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

	std::cout << "\033[1m\033[30mADASDGHTRK\033[0m" << std::endl;
	std::cout << "\033[1m\033[30mTRTHRTrthrth\033[0m" << std::endl;
	std::cout << "\033[1m\033[30mOIPYJYHRTGREG\033[0m" << std::endl;
	
	srand(time(0));
	int random = rand() % 2;
	if (random)
		std::cout << "\033[1m\033[32m" << _target << " has been robotomized!\033[0m" << std::endl;
	else
		std::cout << "\033[1m\033[32mThe robotomy of " << _target << " failed!\033[0m" << std::endl;
}

