/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 09:56:22 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/03 09:56:22 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_OPERAND_HPP
#define AVM_OPERAND_HPP

# include "IOperand.hpp"
#include "Factory.hpp"
# include <math.h>

template <typename T>
class Operand : public IOperand {
private:
	eOperandType	_type;
	T			 	_value;
	int 			_precision{};

public:
	Operand<T>(void){
		return ;
	}

	~Operand<T>(){
		return;
	}

	Operand<T>(Operand<T> const & src){
		_type = src.getType();
		_value = src.getValue();
		_precision = src.getPrecision();
		*this = src;
	}

	Operand<T> &operator=(Operand<T> const & rhs){
		if (this != &rhs)
			*this = rhs;
		return *this;
	}

	Operand<T> (eOperandType type, std::string const & value) : _type(type) {
		this->_precision = static_cast<int>(type);
		this->_value = stod(value, NULL);
		//todo : erreur overflow / underflow
	}

	std::string 	toString(void) const {
		return "";
	}

	eOperandType getType() const
	{
		return _type;
	}

	T getValue() const
	{
		return _value;
	}

	int getPrecision() const
	{
		return _precision;
	}

	IOperand const *operator+(IOperand const & src) const {
		return Factory().createOperand(src.getType(), src.toString()); //todo l'addition ???
	}

	IOperand const *operator-(IOperand const & src) const {
		(void)src;
		return nullptr;
	}

	IOperand const *operator*(IOperand const & src) const {
		(void)src;
		return nullptr;
	}

	IOperand const *operator/(IOperand const & src) const {
		(void)src;
		return nullptr;
	}

	IOperand const *operator%(IOperand const & src) const {
		(void)src;
		return nullptr;
	}
};

#endif //AVM_OPERAND_HPP
