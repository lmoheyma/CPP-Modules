/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:44:29 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 07:05:05 by lmoheyma         ###   ########.fr       */
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
		void announce(void);
		Zombie(std::string name);
		~Zombie();
		Zombie*	newZombie(std::string name);
		void	ramdomChump(std::string name);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
