/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataConfige.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:43 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/15 14:02:20 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataConfige.hpp"

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