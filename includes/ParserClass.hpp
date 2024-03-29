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

#ifndef AVM_PARSERCLASS_HPP
#define AVM_PARSERCLASS_HPP

# include <iostream>
# include <list>
# include "ValueClass.hpp"

typedef std::shared_ptr<class Value> val_ptr;
class Parser
{
public:
	Parser();
	Parser(verbs verb, int lineNb, const std::string& value);
	Parser(Parser const & src);
	~Parser();

	Parser &operator=(Parser const & rhs);

	std::string		toString() const;
	verbs			getVerb() const;
	val_ptr			getInstruct() const;
	int 			getLineNb() const;

private:
	verbs 			_verb;
	val_ptr			_instruct;
	int 			_lineNb;

};
std::ostream	&	operator<< (std::ostream & o, Parser const & rhs);


#endif //AVM_PARSERCLASS_HPP
