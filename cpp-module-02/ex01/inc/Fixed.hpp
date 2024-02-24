/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:26:15 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/24 18:30:31 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <string>
# include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixedValue;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int nb);
		Fixed(const float nb);
		~Fixed();
		Fixed &operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const fixedValue);
		float toFloat(void) const;
		int toInt(void) const;
		bool operator>(Fixed const &other);
		bool operator>(Fixed const &other);
};

std::ostream &operator<<(std::ostream& os, Fixed const &f);

#endif