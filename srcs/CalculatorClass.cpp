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

Calculator::instructs Calculator::_instruct = {
//		&Calculator::push,
		&Calculator::pop,
		&Calculator::dump,
//		&Calculator::asert,
		&Calculator::add,
		&Calculator::sub,
		&Calculator::mul,
		&Calculator::div,
		&Calculator::mod,
		&Calculator::print,
		&Calculator::exit,
};

Calculator::Calculator()
{
}

Calculator::Calculator(Calculator const & src) 
{
    //Do whatever needs to be done
    *this = src;
}

Calculator::~Calculator(void)
{
    return;
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
/*
IOperand *Calculator::findOperand(std::string str){
	std::regex reg = (const std::basic_regex<char> &) "^(\\s+)(int8|int16|int32|float|double)([)-?[0-9]+(.?[0-9]+)?[)])(\\s*)$";
	if (std::regex_match(str, reg))
	{
		if (str.find("int8"))
//			return Factory().createOperand(Int8, str.substr(3));
			return nullptr;//todo : ??????
	}
}*/


void Calculator::doOperation(int type, const std::string& value)
{
	Instruct instruct = Instruct(value);
	if (type == Lexer::PUSH)
		push(const_cast<IOperand *>(Factory().createOperand(
				instruct.getType(), instruct.getValue())));
	else if (type == Lexer::ASSERT)
    	std::cout << "OK LA : " << value << std::endl;
	else
		std::throw_with_nested(Exception::DivideByZeroException());//todo : correct exception
//		throw Exception("");
}

void Calculator::doOperation(int type)
{
	if (type != Lexer::PUSH && type != Lexer::ASSERT)
	{
		(this->*_instruct[type])();
	}
	else
		throw Exception("Invalid Operation");
}

void Calculator::push(IOperand *Op)
{
	_operands.push(Op);
}

void Calculator::pop()
{
	if (_operands.empty())
		throw Exception("Empty stack");
	else
		_operands.pop();
}

void Calculator::printTop()
{
	if (_operands.empty())
		return;
	IOperand *Op = _operands.top();
	_operands.pop();
	printTop();
	_operands.push(Op);
	std::cout << Op->toString() << std::endl;
}

void Calculator::dump()
{
//	_operands.dump();
//Todo : dump() instruction
/*Displays each value of the stack, from the most recent one to the oldest
one WITHOUT CHANGING the stack. Each value is separated from the next one
by a newline.*/
	printTop();
}

void Calculator::assertion(IOperand *Op)
{
	(void)Op;
	//todo : assert() instruction
	/* Asserts that the value at the top of the stack is equal to the one passed
as parameter for this instruction. If it is not the case, the program execution must
stop with an error. The value v has the same form that those passed as parameters
to the instruction push.*/
}

void Calculator::add()
{
	IOperand *a = _operands.top();
	_operands.pop();
	IOperand *b = _operands.top();
	_operands.pop();
	_operands.push(const_cast<IOperand *>(*a + *b));
	delete a;
	delete b;
	//todo : stack < 2 Exception
}

void Calculator::sub()
{
	IOperand *a = _operands.top();
	_operands.pop();
	IOperand *b = _operands.top();
	_operands.pop();
	_operands.push(const_cast<IOperand *>(*a - *b));
	delete a;
	delete b;
	//todo : stack < 2 Exception
}

void Calculator::mul()
{
	IOperand *a = _operands.top();
	_operands.pop();
	IOperand *b = _operands.top();
	_operands.pop();
	_operands.push(const_cast<IOperand *>(*a * *b));
	delete a;
	delete b;
	//todo : stack < 2 Exception
}

void Calculator::div()
{
	IOperand *a = _operands.top();
	_operands.pop();
	IOperand *b = _operands.top();
	_operands.pop();
	_operands.push(const_cast<IOperand *>(*a / *b));
	delete a;
	delete b;
	//todo : stack < 2 Exception
	//Todo : /0 Exception

	//Todo : floating point value ?
}

void Calculator::mod()
{
	IOperand *a = _operands.top();
	_operands.pop();
	IOperand *b = _operands.top();
	_operands.pop();
	_operands.push(const_cast<IOperand *>(*a % *b));
	delete a;
	delete b;
	//todo : stack < 2 Exception
	//Todo : /0 Exception
}

void Calculator::print()
{
	//todo : print() instruction
	/*Asserts that the value at the top of the stack is an 8-bit integer.
	 *(If not,see the instruction assert), then interprets it as an ASCII value
	 * and displays the corresponding character on the standard output
	 * */
}

void Calculator::exit()
{
/*
 * Terminate the execution of the current program.
 * If this instruction does not appears while all others instruction has been processed,
 * the execution must stop with an error.
 */
}

