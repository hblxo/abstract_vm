/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnalyzerClass.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:55:03 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/14 10:55:03 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_ANALYZER_CLASS_HPP
#define AVM_ANALYZER_CLASS_HPP

#include <iostream>
#include <list>
#include "CalculatorClass.hpp"
#include "ParserClass.hpp"
#include "LexerClass.hpp"
#include "eVerboseLevel.hpp"
#include "LogClass.hpp"

class Analyzer{
public:
	Analyzer();
	Analyzer(int ac, char **av);
	Analyzer(Analyzer const & src);
	~Analyzer();

	Analyzer 						&operator=(Analyzer const & rhs);
	std::string						toString() const;

	struct s_input {
		std::string					content;
		int 						line;
	};

private:
	std::list<s_input>				_input2;
	std::list<std::string>			_input;
	std::list<Lexer*>				_phrases;
	std::list<class Parser*>		_operations;

	static std::list<Tokenizer*>	*initializeTokenList();
	void							readFile(std::istream &file);
	void							readInput(std::istream &input);
	/* Setters */
	void							SetInput(const std::string& filename);
	void							SetOptions(int ac, char **av);
};
std::ostream						&operator<< (std::ostream & o, Analyzer const & rhs);


#endif //AVM_ANALYZER_CLASS_HPP
