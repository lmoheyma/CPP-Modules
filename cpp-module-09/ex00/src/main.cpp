/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:08:41 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/14 18:54:44 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw BitcoinExchange::WrongArgumentException();
    }
    catch (const BitcoinExchange::WrongArgumentException& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    BitcoinExchange btc;
    
    btc.fillMap();
    std::ifstream input;
    std::string date;
    float value;
    input.open(argv[1]);
    if (input.is_open())
    {
        std::string line;
        getline(input, line);
        while (getline(input, line))
        {
            date = line.substr(0, line.find('|') - 1);
            line.erase(0, line.find('|') + 2);
            std::stringstream is(line);
            is >> value;
            std::map<std::string, float> mymap = btc.getMap();
            std::map<std::string, float>::const_iterator it = mymap.find(date);
            std::map<std::string, float>::const_iterator ite = mymap.end();
            if (it != ite)
            {
                if (value < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else if (value > 1000)
                    std::cout << "Error: too large number." << std::endl;
                else
                {
                    float res = value * it->second;
                    std::cout << date << " => " << line << " = " << res << std::endl;   
                }
            }
            else
            {
                if (!btc.isValidDate(date))
                    continue ;
                for (it = mymap.begin(); it != mymap.end(); it++)
                {
                    int cmp = it->first.compare(date);
                    if (cmp > 0)
                    {
                        it--;
                        break ;
                    }
                }
                float res = value * it->second;
                std::cout << date << " => " << line << " = " << res << std::endl;
            }
        }
    }
    return (0);
}
