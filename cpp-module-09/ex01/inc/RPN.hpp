/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:40:20 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/15 02:40:42 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstring>

class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        ~RPN();
        RPN& operator=(const RPN &other);
        static int calculator(std::string str);
        class DivisionByZeroException : public std::exception{
            public:
                const char* what() const throw () { return ("\033[1m\033[31mError: can't divide by zero !\033[0m");}};
        class WrongArgumentException : public std::exception{
            public:
                const char* what() const throw () { return ("\033[1m\033[31mError: Expressions needed.\033[0m");}};
        class BadArgumentException : public std::exception{
            public:
                const char* what() const throw () { return ("\033[1m\033[31mError: Bad argument.\033[0m");}};
};

#endif