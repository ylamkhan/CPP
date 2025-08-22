/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:44:49 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 05:24:56 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include <climits>

ClapTrap::ClapTrap(  void )
{
    std::cout << "Claptrap default constructor is called" << std::endl;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap( std::string name )
{
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    this->name = name;
    std::cout << GREEN << "ClapTrap " << this->name << " is born!" << DEFAULT << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
    *this = c;
    std::cout << "ClapTrap copy constructor called" << std::endl;
    return;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& c )
{
    this->name = c.name;
    this->hitPoints = c.hitPoints;
    this->energyPoints = c.energyPoints;
    this->attackDamage = c.attackDamage;
    return *this;
}

void    ClapTrap::attack( std::string const& target )
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
