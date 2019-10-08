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

class Exception : public std::exception {
public: 
//	class DivideByZeroException;
//	class OverflowException;
//	class UnderflowException;
//	class OpenFailureException;
//	class InvalidArgumentsCountException;
	Exception();
    explicit Exception(std::string  msg);
    Exception(Exception const & src);
    ~Exception(void) noexcept override;
    const char* what() const noexcept override;

	Exception &		operator=(Exception const & rhs);

private:
   const std::string _msg;

};

std::ostream &	operator<< (std::ostream & o, Exception const & rhs);

/*
 * Nested Class DivideByZero
 */
class DivideByZeroException : public Exception{
public:
	DivideByZeroException();
	DivideByZeroException(DivideByZeroException const & src);
	~DivideByZeroException() override;
	const char* what() const noexcept override;

	DivideByZeroException	&operator=(DivideByZeroException const & rhs);

private:
	std::string _msg;
};

/*
 * Nested Class OverflowException
 */
class OverflowException : public Exception{
public:
	OverflowException();
	OverflowException(OverflowException const & src);
	~OverflowException() override;
	const char* what() const noexcept override;

	OverflowException	&operator=(OverflowException const & rhs);

private:
	std::string _msg;
};

/*
 * Nested Class UnderflowException
 */
class UnderflowException : public Exception{
public:
	UnderflowException();
	UnderflowException(UnderflowException const & src);
	~UnderflowException() override;
	const char* what() const noexcept override;

	UnderflowException	&operator=(UnderflowException const & rhs);

private:
	std::string _msg;
};

/*
 * Nested Class OpenFailureException
 */
class OpenFailureException : public Exception{
public:
	OpenFailureException();
	OpenFailureException(OpenFailureException const & src);
	~OpenFailureException() override;
	const char* what() const noexcept override;

	OpenFailureException	&operator=(OpenFailureException const & rhs);

private:
	std::string _msg;
};

/*
 * Nested Class InvalidArgumentsCountException
 */
class InvalidArgumentsCountException : public Exception{
public:
	InvalidArgumentsCountException();
	InvalidArgumentsCountException(InvalidArgumentsCountException const & src);
	~InvalidArgumentsCountException() override;
	const char* what() const noexcept override;

	InvalidArgumentsCountException	&operator=(InvalidArgumentsCountException const & rhs);

private:
	std::string _msg;
};

/*
 * Nested Class InvalidInstructionException
 */
class InvalidInstructionException : public Exception{
public:
	InvalidInstructionException();
	InvalidInstructionException(InvalidInstructionException const & src);
	~InvalidInstructionException() override;
	const char* what() const noexcept override;

	InvalidInstructionException	&operator=(InvalidInstructionException const & rhs);

private:
	std::string _msg;
};

/*
 * Nested Class EmptyStackException
 */
class EmptyStackException : public Exception{
public:
	EmptyStackException();
	EmptyStackException(EmptyStackException const & src);
	~EmptyStackException() override;
	const char* what() const noexcept override;

	EmptyStackException	&operator=(EmptyStackException const & rhs);

private:
	std::string _msg;
};

/*
 * Nested Class InvalidTypeException
 */
class InvalidTypeException : public Exception{
public:
	InvalidTypeException();
	InvalidTypeException(InvalidTypeException const & src);
	~InvalidTypeException() override;
	const char* what() const noexcept override;

	InvalidTypeException	&operator=(InvalidTypeException const & rhs);

private:
	std::string _msg;
};

/*
 * Nested Class InvalidValueException
 */
class InvalidValueException : public Exception{
public:
	InvalidValueException();
	InvalidValueException(InvalidValueException const & src);
	~InvalidValueException() override;
	const char* what() const noexcept override;

	InvalidValueException	&operator=(InvalidValueException const & rhs);

private:
	std::string _msg;
};

/*
 * Nested Class NotEnoughOnStackException
 */
class NotEnoughOnStackException : public Exception{
public:
	NotEnoughOnStackException();
	NotEnoughOnStackException(NotEnoughOnStackException const & src);
	~NotEnoughOnStackException() override;
	const char* what() const noexcept override;

	NotEnoughOnStackException	&operator=(NotEnoughOnStackException const & rhs);

private:
	std::string _msg;
};

#endif
//	class NotEnoughOnStackException;
