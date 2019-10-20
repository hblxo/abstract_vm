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

#include "LogClass.hpp"

Log::Log()
{
	_options = L_OFF;
}

Log::Log(verbosity options) : _options(options)
{

}

Log::Log(Log const &src)
{
	this->_options = src.getOptions();
	*this = src;
}

Log::~Log()
{
}

Log &Log::operator=(Log const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string Log::toString() const
{
	return std::string();
}

verbosity Log::getOptions() const
{
	return _options;
}

void Log::print(verbosity level, std::string msg)
{
	if (level >= _options)
		std::cout << msg << std::endl;
}

std::ostream &operator<<(std::ostream &o, Log const &rhs)
{
	o << rhs.toString();
	return o;
}
