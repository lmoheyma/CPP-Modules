/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:48:29 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/08 22:06:22 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string type;
        type = ScalarConverter::setType(argv[1]);
        try
        {
            ScalarConverter::convert(argv[1], type);
        }
        catch (const ScalarConverter::ImpossibleConversionException& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}