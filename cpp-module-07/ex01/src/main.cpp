/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:10:10 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/12 19:22:58 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    {
        std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
        std::cout << "/*                     INT ARRAY                     */" << std::endl;
        std::cout << "/* ************************************************* */\033[1m\033[37m" << std::endl;
        int array[] = {2, 0, 2, 4};
        iter(array, 4, print_tab<int>);
        std::cout << "\033[0m" << std::endl;
    }
    {
        std::cout << "\033[1m\033[32m/* ************************************************* */" << std::endl;
        std::cout << "/*                     CHAR ARRAY                    */" << std::endl;
        std::cout << "/* ************************************************* */\033[1m\033[37m" << std::endl;
        char array[] = {'h', 'e', 'l', 'l', 'o', '!'};
        iter(array, 6, print_tab<char>);
        std::cout << "\033[0m" << std::endl;
    }
    return (0);
}
