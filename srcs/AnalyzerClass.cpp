/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnalyzerClass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:58:35 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/14 10:58:35 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "ExceptionClass.hpp"
#include "AnalyzerClass.hpp"

Analyzer::Analyzer()
{
}

Analyzer::Analyzer(int ac, char **av)
{
	SetOptions(ac, av);
	SetInput(ac, av);
	std::list<std::string>::iterator ite;

	std::list<Tokenizer *> *tokenList = initializeTokenList();
	for (ite = _input.begin(); ite != _input.end(); ite++)
	{
		_phrases.push_back(new Lexer((*ite), tokenList));
	}

	for (Lexer *lex : _phrases)
	{
//		std::cout << "lex-verb : " << lex->getVerb() << std::endl;
		_operations.push_back(new Parser(lex->getVerb(), lex->getValue()));
	}

	Calculator	*calc = new Calculator;
	for (Parser *par : _operations)
	{
//		std::cout << par->getVerb() << std::endl;
		calc->run(par->getVerb(), par->getInstruct());
	}
}

void Analyzer::SetOptions(int ac, char **av)
{
	_verbosity = L_OFF;
	if (ac > 1 && av[1][0] == '-')
	{
		if (strcmp(av[1], "-verbose") == 0 || strcmp(av[1], "-v"))
			_verbosity = L_INFO;
		else
			;//todo : throw error
	}
	_log = new Log(_verbosity);
}


void	Analyzer::SetInput(int ac, char **av){
	std::ifstream file;
	std::string filename;

	if (ac > 3)
		throw InvalidArgumentsCountException();
	else if ((ac == 2 && _verbosity == L_OFF) || (ac == 3 && _verbosity != L_OFF))
	{
		filename = av[ac - 1];
		file.open(filename);
		if (file.fail())
			throw OpenFailureException();
		readFile(file);
	}
	else
		readInput(std::cin);
}

Analyzer::Analyzer(Analyzer const &src)
{
	*this = src;
}

Analyzer::~Analyzer()
{
}

void	Analyzer::readInput(std::istream &input)
{
	auto	*tmp = new std::string("");

	getline(input, *tmp);
	while (*tmp != ";;")
	{
		_input.push_back(*tmp);
		getline(input, *tmp);
	}
	delete(tmp);
}

void 	Analyzer::readFile(std::istream &file)
{
	auto	*tmp = new std::string("");

	while (getline(file, *tmp))
		_input.push_back(*tmp);
	std::list<std::string>::iterator	it;
	for (it = _input.begin(); it != _input.end() && (*it) != "exit" ; it++)
		;
	if ((std::find(_input.begin(), _input.end(), "exit") == _input.end()))
	{
		delete(tmp);
		throw NoExitInstructionException();
	}
	delete(tmp);
}


Analyzer&Analyzer::operator=(Analyzer const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string Analyzer::toString() const
{
	return "";
}

std::ostream &operator<<(std::ostream &o, Analyzer const &rhs)
{
	o << rhs.toString();
	return o;
}

std::list<Tokenizer*> *Analyzer::initializeTokenList()
{
	auto *tokenList = new std::list<Tokenizer*>;
	tokenList->push_back(new Tokenizer(POP, "pop"));
	tokenList->push_back(new Tokenizer(DUMP, "dump"));
	tokenList->push_back(new Tokenizer(ADD, "add"));
	tokenList->push_back(new Tokenizer(SUB, "sub"));
	tokenList->push_back(new Tokenizer(MUL, "mul"));
	tokenList->push_back(new Tokenizer(DIV, "div"));
	tokenList->push_back(new Tokenizer(MOD, "mod"));
	tokenList->push_back(new Tokenizer(PRINT, "print"));
	tokenList->push_back(new Tokenizer(EXIT, "exit"));
	tokenList->push_back(new Tokenizer(COMMENT, ";"));
	tokenList->push_back(new Tokenizer(PUSH, "push"));
	tokenList->push_back(new Tokenizer(ASSERT, "assert"));
	return tokenList;
}
