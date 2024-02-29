/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:44:55 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/29 21:36:43 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &other);
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw() { return ("Too high grade!");}};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw () { return ("Too low grade!");}};
		std::string getName(void) const ;
		int getGrade(void) const ;
		void incrementGrade(void);
		void decrementGrade(void);
};

std::ostream& operator<<(std::ostream &os, Bureaucrat const &f);

#endif