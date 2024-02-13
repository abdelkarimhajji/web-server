/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:10:08 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/13 20:42:01 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parseConfigeFile.hpp"

std::vector<std::string>     split(std::string str)
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

int main(void)
{
    std::string line;
    std::vector<std::string> myVectors;
    std::vector<std::string> myVectort;
    std::vector<std::string> splitVector;
    int i = 0;
    int j = 0;
    std::ifstream configFile("configfile.txt");
    if(configFile.is_open())
    {
        while (std::getline(configFile, line))
        {
            myVectors.push_back(line);
        }
        while (i < myVectors.size())
        {
            splitVector = split(myVectors[i]);
            if(!splitVector.empty() && splitVector[0] != "#" && splitVector[0][0] != '#')
            {
                std::cout << "hello\n";
            }
            i++;
        }
        
        // std::cout << myVectors[7] << std::endl;
    }

    return 0;
}