/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:40:05 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 22:40:13 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string s)
{
    this->type = s;
}

Weapon::~Weapon()
{
    std::cout<<"Destructor has been called ."<<std::endl;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}

void Weapon::setType(std::string newType)
{
    this->type = newType;
}