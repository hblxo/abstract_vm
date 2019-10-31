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

verbosity				global_verbosity;
bool					global_diag;
bool					global_hasError = false;
ErrorHandler			*global_errorHandler;
std::list<Tokenizer *>	*global_tokenList;


Analyzer::Analyzer()
= default;

Analyzer::Analyzer(int ac, char **av)
{
	SetOptions(ac, av);
	global_errorHandler = new ErrorHandler();

	global_tokenList = initializeTokenList();
	for (const input_ptr& inp : _input)
	{
		lex_ptr phrase(new Lexer(inp->content, inp->line, global_tokenList));
		_phrases.push_back(phrase);
	}

	for (const lex_ptr& lex : _phrases)
	{
		par_ptr par(new Parser(lex->getVerb(), lex->getLineNb(), lex->getValue()));
		_operations.push_back(par);
	}

	if (global_diag && global_hasError)
	{
		global_errorHandler->print();
		return ;
	}

	std::shared_ptr<Calculator> calc(new Calculator());
	for (const par_ptr& par : _operations)
	{
		calc->run(par->getVerb(), par->getInstruct());
	}
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

Analyzer::~Analyzer()
{
	for (auto & it : *global_tokenList)
		delete (it);
	delete(global_tokenList);
}

void	Analyzer::readInput(std::istream &input)
{
	std::string	tmp;
	int 	line = 0;

	std::getline(input, tmp);
	while (tmp != ";;")
	{
		input_ptr ptr = std::make_shared<s_input>();
		ptr->content = tmp;
		ptr->line = line;
//		std::cout << "ret-content : \"" << ret->content << "\" - line : " << ret->line << std::endl;
		_input.push_back(ptr);
		getline(input, tmp);
		line++;
	}
}

void 	Analyzer::readFile(std::istream &file)
{
	int 	line = 1;
	std::string	tmp;
	while ((std::getline(file, tmp)))
	{
		input_ptr ptr = std::make_shared<s_input>();
		ptr->line = line++;
		ptr->content = std::string(tmp);
		_input.push_back(ptr);
	}
	std::vector<input_ptr>::iterator	it;
	//todo exit + espace
	for (it = _input.begin(); it != _input.end() && (*it)->content != "exit" ; it++)
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
	tokenList->push_back(new Tokenizer(MAX, "max"));
	tokenList->push_back(new Tokenizer(MIN, "min"));
	tokenList->push_back(new Tokenizer(POW, "pow"));
	tokenList->push_back(new Tokenizer(SIN, "sin"));
	tokenList->push_back(new Tokenizer(COS, "cos"));
	tokenList->push_back(new Tokenizer(TAN, "tan"));
	tokenList->push_back(new Tokenizer(SQRT, "sqrt"));
	tokenList->push_back(new Tokenizer(AND, "and"));
	tokenList->push_back(new Tokenizer(XOR, "xor"));
	tokenList->push_back(new Tokenizer(OR, "or"));
	tokenList->push_back(new Tokenizer(EXIT, "exit"));
	tokenList->push_back(new Tokenizer(COMMENT, ";"));
	tokenList->push_back(new Tokenizer(PUSH, "push"));
	tokenList->push_back(new Tokenizer(ASSERT, "assert"));
	return tokenList;
}
