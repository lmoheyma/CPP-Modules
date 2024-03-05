/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:44:57 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/05 17:26:28 by lmoheyma         ###   ########.fr       */
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
	os << "\033[1m\033[37m" << f.getName() << ", bureaucrat grade " << f.getGrade() << ".\033[0m";
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
