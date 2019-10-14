/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:16:45 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/14 10:16:45 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERCLASS_HPP
#define PARSERCLASS_HPP

#include <iostream>
#include <list>
#include "CalculatorClass.hpp"
#include "AnalyzerClass.hpp"
#include "InstructClass.hpp"

class Parser
{
public:
	Parser();
	Parser(verbs verb, const std::string& value);
	Parser(Parser const & src);
	~Parser();

	Parser &operator=(Parser const & rhs);

	std::string	toString() const;
	verbs getVerb() const;
	const Instruct &getInstruct() const;

private:
	verbs 			_verb;
	Instruct		_instruct;

};
std::ostream	&	operator<< (std::ostream & o, Parser const & rhs);


#endif //AVM_PARSERCLASS_HPP
