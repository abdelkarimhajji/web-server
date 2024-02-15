/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseConfigeFile.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:15 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/15 12:02:22 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseConfigeFile.hpp"

void    ParseConfigeFile::errorParse()
{
    std::cout << "error in parse" << std::endl;
}

ParseConfigeFile::ParseConfigeFile()
{
    this->findBraciteRight = 0;
    this->findBraciteLeft = 0;
}

std::vector<std::string>     ParseConfigeFile::split(std::string str)
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

void    ParseConfigeFile::checkValidServer(std::vector<std::string> splitVector)
{
    if ((splitVector[1] == "{" && splitVector.size() == 2)
        || (splitVector.size() == 1))
    {
            this->findBraciteRight++;
            DataConfige newConfig;
            data.push_back(newConfig);
    }
    else
        errorParse();
}

void    ParseConfigeFile::checkValidListen(std::vector<std::string> splitVector)
{
    int i = 0;
    if(splitVector.size() == 2)
    {
        while(i < splitVector[1].size())
        {
            if(!std::isdigit(splitVector[1][i]))
                errorParse();
            i++;
        }
        
    }
    else
        errorParse();
        
}

void    ParseConfigeFile::parser(std::string nameFile)
{
    int i = 0;
    int j = 0;
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
        // std::cout << myVector_s.back() << std::endl;
        while (true)
        {
            i = 0;
            while (i < myVector_s.size())
            {
                splitVector = split(myVector_s[i]);
                if(!splitVector.empty() && splitVector[0] != "#" && splitVector[0][0] != '#')
                {
                    if(splitVector[0] == "server" || splitVector[0] == "server{")
                        checkValidServer(splitVector);
                    else if(splitVector[0] == "listen" && this->findBraciteRight >= 1)
                        checkValidListen(splitVector);
                }
                i++;
            }
            exit(0);
        }
    }
    else 
        std::cout << "error happen with this file" << std::endl;
}