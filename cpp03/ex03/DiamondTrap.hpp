/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:45:56 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 04:45:58 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#define MAGENTA "\033[35m"

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;

    public:
            DiamondTrap();
            DiamondTrap( std::string name );
            DiamondTrap(const DiamondTrap &);
            DiamondTrap &operator=(const DiamondTrap& c);
            ~DiamondTrap();


            void whoAmI();
};

#endif
