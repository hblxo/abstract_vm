/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:36:26 by hbouchet          #+#    #+#             */
/*   Updated: 2019/03/04 12:32:52 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LexerClass.hpp"
#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>
#include <regex>
#include <GlobalVariables.hpp>

Lexer::Lexer(const std::string& str, int lineNb,
			 const std::list<Tokenizer*>*pList) :  _lineNb(lineNb), _verb(COMMENT)
{
	std::string line = Lexer::ignoreComment(str);
//	std::cout << "LEXER - line : " << line << std::endl;

	line = formatSpace(line);
	if (line.empty() || line[0] == ';' || line[0] == '\n')
		return ;
	defineLexerInstruct(line, pList);
}

void Lexer::defineLexerInstruct(const std::string &string,
								const std::list<Tokenizer*>* tokenList)
{
    std::size_t pos;


    char c = ' ';
    pos = string.find(c);
	std::string value = string.substr(0, pos);

    for (Tokenizer* tok : *tokenList)
	{
		if (tok->matchSearch(value))
		{
    		if (findInstructType(value) == 1)
				this->_verb = tok->getType();
    		else if (findInstructType(value) == 2)
			{
    			this->_verb = tok->getType();
    			this->_value = string.substr(pos + 1);
			}
    		else
				global_errorHandler->handler("Invalid Instruction", _lineNb);
//			std::cout << this->_verb << std::endl;
    		return;
		}
    }
	global_errorHandler->handler("Invalid Instruction", _lineNb);
}

int	Lexer::findInstructType(const std::string& value){
	std::regex regS, regC;
	regS = R"(^(\s*)(add|dump|pop|sub|mul|div|mod|print|exit)(\s*)$)";
	regC = R"(^(\s*)(push|assert)*$)";
	if (std::regex_match(value, regS))
		return 1;
	else if (std::regex_match(value, regC))
		return 2;
	return 0;
}

std::string	Lexer::ignoreComment(const std::string& line)
{
	std::size_t commentPos;

	char c = ';';
	commentPos = line.find(c);
	std::string value = line.substr(0, commentPos);
	return value;
}

std::string Lexer::formatSpace(const std::string &str)
{
	std::regex reg(R"([\t])");
	return std::regex_replace(str, reg, " ");
}

Lexer::Lexer() : _lineNb(-1), _verb(COMMENT)
{}

Lexer::Lexer(Lexer const & src) 
{
	this->_verb = src.getVerb();
	this->_lineNb = src.getLineNb();
	this->_value = src.getValue();
    *this = src;
}

Lexer::~Lexer()
{
	_value.erase();
	//	std::cout << "destructor Lexer" << std::endl;
}

Lexer &	Lexer::operator=(Lexer const & rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

std::string Lexer::toString() const
{
	std::string ret;
	ret = std::to_string(getVerb());
	ret += " " + getValue();
    return ret;
}

std::string Lexer::getValue() const
{
	return _value;
}

verbs Lexer::getVerb() const
{
	return _verb;
}

int Lexer::getLineNb() const
{
	return _lineNb;
}

std::ostream &	operator<< (std::ostream & o, Lexer const & rhs)
{
    o << rhs.toString();
    return o;
}