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

#include <algorithm>
#include "LogClass.hpp"
#include "ExceptionClass.hpp"
#include "ErrorHandlerClass.hpp"
#include "GlobalVariables.hpp"

ErrorHandler::ErrorHandler()
= default;

ErrorHandler::ErrorHandler(ErrorHandler const &src)
{
	this->_errorLog = getErrorLog();
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

void ErrorHandler::handler(const std::string& msg, int lineNb)
{
	std::string tmp("Line " + std::to_string(lineNb) + " - " + msg);
	auto ptr = log_ptr(new Log(lineNb, tmp));
	if (!::global_diag)
	{
		for (auto & it : *global_tokenList)
			delete (it);
		delete(global_tokenList);
		throw ParsingException(ptr->toString());
	}
	_errorLog.push_back(ptr);
	global_hasError = true;
}

void ErrorHandler::print()
{
	sort(_errorLog.begin(), _errorLog.end(),
			[](log_ptr const& a, log_ptr const&b)
			{ return a->getLine() < b->getLine();});
	for (const auto& it : _errorLog)
	{
		it->print();
	}
}

const std::vector<log_ptr> &ErrorHandler::getErrorLog() const
{
	return _errorLog;
}

ErrorHandler::~ErrorHandler()
= default;

std::ostream &	operator<< (std::ostream & o, ErrorHandler const & rhs)
{
	o << rhs.toString();
	return o;
}
