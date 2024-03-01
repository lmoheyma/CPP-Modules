/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:38:11 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/01 17:55:36 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signatureGrade;
		const int _executeGrade;
	public:
		Form();
		Form(const std::string name, int signatureGrade, int executeGrade);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw() { return ("\033[1m\033[35mToo high grade!\033[0m");}};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw () { return ("\033[1m\033[35mToo low grade!\033[0m");}};
		class AlreadySignedException : public std::exception{
			public:
				const char* what() const throw () { return ("\033[1m\033[35mForm is alreay signed!\033[0m");}};
		std::string getName(void) const ;
		bool isSigned(void) const ;
		void beSigned(Bureaucrat &bureaucrat);
		int getSignatureGrade(void) const ;
		int getExecuteGrade(void) const ;
};

std::ostream& operator<<(std::ostream &os, Form const &f);

#endif