/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:39:58 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/15 03:04:03 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN::~RPN()
{

}

RPN& RPN::operator=(const RPN &other)
{
    (void)other;
    return (*this);
}

int RPN::calculator(std::string str)
{
    int nb1;
    int nb2;
    int i = 0;
    int res;
    std::stack<int> stack;

    while (str[i])
    {
        if (str[i] == ' ')
        {
            i++;
            continue ;
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (stack.size() < 2)
                throw RPN::BadArgumentException();
            nb2 = stack.top();
            stack.pop();
            nb1 = stack.top();
            stack.pop();
            switch(str[i])
            {
                case '+':
                    res = nb1 + nb2;
                    break ;
                case '-':
                    res = nb1 - nb2;
                    break ;
                case '*':
                    res = nb1 * nb2;
                    break ;
                case '/':
                    if (nb2 == 0)
                        throw RPN::DivisionByZeroException();
                    res = nb1 / nb2;
                    break ;
            }
            stack.push(res);
        }
        else
        {
            stack.push(str[i] - '0');
        }
        i++;
    }
    return (stack.top());
}