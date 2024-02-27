/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:17:21 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 17:49:37 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[1m\033[33mBrain default constructor called\033[0m" << std::endl;
}

Brain::~Brain()
{
	std::cout << "\033[1m\033[31mBrain destructor called\033[0m" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "\033[1m\033[33mBrain copy constructor called\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << "\033[1m\033[36mBrain copy assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}
