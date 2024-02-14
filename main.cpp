/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:10:08 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/14 14:11:07 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parseConfigeFile.hpp"



int main(void)
{
    parseConfigeFile parse;

    parse.parser("configfile.txt");

    return 0;
}