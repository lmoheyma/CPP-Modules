/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:48:29 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/08 18:35:42 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter converter;
        converter.setType(argv[1]);
        try
        {
             converter.convert(argv[1]);
        }
        catch (const ScalarConverter::ImpossibleConversionException& e)
        {
            std::cerr << e.what() << '\n';
            return (0);
        }
        
        std::cout << converter << std::endl;
    }
    return (0);
}