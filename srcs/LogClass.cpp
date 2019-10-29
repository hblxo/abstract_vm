/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:36:53 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/20 17:36:53 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GlobalVariables.hpp>
#include <utility>
#include "LogClass.hpp"

Log::Log() : _msg(std::string()), _line(-1)
{}


Log::Log(int line, std::string msg) : _msg(std::move(msg)), _line(line)
{
}

Log::Log(verbosity level, std::string  msg) : _msg(std::move(msg)), _line(-1)
{
	if (level >= global_verbosity && !_msg.empty())
		print();
//		std::cout << "\033[1;31m" << msg << "\033[0m" << std::endl;
}

Log::Log(Log const &src)
{
	_line = src.getLine();
	_msg = src.getMsg();
	*this = src;
}

Log::~Log()
= default;

Log &Log::operator=(Log const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string Log::toString() const
{
	return _msg;
}

std::string Log::getMsg() const
{
	return _msg;
}

int Log::getLine() const
{
	return _line;
}

void Log::print()
{
	std::cout << *this << std::endl;
}

std::ostream &operator<<(std::ostream &o, Log const &rhs)
{
	o << rhs.toString();
	return o;
}
