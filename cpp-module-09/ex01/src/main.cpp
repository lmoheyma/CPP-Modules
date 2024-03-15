/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:26:16 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/15 02:47:06 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw RPN::WrongArgumentException();
    }
    catch(const RPN::WrongArgumentException& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    try
    {
        for (size_t i = 0; i < std::strlen(argv[1]); i++)
        {
            if (!((argv[1][i] >= '0' && argv[1][i] <= '9') || argv[1][i] == ' ' || argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*' || argv[1][i] == '/'))
                throw RPN::BadArgumentException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    try
    {
        std::cout << "\033[1m\033[37m" << RPN::calculator(argv[1]) << "\033[0m" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return (0);
}