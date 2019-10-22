/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CalculatorClass.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:13:34 by hbouchet          #+#    #+#             */
/*   Updated: 2019/03/03 16:09:00 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <regex>
#include "LexerClass.hpp"
#include "ExceptionClass.hpp"
#include "LogClass.hpp"
#include "ErrorHandlerClass.hpp"
#include "Factory.hpp"

Calculator::instructs Calculator::_instruct = {
		&Calculator::pop,
		&Calculator::dump,
		&Calculator::add,
		&Calculator::sub,
		&Calculator::mul,
		&Calculator::div,
		&Calculator::mod,
		&Calculator::print,
		&Calculator::exit,
		&Calculator::comment,
};

Calculator::Calculator()
= default;

Calculator::Calculator(Calculator const & src) 
{
    //Do whatever needs to be done
    *this = src;
}

Calculator::~Calculator()
{
//	std::cout << "Calculator Destructor" << std::endl;
		_operands.clear();
}

Calculator &	Calculator::operator=(Calculator const & rhs)
{
    //Do whatever needs to be done
    if (this != &rhs)
        *this = rhs;
    return *this;
}

std::string Calculator::toString() const
{
    // Return whatever needs to be returned
    return "";
}

std::ostream &	operator<< (std::ostream & o, Calculator const & rhs)
{
    o << rhs.toString();
    return o;
}

void Calculator::run(verbs verb, Value *instruction)
{
//	std::cout << verb << std::endl;
	if (verb == ASSERT || verb == PUSH)
		doOperation(verb, *instruction);
	else
		doOperation(verb);
}

void Calculator::doOperation(verbs verb, const Value& instruction)
{
	if (verb == PUSH)
		Calculator::push(const_cast<IOperand *>(Factory().createOperand(
				instruction.getType(), instruction.getValue())));
	else if (verb == ASSERT)
    	Calculator::assertion(const_cast<IOperand *>(Factory().createOperand(
				instruction.getType(), instruction.getValue())));
	else
	{
//		std::cout << "1" << std::endl;
		throw InvalidInstructionException("Invalid format of instruction");
	}
}

void Calculator::doOperation(verbs type)
{
	if (type != PUSH && type != ASSERT)
	{
		(this->*_instruct[type])();
	}
	else
	{
//		std::cout << "2" << std::endl;
		throw InvalidInstructionException("Invalid format of instruction");
	}
}

void Calculator::push(IOperand *Op)
{
	Log(L_INFO, Op->toString() + " push on the top of the stack");
	_operands.push_back(Op);
}

void Calculator::pop()
{
//	std::cout << "pop" << std::endl;
	if (_operands.empty())
		throw EmptyStackException("Pop operation on empty stack");
	else
	{
		Log(L_INFO, _operands.back()->toString() + " remove from the top of the stack");
		delete (_operands.back());
		_operands.pop_back();
	}
}

void Calculator::dump()
{
//	std::cout << "dump" << std::endl;
	//	if (_operands.empty())
//		throw EmptyStackException();
/*Displays each value of the stack, from the most recent one to the oldest
one WITHOUT CHANGING the stack. Each value is separated from the next one
by a newline.*/
	std::vector<IOperand *>::iterator it;
	for (it = _operands.begin(); it != _operands.end(); it++)
	{
		std::cout << (*it)->toString() << std::endl;
	}
}

void Calculator::assertion(IOperand *Op)
{
//	std::cout << "assertion" << std::endl;
	if (_operands.empty())
		throw EmptyStackException("Assert operation on empty stack");
	auto tmp = _operands.back();
	if (*tmp == *Op)
	{
		Log(L_INFO, "The value at the top of the stack is equal to the parameter");
		return;
	}
	throw BadAssertionException("Assertion is false");

	/* Asserts that the value at the top of the stack is equal to the one passed
as parameter for this instruction. If it is not the case, the program execution must
stop with an error. The value v has the same form that those passed as parameters
to the instruction push.*/
}

