/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:36:44 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/20 17:36:44 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_LOGCLASS_HPP
#define AVM_LOGCLASS_HPP

#include <iostream>
#include "eVerboseLevel.hpp"

class Log {
public:
	Log();
	Log(verbosity level, const std::string& msg);
	Log(Log const & src);
	~Log();

	Log &operator=(Log const & rhs);

	std::string toString() const;
private:
};

std::ostream & operator<< (std::ostream & o, Log const & rhs);

#endif //AVM_LOGCLASS_HPP
