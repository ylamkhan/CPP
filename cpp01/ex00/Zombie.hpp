/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:36:45 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 22:36:52 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include<iostream>


class Zombie
{
    public :
        Zombie(std::string name);
        ~Zombie();
        void    announce(void);
    private:
        std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif