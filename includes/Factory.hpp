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


class Factory
{
private:
	typedef IOperand* (Factory::*createFunc)(const std::string& value);
	IOperand* createInt8(const std::string& value);
public:
	Factory();
	Factory(int nbr_ptr);
};


#endif //ABSTRACT_VM_FACTORY_HPP

