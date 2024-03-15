/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:40:25 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/15 05:22:41 by lmoheyma         ###   ########.fr       */
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
}

std::map<std::string, float> BitcoinExchange::getMap(void) const
{
    return (_btcMap);
}

int BitcoinExchange::isValidDate(std::string date)
{
    std::string year;
    std::string month;
    std::string day;

    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 10);
    if (year.compare("2024") > 0 || year.compare("2009") < 0 )
        return (std::cout << "Error: bad input => " << date << std::endl, 0);
    else if (month.compare("01") < 0 || month.compare("12") > 0)
        return (std::cout << "Error: bad input => " << date << std::endl, 0);
    else if (day.compare("01") < 0 || day.compare("31") > 0)
        return (std::cout << "Error: bad input => " << date << std::endl, 0);
    else
        return (1);
}
