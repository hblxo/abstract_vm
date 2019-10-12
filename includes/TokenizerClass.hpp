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

#ifndef TOKENIZERCLASS_HPP
# define TOKENIZERCLASS_HPP
# include <iostream>
# include <list>

class Tokenizer {

public: 

    Tokenizer(int type, std::string token);
    Tokenizer();
    Tokenizer(Tokenizer const & src);
    ~Tokenizer();

	Tokenizer &		operator=(Tokenizer const & rhs);

    std::string 	toString() const;

	int                 getType() const;
    void                setType(int type);
	std::string         getToken() const;
    void	            setToken(std::string token);

    int                 matchSearch(const std::string& value);

private:
    int                 _type;
    std::string         _token;

};

std::ostream &	operator<< (std::ostream & o, Tokenizer const & rhs);

#endif

