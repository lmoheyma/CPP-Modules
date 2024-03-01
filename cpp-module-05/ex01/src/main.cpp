/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:25:00 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/01 18:00:38 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Bob("Bob", 9);
	Form form("Form", 10, 10);
	std::cout << form << std::endl;
	Bob.signForm(form);
	return (0);
}