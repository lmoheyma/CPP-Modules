/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:07 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/27 17:18:55 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain &operator=(const Brain &other);
};

#endif