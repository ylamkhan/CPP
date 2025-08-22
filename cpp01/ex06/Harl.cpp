/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:41:36 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 23:36:59 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void    Harl::debug(void)
{
	std::cout<<"\033[33m[ DEBUG ] \033[0m"<<std::endl;
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void    Harl::info(void)
{
	std::cout<<"\033[33m[ INFO ]\033[0m"<<std::endl;
    std::cout<<"I cannot believe adding extra bacon costs more money."<<std::endl;
    std::cout<<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void    Harl::warning(void)
{
	std::cout<<"\033[33m[ WARNING ]\033[0m"<<std::endl;
    std::cout<<"I think I deserve to have some extra bacon for free."<<std::endl;
    std::cout<<"I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void    Harl::error(void)
{
	std::cout<<"\033[33m[ ERROR ]\033[0m"<<std::endl;
    std::cout<< "This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain( std::string level )
{
    void	(Harl::*fct[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	msg[4] = {"debug", "info", "warning", "error"};
	int d = 0;
	for (int i = 0; i < 4; i++)
	{
		if (msg[i] == level)
		{
			switch (i)
			{
				case 0:
					(this->*(fct[0]))();
				case 1:
					(this->*(fct[1]))();
				case 2:
					(this->*(fct[2]))();
				case 3:
					(this->*(fct[3]))();
				default:
					break;
			}
			d = 1;
		}
	}
	if (d==0)
		std::cout<< "\t\t\t \033[31mLevel not exit.\033[0m"<<std::endl;
}