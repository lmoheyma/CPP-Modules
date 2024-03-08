/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:55:45 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/09 00:13:38 by lmoheyma         ###   ########.fr       */
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
    std::cout << "Interpreted value : " << serializedValue << std::endl;
    deserializedValue = Serializer::deserialize(serializedValue);
    std::cout << "Deserialized value : " << deserializedValue->str << std::endl;
    return (0);
}
