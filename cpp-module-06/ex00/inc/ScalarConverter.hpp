/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:49:12 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/08 05:43:01 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
	private:
		std::string _type;
		int _limits;
		char _charValue;
		int _intValue;
		float _floatValue;
		double _doubleValue;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
		char getCharValue(void) const ;
		int getIntValue(void) const ;
		float getFloatValue(void) const ;
		double getDoubleValue(void) const ;
		std::string getType(void) const ;
		int getLimits(void) const ;
		void setType(std::string str) ;
		void convert(std::string str);
};

std::ostream &operator<<(std::ostream &os, const ScalarConverter &f);

#endif