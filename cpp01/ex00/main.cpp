/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:35:18 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 22:35:23 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int main()
{
    std::string name;

    std::cout << "\t\t\033[31mCreating zombie on the stack.\033[0m"<<std::endl;
    do
    {
        std::cout << "\033[33mZombie name: \033[0m"<< std::flush;
        getline(std::cin, name);
        if(std::cin.eof() == true)
        {
            std::cout<<"\033[31m passing CTRL+D  in paramtre.\033[0m"<<std::endl;
            return 0;
        }
        if(name.empty()==false)
        {
            Zombie zombie1(name);
            zombie1.announce();
            std::cout << "\t\t\t\033[31mCalling randoChump().\033[0m"<<std::endl;
            randomChump(name);
        }
    }while(name.empty()==true);

    std::cout << "\t\t\033[31mCreating zombie on the heap.\033[0m"<<std::endl;
     do
    {
        std::cout << "\033[33mZombie name: \033[0m"<< std::flush;
        getline(std::cin, name);
        if(std::cin.eof() == true)
        {
            std::cout<<"\033[31m passing CTRL+D  in paramtre.\033[0m"<<std::endl;
            return 0;
        }
        if(name.empty()==false)
        {
            Zombie *zombie2 = newZombie(name);
            zombie2->announce();
            std::cout << "\t\t\t\033[31mCalling randoChump().\033[0m"<<std::endl;
            randomChump(name);
            delete zombie2;
        }
    }while(name.empty()==true);
    return 0;
}