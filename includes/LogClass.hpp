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
	Log(verbosity options);
//	Log(verbosity level, std::string msg);

	Log(Log const & src);
	~Log();

	verbosity getOptions() const;

	Log &operator=(Log const & rhs);

	std::string toString() const;
	void		print(verbosity level, std::string msg);
private:
	verbosity _options;
};

std::ostream & operator<< (std::ostream & o, Log const & rhs);

#endif //AVM_LOGCLASS_HPP
