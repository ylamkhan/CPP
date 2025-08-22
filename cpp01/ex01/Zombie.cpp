/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:37:24 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 22:37:28 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
    std::cout << "Zombie "<< this->name << " has been destroyed." << std::endl;
}

void Zombie::setZombie(std::string newName)
{
    this->name = newName;
}

void    Zombie::announce(void)
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ...  "<<std::endl;
}