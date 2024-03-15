/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:50:34 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/15 16:35:06 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw PmergeMe::WrongArgumentException();
	}
	catch(const PmergeMe::WrongArgumentException& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	try
	{
		for (size_t i = 1; i < (size_t)argc; i++)
        {
			for (size_t j = 0; j < std::strlen(argv[i]); j++)
        	{
				if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
					throw PmergeMe::BadArgumentException();
			}
			long value = std::atol(argv[i]);
			if (value > std::numeric_limits<int>::max())
				throw PmergeMe::BadArgumentException();
        }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);	
	}
	PmergeMe pmm;

	pmm.sortVector(argc, argv);
	pmm.sortList(argc, argv);
	return (0);
}
