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
#include "ErrorHandlerClass.hpp"
#include "ExceptionClass.hpp"
#include "GlobalVariables.hpp"
#include "AnalyzerClass.hpp"

verbosity	global_verbosity;
bool		global_diag;
bool		global_hasError = false;

Analyzer::Analyzer()
= default;

Analyzer::Analyzer(int ac, char **av)
{
	SetOptions(ac, av);
	SetInput(ac, av);
	std::list<s_input>::iterator ite;

	std::list<Tokenizer *> *tokenList = initializeTokenList();
	for (ite = _input2.begin(); ite != _input2.end(); ite++)
	{
//		std::cout << "content : " << (*ite).content << std::endl;
		_phrases.push_back(new Lexer((*ite).content, (*ite).line, tokenList));
	}

	for (Lexer *lex : _phrases)
	{
//		std::cout << "lex-verb : " << lex->getVerb() << std::endl;
		_operations.push_back(new Parser(lex->getVerb(), lex->getLineNb(), lex->getValue()));
	}

//	std::cout << "diag : " << global_diag << std::endl;
//	std::cout << "Error : " << global_hasError << std::endl;
	if (global_diag && global_hasError)
//		std::cout << "Ok" << std::endl;
		throw std::runtime_error("Error") ;

	auto	*calc = new Calculator;
	for (Parser *par : _operations)
	{
//		std::cout << par->getVerb() << std::endl;
		calc->run(par->getVerb(), par->getInstruct());
	}
	delete(calc);
}

void Analyzer::SetOptions(int ac, char **av)
{
	::global_verbosity = L_ERROR;
	::global_diag = false;
	if (ac > 1 && av[1][0] == '-')
	{
		if (strcmp(av[1], "-verbose") == 0 || strcmp(av[1], "-v") == 0)
			::global_verbosity = L_INFO;
		else
//			ErrorHandler("Invalid");
			throw InvalidArgumentsCountException();
	}
}


void	Analyzer::SetInput(int ac, char **av){
	std::ifstream file;
	std::string filename;

	if (ac > 3)
		throw InvalidArgumentsCountException();
	else if ((ac == 2 && global_verbosity == L_OFF) || (ac == 3 && global_verbosity != L_OFF))
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

Analyzer::~Analyzer(){
}

void	Analyzer::readInput(std::istream &input)
{
	auto	*tmp = new std::string("");
	int 	line = 0;
	auto	*ret = new s_input;

	getline(input, *tmp);
	while (*tmp != ";;")
	{
		ret->content = *tmp;
		ret->line = line;
//		std::cout << "ret-content : \"" << ret->content << "\" - line : " << ret->line << std::endl;
		_input2.push_back(*ret);
//		_input.push_back(*tmp); // delete
		getline(input, *tmp);
		line++;
//		ret = {};
	}
//	delete(ret);
//	delete(tmp);
}

void 	Analyzer::readFile(std::istream &file)
{
	auto	*tmp = new std::string("");
	int 	line = 0;
	auto	*ret = new s_input;

	while (getline(file, *tmp))
	{
		ret->line = line++;
		ret->content = *tmp;
		_input2.push_back(*ret);
		_input.push_back(*tmp);
//		ret = {};
	}
	delete(ret);
	delete(tmp);
	std::list<std::string>::iterator	it;
	for (it = _input.begin(); it != _input.end() && (*it) != "exit" ; it++)
		;
	if ((std::find(_input.begin(), _input.end(), "exit") == _input.end()))
	{
		throw NoExitInstructionException();
	}
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
