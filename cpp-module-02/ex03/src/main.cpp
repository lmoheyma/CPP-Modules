/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:38:04 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/25 00:53:37 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

int main( void ) {
	Point a;
	Point b(10.0, 0.0);
	Point c(0.0, 10.0);
	Point m(4.0, 5.9);
	// Point d = a;
	// Point p(m);
	
	if (bsp(a, b, c, m) == true)
	{
		std::cout << "\033[1m\033[37mPoint M(" << m.getX() << "," << m.getY() << ") is inside the triangle A(";
		std::cout << a.getX() << "," << a.getY() << "), B(" << b.getX() << "," << b.getY() << "), and C(";
		std::cout << c.getX() << "," << c.getY() << ").\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[1m\033[37mPoint M(" << m.getX() << "," << m.getY() << ") is not inside the triangle A(";
		std::cout << a.getX() << "," << a.getY() << "), B(" << b.getX() << "," << b.getY() << "), and C(";
		std::cout << c.getX() << "," << c.getY() << ").\033[0m" << std::endl;
	}
	return 0;
}