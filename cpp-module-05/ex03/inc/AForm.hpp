/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:38:11 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/04 17:05:58 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signatureGrade;
		const int _executeGrade;
	public:
		AForm();
		AForm(const std::string name, int signatureGrade, int executeGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw() { return ("\033[1m\033[35mToo high grade!\033[0m");}};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw () { return ("\033[1m\033[35mToo low grade!\033[0m");}};
		class AlreadySignedException : public std::exception{
			public:
				const char* what() const throw () { return ("\033[1m\033[35mForm is alreay signed!\033[0m");}};
		class NotSignedException : public std::exception{
			public:
				const char* what() const throw () { return ("\033[1m\033[35mForm is not signed!\033[0m");}};
		std::string getName(void) const ;
		bool isSigned(void) const ;
		void beSigned(Bureaucrat &bureaucrat);
		int getSignatureGrade(void) const ;
		int getExecuteGrade(void) const ;
		virtual void execute(Bureaucrat const &executor) const = 0 ;
};

std::ostream& operator<<(std::ostream &os, AForm const &f);

#endif