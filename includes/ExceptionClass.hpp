/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:34:25 by hbouchet          #+#    #+#             */
/*   Updated: 2019/02/23 14:59:43 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONCLASS_HPP
# define EXCEPTIONCLASS_HPP

# include <iostream>

class Exception : public std::exception {

public: 
    
    Exception(const std::string& msg); 
    Exception(Exception const & src); 
    ~Exception(void) throw(); 
    virtual const char* what() const throw();

    void BadArgumentsException();

	Exception &		operator=(Exception const & rhs);

private:
    const std::string _msg;

};

std::ostream &	operator<< (std::ostream & o, Exception const & rhs);

#endif