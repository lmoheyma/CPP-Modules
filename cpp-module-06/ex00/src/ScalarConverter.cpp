/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:49:14 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/08 22:47:18 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	std::string type = "int";
	int i = 0;
	int flag = 0;
	char charValue = '\0';
	long int intValue = 0;
	float floatValue = 0.0f;
	double doubleValue = 0.0;
	int limits = 0;
	int overflow = 0;
	
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			continue ;
		}
		if (str[i] == '.' && flag == 1)
		{
			type = "other";
			break ;
		}
		if (str[i] == '.')
		{
			flag = 1;
			type = "double";
			i++;
			continue ;
		}
		if (str[i] == 'f' && i == (int)str.length() - 1 && str.length() != 1)
		{
			type = "float";
			break ;
		}
		else
		{
			type = "other";
			break ;
		}
	}
	if (!type.compare("int") && (str[0] == '+' || str[0] == '-') && str.length() == 1)
	{
		intValue = static_cast<int>(str[0]);;
		charValue = str[0];
		floatValue = static_cast<float>(str[0]);
		doubleValue = static_cast<double>(str[0]);
	}
	else if (!type.compare("int"))
	{
		intValue = std::atol(str.c_str());
		if (intValue > std::numeric_limits<int>::max())
			overflow = 1;
		if (intValue < std::numeric_limits<int>::min())
			overflow = 1;
		charValue = static_cast<char>(intValue);
		floatValue = static_cast<float>(intValue);
		doubleValue = static_cast<double>(intValue);
	}
	else if (!type.compare("double") || !type.compare("float"))
	{
		floatValue = std::atof(str.c_str());
		charValue = static_cast<char>(floatValue);
		intValue = static_cast<int>(floatValue);
		doubleValue = static_cast<double>(floatValue);
	}
	else if (!type.compare("other"))
	{
		if (str.length() == 1)
		{
			intValue = static_cast<int>(str[0]);;
			charValue = str[0];
			floatValue = static_cast<float>(str[0]);
			doubleValue = static_cast<double>(str[0]);
		}
		else if (!str.compare("nan") || !str.compare("nanf"))
		{
			charValue = 127;
			floatValue = std::numeric_limits<float>::quiet_NaN();
			doubleValue = std::numeric_limits<double>::quiet_NaN();
			limits = 1;
		}
		else if (!str.compare("-inff") || !str.compare("-inf"))
		{
			charValue = 127;
			floatValue = std::numeric_limits<float>::infinity() * -1;
			doubleValue = std::numeric_limits<double>::infinity() * -1;
			limits = 1;
		}
		else if (!str.compare("+inff") || !str.compare("+inf"))
		{
			charValue = 127;
			floatValue = std::numeric_limits<float>::infinity();
			doubleValue = std::numeric_limits<double>::infinity();
			limits = 1;
		}
		else
		{
			std::cout << "\033[1m\033[31mImpossible conversion!\033[0m" << std::endl;
			return ;
		}
	}
	if (limits)
	{
		std::cout << "\033[1m\033[37mChar: \033[1m\033[31mImpossible\033[0m" << std::endl;
		std::cout << "\033[1m\033[37mInt: \033[1m\033[31mImpossible\033[0m" << std::endl;
		std::cout << "\033[1m\033[37mFloat: \033[1m\033[32m" << floatValue << "f\033[0m" << std::endl;
		std::cout << "\033[1m\033[37mDouble: \033[1m\033[32m" << doubleValue << "\033[0m" << std::endl;
	}
	else
	{
		if (charValue < 33)
			std::cout << "\033[1m\033[37mChar: \033[1m\033[31mNon displayable\033[0m" << std::endl;
		else
			std::cout << "\033[1m\033[37mChar: \033[1m\033[32m'" << charValue << "'\033[0m" << std::endl;
		if (overflow)
			std::cout << "\033[1m\033[37mInt: \033[1m\033[31mOverflow\033[0m" << std::endl;
		else
			std::cout << "\033[1m\033[37mInt: \033[1m\033[32m" << intValue << "\033[0m" << std::endl;
		if (intValue == floatValue)
		{
			std::cout << "\033[1m\033[37mFloat: \033[1m\033[32m" << floatValue << ".0\033[0m" << std::endl;
			std::cout << "\033[1m\033[37mDouble: \033[1m\033[32m" << doubleValue << ".0f\033[0m" << std::endl;
		}
		else
		{
			std::cout << "\033[1m\033[37mFloat: \033[1m\033[32m" << floatValue << "\033[0m" << std::endl;
			std::cout << "\033[1m\033[37mDouble: \033[1m\033[32m" << doubleValue << "f\033[0m" << std::endl;
		}
	}
}