/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:22:54 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/07 09:22:54 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_INSTRUCTCLASS_HPP
#define AVM_INSTRUCTCLASS_HPP

#include <iostream>
#include "LexerClass.hpp"

class Value
{
public:
	Value();
	Value(const std::string& str);
	Value(Value const & src);
	~Value();

	Value	&operator=(Value const & rhs);

	const std::string &	getValue() const;
	eOperandType 		getType() const;

	std::string			toString() const;


private:
	eOperandType		_type;
	std::string			_value;

	void findValue(const std::string& basicString);
};

std::ostream	&operator<<(std::ostream & o, Value const & rhs);

#endif //AVM_INSTRUCTCLASS_HPP
