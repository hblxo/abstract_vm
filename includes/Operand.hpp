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
#include "ExceptionClass.hpp"
# include <cmath>

template <typename T>
class Operand : public IOperand {
private:
	eOperandType	_type;
	T			 	_value;
	int 			_precision;

public:
	Operand<T>(){
	}

	~Operand<T>(){
//		std::cout << "Operand Destructor" << std::endl;
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
//		std::cout << "min : " << std::numeric_limits<T>::lowest() << " - max : " << std::numeric_limits<T>::max() << std::endl;
		if (stod(value) > std::numeric_limits<T>::max())
			throw OverflowException();
		if (stod(value) <= std::numeric_limits<T>::lowest())
			throw UnderflowException();

		this->_precision = static_cast<int>(type);
		this->_value = stod(value, nullptr);
	}

	std::string 	toString() const override {
		return(std::to_string(this->getValue()));
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

	IOperand const *operator+(IOperand const & rhs) const override {
		auto resType = (eOperandType) (rhs.getPrecision() > this->getPrecision()
								  ? rhs.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType,
				std::to_string(static_cast<double>(stod(rhs.toString())) + static_cast<double>(stod(this->toString()))));
		return ret;
	}

	IOperand const *operator-(IOperand const & rhs) const override {
		auto resType = (eOperandType) (rhs.getPrecision() > this->getPrecision()
											   ? rhs.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType, std::to_string(static_cast<double>(stod(rhs.toString())) -
																		static_cast<double>(stod(this->toString()))));
		return ret;
	}

	IOperand const *operator*(IOperand const & rhs) const override {
		auto resType = (eOperandType) (rhs.getPrecision() > this->getPrecision()
											   ? rhs.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType, std::to_string(static_cast<double>(stod(rhs.toString())) *
																		static_cast<double>(stod(this->toString()))));
		return ret;
	}

	IOperand const *operator/(IOperand const & src) const override {
		auto resType = (eOperandType) (src.getPrecision() > this->getPrecision()
											   ? src.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType, std::to_string(static_cast<double>(stod(src.toString())) /
																		static_cast<double>(stod(this->toString()))));
		return ret;
	}

	IOperand const *operator%(IOperand const & src) const override {
		auto resType = (eOperandType) (src.getPrecision() > this->getPrecision()
											   ? src.getPrecision() : this->getPrecision());

		const IOperand *ret = Factory().createOperand(resType, std::to_string(fmod(static_cast<double>(stod(src.toString())),
																		static_cast<double>(stod(this->toString())))));
		return ret;
	}

	bool operator==(IOperand const & src) const override {
//		std::cout << this->toString() << " - " << src.toString() << std::endl;
//		std::cout << this->getType() << " - " << src.getType() << std::endl;
//		std::cout << this->getPrecision() << " - " << src.getPrecision() << std::endl;
		return ((this->toString() == src.toString()) && (this->getType() == src.getType()) && (this->getPrecision() == src.getPrecision()));
	}

};

#endif //AVM_OPERAND_HPP
