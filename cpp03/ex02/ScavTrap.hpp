/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:45:30 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 04:45:31 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap( std::string name );
        ScavTrap(const ScavTrap &);
        ScavTrap &operator=(const ScavTrap& c);
        ~ScavTrap();

        void    attack(std::string const& target);
        void    guardGate();
};

#endif