/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:59:38 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/21 21:12:15 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "./Sed infile ToFind ReplaceWith" << std::endl;
		return (0);
	}
	else
	{
		Sed sed(argv[1]);
		sed.ft_sed(argv[2], argv[3]);
	}
}