/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:16:51 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/14 10:16:51 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExceptionClass.hpp"
#include "ParserClass.hpp"

Parser::Parser()
= default;

Parser::Parser(verbs verb, std::string value)
{

	if ((verb == PUSH || verb == ASSERT) && !value.empty())
	{
		_verb = verb;
		_instruct = new Value(value);
	}
	else if (verb != PUSH && verb != ASSERT && value.empty())
	{
		_verb = verb;
	}
	else
	{
		throw InvalidInstructionException();
	}
}

Parser::Parser(Parser const &src)
{
	this->_instruct = src.getInstruct();
	this->_verb = src.getVerb();
	*this = src;
}

Parser::~Parser()
= default;

Parser &Parser::operator=(Parser const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string Parser::toString() const
{
	std::string 						tmp;

	if (_verb == PUSH || _verb == ASSERT)
		tmp = std::to_string(_verb) + " " + _instruct->toString();
	else
		tmp = std::to_string(_verb);
	return tmp;
}

verbs Parser::getVerb() const
{
	return _verb;
}

Value *Parser::getInstruct() const
{
	return _instruct;
}


std::ostream &operator<<(std::ostream &o, Parser const &rhs)
{
	o << rhs.toString();
	return o;
}
