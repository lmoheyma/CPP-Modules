/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:08:50 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/12 03:18:39 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);

		std::cout << "\033[1m\033[36mTop of the stack: \033[1m\033[37m" << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "\033[1m\033[36mSize of the stack: \033[1m\033[37m" << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		std::cout << "\033[1m\033[35mElements of the stack: \033[1m\033[37m";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}
	{
		MutantStack<int> mstack;

		for (int i = 0; i < 5; i++)
			mstack.push(i);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		std::cout << "\033[1m\033[35mElements of the stack: \033[1m\033[37m";
		while (it != ite)
		{
			std::cout << "\033[1m\033[37m" << *it << " ";
			++it;
		}
		std::cout << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << "\033[1m\033[36mTop of the stack: \033[1m\033[37m" << mstack.top() << std::endl;
			mstack.pop();
		}
		it = mstack.begin();
		ite = mstack.end();
		
		std::cout << "\033[1m\033[35mElements of the stack: \033[1m\033[37m";
		while (it != ite)
		{
			std::cout << "\033[1m\033[37m" << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	return (0);
}