/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:44:29 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 08:12:28 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string> 
# include <iostream>
# include <iomanip>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void announce(void);
		void setName(std::string name);
		Zombie*	zombieHorde(int N, std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
