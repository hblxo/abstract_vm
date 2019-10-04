/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VmClass.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:24:13 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/04 19:24:13 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_VMCLASS_HPP
#define AVM_VMCLASS_HPP

# include <iostream>
# include <stack>
# include "IOperand.hpp"

class Vm
{
public:
	Vm();
	Vm(Vm const & src);
	~Vm();

	Vm &operator=(Vm const & rhs);
	std::string toString() const;

	std::stack<IOperand *>	_operands;
};


#endif //AVM_VMCLASS_HPP
