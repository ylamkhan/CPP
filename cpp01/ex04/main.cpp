/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:30:53 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/10/13 02:17:55 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool checkargm(int ac, char **av)
{

    std::string s(av[2]);
    if (ac != 4 || av[1] == NULL || s.empty()  || av[3] == NULL) {
        std::cerr << "\t\t\t\033[31mUsage: " << av[0] << " <filename> <s1> <s2>\033[0m" << std::endl;
         return false;
    }
    else
        return true;
}

void customReplace(std::string& str, const std::string& find, const std::string& replace) {
    size_t start_pos = 0;
    while ((start_pos = str.find(find, start_pos)) != std::string::npos) {
        str = str.substr(0, start_pos) + replace + str.substr(start_pos + find.length());
        start_pos += replace.length();
    }
}

int main(int ac, char* av[]) {
    

    if (checkargm(ac, av) == false)
        return -1;
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "\033[31mError: Unable to open input file.\033[0m" << std::endl;
        return 1;
    }
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);

    if (!outputFile) {
        std::cerr << "\033[31mError: Unable to create or open output file.\033[0m" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        customReplace(line, s1, s2);
        outputFile << line << std::endl;
    }

    std::cout << "\033[31mReplacement complete. Output written to \033[0m" << "\033[33m"<<outputFilename << "\033[0m"<<std::endl;

    return 0;
}
