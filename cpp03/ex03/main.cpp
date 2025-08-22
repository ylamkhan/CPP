/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:46:13 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 04:46:15 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap ash( "Ash" );
    DiamondTrap ash2( ash );
    DiamondTrap ash3(".");

    ash.whoAmI();
    ash2.whoAmI();
    ash3 = ash;
    ash3.whoAmI();

    ash.attack( "the air" );
    ash.takeDamage( 10 );
    ash.beRepaired( 10 );

    return 0;
}