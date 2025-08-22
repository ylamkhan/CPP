/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:41:44 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 22:41:47 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
    public:
        std::string levels;
    public:
        Harl();
        ~Harl();
        void complain( std::string level);
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};
#endif