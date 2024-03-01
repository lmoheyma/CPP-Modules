/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:44:29 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/01 17:56:53 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form"), _signatureGrade(1), _executeGrade(1)
{
	std::cout << "\033[1m\033[33mForm default constructor called\033[0m" << std::endl;
	_isSigned = false;
}

Form::Form(const std::string name, int signatureGrade, int executeGrade) : _name(name), _signatureGrade(signatureGrade), _executeGrade(executeGrade)
{
	std::cout << "\033[1m\033[33mForm name constructor called\033[0m" << std::endl;
	try
	{
		if (signatureGrade > 150 || executeGrade > 150)
			throw (Form::GradeTooLowException());
		else
			_isSigned = false;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		if (signatureGrade < 1 || executeGrade < 1)
			throw (Form::GradeTooHighException());
		else
			_isSigned = false;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Form::Form(const Form &other) : _name(other._name),
	_isSigned(other._isSigned),
	_signatureGrade(other._signatureGrade),
	_executeGrade(other._executeGrade)
{
	std::cout << "\033[1m\033[35mForm copy constructor called\033[0m" << std::endl;
}

Form::~Form()
{
	std::cout << "\033[1m\033[31mForm destructor called\033[0m" << std::endl;
}

Form& Form::operator=(const Form &other)
{
	std::cout << "\033[1m\033[36mForm copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &os, Form const &f)
{
	if (f.isSigned())
		os << "\033[1m\033[36mForm " << f.getName() << " is signed, and require a grade " << f.getSignatureGrade() << " to be signed and a grade " << f.getExecuteGrade() << " to be execute.\033[0m";
	else
		os << "\033[1m\033[36mForm " << f.getName() << " is not signed, and require a grade " << f.getSignatureGrade() << " to be signed and a grade " << f.getExecuteGrade() << " to be execute.\033[0m";
	return (os);
}

std::string Form::getName(void) const
{
	return (_name);	
}

bool Form::isSigned(void) const
{
	return (_isSigned);
}

int Form::getSignatureGrade(void) const
{
	return (_signatureGrade);
}

int Form::getExecuteGrade(void) const
{
	return (_executeGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_isSigned)
		throw (Form::AlreadySignedException());
	if (bureaucrat.getGrade() > _signatureGrade)
		throw (Form::GradeTooLowException());
	else
		_isSigned = true;
}