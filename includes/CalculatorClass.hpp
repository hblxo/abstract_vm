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

class Calculator {

public: 

    Calculator();
    Calculator(Calculator const & src); 
    ~Calculator();

	Calculator &		operator=(Calculator const & rhs);

    std::string toString() const;

    static void doOperation(int type, const std::string& value);
    static void doOperation(int type);

private:

};

std::ostream &	operator<< (std::ostream & o, Calculator const & rhs);

#endif
