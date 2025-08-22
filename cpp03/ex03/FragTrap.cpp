/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:46:02 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 05:31:45 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap(  void )
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << GREEN << "Fragtrap default constructor is called" << DEFAULT << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << BLUE << "| FragTrap | - " << this->name << " constructed." << DEFAULT << std::endl;
}

FragTrap::FragTrap(const FragTrap &c)
{
    *this = c;
    std::cout << GREEN << "FragTrap copy constructor called" << DEFAULT << std::endl;
}

FragTrap&   FragTrap::operator=( const FragTrap& c )
{
    this->name = c.name;
    this->hitPoints = c.hitPoints;
    this->energyPoints = c.energyPoints;
    this->attackDamage = c.attackDamage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << BLUE << "| FragTrap | - " << DEFAULT << this->name << " destructed." << std::endl;
}

void    FragTrap::highFive( void )
{
    if (hitPoints == 0)
    {
        std::cout << RED <<  "| FragTrap | - " << name << " has no hit points left. " << DEFAULT << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << RED << "| FragTrap | - " << name << " has no enrgey points left." << DEFAULT << std::endl;
        return;
    }
    std::cout << BLUE << "| FragTrap | - " << DEFAULT << this->name << " high fives everybody." << std::endl;
    this->energyPoints -= 1;
}