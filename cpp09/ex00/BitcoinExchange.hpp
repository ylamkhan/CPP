#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <stdexcept>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string file);
        ~BitcoinExchange();
        void traitement(std::string fileInput);
        std::string dateValuein(std::string line, std::string &date, double &value);
        std::string checkeDateValue(std::string date, double value);
    private:
        std::map<std::string, double> base;
        BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &o);
        BitcoinExchange(const BitcoinExchange &o);

};

#endif