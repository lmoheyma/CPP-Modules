/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:49:12 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/08 19:35:33 by lmoheyma         ###   ########.fr       */
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
		int _overflow;
		char _charValue;
		long int _intValue;
		float _floatValue;
		double _doubleValue;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
		char getCharValue(void) const ;
		long int getIntValue(void) const ;
		float getFloatValue(void) const ;
		double getDoubleValue(void) const ;
		std::string getType(void) const ;
		int getLimits(void) const ;
		int getOverflow(void) const ;
		void setType(std::string str) ;
		void convert(std::string str);
		class ImpossibleConversionException : public std::exception{
			public:
				const char* what() const throw () { return ("Impossible conversion!");}};
};

std::ostream &operator<<(std::ostream &os, const ScalarConverter &f);

#endif