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
#include <ErrorHandlerClass.hpp>
#include "InputParserClass.hpp"
#include "ExceptionClass.hpp"
#include "GlobalVariables.hpp"
#include "AnalyzerClass.hpp"

verbosity		global_verbosity;
bool			global_diag;
bool			global_hasError = false;
ErrorHandler	*global_errorHandler = new ErrorHandler();

Analyzer::Analyzer()
= default;

Analyzer::Analyzer(int ac, char **av)
{
	SetOptions(ac, av);
	std::list<s_input>::iterator ite;

	std::list<Tokenizer *> *tokenList = initializeTokenList();
	for (ite = _input.begin(); ite != _input.end(); ite++)
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
	{
		global_errorHandler->print();
		return ;
	}

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
	InputParser 	inputParser(ac, av);
	std::string 	filename;
	int 			flagNb = 1;

	::global_verbosity = L_ERROR;
	::global_diag = false;
	if (inputParser.cmdOptExist("-v") || inputParser.cmdOptExist("--verbose"))
	{
		flagNb++;
		global_verbosity = L_INFO;
	}
	if (inputParser.cmdOptExist("-d") || inputParser.cmdOptExist("--diag"))
	{
		flagNb++;
		global_diag = true;
	}
	if (inputParser.cmdOptExist("-f"))
	{
		flagNb += 2;
		filename = inputParser.getCmdOpt("-f");
	}
	else if (inputParser.cmdOptExist("--filename"))
	{
		flagNb += 2;
		filename = inputParser.getCmdOpt("--filename");
	}
	else
		filename = std::string("");
	if (flagNb == ac)
		SetInput(filename);
	else
		throw InvalidArgumentsException("usage : ./avm [-v --verbose] [-d --diag] [-f --filename filename]");
}


void	Analyzer::SetInput(const std::string& filename){
	std::ifstream file;

	if (!filename.empty())
	{
		file.open(filename);
		if (file.fail())
			throw FileOpeningException("The file can't be opened");
		readFile(file);
	}
	else
		readInput(std::cin);
}

Analyzer::Analyzer(Analyzer const &src)
{
	*this = src;
}

Analyzer::~Analyzer()= default;

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
		_input.push_back(*ret);
		getline(input, *tmp);
		line++;
	}
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
		_input.push_back(*ret);
	}
	delete(ret);
	delete(tmp);
	std::list<s_input>::iterator	it;
	for (it = _input.begin(); it != _input.end() && (*it).content != "exit" ; it++)
		;
	if (it == _input.end())
		throw NoExitInstructionException("The file doesn't contain a \"exit\" instruction");
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
