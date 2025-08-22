/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:36:57 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/13 02:15:41 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    
    Zombie *hord = zombieHorde(0, "youssef");
    for (int i = 0; i < 10; i++)
        hord[i].announce();
    delete[] hord;
    return 0;
}