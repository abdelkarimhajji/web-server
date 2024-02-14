/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseConfigeFile.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:41:14 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/14 15:20:15 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class parseConfigeFile
{
    private:
        std::vector<std::string>     split(std::string str);
        void    checkValidServer(std::vector<std::string> splitVector);
    public:
        void    parser(std::string nameFile);
};