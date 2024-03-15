/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 04:22:58 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/15 16:29:49 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <limits>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &other);
        void sortVector(int argc, char **argv);
        void sortList(int argc, char **argv);
        class WrongArgumentException : public std::exception{
            public:
                const char* what() const throw () { return ("\033[1m\033[31mError: Expressions needed.\033[0m");}};
        class BadArgumentException : public std::exception{
            public:
                const char* what() const throw () { return ("\033[1m\033[31mError: Bad argument.\033[0m");}};
};

#endif