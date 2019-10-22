/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:11:04 by hbouchet          #+#    #+#             */
/*   Updated: 2019/02/23 14:57:47 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExceptionClass.hpp"
#include <iostream>

DivideByZeroException::DivideByZeroException(const std::string &what_arg) : runtime_error(
		what_arg)
{

}

OverflowException::OverflowException(const std::string &what_arg) : overflow_error(what_arg)
{

}

FileOpeningException::FileOpeningException(const std::string &what_arg)
		: runtime_error(what_arg)
{

}

UnderflowException::UnderflowException(const std::string &what_arg)
		: overflow_error(what_arg)
{

}

InvalidArgumentsException::InvalidArgumentsException(
		const std::string &what_arg) : runtime_error(what_arg)
{

}

InvalidInstructionException::InvalidInstructionException(
		const std::string &what_arg) : runtime_error(what_arg)
{

}

EmptyStackException::EmptyStackException(const std::string &what_arg)
		: runtime_error(what_arg)
{

}

NotEnoughOnStackException::NotEnoughOnStackException(
		const std::string &what_arg) : runtime_error(what_arg)
{

}

NoExitInstructionException::NoExitInstructionException(
		const std::string &what_arg) : runtime_error(what_arg)
{

}

NotACharException::NotACharException(const std::string &what_arg)
		: runtime_error(what_arg)
{

}

BadAssertionException::BadAssertionException(const std::string &what_arg)
		: runtime_error(what_arg)
{

}

ParsingException::ParsingException(const std::string &what_arg) : runtime_error(
		what_arg)
{

}
