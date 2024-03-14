/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:26:50 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/14 01:23:45 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iterator>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _btcMap;
        std::string _infile;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string infile);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &other);
        void fillMap(void);
};

#endif