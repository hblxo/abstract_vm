/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GlobalVariables.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:13:01 by hbouchet          #+#    #+#             */
/*   Updated: 2019/10/21 18:13:01 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_GLOBALVARIABLES_HPP
#define AVM_GLOBALVARIABLES_HPP

# include "eVerboseLevel.hpp"
# include "ErrorHandlerClass.hpp"


extern verbosity	global_verbosity;
extern bool 		global_diag;
extern bool			global_hasError;
extern ErrorHandler	*global_errorHandler;

#endif //AVM_GLOBALVARIABLES_HPP
