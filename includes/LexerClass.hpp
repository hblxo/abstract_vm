/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:35:50 by hbouchet          #+#    #+#             */
/*   Updated: 2019/02/20 13:07:39 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXERCLASS_HPP
# define LEXERCLASS_HPP

# include <iostream>

class Lexer {
public: 
    class BadArgumentsException;

    Lexer(void); 
    Lexer(int argc, char **argv);
    // Lexer(std::string filename); 
    Lexer(Lexer const & src); 
    ~Lexer(void); 

	Lexer &		operator=(Lexer const & rhs);

    std::string const	toString(void) const;


private:

};

class Lexer::BadArgumentsException : public std::exception {
public:
    BadArgumentsException(void);
    BadArgumentsException(BadArgumentsException const & src);
    ~BadArgumentsException(void) throw();
    virtual const char* what() const throw();

	BadArgumentsException &		operator=(BadArgumentsException const &);
};


std::ostream &	operator<< (std::ostream & o, Lexer const & rhs);


#endif