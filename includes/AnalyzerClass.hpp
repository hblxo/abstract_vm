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

	Analyzer &operator=(Analyzer const & rhs);

	std::string	toString() const;

private:
	std::list<std::string>		_input;
	std::list<Lexer*>			_phrases;
	std::list<class Parser*>	_operations;
	verbosity					_verbosity;

	Log							*_log;

	static std::list<Tokenizer*> *initializeTokenList();
	void readFile(std::istream &file);
	void readInput(std::istream &input);

	void	SetInput(int ac, char **av);
	void	SetOptions(int ac, char **av);
};
std::ostream	&	operator<< (std::ostream & o, Analyzer const & rhs);


#endif //AVM_ANALYZER_CLASS_HPP
