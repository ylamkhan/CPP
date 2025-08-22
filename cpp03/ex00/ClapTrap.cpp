/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:43:33 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 05:24:08 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include <climits>

ClapTrap::ClapTrap()
{
    std::cout << GREEN << "Claptrap default constructor is called" << DEFAULT << std::endl;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap( std::string name)
{
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    this->name = name;
    std::cout << GREEN << "ClapTrap " << this->name << " is born!" << DEFAULT << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << DEFAULT << "ClapTrap destructor called" << DEFAULT << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << DEFAULT << "ClapTrap copy constructor called"<< DEFAULT << std::endl;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& copy)
{
    if(this != &copy)
    {
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
        this->attackDamage = copy.attackDamage;
    }
    return *this;
}

void    ClapTrap::attack( std::string const& target)
{
    if (hitPoints == 0)
    {
        std::cout << RED <<  "ClapTrap " << name << " has no hit points left. " << DEFAULT << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << RED << "ClapTrap " << name << " has no enrgey points left." << DEFAULT << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints -= 1;
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if (hitPoints == 0)
    {
        std::cout << RED <<  "ClapTrap " << name << " has no hit points left. " << DEFAULT << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << RED << "ClapTrap " << name << " has no enrgey points left." << DEFAULT << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
    if (amount > hitPoints)
        amount = hitPoints;
    hitPoints -= amount;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (hitPoints == 0)
    {
        std::cout << RED <<  "ClapTrap " << name << " has no hit points left. " << DEFAULT << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << RED << "ClapTrap " << name << " has no enrgey points left." << DEFAULT << std::endl;
        return;
    }
    std::cout << YELLOW <<"ClapTrap " << name << " repairs itself for " << amount << " hit points!" << DEFAULT << std::endl;
    energyPoints -= 1;
    if (amount > UINT_MAX - hitPoints)
        amount = UINT_MAX - hitPoints;
    hitPoints += amount;
}
