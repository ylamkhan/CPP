/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:37:43 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/14 02:55:35 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    if (N <= 0)
        exit(0);
    Zombie *arryZombie = new Zombie[N];
    for(int i=0; i< N; i++)
        arryZombie[i].setZombie(name);
    return(arryZombie);
}