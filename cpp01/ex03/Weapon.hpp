/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:40:12 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 22:40:16 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include<iostream>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(std::string s);
        ~Weapon();
        const std::string& getType(void);
        void setType(std::string newType);
};
#endif