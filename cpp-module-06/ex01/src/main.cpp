/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:55:45 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/09 00:46:44 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    Data data;
    Data* deserializedValue;
    uintptr_t serializedValue;
    
    data.str = "Message";
    serializedValue = Serializer::serialize(&data);
    std::cout << "\033[1m\033[37mInterpreted value : \033[1m\033[36m" << serializedValue << "\033[0m" << std::endl;
    deserializedValue = Serializer::deserialize(serializedValue);
    std::cout << "\033[1m\033[37mDeserialized value : \033[1m\033[36m" << deserializedValue->str << "\033[0m" << std::endl;
    return (0);
}
