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
#include <utility>
#include <LexerClass.hpp>

Matcher::Matcher(int type, std::string token) : _type(type), _token(std::move(token))
{
}

Matcher::Matcher()
= default;

Matcher::Matcher(Matcher const & src)
{
    *this = src;
	this->_type = src.getType();
	this->_token = src.getToken();
}

Matcher::~Matcher()
= default;

Matcher &	Matcher::operator=(Matcher const & rhs)
{
    //Do whatever needs to be done
    if (this != &rhs)
        *this = rhs;
    return *this;
}

std::string Matcher::toString() const
{
    return(std::to_string(this->getType() ) + " - " + this->getToken() );
}

std::ostream &	operator<< (std::ostream & o, Matcher const & rhs)
{
    o << rhs.toString();
    return o;
}


int	Matcher::getType () const { return (this->_type); }
void	Matcher::setType (int type) { this->_type = type; }
std::string	Matcher::getToken () const { return (this->_token); }
void	Matcher::setToken (std::string token) { this->_token = std::move(token); }

int     Matcher::matchSearch(const std::string& value)
{
	return _token == value ? 1 : 0;
}