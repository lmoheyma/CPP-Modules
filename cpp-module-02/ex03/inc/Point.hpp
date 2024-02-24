/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 23:23:47 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/25 00:45:21 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <string>
# include <iostream>
# include "Fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;
    public:
		// Canon
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		~Point();
		Point &operator=(const Point &other);
		//Getter
		Fixed getX(void) const ;
		Fixed getY(void) const ;
		//Setter
		void setX(const Fixed x);
		void setY(const Fixed y);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
