/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:10:03 by hbouchet          #+#    #+#             */
/*   Updated: 2019/09/30 12:10:03 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Operand.hpp>
#include "../includes/Factory.hpp"
#include <iostream>

Factory::ptrfnc Factory::_create = {
	&Factory::createInt8,
	&Factory::createInt16,
	&Factory::createInt32,
	&Factory::createFloat,
	&Factory::createDouble
};

Factory::Factory()
{
	return ;
}

IOperand const *
Factory::createOperand(eOperandType type, std::string const &value) const
{
	return (this->*_create[type])(value);
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	return new Operand<int8_t>(Int8, value);
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	return new Operand<int8_t>(Int16, value);
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	return new Operand<int32_t>(Int32, value);
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	return new Operand<float>(Float, value);
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	return new Operand<double >(Double, value);
}

Factory::Factory(Factory const &src)
{
	*this = src;
}

Factory::~Factory(void)
{
	return;
}

Factory &Factory::operator=(Factory const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string Factory::toString() const
{
	return std::string();
}
