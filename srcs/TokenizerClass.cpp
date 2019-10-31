/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenizerClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:57:15 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/15 14:57:15 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenizerClass.hpp"
#include <iostream>
#include <utility>

Tokenizer::Tokenizer(verbs type, std::string token) : _type(type), _token(std::move(token))
{
}

Tokenizer::Tokenizer() : _type(COMMENT)
{
}

Tokenizer::Tokenizer(Tokenizer const & src)
{
    *this = src;
	this->_type = src.getType();
	this->_token = src.getToken();
}

Tokenizer::~Tokenizer(){
//	std::cout << "destructor Tokenizer" << std::endl;
	_token.erase();
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
	//todo espace debut de ligne
	return _token == value ? 1 : 0;
}