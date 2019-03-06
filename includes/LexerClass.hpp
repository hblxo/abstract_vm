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
# include "MatcherClass.hpp"


class Lexer {
    public: 

        Lexer(void); 
        Lexer(int argc, char **argv);
        Lexer(Lexer const & src); 
        ~Lexer(void); 

        Lexer &		operator=(Lexer const & rhs);

        std::string const	toString(void) const;

        enum instructions {
            COMMENT,
            PUSH,
            POP,
            DUMP,
            ASSERT,
            ADD,
            SUB,
            MUL,
            DIV,
            MOD,
            PRINT,
            EXIT
        };

        void    run(void);
        void    defineLexerInstruct(std::string string);

    private:
        std::list<Matcher*>  *_matchList;

        std::list<Matcher*> *InitializeMatchList();
};

std::ostream &	operator<< (std::ostream & o, Lexer const & rhs);


#endif