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

#include <LogClass.hpp>
#include "ExceptionClass.hpp"
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

void ErrorHandler::handler(const std::string &msg, int lineNb)
{
	s_errorLog	log;

	log.line = lineNb;
	log.errorMsg = "Line " + std::to_string(lineNb) + " - " + msg;
	if (!::global_diag)
	{
		throw ParsingException(log.errorMsg);
	}
	_errorLog.push_back(log);
//	Log log(L_ERROR, "Line " + std::to_string(lineNb) + " - " + msg);
	global_hasError = true;
}

void ErrorHandler::print()
{
	std::vector<s_errorLog>::iterator it;

	sort(_errorLog.begin(), _errorLog.end(), s_errorLog());
	for (it = _errorLog.begin(); it != _errorLog.end(); it++)
	{
		Log(L_ERROR, (*it).errorMsg);
	}
}

ErrorHandler::~ErrorHandler()
= default;

std::ostream &	operator<< (std::ostream & o, ErrorHandler const & rhs)
{
	o << rhs.toString();
	return o;
}
