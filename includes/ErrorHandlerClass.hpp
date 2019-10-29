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
#include <list>
#include <vector>

typedef std::shared_ptr<class Log>		log_ptr;
class ErrorHandler
{
public:
	ErrorHandler();
	ErrorHandler(ErrorHandler const &src);
	~ErrorHandler();

	ErrorHandler 			&operator=(ErrorHandler const &rhs);
	std::string 			toString() const;

	void 					print();
	void 					handler(const std::string& msg, int lineNb);

	const std::vector<log_ptr> &getErrorLog() const;
private:
	std::vector<log_ptr>	_errorLog;
};


std::ostream &				operator<< (std::ostream & o, ErrorHandler const & rhs);

#endif //AVM_ERRORHANDLERCLASS_HPP
