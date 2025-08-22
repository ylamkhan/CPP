/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:39:09 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 23:02:25 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):name(name){
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    std::cout<<"Destructor has been called ."<<std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if(this->weapon)
        std::cout<<this->name<<"  attacks with their "<< this->weapon->getType()<<std::endl;
    else
        std::cout<<this->name<<" has no weapon "<<std::endl;
}