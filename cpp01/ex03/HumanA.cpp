/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:38:52 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 22:38:54 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name),weapon(weapon){}

HumanA::~HumanA()
{
    std::cout<<"Destructor has been called ."<<std::endl;
}

void HumanA::attack() const
{
    std::cout<<this->name<<"  attacks with their "<< weapon.getType()<<std::endl;
}