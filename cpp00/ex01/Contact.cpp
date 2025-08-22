/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:47:10 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/10 01:48:47 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string ft_trim(std::string s)
{
    std::string r;
    unsigned long i=0;
    if (s.size()==1 && s[0]!=' ' && s[0]!='\t')
        return s;
    while((s[i]=='\t' || s[i]==' ') && s[i]!='\0')
        i++;
    unsigned long j = s.size()-1;
    while (i!=j && j>0 && (s[j]=='\t' || s[j]==' '))
            j--;
    if (i==s.size()-1)
        return NULL;
    else
        r = s.substr(i, j+1);
    return r;
}

std::string getInput(std::string prompt)
{
    std::string input1;
    std::cout << "\033[32m" << prompt << "\033[0m";
	getline(std::cin, input1);
    std::string input;
    input = ft_trim(input1);
   for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == '\t') {
            input[i] = ' ';
        }
    }
    if (std::cin.eof() == true)
    {
		std::cout << std::endl << "\033[31mYou pressed CTRL+D, program i exiting...\033[0m" << std::endl;
        exit(0);
    }
    while (input.empty())
    {
        std::cout << "\033[31mField can't be empty, please try again.\033[0m" << std::endl;
        std::cout << "\033[32m" << prompt << "\033[0m";
        getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << std::endl << "\033[31mYou pressed CTRL+D, program i exiting...\033[0m" << std::endl;
			exit(0);
   		}
    }
    return input;
}

int check(std::string phone)
{
    for (std::string::size_type i = 0; i < phone.size(); i++)
    {
        if (!isdigit(phone[i]))
        {
            std::cout << "\033[31mPhone number can only contain digits.\033[0m" << std::endl;
            return (0);
        }
    }
    return 1;
}

void Contact::setContact()
{
    this->firstName = getInput("Enter first name: ");
    this->lastName = getInput("Enter last name: ");
    this->nickname = getInput("Enter nickname: ");
    this->phoneNumber = getInput("Enter phone number: ");
    while (!check(phoneNumber))
        this->phoneNumber = getInput("Enter phone number: ");
    this->darkeSecret = getInput("Enter darkest secret: ");
    std::cout << "\033[34mContact added!\033[0m" << std::endl;
}

void Contact::ft_printInfos()
{
    if (firstName.size() >= 10)
        std::cout << std::setw(9) << firstName.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << firstName.substr(0, 10) << "|";
    if (lastName.size() >= 10)
        std::cout << std::setw(9) << lastName.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << lastName.substr(0, 10) << "|";
    if (nickname.size() >= 10)
        std::cout << std::setw(9) << nickname.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << nickname.substr(0, 10) << "|";
    std::cout << std::endl;
}

void Contact::ft_printfTout()
{
    std::cout << "\033[32mFirst Name: \033[0m" << firstName << std::endl;
    std::cout << "\033[32mLast Name: \033[0m" << lastName << std::endl;
    std::cout << "\033[32mnickname: \033[0m" << nickname << std::endl;
    std::cout << "\033[32mPhone Number: \033[0m" << phoneNumber << std::endl;
    std::cout << "\033[32mDarkest Secret: \033[0m" << darkeSecret << std::endl;
}
