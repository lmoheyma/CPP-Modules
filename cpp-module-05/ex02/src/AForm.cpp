/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:44:29 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/04 17:05:38 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signatureGrade(1), _executeGrade(1)
{
	std::cout << "\033[1m\033[33mAForm default constructor called\033[0m" << std::endl;
	_isSigned = false;
}

AForm::AForm(const std::string name, int signatureGrade, int executeGrade) : _name(name), _signatureGrade(signatureGrade), _executeGrade(executeGrade)
{
	std::cout << "\033[1m\033[33mAForm name constructor called\033[0m" << std::endl;
	try
	{
		if (signatureGrade > 150 || executeGrade > 150)
			throw (AForm::GradeTooLowException());
		else
			_isSigned = false;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		if (signatureGrade < 1 || executeGrade < 1)
			throw (AForm::GradeTooHighException());
		else
			_isSigned = false;
	}
	catch (const AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

AForm::AForm(const AForm &other) : _name(other._name),
	_isSigned(other._isSigned),
	_signatureGrade(other._signatureGrade),
	_executeGrade(other._executeGrade)
{
	std::cout << "\033[1m\033[35mAForm copy constructor called\033[0m" << std::endl;
}

AForm::~AForm()
{
	std::cout << "\033[1m\033[31mAForm destructor called\033[0m" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	std::cout << "\033[1m\033[36mAForm copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &os, AForm const &f)
{
	if (f.isSigned())
		os << "\033[1m\033[36mAForm " << f.getName() << " is signed, and require a grade " << f.getSignatureGrade() << " to be signed and a grade " << f.getExecuteGrade() << " to be execute.\033[0m";
	else
		os << "\033[1m\033[36mAForm " << f.getName() << " is not signed, and require a grade " << f.getSignatureGrade() << " to be signed and a grade " << f.getExecuteGrade() << " to be execute.\033[0m";
	return (os);
}

std::string AForm::getName(void) const
{
	return (_name);	
}

bool AForm::isSigned(void) const
{
	return (_isSigned);
}

int AForm::getSignatureGrade(void) const
{
	return (_signatureGrade);
}

int AForm::getExecuteGrade(void) const
{
	return (_executeGrade);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_isSigned)
		throw (AForm::AlreadySignedException());
	if (bureaucrat.getGrade() > _signatureGrade)
		throw (AForm::GradeTooLowException());
	else
		_isSigned = true;
}
