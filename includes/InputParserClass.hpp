/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputParserClass.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:53:34 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/22 11:53:34 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_INPUTPARSERCLASS_HPP
#define AVM_INPUTPARSERCLASS_HPP

#include <iostream>
#include <list>

class InputParser
{
public:
	InputParser();
	InputParser(int &ac, char **av);
	InputParser(InputParser const & src);
	~InputParser();

	const std::string&		getCmdOpt(const std::string &options);
	bool					cmdOptExist(const std::string &opt);
	std::string				toString() const;

	InputParser 			&operator=(InputParser const & rhs);

private:
	std::list<std::string>	_tokens;
};

std::ostream				&operator<< (std::ostream & o, InputParser const & rhs);


#endif //AVM_INPUTPARSERCLASS_HPP
