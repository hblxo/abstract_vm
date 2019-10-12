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


class Lexer {
    public: 

        Lexer(void); 
        Lexer(int argc, char **argv);
        Lexer(Lexer const & src); 
        ~Lexer(void); 

        Lexer &		operator=(Lexer const & rhs);

        std::string 	toString(void) const;

        enum instructions {
            POP,
            DUMP,
            ADD,
            SUB,
            MUL,
            DIV,
            MOD,
            PRINT,
            EXIT,
            PUSH,
            ASSERT,
            COMMENT,
        };


    private:
        void    defineLexerInstruct(const std::string& string);
		static std::string parseLine(const std::string& line);
        static std::list<Tokenizer*> *InitializeMatchList();
		void run();

		std::list<std::string>	_input;
        std::list<Tokenizer*> 	*_matchList{};
        Calculator				_calc;

	void readFile(std::istream &file);

	void readInput(std::istream &input);

	static int findInstructType(const std::string& value);

	static std::string epurString(const std::string& str);
};

std::ostream &	operator<< (std::ostream & o, Lexer const & rhs);


#endif