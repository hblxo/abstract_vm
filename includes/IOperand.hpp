/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:54:27 by hbouchet          #+#    #+#             */
/*   Updated: 2019/09/30 11:54:27 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_IOPERAND_HPP
#define ABSTRACT_VM_IOPERAND_HPP

#include <iostream>
#include "eOperandType.hpp"

class IOperand
{
public:
	virtual int 				getPrecision() const= 0;// Precision of the type of the instance
	virtual eOperandType  		getType() const= 0;// Type of the instance

	virtual IOperand const *	operator+( IOperand const& rhs ) const= 0;// Sum
	virtual IOperand const *	operator-( IOperand const& rhs ) const= 0;// Difference
	virtual IOperand const *	operator*( IOperand const& rhs ) const= 0;// Product
	virtual IOperand const *	operator/( IOperand const& rhs ) const= 0;// Quotient
	virtual IOperand const *	operator%( IOperand const& rhs ) const= 0;// Modulo

	virtual bool operator==(IOperand const & src) const = 0;
	virtual std::string			toString() const= 0;// String representation of the instance

	virtual 					~IOperand() = default;
};


#endif //ABSTRACT_VM_IOPERAND_HPP
