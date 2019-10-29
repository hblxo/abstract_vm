/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:34:25 by hbouchet          #+#    #+#             */
/*   Updated: 2019/03/04 11:23:30 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONCLASS_HPP
# define EXCEPTIONCLASS_HPP

# include <iostream>


class DivideByZeroException : public std::runtime_error
{
public:
	explicit DivideByZeroException(const std::string& what_arg);
};

class OverflowException : public std::overflow_error
{
public:
	explicit OverflowException(const std::string& what_arg);
};

class UnderflowException : public std::overflow_error
{
public:
	explicit UnderflowException(const std::string& what_arg);
};

class FileOpeningException : public std::runtime_error
{
public:
	explicit FileOpeningException(const std::string& what_arg);
};

class InvalidArgumentsException : public std::runtime_error
{
public:
	explicit InvalidArgumentsException(const std::string& what_arg);
};

class InvalidInstructionException : public std::runtime_error
{
public:
	explicit InvalidInstructionException(const std::string& what_arg);
};

class EmptyStackException : public std::runtime_error
{
public:
	explicit EmptyStackException(const std::string& what_arg);
};

class ParsingException : public std::runtime_error
{
public:
	explicit ParsingException(const std::string& what_arg);
};

class NotEnoughOnStackException : public std::runtime_error
{
public:
	explicit NotEnoughOnStackException(const std::string& what_arg);
};

class NoExitInstructionException : public std::runtime_error
{
public:
	explicit NoExitInstructionException(const std::string& what_arg);
};

class BadAssertionException : public std::runtime_error
{
public:
	explicit BadAssertionException(const std::string &what_arg);
};

class NotACharException : public std::runtime_error
{
public:
	explicit NotACharException(const std::string& what_arg);
};

class OutLimitException : public std::runtime_error
{
public:
	explicit OutLimitException(const std::string& what_arg);
};

#endif
