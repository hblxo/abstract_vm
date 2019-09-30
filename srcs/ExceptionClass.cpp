/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:11:04 by hbouchet          #+#    #+#             */
/*   Updated: 2019/02/23 14:57:47 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LexerClass.hpp"
#include "../includes/ExceptionClass.hpp"
#include <iostream>

Exception::Exception(const std::string& msg) : _msg(msg)
{
    return ;
}

Exception::Exception(Exception const & src) 
{
    //Do whatever needs to be done
    *this = src;
    return;
}

Exception::~Exception(void) throw()
{
    return;
}

const char* Exception::what() const throw()
{
    return _msg.c_str();
}

Exception &	Exception::operator=(Exception const & rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

//Todo : gestion des erreurs
