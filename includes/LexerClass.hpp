/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:35:50 by hbouchet          #+#    #+#             */
/*   Updated: 2019/03/04 11:22:57 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXERCLASS_HPP
# define LEXERCLASS_HPP

# include <iostream>
# include <list>
# include "TokenizerClass.hpp"
#include "IOperand.hpp"
#include "CalculatorClass.hpp"
#include "InstructClass.hpp"
#include "AnalyzerClass.hpp"


class Lexer {
   public:
	Lexer();
	Lexer(std::basic_string<char> basicString,
		  std::list<Tokenizer*> pList);
	Lexer(Lexer const & src);
	~Lexer();

    Lexer &		operator=(Lexer const & rhs);

    std::string 	toString() const;
	const std::string &getValue() const;
	verbs getVerb() const;


private:
	static std::string ignoreComment(const std::string& line);
	void defineLexerInstruct(const std::string &string,
						 const std::list<Tokenizer*>& tokenList);

	static int findInstructType(const std::string& value);
	static std::string formatSpace(const std::string& str);


	std::string			_value;
	verbs 				_verb;

};

std::ostream &	operator<< (std::ostream & o, Lexer const & rhs);


#endif