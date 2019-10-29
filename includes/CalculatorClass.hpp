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
# include <vector>

# include "IOperand.hpp"
# include "eVerb.hpp"

typedef std::shared_ptr<IOperand> op_ptr;
typedef std::shared_ptr<class Value> val_ptr;

class Calculator {
public:
    Calculator();
    Calculator(Calculator const & src); 
    ~Calculator();

	Calculator &		operator=(Calculator const & rhs);

    std::string toString() const;

	void run(verbs verb, const val_ptr &instruction);
    void doOperation(verbs verb, const val_ptr& instruction);
    void doOperation(verbs type);

    typedef	void	(Calculator::*instructs[20])();
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
    void	max();
    void	min();
    void	pow();
    void	sin();
    void	cos();
    void	tan();
    void	sqrt();
    void	bit_and();
    void	bit_xor();
    void	bit_or();
    void	exit();
    void	comment();

	std::vector<op_ptr>		_operands;
};

std::ostream &	operator<< (std::ostream & o, Calculator const & rhs);

#endif
