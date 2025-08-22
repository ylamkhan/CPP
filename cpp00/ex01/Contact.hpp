/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:35:41 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 00:56:51 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_PHH
#define CONTACT_PHH

#include <iostream>
#include <string>
#include <ostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkeSecret;
	public:
		void setContact();
		void ft_printInfos();
		void ft_printfTout();
};
std::string getInput(std::string p);
bool checkPhone(std::string ph);
#endif