/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:28:48 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/11 20:20:14 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		{
			std::cout << "\033[1m\033[33mMutantStack default constructor called\033[0m" << std::endl;
		}
		MutantStack(const MutantStack &other)
		{
			(void)other;
			std::cout << "\033[1m\033[35mMutantStack copy constructor called\033[0m" << std::endl;
		}
		~MutantStack()
		{
			std::cout << "\033[1m\033[31mMutantStack destructor called\033[0m" << std::endl;
		}
		MutantStack& operator=(const MutantStack &other)
		{
			this->c = other.c;
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin()
		{
			return (this->c.begin());	
		}
		iterator end()
		{
			return (this->c.end());
		}
};

#endif