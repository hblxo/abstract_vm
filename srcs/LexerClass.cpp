/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:36:26 by hbouchet          #+#    #+#             */
/*   Updated: 2019/02/20 13:10:37 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LexerClass.hpp"
#include <iostream>
#include <fstream>

Lexer::Lexer(int argc, char **argv)
{
    std::ifstream file;
    std::string filename;

    if (argc != 2)
        throw BadArgumentsException();
        // std::cout << "usage : ./avm" << std::endl;
    filename = argv[1];
    file.open(filename);
    return;
}

Lexer::Lexer(void)
{
    return;
}

Lexer::Lexer(Lexer const & src) 
{
    //Do whatever needs to be done
    *this = src;
    return;
}

Lexer::~Lexer(void)
{
    return;
}

Lexer &	Lexer::operator=(Lexer const & rhs)
{
    //Do whatever needs to be done
    if (this != &rhs)
        *this = rhs;
    return *this;
}

std::string const Lexer::toString(void) const
{
    return "OK";
    // Return whatever needs to be returned
}

std::ostream &	operator<< (std::ostream & o, Lexer const & rhs)
{
    o << rhs.toString();
    return o;
}

/*
** LEXER EXCEPTION : Bad arguments
*/


Lexer::BadArgumentsException::BadArgumentsException(void)
{
    return;
}

Lexer::BadArgumentsException::BadArgumentsException(BadArgumentsException const & src) 
{
    *this = src;
    return;
}

Lexer::BadArgumentsException::~BadArgumentsException(void) throw()
{
    return;
}

const char* Lexer::BadArgumentsException::what() const throw()
{
    return ("Bad Arguments\nusage : ./avm");
}

Lexer::BadArgumentsException &	Lexer::BadArgumentsException::operator=(Lexer::BadArgumentsException const & )
{
    // if (this != &rhs)
    //     *this = rhs;
    return *this;
}