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
#include <regex>

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
//	std::string							tmp;

	auto							*tmp = new std::string("");

	getline(input, *tmp);
	while (*tmp != ";;")
	{
		_input.push_back(*tmp);
		getline(input, *tmp);
	}
	delete(tmp);
}

void 	Lexer::readFile(std::istream &file)
{
	auto							*tmp = new std::string("");

	while (getline(file, *tmp))
		_input.push_back(*tmp);
	std::list<std::string>::iterator	it;
	for (it = _input.begin(); it != _input.end() && (*it) != "exit" ; it++)
		;
	if ((std::find(_input.begin(), _input.end(), "exit") == _input.end()))
		throw NoExitInstructionException();
	delete(tmp);
}

void Lexer::run()
{
	std::list<std::string>::iterator ite;

    this->_matchList = InitializeMatchList();

    for (ite = _input.begin(); ite != _input.end() && (*ite) != "exit" && (*ite) != ";;" ; ite++)
	{
		if ((*ite)[0] == ';')
    		;
		else if (!(*ite).empty() && (*ite)[0] != '\n')
            defineLexerInstruct((*ite));
	}
}

std::string	Lexer::parseLine(const std::string& line)
{
	std::size_t commentPos;

	char c = ';';
	commentPos = line.find(c);
	std::string value = line.substr(0, commentPos);
	return value;
}

int	Lexer::findInstructType(const std::string& value){
	std::regex regS, regC;
	regS = R"(^(\s*)(add|dump|pop|sub|mul|div|mod|print|exit)(\s*)$)";
	if (std::regex_match(value, regS))
		return 1;
	return 0;
}

std::string Lexer::epurString(const std::string &str)
{
	std::regex reg(R"([\t])");
	return std::regex_replace(str, reg, " ");
}

void    Lexer::defineLexerInstruct(const std::string& string)
{
    std::list<Tokenizer*>::iterator ite;
    std::size_t pos;


    std::string line = Lexer::parseLine(string);
    line = epurString(line);
    char c = ' ';
    pos = line.find(c);
	std::string value = line.substr(0, pos);

    for(ite = _matchList->begin(); ite != _matchList->end(); ite++)
    {
        if ((*ite)->matchSearch(value))
        {
        	if (findInstructType(value) == 1)
				_calc.doOperation((*ite)->getType());
        	else
				_calc.doOperation((*ite)->getType(), line.substr(pos + 1));
			return ;
		}
    }
    throw InvalidInstructionException();
}


//cf : http://onoffswitch.net/building-a-custom-lexer/
std::list<Tokenizer*> *Lexer::InitializeMatchList()
{
    auto *keywordMatchers = new std::list<Tokenizer*>;
    keywordMatchers->push_back(new Tokenizer(POP, "pop"));
    keywordMatchers->push_back(new Tokenizer(DUMP, "dump"));
    keywordMatchers->push_back(new Tokenizer(ADD, "add"));
    keywordMatchers->push_back(new Tokenizer(SUB, "sub"));
    keywordMatchers->push_back(new Tokenizer(MUL, "mul"));
    keywordMatchers->push_back(new Tokenizer(DIV, "div"));
    keywordMatchers->push_back(new Tokenizer(MOD, "mod"));
    keywordMatchers->push_back(new Tokenizer(PRINT, "print"));
    keywordMatchers->push_back(new Tokenizer(EXIT, "exit"));
    keywordMatchers->push_back(new Tokenizer(COMMENT, ";"));
    keywordMatchers->push_back(new Tokenizer(PUSH, "push"));
    keywordMatchers->push_back(new Tokenizer(ASSERT, "assert"));
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
//	std::cout << "destructor Lexer" << std::endl;
	std::list<Tokenizer*>::iterator ite;

	for(ite = _matchList->begin(); ite != _matchList->end(); ite++)
	{
		delete((*ite));
	}
	_matchList->clear();
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
	std::list<Tokenizer*>::iterator ite;

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