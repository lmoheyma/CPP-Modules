/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:57:08 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/09 01:18:34 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
    Base* base;

    base = generate();
    std::cout << "\033[1m\033[33mIdentify with pointer and dynamic cast : " << std::endl;
    identify(base);
    std::cout << "\033[1m\033[33mIdentify with reference, dynamic cast and exceptions : " << std::endl;
    identify(*base);
    return (0);
}