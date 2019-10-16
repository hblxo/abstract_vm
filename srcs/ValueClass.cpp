/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValueClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:55:33 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/15 14:55:33 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>
#include <utility>
# include "ExceptionClass.hpp"
# include "ValueClass.hpp"

Value::Value(const std::string& str)
{
	Value::findValue(str);
}

Value::Value()
= default;

Value::Value(Value const &src)
{
	this->_type = src._type;
	this->_value = src._value;
	*this = src;
}

Value::~Value()
= default;

Value& Value::operator=(Value const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string Value::toString() const
{
	std::string	ret;
	ret = std::to_string(getType()) + " - " + getValue();
	return (ret);
}

eOperandType Value::getType() const
{
	return _type;
}

const std::string &Value::getValue() const
{
	return _value;
}

void Value::findValue(const std::string& basicString)
{
	std::regex reg;
	reg = R"(^([\s\t\n]*)(int8|int16|int32|float|double)(\()([-+]?[0-9]+(.?[0-9]+)?)(\))(\s*)?$)";
	if (!std::regex_match(basicString, reg))
		throw InvalidValueException();
	else
	{
		size_t pos;
		if ((pos = basicString.find("int8(")) != std::string::npos)
			this->_type = (eOperandType)Int8;
		else if ((pos = basicString.find("int16(")) != std::string::npos)
			this->_type = (eOperandType)Int16;
		else if ((pos = basicString.find("int32(")) != std::string::npos)
			this->_type = (eOperandType)Int32;
		else if ((pos = basicString.find("float(")) != std::string::npos)
			this->_type = (eOperandType)Float;
		else if ((pos = basicString.find("double(")) != std::string::npos)
			this->_type = (eOperandType)Double;
		else
			throw InvalidTypeException();
		this->_value = std::to_string(std::stod(basicString.substr(basicString.find('(') + 1, basicString.find(')'))));
	}
}

std::ostream &operator<<(std::ostream &o, Value const &rhs)
{
	o << rhs.toString();
	return o;
}

