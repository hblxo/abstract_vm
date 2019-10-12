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
#include "CalculatorClass.hpp"
#include "ExceptionClass.hpp"
#include <iostream>
#include <regex>
#include <Factory.hpp>
#include <InstructClass.hpp>
#include <Operand.hpp>

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
//	while (!_operands.empty())
//	{
//		_operands.
//		delete(_operands.top());
		_operands.clear();
//	}
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
    return "Operation OK";
}

std::ostream &	operator<< (std::ostream & o, Calculator const & rhs)
{
    o << rhs.toString();
    return o;
}

void Calculator::doOperation(int type, const std::string& value)
{
	Instruct instruct = Instruct(value);
	if (type == Lexer::PUSH)
		Calculator::push(const_cast<IOperand *>(Factory().createOperand(
				instruct.getType(), instruct.getValue())));
	else if (type == Lexer::ASSERT)
    	Calculator::assertion(const_cast<IOperand *>(Factory().createOperand(
				instruct.getType(), instruct.getValue())));
	else
		throw InvalidInstructionException();
}

void Calculator::doOperation(int type)
{
	if (type != Lexer::PUSH && type != Lexer::ASSERT)
	{
		(this->*_instruct[type])();
	}
	else
		throw InvalidInstructionException();
}

void Calculator::push(IOperand *Op)
{
	_operands.push_back(Op);
}

void Calculator::pop()
{
	if (_operands.empty())
		throw EmptyStackException();
	else
	{
		delete (_operands.back());
		_operands.pop_back();
	}
}

void Calculator::printTop()
{
	if (_operands.empty())
		return;
	IOperand *Op = _operands.back();
//	delete(_operands.top());
	_operands.pop_back();
	std::cout << Op->toString() << std::endl;
	printTop();
	_operands.push_back(Op);
}

void Calculator::dump()
{
	if (_operands.empty())
		throw EmptyStackException();
/*Displays each value of the stack, from the most recent one to the oldest
one WITHOUT CHANGING the stack. Each value is separated from the next one
by a newline.*/
	printTop();
}

void Calculator::assertion(IOperand *Op)
{
	if ((_operands.back() == Op) != 0)
		throw Exception("Assertion Error");

	/* Asserts that the value at the top of the stack is equal to the one passed
as parameter for this instruction. If it is not the case, the program execution must
stop with an error. The value v has the same form that those passed as parameters
to the instruction push.*/
}

void Calculator::add()
{
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
	if (_operands.empty())
		throw EmptyStackException();
	IOperand *a = _operands.back();
	_operands.pop_back();
	if (_operands.empty())
		throw NotEnoughOnStackException();
	IOperand *b = _operands.back();
	_operands.pop_back();
	_operands.push_back(const_cast<IOperand *>(*a - *b));
	delete a;
	delete b;
}

void Calculator::mul()
{
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
	_operands.push_back(const_cast<IOperand *>(*a / *b));
	delete a;
	delete b;
	//Todo : floating point value ?
}

void Calculator::mod()
{
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
	_operands.push_back(const_cast<IOperand *>(*a % *b));
	delete a;
	delete b;
}

void Calculator::print()
{
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
/*
 * Terminate the execution of the current program.
 * If this instruction does not appears while all others instruction has been processed,
 * the execution must stop with an error.
 */
}

