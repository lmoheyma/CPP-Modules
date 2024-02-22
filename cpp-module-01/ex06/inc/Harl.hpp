/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:45:16 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/22 17:58:23 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <string>
#include <iostream>

class HarlFilter
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);	
	public:
		HarlFilter();
		~HarlFilter();
		void	complain(std::string level, int i);
};

#endif