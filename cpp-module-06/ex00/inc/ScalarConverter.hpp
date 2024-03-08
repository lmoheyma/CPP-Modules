/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:49:12 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/08 22:06:13 by lmoheyma         ###   ########.fr       */
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
	public:
		static std::string setType(std::string str);
		static void convert(std::string str, std::string type);
		class ImpossibleConversionException : public std::exception{
			public:
				const char* what() const throw () { return ("Impossible conversion!");}};
};

#endif
