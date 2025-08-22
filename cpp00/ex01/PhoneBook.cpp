/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:41:49 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/12 00:59:22 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::indexContact=0;
bool PhoneBook::addContact()
{
    if (indexContact < 8)
    {
        contact[indexContact].setContact();
        indexContact++;
        return true;
    }
    else
    {
        contact[indexContact%8].setContact();
        indexContact++;
        return false;
    }
}

void PhoneBook::searchContact()
{
    printfHeader();
    int size;
    if (indexContact < 8)
        size = indexContact;
    else   
        size = 8;
    for (int i = 0; i < size; i++)
    {
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        contact[i].ft_printInfos();
    }
    std::cout << std::setfill('-') << std::setw(44) << "-" << std::setfill(' ') << std::endl;
    if (indexContact > 0)
    {
        std::string s;
        int index;
        s = getInput("Enter an index to display contact details: ");
        index = atoi(s.c_str());
        if (index >= 1 && index <= size)
            contact[index - 1].ft_printfTout();
        else
        {
            do
            {
                std::cout << "\033[31mInvalid index. Contact not found.\033[0m" << std::endl;
                s = getInput("Enter an index to display contact details: ");
                index = atoi(s.c_str());
                if (index >= 1 && index <= size)
                    contact[index - 1].ft_printfTout();
            }while(!(index >= 1 && index <= size));
        }
    }
    else
        std::cout << "\033[31mPhonebook is empty.\033[0m" << std::endl;
}

void printfHeader()
{
    std::cout << std::setfill('-') << std::setw(44) << "-" << std::setfill(' ') << std::endl;

    std::cout << "|     " << std::setw(10) << "\033[33mIndex\033[0m" << "|";
    std::cout << std::setw(10) << "\033[33mFirst Name\033[0m" << "| ";
    std::cout << std::setw(10) << "\033[33mLast Name\033[0m" << "|  ";
    std::cout << std::setw(10) << "\033[33mNickname\033[0m" << "|" << std::endl;

    std::cout << std::setfill('-') << std::setw(44) << "-" << std::setfill(' ') << std::endl;
}
