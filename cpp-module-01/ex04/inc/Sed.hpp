/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:00:24 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 21:09:05 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

# include <string>
# include <fstream>
# include <iostream>

class Sed
{
	private:
		std::string infile;
		std::string outfile;
	public:
		Sed(std::string file);
		~Sed();
		void ft_sed(std::string s1, std::string s2);
};

#endif