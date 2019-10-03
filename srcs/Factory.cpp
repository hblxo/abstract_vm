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

#include "../includes/Factory.hpp"

Factory::Factory()
{
	return ;
}

IOperand const *
Factory::createOperand(eOperandType type, std::string const &value) const
{
	return nullptr;
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	return nullptr;
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	return nullptr;
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	return nullptr;
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	return nullptr;
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	return nullptr;
}

Factory::Factory(Factory const &src)
{
	*this = src;
}

Factory::~Factory(void)
{

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
