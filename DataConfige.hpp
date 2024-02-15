/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataConfige.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:31 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/15 14:01:09 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATA
#define DATA

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class DataConfige
{
    private:
        std::vector<std::string> listen;
        std::vector<std::string> serverName;
        std::string root;
        std::string index;

    public:
        std::vector<std::string>    getListen();
        void    setListen(std::string listen);
        std::vector<std::string>    getServerName();
        void    setServerName(std::string serverName);
        std::string    getRoot();
        void    setRoot(std::string index);
        std::string    getIndex();
        void    setIndex(std::string index);
};

#endif