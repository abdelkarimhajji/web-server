/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataConfige.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:31 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/15 15:23:29 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATA
#define DATA

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

struct EroorPage
{
    std::string error;
    std::string page;
};

class DataConfige
{
    private:
        std::vector<std::string> listen;
        std::vector<std::string> serverName;
        std::string root;
        std::string index;
        std::vector<EroorPage> errorPage;
    public:
        std::vector<std::string>    getListen();
        void    setListen(std::string listen);
        std::vector<std::string>    getServerName();
        void    setServerName(std::string serverName);
        std::string    getRoot();
        void    setRoot(std::string index);
        std::string    getIndex();
        void    setIndex(std::string index);
        std::vector<EroorPage>    getErrorPage();
        void    setErrorPage(std::string error, std::string page);
};

#endif