void Calculator::add()
{
//	std::cout << "add" << std::endl;
	if (_operands.empty())
		throw EmptyStackException("Addition operation on empty stack");
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (_operands.empty())
		throw NotEnoughOnStackException("Two values on stack are required to perform addition operation");
	IOperand *b = _operands.back();
	Log(L_INFO, "The last two values on the stack are added and removed from the stack");
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*a + *b));
	Log(L_INFO, "The result (" + _operands.back()->toString() + ") is push on the stack");
	delete a;
	delete b;
}

void Calculator::sub()
{
//	std::cout << "sub" << std::endl;
	if (_operands.empty())
		throw EmptyStackException("Subtraction operation on empty stack");
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (_operands.empty())
		throw NotEnoughOnStackException("Two values on stack are required to perform subtraction operation");
	IOperand *b = _operands.back();
	Log(L_INFO, "A subtraction is made between the last two values on the stack and they are removed from the stack");
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*b - *a));
	Log(L_INFO, "The result (" + _operands.back()->toString() + ") is push on the stack");
	delete a;
	delete b;
}

void Calculator::mul()
{
//	std::cout << "mul" << std::endl;
	if (_operands.empty())
		throw EmptyStackException("Multiplication operation on empty stack");
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (_operands.empty())
		throw NotEnoughOnStackException("Two values on stack are required to perform multiplication operation");
	IOperand *b = _operands.back();
	Log(L_INFO, "A multiplication is made between the last two values on the stack and they are removed from the stack");
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*a * *b));
	Log(L_INFO, "The result (" + _operands.back()->toString() + ") is push on the stack");
	delete a;
	delete b;
}

void Calculator::div()
{
//	std::cout << "div" << std::endl;
	if (_operands.empty())
		throw EmptyStackException("Division operation on empty stack");
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (std::stod(a->toString()) == 0)
		throw DivideByZeroException("Impossible to divide by zero");
	if (_operands.empty())
		throw NotEnoughOnStackException("Two values on stack are required to perform multiplication operation");
	IOperand *b = _operands.back();
	Log(L_INFO, "A division is made between the last two values on the stack and they are removed from the stack");
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*b / *a));
	Log(L_INFO, "The result (" + _operands.back()->toString() + ") is push on the stack");
	delete a;
	delete b;
	//Todo : floating point value ?
}

void Calculator::mod()
{
//	std::cout << "mod" << std::endl;
	if (_operands.empty())
		throw EmptyStackException("Modulo operation on empty stack");
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (std::stod(a->toString()) == 0)
		throw DivideByZeroException("Impossible to divide by zero");
	if (_operands.empty())
		throw NotEnoughOnStackException("Two values on stack are required to perform modulo operation");
	IOperand *b = _operands.back();
	Log(L_INFO, "A modulo operation is made between the last two values on the stack and they are removed from the stack");
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*b % *a));
	Log(L_INFO, "The result (" + _operands.back()->toString() + ") is push on the stack");
	delete a;
	delete b;
}

void Calculator::print()
{
//	std::cout << "print" << std::endl;
	/*Asserts that the value at the top of the stack is an 8-bit integer.
	 *(If not,see the instruction assert), then interprets it as an ASCII value
	 * and displays the corresponding character on the standard output
	 * */
	if (_operands.empty())
		throw EmptyStackException("Print operation on empty stack");
	IOperand *a = _operands.back();
	if (a->getType() != eOperandType::Int8)
		NotACharException("The Value on top isn't a char");
	Log(L_INFO, "The value on the top of the stack's type is 'int8'");
	std::cout << static_cast<char>(std::stod(a->toString())) << std::endl;
}

void Calculator::exit()
{
//	std::cout << "exit" << std::endl;
/*
 * Terminate the execution of the current program.
 * If this instruction does not appears while all others instruction has been processed,
 * the execution must stop with an error.
 */
}

void Calculator::comment()
{
	Log(L_COMMENT, "");
	//	std::cout << "comment" << std::endl;
}

