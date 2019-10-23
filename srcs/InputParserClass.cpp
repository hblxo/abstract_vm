/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputParserClass.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:53:41 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/22 11:53:41 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputParserClass.hpp"

InputParser::InputParser()
= default;

InputParser::InputParser(int &ac, char **av)
{
	for (int i=1; i < ac; i++)
	{
		_tokens.emplace_back(av[i]);
	}
}

const std::string &InputParser::getCmdOpt(const std::string &options)
{
	std::list<std::string>::iterator	it;

	it = std::find(_tokens.begin(), _tokens.end(), options);
	if (it != _tokens.end() && ++it != _tokens.end())
		return *it;
	static const std::string empty;
	return empty;
}

bool InputParser::cmdOptExist(const std::string &opt)
{
	return (std::find(_tokens.begin(), _tokens.end(), opt) != _tokens.end());
}

InputParser::InputParser(InputParser const &src)
{
	*this = src;
}

InputParser::~InputParser()
= default;

std::string InputParser::toString() const
{
	return std::string();
}

InputParser &InputParser::operator=(InputParser const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, InputParser const &rhs)
{
	o << rhs.toString();
	return o;
}
