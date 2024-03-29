/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:44:57 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/04 18:50:08 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(13)
{
	std::cout << "\033[1m\033[33mBureaucrat default constructor called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "\033[1m\033[33mBureaucrat name/grade constructor called\033[0m" << std::endl;
	try
	{
		if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "\033[1m\033[35mBureaucrat copy constructor called\033[0m" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[1m\033[31mBureaucrat destructor called\033[0m" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "\033[1m\033[36mBureaucrat copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, Bureaucrat const &f)
{
	os << f.getName() << ", bureaucrat grade " << f.getGrade() << ".";
	return (os);
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (_grade - 1 < 1)
			throw (Bureaucrat::GradeTooHighException());
		else
			_grade--;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if (_grade + 1 > 150)
			throw (Bureaucrat::GradeTooLowException());
		else
			_grade++;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "\033[1m\033[32m" << _name << " signed " << form.getName() << "\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\033[1m\033[32m" << _name << " couldn't sign " << form.getName() << " because -> " << e.what() << "\033[0m" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		if (form.isSigned() == false)
			throw AForm::NotSignedException();
		if (_grade > form.getExecuteGrade())
			throw AForm::GradeTooLowException();
		else
			std::cout << "\033[1m\033[32m" << _name << " executed " << form.getName() << "\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\033[1m\033[32m" << _name << " couldn't execute " << form.getName() << " because -> " << e.what() << "\033[0m" << std::endl;
	}
	
}