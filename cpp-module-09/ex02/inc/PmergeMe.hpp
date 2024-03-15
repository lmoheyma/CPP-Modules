/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 04:22:58 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/15 04:26:10 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &other);
};

#endif