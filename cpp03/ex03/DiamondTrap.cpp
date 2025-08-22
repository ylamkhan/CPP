/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:45:50 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 05:30:11 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(  void )
{
    this->ClapTrap::name = "_clap_name";
    
    FragTrap::hitPoints = 100;
    ScavTrap::energyPoints = 50;
    FragTrap::attackDamage = 30;
    std::cout << GREEN << "Diamondtrap default constructor is called" << DEFAULT << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), FragTrap( name ), ScavTrap( name )
{
    this->name = name;
    this->ClapTrap::name = name + "_clap_name";
    
    FragTrap::hitPoints = 100;
    ScavTrap::energyPoints = 50;
    FragTrap::attackDamage = 30;
    
    std::cout << GREEN << "# DiamondTrap # - " << this->name << " constructed." << DEFAULT << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &c)
{
    *this = c;
    std::cout << GREEN <<"DiamondTrap copy constructor called" << DEFAULT << std::endl;
}

DiamondTrap&   DiamondTrap::operator=( const DiamondTrap& c )
{
    this->name = c.name;
    this->hitPoints = c.hitPoints;
    this->energyPoints = c.energyPoints;
    this->attackDamage = c.attackDamage;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << MAGENTA << "# DiamondTrap # - " << DEFAULT << this->name << " is dead." << std::endl;
}

void    DiamondTrap::whoAmI( void ) {
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
    std::cout << "I am a DiamondTrap named " << BLUE << this->name << DEFAULT << ", ClapTrap name: " << BLUE << ClapTrap::name << DEFAULT << std::endl;
}
