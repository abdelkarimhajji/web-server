/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseConfigeFile.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:15 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/14 14:19:54 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parseConfigeFile.hpp"

std::vector<std::string>     parseConfigeFile::split(std::string str)
{
    std::vector<std::string> allElments;
    std::string part, part2;
    std::stringstream convert(str);
    while (std::getline(convert, part, ' '))
    {
        std::stringstream convert2(part);
        while (std::getline(convert2, part2, '\t'))
        {
            allElments.push_back(part2);
        }
    }
    return allElments;
}

void    parseConfigeFile::parser(std::string nameFile)
{
    int i = 0;
    std::string line;
    std::vector<std::string> myVector_s;
    std::vector<std::string> splitVector;
    std::ifstream configFile(nameFile);

    if(configFile.is_open())
    {
        while (std::getline(configFile, line))
        {
            myVector_s.push_back(line);
        }
        while (i < myVector_s.size())
        {
            splitVector = split(myVector_s[i]);
            if(!splitVector.empty() && splitVector[0] != "#" && splitVector[0][0] != '#')
            {
                std::cout << splitVector[0] << std::endl;
                std::cout << splitVector[1] << std::endl;
                checkValidServer();
                // std::cout << "hello\n";
            }
            i++;
        }
    }
    else 
        std::cout << "error happen with this file" << std::endl;
}