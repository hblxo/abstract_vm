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

#include "../includes/LexerClass.hpp"
#include "../includes/ExceptionClass.hpp"
#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>
#include <fstream>

Lexer::Lexer(int argc, char **argv)
{
    std::ifstream file;
    std::string filename;

    if (argc > 2)
        throw InvalidArgumentsCountException();
    else if (argc == 2)
    {
        filename = argv[1];
        file.open(filename);
        if (file.fail())
        	throw OpenFailureException();
        Lexer::readFile(file);
		Lexer::run();
    }
    else
	{
    	Lexer::readInput(std::cin);
		Lexer::run();
	}
}

void	Lexer::readInput(std::istream &input)
{
	std::string							tmp;

	getline(input, tmp);
	while (tmp != ";;")
	{
		_input.push_back(tmp);
		getline(input, tmp);
	}
}

void 	Lexer::readFile(std::istream &file)
{
	std::string							tmp;

	while (getline(file, tmp))
		_input.push_back(tmp);
	std::list<std::string>::iterator	it;
	for (it = _input.begin(); it != _input.end() && (*it) != "exit" ; it++)
		;
	if ((std::find(_input.begin(), _input.end(), "exit") == _input.end()))
		throw NoExitInstructionException();
}

void Lexer::run()
{
	std::list<std::string>::iterator ite;

    this->_matchList = InitializeMatchList();

    for (ite = _input.begin(); ite != _input.end() && (*ite) != "exit" && (*ite) != ";;" ; ite++)
	{
		if ((*ite)[0] == ';')
    		;
		else if ((*ite).size() != 0 && (*ite)[0] != '\n')
            defineLexerInstruct((*ite));
	}
}

std::string	Lexer::parseLine(std::string line)
{
	std::size_t commentPos;

	commentPos = line.find(";");
	std::string value = line.substr(0, commentPos);
	return value;
}

void    Lexer::defineLexerInstruct(std::string string)
{
    std::list<Matcher*>::iterator ite;
    std::size_t pos;

    std::string line = Lexer::parseLine(string);
    pos = line.find(" ");
	std::string value = line.substr(0, pos);

    for(ite = _matchList->begin(); ite != _matchList->end(); ite++)
    {
        if ((*ite)->matchSearch(value))
        {
            if (pos != std::string::npos)
                _calc.doOperation((*ite)->getType(), line.substr(pos + 1));
            else
                _calc.doOperation((*ite)->getType());
            return ;
        }
    }
    throw InvalidInstructionException();
}


//cf : http://onoffswitch.net/building-a-custom-lexer/
std::list<Matcher*> *Lexer::InitializeMatchList()
{
    auto *keywordMatchers = new std::list<Matcher*>;
    keywordMatchers->push_back(new Matcher(POP, "pop"));
    keywordMatchers->push_back(new Matcher(DUMP, "dump"));
    keywordMatchers->push_back(new Matcher(ADD, "add"));
    keywordMatchers->push_back(new Matcher(SUB, "sub"));
    keywordMatchers->push_back(new Matcher(MUL, "mul"));
    keywordMatchers->push_back(new Matcher(DIV, "div"));
    keywordMatchers->push_back(new Matcher(MOD, "mod"));
    keywordMatchers->push_back(new Matcher(PRINT, "print"));
    keywordMatchers->push_back(new Matcher(EXIT, "exit"));
    keywordMatchers->push_back(new Matcher(COMMENT, ";"));
    keywordMatchers->push_back(new Matcher(PUSH, "push"));
    keywordMatchers->push_back(new Matcher(ASSERT, "assert"));
    return keywordMatchers;
}

Lexer::Lexer()
= default;

Lexer::Lexer(Lexer const & src) 
{
    *this = src;
}

Lexer::~Lexer()
{
    delete _matchList;
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
	std::list<Matcher*>::iterator ite;

	for (ite = this->_matchList->begin(); ite != this->_matchList->end(); ite++)
	{
		ret += (*ite)->toString();
		ret += '\n';
	}
    return ret;
}

std::ostream &	operator<< (std::ostream & o, Lexer const & rhs)
{
    o << rhs.toString();
    return o;
}