/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:01:33 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 21:14:36 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Sed.hpp"

Sed::Sed(std::string file) : infile(file)
{
	this->outfile = this->infile + ".replace";
}

Sed::~Sed()
{
	
}

void Sed::ft_sed(std::string s1, std::string s2)
{
	std::ifstream infile(this->infile.c_str());
	
	if (infile.is_open())
	{
		std::string line;
		std::ofstream outfile(this->outfile.c_str());
		while (std::getline(infile, line) && outfile.is_open())
		{
			size_t pos = line.find(s1);
			while (pos != std::string::npos)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos = line.find(s1);
			}
			outfile << line << "\n";
		}
		outfile.close();
	}
	else
	{
		std::cout << "Can't open file" << std::endl;
		return ;
	}
	infile.close();
}
