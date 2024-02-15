/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataConfige.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:43 by ahajji            #+#    #+#             */
/*   Updated: 2024/02/15 12:16:08 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataConfige.hpp"

void    DataConfige::setListen(std::string listen)
{
    this->listen.push_back(listen);
}