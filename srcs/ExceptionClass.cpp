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
#include <utility>

Exception::Exception(std::string  msg) : _msg(std::move(msg))
{
}

Exception::Exception(Exception const & src) 
{
    //Do whatever needs to be done
    *this = src;
}

Exception::~Exception() noexcept
= default;

const char* Exception::what() const noexcept
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

/*
 * Nested Class : DivideByZeroException
 */

Exception::DivideByZeroException::DivideByZeroException()
{
	_msg = "Divide by zero exception";
}

Exception::DivideByZeroException::DivideByZeroException(
		const Exception::DivideByZeroException &src)
{
	*this = src;
}

Exception::DivideByZeroException::~DivideByZeroException()= default;

const char *Exception::DivideByZeroException::what() const throw()
{
	return _msg.c_str();
}

Exception::DivideByZeroException &Exception::DivideByZeroException::operator=(Exception::DivideByZeroException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}


