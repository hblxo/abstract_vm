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
# include <cmath>
//#include <tclDecls.h>

template <typename T>
class Operand : public IOperand {
private:
	eOperandType	_type;
	T			 	_value;
	int 			_precision{};

public:
	Operand<T>(){
	}

	~Operand<T>()= default;

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
		this->_value = stod(value, nullptr);
		//todo : erreur overflow / underflow
	}

	std::string 	toString() const override {
		return "";
	}

	eOperandType getType() const override
	{
		return _type;
	}

	T getValue() const
	{
		return _value;
	}

	int getPrecision() const override
	{
		return _precision;
	}


	//TODO : implement operator
	IOperand const *operator+(IOperand const & rhs) const override {
		eOperandType resType = (eOperandType) (rhs.getPrecision() > this->getPrecision()
								  ? rhs.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType, std::to_string(static_cast<double>(stod(rhs.toString())) +
																				static_cast<double>(stod(this->toString()))));
		return ret;
	}

	IOperand const *operator-(IOperand const & rhs) const override {
		eOperandType resType = (eOperandType) (rhs.getPrecision() > this->getPrecision()
											   ? rhs.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType, std::to_string(static_cast<double>(stod(rhs.toString())) -
																		static_cast<double>(stod(this->toString()))));
		return ret;
	}

	IOperand const *operator*(IOperand const & rhs) const override {
		eOperandType resType = (eOperandType) (rhs.getPrecision() > this->getPrecision()
											   ? rhs.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType, std::to_string(static_cast<double>(stod(rhs.toString())) *
																		static_cast<double>(stod(this->toString()))));
		return ret;
	}

	IOperand const *operator/(IOperand const & src) const override {
		eOperandType resType = (eOperandType) (src.getPrecision() > this->getPrecision()
											   ? src.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType, std::to_string(static_cast<double>(stod(src.toString())) /
																		static_cast<double>(stod(this->toString()))));
		return ret;
	}

	IOperand const *operator%(IOperand const & src) const override {
		eOperandType resType = (eOperandType) (src.getPrecision() > this->getPrecision()
											   ? src.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType, std::to_string(fmod(static_cast<double>(stod(src.toString())),
																		static_cast<double>(stod(this->toString())))));
		return ret;
	}
};

#endif //AVM_OPERAND_HPP
