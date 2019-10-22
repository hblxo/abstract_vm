/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorHandlerClass.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:21:21 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/21 18:21:21 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_ERRORHANDLERCLASS_HPP
#define AVM_ERRORHANDLERCLASS_HPP

#include <iostream>

class ErrorHandler
{
public:
	ErrorHandler();
	explicit ErrorHandler(const std::string& msg, int lineNb);
	ErrorHandler(const char *src);
	~ErrorHandler();

	ErrorHandler &operator=(ErrorHandler const &rhs);
	std::string toString() const;
};

std::ostream &	operator<< (std::ostream & o, ErrorHandler const & rhs);

#endif //AVM_ERRORHANDLERCLASS_HPP
