/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseConfigeFile.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:15 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/19 19:24:43 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseConfigeFile.hpp"

void    ParseConfigeFile::errorParse()
{
    std::cout << "error in parse" << std::endl;
    exit(1);
}

ParseConfigeFile::ParseConfigeFile()
{
    this->findBraciteRight = 0;
    this->findBraciteLeft = 0;
    this->findBraciteRightLocation = 0;
    this->findBraciteLeftLocation = 0;
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
            this->findBraciteRight = 1;
            this->findBraciteLeftLocation = 0;
            this->findBraciteRightLocation = 0;
            DataConfige newConfig;
            data.push_back(newConfig);
    }
    else
    {
        std::cout << "i check server" << std::endl;
        errorParse();
    }
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
        this->data.back().setListen(splitVector[1]);
    }
    else
    {
        std::cout << "i check listen" << std::endl;
        errorParse();
    }
        
}
void    ParseConfigeFile::checkValidServerName(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
    {
        this->data.back().setServerName(splitVector[1]);
    }
    else
    {
        std::cout << "i check servername" << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidRoot(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
    {
        this->data.back().setRoot(splitVector[1]);
    }
    else
    {
        std::cout << "i check root" << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidIndex(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
    {
        this->data.back().setRoot(splitVector[1]);
    }
    else
    {
        std::cout << "i error validIndex" << std::endl;
        errorParse();
    }
}
void    ParseConfigeFile::checkValidErrorPage(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 3)
    {
        this->data.back().setErrorPage(splitVector[1], splitVector[2]);
    }
    else
    {
        std::cout << "i error page" << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidLocation(std::vector<std::string> splitVector)
{
    if(this->findBraciteLeftLocation == 1 && this->findBraciteRightLocation == 1)
    {
        this->findBraciteLeftLocation = 0;
        this->findBraciteRightLocation = 0;
    }
    if(splitVector.size() == 3 && splitVector[2] == "{")
    {
        
        this->data.back().setLocation(splitVector[1]);
        this->findBraciteRightLocation = 1;
    }
    else
    {
        std::cout << "location" << std::endl;
        errorParse();
    }

}
void    ParseConfigeFile::checkValidLocationRoot(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
    {
        this->data.back().setLocationRoot(splitVector[1]);
    }
    else
    {
        std::cout << "i check location root" << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidLocationAlias(std::vector<std::string> splitVector)
{

    if(splitVector.size() == 2)
    {
        this->data.back().setLocationAlias(splitVector[1]);
    }
    else
    {
        std::cout << "i check location alias" << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidLocationIndex(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
    {
        this->data.back().setLocationIndex(splitVector[1]);
    }
    else
    {
        std::cout << "i check location index" << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidLocationMethods(std::vector<std::string> splitVector)
{
    if(splitVector.size() >= 2 && splitVector.size() <= 4)
    {
        if(splitVector.size() == 2)
            this->data.back().setLocationMethods(splitVector[1], "", "");
        if(splitVector.size() == 3)
            this->data.back().setLocationMethods(splitVector[1], splitVector[2], "");
        if(splitVector.size() == 4)
            this->data.back().setLocationMethods(splitVector[1], splitVector[2], splitVector[3]);
    }
    else
    {
        std::cout << "i check loaction methods" << std::endl;
        errorParse();
    }
}
void    ParseConfigeFile::checkValidLocationAutoIndex(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
        this->data.back().setLocationAutoIndex(splitVector[1]);
    else
    {
        std::cout << "i check autoInedx" << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidLocationCgiExtention(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
        this->data.back().setLocationCgiExtention(splitVector[1]);
    else
    {
        std::cout << "i check cgiextention" << std::endl;
        errorParse();
    }
}
void    ParseConfigeFile::checkValidLocationCgiBin(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
        this->data.back().setLocationCgiBin(splitVector[1]);
    else
    {
        std::cout << "i check cgiBIn" << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidLocationReturn(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 3)
        this->data.back().setLocationReturn(splitVector[1], splitVector[2]);
    else
    {
        std::cout << "i check return " << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidLocationLeftBrackite(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 1)
    {
        this->findBraciteLeftLocation = 1;
    }
    else
        errorParse();
}

void    ParseConfigeFile::checkValidServerLeftBrackite(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 1)
    {
        this->findBraciteRight = 0;
        this->findBraciteLeft = 0;
    }
    else
        errorParse();
}
void    ParseConfigeFile::checkValidHost(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
        this->data.back().setHost(splitVector[1]);
    else
    {
        std::cout << "i check host " << std::endl;
        errorParse();
    }
}

void    ParseConfigeFile::checkValidAutoIndex(std::vector<std::string> splitVector)
{
    if(splitVector.size() == 2)
        this->data.back().setAutoIndex(splitVector[1]);
    else
    {
        std::cout << "i check autoIndex " << std::endl;
        errorParse();
    }
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
       
            i = 0;
            while (i < myVector_s.size())
            {
                splitVector = split(myVector_s[i]);
                if(!splitVector.empty() && splitVector[0] != "#" && splitVector[0][0] != '#')
                {
                    if((splitVector[0] == "server" || splitVector[0] == "server{")
                        && ((this->findBraciteRight == 0 && this->findBraciteLeft == 0)
                        || (this->findBraciteRight == 1 && this->findBraciteLeft == 1)))
                        {    
                            checkValidServer(splitVector);
                        }
                    else if(splitVector[0] == "listen" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 0)
                        checkValidListen(splitVector);
                    else if(splitVector[0] == "server_name" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 0)
                        checkValidServerName(splitVector);
                    else if(splitVector[0] == "root" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 0)
                        checkValidRoot(splitVector);
                    else if(splitVector[0] == "index" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 0)
                        checkValidIndex(splitVector);
                    else if(splitVector[0] == "host" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 0)
                        checkValidHost(splitVector);
                    else if(splitVector[0] == "autoindex" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 0)
                        checkValidAutoIndex(splitVector);
                    else if(splitVector[0] == "error_page" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 0)
                        checkValidErrorPage(splitVector);
                    else if(splitVector[0] == "location" && this->findBraciteRight == 1)
                        checkValidLocation(splitVector);
                    else if(splitVector[0] == "root" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 1)
                        checkValidLocationRoot(splitVector);
                    else if(splitVector[0] == "alias" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 1)
                        checkValidLocationAlias(splitVector);
                    else if(splitVector[0] == "index" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 1)
                        checkValidLocationIndex(splitVector);
                    else if(splitVector[0] == "methods" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 1)
                        checkValidLocationMethods(splitVector);
                    else if(splitVector[0] == "autoindex" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 1)
                        checkValidLocationAutoIndex(splitVector);
                    else if(splitVector[0] == "cgi_extention" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 1)
                        checkValidLocationCgiExtention(splitVector);
                    else if(splitVector[0] == "cgi_bin" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 1)
                        checkValidLocationCgiBin(splitVector);
                    else if(splitVector[0] == "return" && this->findBraciteRight == 1
                        && this->findBraciteRightLocation == 1){
                           
                        checkValidLocationReturn(splitVector);
                        }
                    else if(splitVector[0] == "}" && this->findBraciteRight == 1 
                        && this->findBraciteRightLocation == 1 && this->findBraciteLeftLocation == 0)
                        {
                            checkValidLocationLeftBrackite(splitVector);
                            
                        }
                    else if(splitVector[0] == "}" && this->findBraciteRight == 1 && this->findBraciteLeft == 0)
                    {
                        checkValidServerLeftBrackite(splitVector);
                    }
                    else
                    {
                        std::cout << "i am here \n";
                        std::cout << myVector_s[i] <<  std::endl;
                        std::cout << this->findBraciteLeftLocation << std::endl;  
                        std::cout << this->findBraciteRightLocation << std::endl; 
                        std::cout << this->findBraciteLeft << std::endl;  
                        std::cout << this->findBraciteRight << std::endl;                        
                        errorParse(); 
                    }
                }
                
                i++;
            }
            if(this->findBraciteLeft != 0 || this->findBraciteRight != 0)
                errorParse();
    }
    else 
        std::cout << "error happen with this file" << std::endl;
}