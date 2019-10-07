/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructClass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:23:52 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/07 09:23:52 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>
#include <ExceptionClass.hpp>
# include "InstructClass.hpp"

Instruct::Instruct(std::string str)
{
	Instruct::findValue(str);
}

Instruct::Instruct()
{

}

Instruct::Instruct(Instruct const &src)
{
	this->_type = src._type;
	this->_value = src._value;
	*this = src;
}

Instruct::~Instruct()
{

}

Instruct& Instruct::operator=(Instruct const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string Instruct::toString() const
{
	return "";
}

eOperandType Instruct::getType() const
{
	return _type;
}

const std::string &Instruct::getValue() const
{
	return _value;
}

void Instruct::findValue(std::string basicString)
{
	std::regex reg;
	reg = R"(^(\s*)(int8|int16|int32|float|double)(\()(-?[0-9]+(.?[0-9]+)?)(\))(\s*)?$)";
	if (!std::regex_match(basicString, reg))
		throw Exception("Invalid Value / RegExp");
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
			throw Exception("Invalid operand");
		this->_value = std::to_string(std::stod(basicString.substr(basicString.find('(') + 1, basicString.find(')'))));
	}
}

std::ostream &operator<<(std::ostream &o, Instruct const &rhs)
{
	o << rhs.toString();
	return o;
}

