/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CalculatorClass.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:13:05 by hbouchet          #+#    #+#             */
/*   Updated: 2019/03/03 16:08:49 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATORCLASS_HPP
# define CALCULATORCLASS_HPP

# include <iostream>
# include <stack>

# include "IOperand.hpp"

class Calculator {

public: 

    Calculator();
    Calculator(Calculator const & src); 
    ~Calculator();

	Calculator &		operator=(Calculator const & rhs);

    std::string toString() const;

    static void doOperation(int type, const std::string& value);
    static void doOperation(int type);

    typedef	void	(Calculator::*instructs[9])();
    static instructs _instruct;

private:
    void	push(IOperand *Op);
    void	pop();
    void	dump();
    void	asert(IOperand *Op); //Todo rename asert to assert
    void	add();
    void	sub();
    void	mul();
    void	div();
    void	mod();
    void	print();
    void	exit();

	std::stack<IOperand *>	_operands;

	//todo implement this instructions
};

std::ostream &	operator<< (std::ostream & o, Calculator const & rhs);

#endif
