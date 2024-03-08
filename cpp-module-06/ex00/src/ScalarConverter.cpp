/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:49:14 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/08 05:47:10 by lmoheyma         ###   ########.fr       */
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
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const ScalarConverter &f)
{
	os << "TYPE: " << f.getType() << std::endl; 
	if (f.getLimits())
	{
		os << "char: impossible" << std::endl;
		os << "int: impossible" << std::endl;
		os << "float: " << f.getFloatValue() << std::endl;
		os << "double: " << f.getDoubleValue();
	}
	else
	{
		os << "char: " << f.getCharValue() << std::endl;
		os << "int: " << f.getIntValue() << std::endl;
		os << "float: " << f.getFloatValue() << ".0" << std::endl;
		os << "double: " << f.getDoubleValue() << ".0f";
	}
	return (os);
}

char ScalarConverter::getCharValue(void) const
{
	return (_charValue);
}

int ScalarConverter::getIntValue(void) const
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
	if (!_type.compare("int"))
	{
		_intValue = std::atoi(str.c_str());
		_charValue = static_cast<char>(_intValue);
		_floatValue = static_cast<float>(_intValue);
		_doubleValue = static_cast<double>(_intValue);
	}
	if (!_type.compare("double") || !_type.compare("float"))
	{
		_floatValue = std::atof(str.c_str());
		_charValue = static_cast<char>(_floatValue);
		_intValue = static_cast<int>(_floatValue);
		_doubleValue = static_cast<double>(_floatValue);
	}
	if (!_type.compare("other"))
	{
		if (str.length() == 1)
		{
			_intValue = static_cast<int>(str[0]);;
			_charValue = str[0];
			_floatValue = static_cast<float>(str[0]);
			_doubleValue = static_cast<double>(str[0]);
		}
		if (str.compare("nan") || str.compare("nanf"))
		{
			_charValue = 127;
			_floatValue = std::numeric_limits<float>::quiet_NaN();
			_doubleValue = std::numeric_limits<double>::quiet_NaN();
			_limits = 1;
		}
		if (str.compare("-inff") || str.compare("-inf"))
		{
			_charValue = 127;
			_floatValue = std::numeric_limits<float>::infinity() * -1;
			_doubleValue = std::numeric_limits<double>::infinity() * -1;
			_limits = 1;
		}
		if (str.compare("inff") || str.compare("inf"))
		{
			_charValue = 127;
			_floatValue = std::numeric_limits<float>::infinity();
			_doubleValue = std::numeric_limits<double>::infinity();
			_limits = 1;
		}
	}
}