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
#include <vector>

# include "IOperand.hpp"
# include "eVerb.hpp"
# include "InstructClass.hpp"

class Calculator {
public:
    Calculator();
    Calculator(Calculator const & src); 
    ~Calculator();

	Calculator &		operator=(Calculator const & rhs);

    std::string toString() const;

    void run(verbs verb, Value instruction);
    void doOperation(verbs verb, Value instruction);
    void doOperation(verbs type);

    typedef	void	(Calculator::*instructs[9])();
    static instructs _instruct;

private:
    void	push(IOperand *Op);
    void	pop();
    void	dump();
    void	assertion(IOperand *Op);
    void	add();
    void	sub();
    void	mul();
    void	div();
    void	mod();
    void	print();
	//todo implement this instructions
    void	exit();

	std::vector<IOperand *>	_operands;

	void printTop();
};

std::ostream &	operator<< (std::ostream & o, Calculator const & rhs);

#endif
