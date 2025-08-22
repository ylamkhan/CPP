/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:46:26 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 04:46:29 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
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