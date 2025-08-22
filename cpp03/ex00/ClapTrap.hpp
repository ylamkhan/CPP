/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:43:50 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 05:15:05 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define GREEN "\033[32m"   
#define RED "\033[31m"     
#define YELLOW "\033[33m" 
#define BLUE "\033[34m"    
#define DEFAULT "\033[39m"

#include <iostream>

class ClapTrap
{
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
public:
    ClapTrap();
    ClapTrap( std::string name);
    ClapTrap(const ClapTrap &opy);
    ClapTrap &operator=(const ClapTrap& copy);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
