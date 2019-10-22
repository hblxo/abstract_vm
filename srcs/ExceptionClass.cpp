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
#include <utility>

Exception::Exception()
= default;

Exception::Exception(std::string  msg) : _msg(std::move(msg))
{
}

Exception::Exception(Exception const & src)
{
    //Do whatever needs to be done
    *this = src;
}

Exception::~Exception() noexcept
= default;

const char* Exception::what() const noexcept
{
    return _msg.c_str();
}

Exception &	Exception::operator=(Exception const & rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

/*
 * Nested Class : DivideByZeroException
 */

DivideByZeroException::DivideByZeroException()
{
	_msg = "Divide by zero exception";
}

DivideByZeroException::DivideByZeroException(
		const DivideByZeroException &src)
 : Exception(src) {
	*this = src;
}

DivideByZeroException::~DivideByZeroException()= default;

const char *DivideByZeroException::what() const noexcept
{
	return _msg.c_str();
}

DivideByZeroException &DivideByZeroException::operator=(DivideByZeroException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

/*
 * Nested Class OverflowException
 */
OverflowException::OverflowException()
{
	_msg = "Overflow Exception";
}

OverflowException::OverflowException(OverflowException const &src)
 : Exception(src) {
	*this = src;
}

const char *OverflowException::what() const noexcept
{
	return _msg.c_str();
}

OverflowException &OverflowException::operator=(OverflowException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

OverflowException::~OverflowException()
= default;

/*
 * Nested Class UnderflowException
 */
UnderflowException::UnderflowException()
{
	_msg = "Underflow Exception";
}

UnderflowException::UnderflowException(UnderflowException const &src)
 : Exception(src) {
	*this = src;
}

const char *UnderflowException::what() const noexcept
{
	return _msg.c_str();
}

UnderflowException &UnderflowException::operator=(UnderflowException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

UnderflowException::~UnderflowException()
= default;

/*
 * Nested Class OpenFailureException
 */
OpenFailureException::OpenFailureException()
{
	_msg = "Open Failure Exception";
}

OpenFailureException::OpenFailureException(OpenFailureException const &src)
 : Exception(src) {
	*this = src;
}

const char *OpenFailureException::what() const noexcept
{
	return _msg.c_str();
}

OpenFailureException &OpenFailureException::operator=(OpenFailureException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

OpenFailureException::~OpenFailureException()
= default;


/*
 * Nested Class InvalidArgumentsCountException
 */
InvalidArgumentsCountException::InvalidArgumentsCountException()
{
	_msg = "Invalid Arguments Count Exception\nusage : ./avm [-v --verbose -d --diag] [filename]";
}

InvalidArgumentsCountException::InvalidArgumentsCountException(InvalidArgumentsCountException const &src)
 : Exception(src) {
	*this = src;
}

const char *InvalidArgumentsCountException::what() const noexcept
{
	return _msg.c_str();
}

InvalidArgumentsCountException &InvalidArgumentsCountException::operator=(InvalidArgumentsCountException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

InvalidArgumentsCountException::~InvalidArgumentsCountException()
= default;


/*
 * Nested Class InvalidInstructionException
 */
InvalidInstructionException::InvalidInstructionException()
{
	_msg = "Invalid Instruction Exception";
}

InvalidInstructionException::InvalidInstructionException(InvalidInstructionException const &src)
 : Exception(src) {
	*this = src;
}

const char *InvalidInstructionException::what() const noexcept
{
	return _msg.c_str();
}

InvalidInstructionException &InvalidInstructionException::operator=(InvalidInstructionException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

InvalidInstructionException::~InvalidInstructionException()
= default;


/*
 * Nested Class EmptyStackException
 */
EmptyStackException::EmptyStackException()
{
	_msg = "Empty Stack Exception";
}

EmptyStackException::EmptyStackException(EmptyStackException const &src)
 : Exception(src) {
	*this = src;
}

const char *EmptyStackException::what() const noexcept
{
	return _msg.c_str();
}

EmptyStackException &EmptyStackException::operator=(EmptyStackException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

EmptyStackException::~EmptyStackException()
= default;


/*
 * Nested Class InvalidTypeException
 */
InvalidTypeException::InvalidTypeException()
{
	_msg = "Invalid Type Exception";
}

InvalidTypeException::InvalidTypeException(InvalidTypeException const &src)
 : Exception(src) {
	*this = src;
}

const char *InvalidTypeException::what() const noexcept
{
	return _msg.c_str();
}

InvalidTypeException &InvalidTypeException::operator=(InvalidTypeException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

InvalidTypeException::~InvalidTypeException()
= default;


/*
 * Nested Class InvalidValueException
 */
InvalidValueException::InvalidValueException()
{
	_msg = "Invalid Value Exception";
}

InvalidValueException::InvalidValueException(InvalidValueException const &src)
 : Exception(src) {
	*this = src;
}

const char *InvalidValueException::what() const noexcept
{
	return _msg.c_str();
}

InvalidValueException &InvalidValueException::operator=(InvalidValueException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

InvalidValueException::~InvalidValueException()
= default;

/*
 * Nested Class NotEnoughOnStackException
 */
NotEnoughOnStackException::NotEnoughOnStackException()
{
	_msg = "Not Enough Values On Stack Exception";
}

NotEnoughOnStackException::NotEnoughOnStackException(NotEnoughOnStackException const &src)
 : Exception(src) {
	*this = src;
}

const char *NotEnoughOnStackException::what() const noexcept
{
	return _msg.c_str();
}

NotEnoughOnStackException &NotEnoughOnStackException::operator=(NotEnoughOnStackException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

NotEnoughOnStackException::~NotEnoughOnStackException()
= default;

/*
 * Nested Class NotEnoughOnStackException
 */
NoExitInstructionException::NoExitInstructionException()
{
	_msg = "No Exit Instruction Exception";
}

NoExitInstructionException::NoExitInstructionException(NoExitInstructionException const &src)
 : Exception(src) {
	*this = src;
}

const char *NoExitInstructionException::what() const noexcept
{
	return _msg.c_str();
}

NoExitInstructionException &NoExitInstructionException::operator=(NoExitInstructionException const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

NoExitInstructionException::~NoExitInstructionException()
= default;

