/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValueClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:52:37 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/15 14:52:37 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_VALUECLASS_HPP
#define AVM_VALUECLASS_HPP

#include <iostream>
#include "LexerClass.hpp"

class Value
{
public:
	Value();
	Value(const std::string& str, int lineNb);
	Value(Value const & src);
	~Value();

	Value	&operator=(Value const & rhs);

	const std::string &	getValue() const;
	eOperandType 		getType() const;
	std::string			toString() const;
	int 				getLineNb() const;

private:
	eOperandType		_type;
	std::string			_value;
	int 				_lineNb;

private:

	void findValue(const std::string& basicString);
};

std::ostream	&operator<<(std::ostream & o, Value const & rhs);

#endif //AVM_VALUECLASS_HPP
