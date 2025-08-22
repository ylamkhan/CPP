/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:41:51 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 23:39:05 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	Harl;
	if(ac != 2)
		std::cout << "\t\t\t\033[33m ENTRE A LEVEL (debug, info, warning,error)\033[0m" << std::endl;
	else
	{
		std::string level(av[1]);
		Harl.complain(level);
	}
	return (0);
}