/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:45:18 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 04:58:44 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

int main( void )
{
    FragTrap you( "YOU" );
    FragTrap you2( you );

    you.attack( "the air" );
    you.takeDamage( 10 );
    you.beRepaired( 10 );
    you.highFive();
    return 0;
}