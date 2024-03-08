/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:49:14 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/08 19:46:11 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	_charValue = '\0';
	_intValue = 0;
	_floatValue = 0.0f;
	_doubleValue = 0.0;
	_type = "int";
	_limits = 0;
	_overflow = 0;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	_charValue = other._charValue;
	_intValue = other._intValue;
	_floatValue = other._floatValue;
	_doubleValue = other._doubleValue;
	_type = other._type;
	_limits = other._limits;
	_overflow = other._overflow;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		_charValue = other._charValue;
		_intValue = other._intValue;
		_floatValue = other._floatValue;
		_doubleValue = other._doubleValue;
		_type = other._type;
		_limits = other._limits;
		_overflow = other._overflow;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const ScalarConverter &f)
{
	// os << "TYPE: " << f.getType() << std::endl; 
	if (f.getLimits())
	{
		os << "\033[1m\033[37mChar: \033[1m\033[31mImpossible\033[0m" << std::endl;
		os << "\033[1m\033[37mInt: \033[1m\033[31mImpossible\033[0m" << std::endl;
		os << "\033[1m\033[37mFloat: \033[1m\033[32m" << f.getFloatValue() << "f\033[0m" << std::endl;
		os << "\033[1m\033[37mDouble: \033[1m\033[32m" << f.getDoubleValue() << "\033[0m";
	}
	else
	{
		if (f.getCharValue() < 33)
			os << "\033[1m\033[37mChar: \033[1m\033[31mNon displayable\033[0m" << std::endl;
		else
			os << "\033[1m\033[37mChar: \033[1m\033[32m" << f.getCharValue() << "\033[0m" << std::endl;
		if (f.getOverflow())
			os << "\033[1m\033[37mInt: \033[1m\033[31mOverflow\033[0m" << std::endl;
		else
			os << "\033[1m\033[37mInt: \033[1m\033[32m" << f.getIntValue() << "\033[0m" << std::endl;
		if (f.getIntValue() == f.getFloatValue())
		{
			os << "\033[1m\033[37mFloat: \033[1m\033[32m" << f.getFloatValue() << ".0\033[0m" << std::endl;
			os << "\033[1m\033[37mDouble: \033[1m\033[32m" << f.getDoubleValue() << ".0f\033[0m";
		}
		else
		{
			os << "\033[1m\033[37mFloat: \033[1m\033[32m" << f.getFloatValue() << "\033[0m" << std::endl;
			os << "\033[1m\033[37mDouble: \033[1m\033[32m" << f.getDoubleValue() << "f\033[0m";
		}
	}
	return (os);
}

char ScalarConverter::getCharValue(void) const
{
	return (_charValue);
}

long int ScalarConverter::getIntValue(void) const
{
	return (_intValue);
}

float ScalarConverter::getFloatValue(void) const
{
	return (_floatValue);
}

double ScalarConverter::getDoubleValue(void) const
{
	return (_doubleValue);
}

std::string ScalarConverter::getType(void) const
{
	return (_type);
}

int ScalarConverter::getLimits(void) const
{
	return (_limits);
}

int ScalarConverter::getOverflow(void) const
{
	return (_overflow);
}

void ScalarConverter::setType(std::string str)
{
	int i = 0;
	int flag = 0;
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
			_type = "other";
			break ;
		}
		if (str[i] == '.')
		{
			flag = 1;
			_type = "double";
			i++;
			continue ;
		}
		if (str[i] == 'f' && i == (int)str.length() - 1)
		{
			_type = "float";
			break ;
		}
		else
		{
			_type = "other";
			break ;
		}
	}
}

void ScalarConverter::convert(std::string str)
{
	if (!_type.compare("int") && (str[0] == '+' || str[0] == '-') && str.length() == 1)
	{
		_intValue = static_cast<int>(str[0]);;
		_charValue = str[0];
		_floatValue = static_cast<float>(str[0]);
		_doubleValue = static_cast<double>(str[0]);
	}
	else if (!_type.compare("int"))
	{
		try
		{
			_intValue = std::atol(str.c_str());
			if (_intValue > std::numeric_limits<int>::max())
				throw ImpossibleConversionException();
			if (_intValue < std::numeric_limits<int>::min())
				throw ImpossibleConversionException();
		}
		catch(const std::exception& e)
		{
			_overflow = 1;
		}
		_charValue = static_cast<char>(_intValue);
		_floatValue = static_cast<float>(_intValue);
		_doubleValue = static_cast<double>(_intValue);
	}
	else if (!_type.compare("double") || !_type.compare("float"))
	{
		_floatValue = std::atof(str.c_str());
		_charValue = static_cast<char>(_floatValue);
		_intValue = static_cast<int>(_floatValue);
		_doubleValue = static_cast<double>(_floatValue);
	}
	else if (!_type.compare("other"))
	{
		if (str.length() == 1)
		{
			_intValue = static_cast<int>(str[0]);;
			_charValue = str[0];
			_floatValue = static_cast<float>(str[0]);
			_doubleValue = static_cast<double>(str[0]);
		}
		else if (!str.compare("nan") || !str.compare("nanf"))
		{
			_charValue = 127;
			_floatValue = std::numeric_limits<float>::quiet_NaN();
			_doubleValue = std::numeric_limits<double>::quiet_NaN();
			_limits = 1;
		}
		else if (!str.compare("-inff") || !str.compare("-inf"))
		{
			_charValue = 127;
			_floatValue = std::numeric_limits<float>::infinity() * -1;
			_doubleValue = std::numeric_limits<double>::infinity() * -1;
			_limits = 1;
		}
		else if (!str.compare("inff") || !str.compare("inf"))
		{
			_charValue = 127;
			_floatValue = std::numeric_limits<float>::infinity();
			_doubleValue = std::numeric_limits<double>::infinity();
			_limits = 1;
		}
		else
		{
			throw ImpossibleConversionException();
		}
	}
}