/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:26:15 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/24 19:15:09 by lmoheyma         ###   ########.fr       */
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
		// Comparaisons
		bool operator>(Fixed const &other) const ;
		bool operator<(Fixed const &other) const ;
		bool operator>=(Fixed const &other) const ;
		bool operator<=(Fixed const &other) const ;
		bool operator==(Fixed const &other) const ;
		bool operator!=(Fixed const &other) const ;
		// Arithmetiques
		Fixed	 operator+(Fixed const &other);
		Fixed	 operator-(Fixed const &other);
		Fixed	 operator*(Fixed const &other);
		Fixed	 operator/(Fixed const &other);
		// Incrementation, decrementation
		Fixed operator++(int);
		Fixed& operator++(void);
		Fixed operator--(int);
		Fixed& operator--(void);
		// Utils
		static Fixed& min(Fixed &nb1, Fixed &nb2);
		static const Fixed& min(Fixed const &nb1, Fixed const &nb2);
		static Fixed& max(Fixed &nb1, Fixed &nb2);
		static const Fixed& max(Fixed const &nb1, Fixed const &nb2);
};

std::ostream &operator<<(std::ostream& os, Fixed const &f);

#endif