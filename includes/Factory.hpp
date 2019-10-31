/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:10:04 by hbouchet          #+#    #+#             */
/*   Updated: 2019/09/30 12:10:04 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_FACTORY_HPP
#define ABSTRACT_VM_FACTORY_HPP

# include <iostream>
#include "IOperand.hpp"


class Factory
{
private:
//	typedef IOperand* (Factory::*createFunc)(const std::string& value);

	IOperand const *createInt8( std::string const & value ) const;
	IOperand const *createInt16( std::string const & value ) const;
	IOperand const *createInt32( std::string const & value ) const;
	IOperand const *createFloat( std::string const & value ) const;
	IOperand const *createDouble( std::string const & value ) const;


public:
	Factory();
	Factory(Factory const & src);
	~Factory();

	IOperand const * createOperand(eOperandType type, std::string const & value ) const;
	Factory &operator=(Factory const & rhs);
	std::string toString() const;

	typedef IOperand const * (Factory::*ptrfnc[5]) (std::string const & value) const;
	static ptrfnc _create;
};


#endif //ABSTRACT_VM_FACTORY_HPP

