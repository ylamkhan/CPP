/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:36:32 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 23:53:40 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "Constructor called." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie "<< this->name << " has been destroyed." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
