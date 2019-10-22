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

#include "LexerClass.hpp"
#include "ExceptionClass.hpp"
#include <iostream>
#include <regex>
#include <LogClass.hpp>
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
		throw InvalidInstructionException();
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
		throw InvalidInstructionException();
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
		throw EmptyStackException();
	else
	{
		Log(L_INFO, _operands.back()->toString() + " removed from the top of the stack");
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
		throw EmptyStackException();
	auto tmp = _operands.back();
	if (*tmp == *Op)
		return;
	throw Exception("Assertion Error");

	/* Asserts that the value at the top of the stack is equal to the one passed
as parameter for this instruction. If it is not the case, the program execution must
stop with an error. The value v has the same form that those passed as parameters
to the instruction push.*/
}

void Calculator::add()
{
//	std::cout << "add" << std::endl;
	if (_operands.empty())
		throw EmptyStackException();
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (_operands.empty())
		throw NotEnoughOnStackException();
	IOperand *b = _operands.back();
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*a + *b));
	delete a;
	delete b;
}

void Calculator::sub()
{
	Log(L_INFO, "");
//	std::cout << "sub" << std::endl;
	if (_operands.empty())
		throw EmptyStackException();
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (_operands.empty())
		throw NotEnoughOnStackException();
	IOperand *b = _operands.back();
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*b - *a));
	delete a;
	delete b;
}

void Calculator::mul()
{
//	std::cout << "mul" << std::endl;
	if (_operands.empty())
		throw EmptyStackException();
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (_operands.empty())
		throw NotEnoughOnStackException();
	IOperand *b = _operands.back();
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*a * *b));
	delete a;
	delete b;
}

void Calculator::div()
{
//	std::cout << "div" << std::endl;
	if (_operands.empty())
		throw EmptyStackException();
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (std::stod(a->toString()) == 0)
		throw DivideByZeroException();
	if (_operands.empty())
		throw NotEnoughOnStackException();
	IOperand *b = _operands.back();
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*b / *a));
	delete a;
	delete b;
	//Todo : floating point value ?
}

void Calculator::mod()
{
//	std::cout << "mod" << std::endl;
	if (_operands.empty())
		throw EmptyStackException();
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (std::stod(a->toString()) == 0)
		throw DivideByZeroException();
	if (_operands.empty())
		throw NotEnoughOnStackException();
	IOperand *b = _operands.back();
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*b % *a));
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
		throw EmptyStackException();
	IOperand *a = _operands.back();
	if (a->getType() != eOperandType::Int8)
		throw Exception("The Value on top isn't a char");
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
//	std::cout << "comment" << std::endl;
}

