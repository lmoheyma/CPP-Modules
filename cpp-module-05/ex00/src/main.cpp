/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:25:00 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/29 21:40:39 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Bob("Bob", 1);
	std::cout << Bob << std::endl;
	Bob.incrementGrade();
	std::cout << Bob << std::endl;
	Bob.decrementGrade();
	std::cout << Bob << std::endl;
	Bureaucrat Ted("Bob", 0);
	Bureaucrat Chris("Bob", 200);
	return (0);
}