/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:37:33 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 22:37:36 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public :
        Zombie();
        ~Zombie();
        void setZombie(std::string newName);
        void    announce(void);
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif