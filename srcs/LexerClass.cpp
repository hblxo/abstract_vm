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
			 const std::list<Tokenizer*>*pList) :  _lineNb(lineNb), _value(""), _verb(COMMENT)
{
//	std::cout << "LEXER - line : " << line << std::endl;
	std::string fline = formatSpace(str);
//	std::cout << fline << std::endl;
	std::string line = Lexer::ignoreComment(fline);

	if (line.empty() || line[0] == ';' || line[0] == '\n')
		return ;
	defineLexerInstruct(line, pList);
}

void Lexer::defineLexerInstruct(const std::string& string,
								const std::list<Tokenizer*>* tokenList)
{
    std::size_t pos;

    char c = ' ';
    pos = string.find_first_of(c);
	std::string value = string.substr(0, pos);

    for (Tokenizer* tok : *tokenList)
	{
		if (tok->matchSearch(value))
		{
   			this->_value = std::string();
    		if (findInstructType(value) == 1)
			{
    			this->_verb = tok->getType();
			}
    		else if (findInstructType(value) == 2)
			{
    			this->_verb = tok->getType();
    			this->_value = string.substr((std::string::size_type)pos + 1);
			}
    		else
			{
    			global_errorHandler->handler("Invalid Instruction", _lineNb);
			}
//			std::cout << this->_verb << std::endl;
    		return;
		}
    }
	global_errorHandler->handler("Invalid Instruction", _lineNb);
}

int	Lexer::findInstructType(const std::string& value){
	std::regex regS, regC;
	regS = R"(^(\s)*(add|dump|pop|sub|mul|div|mod|print|exit|max|min|pow|sin|cos|tan|sqrt|and|xor|or)(\s*)$)";
	regC = R"(^(\s)*(push|assert)*$)";
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
	commentPos = line.rfind(c);
	std::string value = line.substr((std::string::size_type )0, (std::string::size_type )commentPos);
	return value;
}

std::string Lexer::formatSpace(std::string str)
{
	std::regex reg(R"([\t])");
	std::string tmp = std::regex_replace(str, reg, " ");
	std::regex reg2(R"(^\s+)");
	return std::regex_replace(tmp, reg2, "");
}

Lexer::Lexer() : _lineNb(-1), _value(""),_verb(COMMENT)
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

//std::string Lexer::getValue() const
//{
//	return _value;
//}

verbs Lexer::getVerb() const
{
	return _verb;
}

int Lexer::getLineNb() const
{
	return _lineNb;
}

const std::string &Lexer::getValue() const
{
	return _value;
}

std::ostream &	operator<< (std::ostream & o, Lexer const & rhs)
{
    o << rhs.toString();
    return o;
}