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
#include <GlobalVariables.hpp>
#include "ErrorHandlerClass.hpp"
# include "ValueClass.hpp"

Value::Value(const std::string& str, int lineNb) : _type(Double), _value(""), _lineNb(lineNb)
{
	Value::findValue(str);
}

Value::Value() : _type(Double), _value(""), _lineNb(-1)
{
}

Value::Value(Value const &src)
{
	this->_lineNb = src.getLineNb();
	this->_type = src.getType();
	this->_value = src.getValue();
	*this = src;
}

Value::~Value()
{
	_value.erase();
}

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
		global_errorHandler->handler("Invalid Type", getLineNb());
	else
	{
		if ((basicString.rfind("int8(")) != std::string::npos)
			this->_type = (eOperandType)Int8;
		else if ((basicString.rfind("int16(")) != std::string::npos)
			this->_type = (eOperandType)Int16;
		else if ((basicString.rfind("int32(")) != std::string::npos)
			this->_type = (eOperandType)Int32;
		else if ((basicString.rfind("float(")) != std::string::npos)
			this->_type = (eOperandType)Float;
		else if ((basicString.rfind("double(")) != std::string::npos)
			this->_type = (eOperandType)Double;
		else
			global_errorHandler->handler("Invalid Type", _lineNb);
		std::string tmp = basicString.substr(basicString.rfind('(') + 1, basicString.rfind(')'));
		this->_value = std::to_string(std::stod(tmp));
	}
}

int Value::getLineNb() const
{
	return _lineNb;
}

std::ostream &operator<<(std::ostream &o, Value const &rhs)
{
	o << rhs.toString();
	return o;
}

