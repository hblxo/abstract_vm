/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatcherClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 12:10:42 by hbouchet          #+#    #+#             */
/*   Updated: 2019/03/04 11:22:43 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATCHERCLASS_HPP
# define MATCHERCLASS_HPP
# include <iostream>
# include <list>

class Matcher {

public: 

    Matcher(int type, std::string token);
    Matcher(void); 
    Matcher(Matcher const & src); 
    ~Matcher(void);

	Matcher &		operator=(Matcher const & rhs);

    std::string const	toString(void) const;

	int                 getType(void) const;
    void                setType(int type);
	std::string         getToken(void) const;
    void	            setToken(std::string token);

    int                 matchSearch(const std::string& value);

private:
    int                 _type;
    std::string         _token;

};

std::ostream &	operator<< (std::ostream & o, Matcher const & rhs);

#endif

