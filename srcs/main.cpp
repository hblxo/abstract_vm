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
#include "AnalyzerClass.hpp"

int     main(int argc, char **argv)
{
    try {
		std::shared_ptr<Analyzer> an(new Analyzer(argc, argv));
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }
//    catch (...)
//	{
//    	std::cout << "Undefined error" << std::endl;
//	}
    return 0;
}
