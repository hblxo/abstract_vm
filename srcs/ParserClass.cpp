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

#include "GlobalVariables.hpp"
#include "ExceptionClass.hpp"
#include "ParserClass.hpp"

Parser::Parser() : _verb(COMMENT), _instruct(new Value()), _lineNb(-1)
{}

Parser::Parser(verbs verb, int lineNb, const std::string& value) : _lineNb(lineNb)
{
	if ((verb == PUSH || verb == ASSERT) && !value.empty())
	{
		_verb = verb;
		val_ptr ptr(new Value(value, _lineNb));
		_instruct = ptr;
	}
	else if (verb != PUSH && verb != ASSERT && value.empty())
	{
		_verb = verb;
	}
	else
	{
//		std::cout << value << std::endl;
		global_errorHandler->handler("Invalid instruction structure", _lineNb);
	}
}

Parser::Parser(Parser const &src)
{
	this->_lineNb = src.getLineNb();
	this->_instruct = src.getInstruct();
	this->_verb = src.getVerb();
	*this = src;
}

Parser::~Parser()= default;

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

val_ptr	Parser::getInstruct() const
{
	return _instruct;
}

int Parser::getLineNb() const
{
	return _lineNb;
}


std::ostream &operator<<(std::ostream &o, Parser const &rhs)
{
	o << rhs.toString();
	return o;
}
