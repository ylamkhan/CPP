/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:44:06 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/16 04:50:34 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap clap("YOU");

    clap.attack("Y");
    clap.beRepaired(6);
    clap.takeDamage(10);
    clap.attack("Y");


    return 0;
}
