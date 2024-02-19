/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataConfige.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:31 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/19 19:31:03 by ahajji           ###   ########.fr       */
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
struct Return
{
    std::string status;
    std::string path;
};

struct Methods
{
    int get;
    int post;
    int _delete;

    Methods()
    {
        get = 0;
        post = 0;
        _delete = 0;
    }
};
struct Location
{
    std::string location;
    std::string alias;
    std::string root;
    std::string index;
    Methods methods;
    int autoIndex;
    std::string cgiExtension;
    std::string cgiBin;
    Return _return;
    
    Location()
    {
        autoIndex = 1;
    }
};

class DataConfige
{
    private:
        std::vector<std::string> listen;
        std::vector<std::string> serverName;
        std::string root;
        std::string index;
        std::string host;
        int autoIndex;
        std::vector<EroorPage> errorPage;
        std::vector<Location> vectorLocation;

    public:
        DataConfige();
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
        std::string    getHost();
        void    setHost(std::string host);
        int    getAutoIndex();
        void    setAutoIndex(int autoIndex);
        std::vector<Location>    getLocation();
        void    setLocation(std::string _location);
        void    setLocationRoot(std::string root);
        void    setLocationAlias(std::string alias);
        void    setLocationIndex(std::string index);
        void    setLocationMethods(std::string method1, std::string method2, std::string method3);
        void    setLocationAutoIndex(std::string autoIndex);
        void    setLocationCgiExtention(std::string cgiExtention);
        void    setLocationCgiBin(std::string cgiBin);
        void    setLocationReturn(std::string returnStatus, std::string returnPath);
        
        void    errorData();
};

#endif