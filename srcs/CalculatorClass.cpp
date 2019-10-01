/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CalculatorClass.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:13:34 by hbouchet          #+#    #+#             */
/*   Updated: 2019/03/03 16:09:00 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CalculatorClass.hpp"
#include <iostream>


Calculator::Calculator(void)
{
    return;
}

Calculator::Calculator(Calculator const & src) 
{
    //Do whatever needs to be done
    *this = src;
    return;
}

Calculator::~Calculator(void)
{
    return;
}

Calculator &	Calculator::operator=(Calculator const & rhs)
{
    //Do whatever needs to be done
    if (this != &rhs)
        *this = rhs;
    return *this;
}

std::string const Calculator::toString(void) const
{
    // Return whatever needs to be returned
    return "Operation OK";
}

std::ostream &	operator<< (std::ostream & o, Calculator const & rhs)
{
    o << rhs.toString();
    return o;
}

void Calculator::doOperation(int type, std::string value)
{
    (void) type;
    std::cout << "OK LA : " << value << std::endl;
    return ;
}

void Calculator::doOperation(int type)
{
    (void) type;
    std::cout << "OK !" << std::endl;
    return ;
}