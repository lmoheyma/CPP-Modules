/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:24:39 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/09 01:17:57 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>
#include <stdexcept>

Base* generate(void)
{
    srand(time(NULL));
    int random = std::rand() % 3;
    if (random == 0)
        return (new A);
    if (random == 1)
        return (new B);
    if (random == 2)
        return (new C);
    return (NULL);
}

void identify(Base* p)
{
    A* ptrA = dynamic_cast<A*>(p);
    if (ptrA)
    {
        std::cout << "\033[1m\033[35mObject type is A\033[0m" << std::endl;
        return ;
    }
    B* ptrB = dynamic_cast<B*>(p);
    if (ptrB)
    {
        std::cout << "\033[1m\033[35mObject type is B\033[0m" << std::endl;
        return ;
    }
    C* ptrC = dynamic_cast<C*>(p);
    if (ptrC)
    {
        std::cout << "\033[1m\033[35mObject type is C\033[0m" << std::endl;
        return ;
    }
    std::cout << "\033[1m\033[31mInvalid type\033[0m" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& refA = dynamic_cast<A&>(p);
        (void)refA;
        std::cout << "\033[1m\033[35mObject type is A\033[0m" << std::endl;
    }
    catch (const std::exception& e)
    {
        try
        {
            B& refB = dynamic_cast<B&>(p);
            (void)refB;
            std::cout << "\033[1m\033[35mObject type is B\033[0m" << std::endl;
        }
        catch (const std::exception& e)
        {
            try
            {
                C& refC = dynamic_cast<C&>(p);
                (void)refC;
                std::cout << "\033[1m\033[35mObject type is C\033[0m" << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cerr << "\033[1m\033[31mInvalid type\033[0m" << std::endl;
            }
        }
    }
}
