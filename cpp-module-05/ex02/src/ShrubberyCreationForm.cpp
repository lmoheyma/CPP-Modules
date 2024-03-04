/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:30:37 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/04 18:54:25 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("Default")
{
	std::cout << "\033[1m\033[33mShrubberyCreationForm default constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Default", 145, 137), _target(target)
{
	std::cout << "\033[1m\033[33mShrubberyCreationForm target constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	std::cout << "\033[1m\033[35mShrubberyCreationForm copy constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[1m\033[31mShrubberyCreationForm destructor called\033[0m" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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
	
	std::ofstream outfile(strcat((char *)(this->_target.c_str()), "_shrubbery"));

	if (outfile.is_open())
	{                                                     
        outfile << "                                     .         ;         " << std::endl; 
        outfile << "        .              .              ;%     ;;    " << std::endl;
        outfile << "          ,           ,                :;%  %;    " << std::endl;
        outfile << "           :         ;                   :;%;'     .,    " << std::endl;
        outfile << "  ,.        %;     %;            ;        %;'    ,; " << std::endl;
        outfile << "    ;       ;%;  %%;        ,     %;    ;%;    ,%' " << std::endl;
        outfile << "     %;       %;%;      ,  ;       %;  ;%;   ,%;'  " << std::endl;
        outfile << "      ;%;      %;        ;%;        % ;%;  ,%;' " << std::endl;
        outfile << "       `%;.     ;%;     %;'         `;%%;.%;' " << std::endl;
        outfile << "        `:;%.    ;%%. %@;        %; ;@%;%' " << std::endl;
        outfile << "           `:%;.  :;bd%;          %;@%;' " << std::endl;
        outfile << "             `@%:.  :;%.         ;@@%;'    " << std::endl;
        outfile << "               `@%.  `;@%.      ;@@%;          " << std::endl;
        outfile << "                 `@%%. `@%%    ;@@%;         " << std::endl;
        outfile << "                   ;@%. :@%%  %@@%;        " << std::endl;
        outfile << "                     %@bd%%%bd%%:;      " << std::endl;
        outfile << "                       #@%%%%%:;; " << std::endl;
        outfile << "                       %@@%%%::; " << std::endl;
        outfile << "                       %@@@%(o);  . '          " << std::endl;
        outfile << "                       %@@@o%;:(.,'          " << std::endl;
        outfile << "                   `.. %@@@o%::;          " << std::endl;
        outfile << "                      `)@@@o%::;          " << std::endl;
        outfile << "                       %@@(o)::;         " << std::endl;
        outfile << "                      .%@@@@%::;          " << std::endl;
        outfile << "                      ;%@@@@%::;.           " << std::endl;
        outfile << "                     ;%@@@@%%:;;;.  " << std::endl;
        outfile << "                 ...;%@@@@@%%:;;;;,..     " << std::endl;
	}
	outfile.close();
}
