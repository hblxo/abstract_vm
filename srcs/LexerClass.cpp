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
#include "../includes/CalculatorClass.hpp"
#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>
#include <fstream>

Lexer::Lexer(int argc, char **argv)
{
//TODO : check EOF
    std::ifstream file;
    std::string filename;

    if (argc > 2)
        throw Exception("usage : ./avm");
    else if (argc == 2)
    {
        filename = argv[1];
        file.open(filename);
        if (file.fail())
        	throw Exception("Fail to open file");
         Lexer::run(file);
    }
    else
	{
		Lexer::run(std::cin);
	}
    return;
}

void    Lexer::run(std::istream &file)
{
    std::string     cmd;

    getline(file, cmd);
    this->_matchList = InitializeMatchList();
    while (cmd != ";;" && cmd != "exit")
    {
    	if (cmd[0] == ';')
    		;//TODO : traiter commentaire debut de ligne
        else if (cmd.size() != 0 && cmd[0] != '\n')
            defineLexerInstruct(cmd);
        cmd.clear();
        getline(file, cmd);
    }
}

std::string	Lexer::parseLine(std::string line)
{
	std::size_t commentPos;

	commentPos = line.find(";");

//	std::string comment = line.substr(commentPos + 1);
	//TODO : traiter commentaire en fin de ligne
	std::string value = line.substr(0, commentPos);
	return value;
}

void    Lexer::defineLexerInstruct(std::string string)
{
    std::list<Matcher*>::iterator ite;
    std::size_t pos;
	auto calc = new Calculator();

    std::string line = Lexer::parseLine(string);
    pos = line.find(" ");
	std::string value = line.substr(0, pos);
      //TODO : parser commentaire en fin d'instruction

    for(ite = _matchList->begin(); ite != _matchList->end(); ite++)
    {
        if ((*ite)->matchSearch(value))
        {
            if (pos != std::string::npos)
//            && std::regex_match(line,
//            		std::regex("^(\\s*)?(push|assert)(\\s+)(((int8|int16|int32)[(]-?[0-9]+[)])|((float|double)[(]-?[0-9]+(.?[0-9]+)?[)]))(\\s*)(;.*)?$")))
                calc->doOperation((*ite)->getType(), line.substr(pos + 1));
            else
                calc->doOperation((*ite)->getType());
            return ;
        }
    }
    throw Exception("\"" + string + "\" does not contain a valid operation");
}


//cf : http://onoffswitch.net/building-a-custom-lexer/
std::list<Matcher*> *Lexer::InitializeMatchList()
{
    std::list<Matcher*> *keywordMatchers = new std::list<Matcher*>;
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
{
}

Lexer::Lexer(Lexer const & src) 
{
    //Do whatever needs to be done
    *this = src;
    return;
}

Lexer::~Lexer()
{
    delete _matchList;
}

Lexer &	Lexer::operator=(Lexer const & rhs)
{
    //Do whatever needs to be done
    if (this != &rhs)
        *this = rhs;
    return *this;
}

std::string const Lexer::toString() const
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