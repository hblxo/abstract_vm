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

Factory::Factory(int nbr_ptr) : nbr_ptr(5)
{

}

Factory::Factory(void)
{
	return ;
}

IOperand*