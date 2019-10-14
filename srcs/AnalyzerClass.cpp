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

#include "../includes/AnalyzerClass.hpp"
#include <iostream>
#include <ExceptionClass.hpp>
#include <fstream>

Analyzer::Analyzer(int ac, char **av)
{
	SetInput(ac, av);
	std::list<std::string>::iterator ite;

	std::list<Tokenizer *> tokenList = initializeTokenList();
	for (ite = _input.begin(); ite != _input.end(); ite++)
		_phrases.push_back(Lexer((*ite), tokenList));
	for (Lexer lex : _phrases)
		_operations.push_back(Parser(lex.getVerb(), lex.getValue()));

	Calculator	*calc = new Calculator;
	for (Parser par : _operations)
		calc->run(par.getVerb(), par.getInstruct());
}

void	Analyzer::SetInput(int ac, char **av){
	std::ifstream file;
	std::string filename;

	if (ac > 2)
		throw InvalidArgumentsCountException();
	else if (ac == 2)
	{
		filename = av[1];
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
}

std::ostream &operator<<(std::ostream &o, Analyzer const &rhs)
{
	o << rhs.toString();
	return o;
}

std::list<Tokenizer*> Analyzer::initializeTokenList()
{
	std::list<Tokenizer*> tokenList;
	tokenList.push_back(new Tokenizer(POP, "pop"));
	tokenList.push_back(new Tokenizer(DUMP, "dump"));
	tokenList.push_back(new Tokenizer(ADD, "add"));
	tokenList.push_back(new Tokenizer(SUB, "sub"));
	tokenList.push_back(new Tokenizer(MUL, "mul"));
	tokenList.push_back(new Tokenizer(DIV, "div"));
	tokenList.push_back(new Tokenizer(MOD, "mod"));
	tokenList.push_back(new Tokenizer(PRINT, "print"));
	tokenList.push_back(new Tokenizer(EXIT, "exit"));
	tokenList.push_back(new Tokenizer(COMMENT, ";"));
	tokenList.push_back(new Tokenizer(PUSH, "push"));
	tokenList.push_back(new Tokenizer(ASSERT, "assert"));
	return tokenList;
}

