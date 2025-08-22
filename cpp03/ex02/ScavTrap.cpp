/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:45:24 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 05:27:32 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ScavTrap.hpp"

ScavTrap::ScavTrap(  void )
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << GREEN << "Scavtrap default constructor is called" << DEFAULT << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << YELLOW << "< ScavTrap > - " << this->name << " constructed." << DEFAULT << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &c)
{
    *this = c;
    std::cout << GREEN << "ScavTrap copy constructor called" << DEFAULT << std::endl;
}

ScavTrap&   ScavTrap::operator=( const ScavTrap& c )
{
    this->name = c.name;
    this->hitPoints = c.hitPoints;
    this->energyPoints = c.energyPoints;
    this->attackDamage = c.attackDamage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << GREEN << "< ScavTrap > - " << this->name << " destructed." << DEFAULT << std::endl;
}

void    ScavTrap::attack( std::string const& target )
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
    std::cout << YELLOW << "< ScavTrap > - " << DEFAULT << this->name << " attacks " << target << " at range, causing " << this->attackDamage << " points of damage !" << std::endl;
    this->energyPoints -= 1;
}

void    ScavTrap::guardGate()
{
    std::cout << YELLOW << "< ScavTrap > - " << DEFAULT << this->name << " is now in Gate keeper mode." << std::endl;
}