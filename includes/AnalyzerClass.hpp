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


typedef std::shared_ptr<Lexer> lex_ptr;
typedef std::shared_ptr<Parser> par_ptr;

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
typedef std::shared_ptr<s_input>	input_ptr;

private:
	std::vector<input_ptr>			_input;
//	std::list<s_input>				_input;
	std::vector<lex_ptr>			_phrases;
	std::vector<par_ptr>			_operations;

	static std::list<Tokenizer*>	*initializeTokenList();
	void							readFile(std::istream &file);
	void							readInput(std::istream &input);
	/* Setters */
	void							SetInput(const std::string& filename);
	void							SetOptions(int ac, char **av);
};
std::ostream						&operator<< (std::ostream & o, Analyzer const & rhs);


#endif //AVM_ANALYZER_CLASS_HPP
