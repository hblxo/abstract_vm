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
#include "LogClass.hpp"

Log::Log()
= default;

Log::Log(verbosity level, const std::string& msg)
{
	if (level >= global_verbosity)
//		std::cout << "\033[1;31m" << msg << "\033[0m" << std::endl;
		std::cout << msg << std::endl;
}

Log::Log(Log const &src)
{
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
	return std::string();
}
//
//verbosity Log::getOptions() const
//{
//	return _options;
//}

std::ostream &operator<<(std::ostream &o, Log const &rhs)
{
	o << rhs.toString();
	return o;
}
