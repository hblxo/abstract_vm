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

#include  "TokenizerClass.hpp"
#include <iostream>
#include <utility>
#include <LexerClass.hpp>

Tokenizer::Tokenizer(int type, std::string token) : _type(type), _token(std::move(token))
{
}

Tokenizer::Tokenizer()
= default;

Tokenizer::Tokenizer(Tokenizer const & src)
{
    *this = src;
	this->_type = src.getType();
	this->_token = src.getToken();
}

Tokenizer::~Tokenizer(){
//	std::cout << "destructor Tokenizer" << std::endl;
	_token.clear();
}

Tokenizer &	Tokenizer::operator=(Tokenizer const & rhs)
{
    //Do whatever needs to be done
    if (this != &rhs)
        *this = rhs;
    return *this;
}

std::string Tokenizer::toString() const
{
    return(std::to_string(this->getType() ) + " - " + this->getToken() );
}

std::ostream &	operator<< (std::ostream & o, Tokenizer const & rhs)
{
    o << rhs.toString();
    return o;
}


verbs	Tokenizer::getType () const { return (this->_type); }
std::string	Tokenizer::getToken () const { return (this->_token); }

int     Tokenizer::matchSearch(const std::string& value)
{
	return _token == value ? 1 : 0;
}