/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorHandlerClass.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:25:44 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/21 18:25:44 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExceptionClass.hpp"
#include "LogClass.hpp"
#include "ErrorHandlerClass.hpp"
#include "GlobalVariables.hpp"

ErrorHandler::ErrorHandler()
= default;


ErrorHandler::ErrorHandler(ErrorHandler const &src)
{
	*this = src;
}

ErrorHandler &ErrorHandler::operator=(ErrorHandler const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string ErrorHandler::toString() const
{
	return std::string();
}

ErrorHandler::ErrorHandler(const std::string& msg, int lineNb)
{
	if (!::global_diag)
	{
		//todo : gérer lineNb == -1 / global error
		throw Exception("Line " + std::to_string(lineNb) + " - " +msg);
	}
	Log log(L_ERROR, msg);
	global_hasError = true;
}

ErrorHandler::~ErrorHandler()
= default;

std::ostream &	operator<< (std::ostream & o, ErrorHandler const & rhs)
{
	o << rhs.toString();
	return o;
}
