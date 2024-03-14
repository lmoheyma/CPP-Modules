/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:40:25 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/14 01:25:38 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(std::string infile)
{
    _infile = infile;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _btcMap = other._btcMap;
    }
    return (*this);
}

void BitcoinExchange::fillMap(void)
{
    std::ifstream data;
    data.open("data.csv");
    std::string date;
    float value;

    if (data.is_open())
    {
        std::string line;
        getline(data, line);
        while (getline(data, line))
        {
            date = line.substr(0, line.find(','));
            line.erase(0, line.find(',') + 1);
            std::stringstream is(line);
            is >> value;
            _btcMap.insert(std::pair<std::string, float>(date, value));
        }
    }
    data.close();

    std::map<std::string, float>::iterator it;
    for (it = _btcMap.begin(); it != _btcMap.end(); it++)
    {
        std::cout << "Date = " << it->first << "   -----   Value: " << it->second << std::endl;
    }
}

