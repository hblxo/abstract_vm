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


class IOperand
{
public:
	virtual int 				getPrecision(void) const= 0;// Precision of the type of the instance
	virtual eOperandType  		getType(void) const= 0;// Type of the instance

	virtual IOperand const *	operator+( IOperand const& rhs ) const= 0;// Sum
	virtual IOperand const *	operator-( IOperand const& rhs ) const= 0;// Difference
	virtual IOperand const *	operator*( IOperand const& rhs ) const= 0;// Product
	virtual IOperand const *	operator/( IOperand const& rhs ) const= 0;// Quotient
	virtual IOperand const *	operator%( IOperand const& rhs ) const= 0;// Modulo

	virtual std::string const	&toString(void) const= 0;// String representation of the instance

	virtual 					~IOperand(void) {}
};


#endif //ABSTRACT_VM_IOPERAND_HPP
