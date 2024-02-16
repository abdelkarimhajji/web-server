/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseConfigeFile.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:41:14 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/16 15:46:46 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE
#define PARSE

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "DataConfige.hpp"

class ParseConfigeFile
{
    private:
        int findBraciteRight;
        int findBraciteLeft;
        std::vector<DataConfige> data;
        std::vector<std::string>     split(std::string str);
        void    checkValidServer(std::vector<std::string> splitVector);
        void    checkValidListen(std::vector<std::string> splitVector);
        void    checkValidServerName(std::vector<std::string> splitVector);
        void    checkValidRoot(std::vector<std::string> splitVector);
        void    checkValidIndex(std::vector<std::string> splitVector);
        void    checkValidErrorPage(std::vector<std::string> splitVector);
        void    checkValidLocation(std::vector<std::string> splitVector);
        void    errorParse();
    public:
        ParseConfigeFile();
        void    parser(std::string nameFile);
};

#endif