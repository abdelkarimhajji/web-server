/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataConfige.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:43 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/17 13:15:19 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataConfige.hpp"

DataConfige::DataConfige()
{

}

void    DataConfige::errorData()
{
    std::cout << "error in parse data" << std::endl;
}

void    DataConfige::setListen(std::string listen)
{
    this->listen.push_back(listen);
}
std::vector<std::string>    DataConfige::getListen()
{
    return this->listen;
}

std::vector<std::string>    DataConfige::getServerName()
{
    return this->serverName;
}
void    DataConfige::setServerName(std::string serverName)
{
    this->serverName.push_back(serverName);
}

std::string    DataConfige::getRoot()
{
    return this->root;
}

void    DataConfige::setRoot(std::string root)
{
    this->root = root;
}

std::string    DataConfige::getIndex()
{
    return this->index;
}

void    DataConfige::setIndex(std::string index)
{
    this->index = index;
}

std::vector<EroorPage> DataConfige::getErrorPage()
{
    return this->errorPage;
}

void    DataConfige::setErrorPage(std::string error, std::string page)
{
    EroorPage newErrorPage;
    newErrorPage.error = error;
    newErrorPage.page = page;
    this->errorPage.push_back(newErrorPage);
}

std::vector<Location>    DataConfige::getLocation()
{
    return this->vectorLocation;
}
void    DataConfige::setLocation(std::string _location)
{
    Location location;

    location.location = _location;
    this->vectorLocation.push_back(location);
}
void    DataConfige::setLocationRoot(std::string root)
{
    this->vectorLocation.back().root = root;
}

void    DataConfige::setLocationAlias(std::string alias)
{
    this->vectorLocation.back().alias = alias;
}

void    DataConfige::setLocationIndex(std::string index)
{
    this->vectorLocation.back().index = index;
}

void    DataConfige::setLocationMethods(std::string method1, std::string method2, std::string method3)
{
    if(!method1.empty() && method1 == "GET")
        this->vectorLocation.back().methods.get = 1;
    else if(!method1.empty() && method1 == "POST")
        this->vectorLocation.back().methods.post = 1;
    else if(!method1.empty() && method1 == "DELETE")
        this->vectorLocation.back().methods._delete = 1;
    else if(!method3.empty())
        errorData();
    if(!method2.empty() && method2 == "GET")
        this->vectorLocation.back().methods.get = 1;
    else if(!method2.empty() && method2 == "POST")
        this->vectorLocation.back().methods.post = 1;
    else if(!method2.empty() && method2 == "DELETE")
        this->vectorLocation.back().methods._delete = 1;
    else if(!method3.empty())
        errorData();
    if(!method3.empty() && method3 == "GET")
        this->vectorLocation.back().methods.get = 1;
    else if(!method3.empty() && method3 == "POST")
        this->vectorLocation.back().methods.post = 1;
    else if(!method3.empty() && method3 == "DELETE")
        this->vectorLocation.back().methods._delete = 1;
    else if(!method3.empty())
        errorData();
}

void    DataConfige::setLocationAutoIndex(std::string autoIndex)
{
    if(autoIndex == "off")
        this->vectorLocation.back().autoIndex = 0;
    else if(autoIndex == "on")
        this->vectorLocation.back().autoIndex = 1;
    else
        errorData();
}
