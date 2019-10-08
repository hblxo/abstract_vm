/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:58:48 by hbouchet          #+#    #+#             */
/*   Updated: 2019/02/23 14:46:01 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/LexerClass.hpp"
#include "../includes/ExceptionClass.hpp"

int     main(int argc, char **argv)
{
    Lexer       *lexer;

    try {
        lexer = new Lexer(argc, argv);
    }
    catch (Exception& e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }
    catch (...)
	{
    	std::cout << "Undefined error" << std::endl;
	}
    return 0;
}

//todo : ajouter config clion github - autre branche ?
//todo : exporter settings