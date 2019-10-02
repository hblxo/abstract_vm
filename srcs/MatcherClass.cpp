/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatcherClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:20:46 by hbouchet          #+#    #+#             */
/*   Updated: 2019/03/04 12:33:00 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "MatcherClass.hpp"
#include <iostream>

Matcher::Matcher(int type, std::string token) : _type(type), _token(token)
{
    return;
}

Matcher::Matcher(void)
{
    return;
}

Matcher::Matcher(Matcher const & src) 
{
    //Do whatever needs to be done
    *this = src;
    return;
}

Matcher::~Matcher(void)
{
    return;
}

Matcher &	Matcher::operator=(Matcher const & rhs)
{
    //Do whatever needs to be done
    if (this != &rhs)
        *this = rhs;
    return *this;
}

std::string const Matcher::toString(void) const
{
    return "OK";
    // Return whatever needs to be returned
}

std::ostream &	operator<< (std::ostream & o, Matcher const & rhs)
{
    o << rhs.toString();
    return o;
}


int	Matcher::getType (void) const { return (this->_type); }
void	Matcher::setType (int type) { this->_type = type; }
std::string	Matcher::getToken (void) const { return (this->_token); }
void	Matcher::setToken (std::string token) { this->_token = token; }

int     Matcher::matchSearch(const std::string& value)
{
	return _token == value ? 1 : 0;
}