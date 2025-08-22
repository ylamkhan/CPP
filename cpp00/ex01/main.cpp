/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:35:54 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/10 02:04:07 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {

    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        command = getInput("Enter a command (ADD, SEARCH, EXIT): ");

        if(command == "ADD")
        {
            if (!phoneBook.addContact())
                std::cerr << "\033[31mPhonebook is full. Oldest contact replaced.\033[0m" << std::endl;
        }
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            return 0;
        else
            std::cout << "\033[31mInvalid command. Please enter ADD, SEARCH, or EXIT.\033[m" << std::endl;
    }

    return 0;
}