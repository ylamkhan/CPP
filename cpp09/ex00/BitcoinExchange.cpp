#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &o)
{
    if( this != &o)
        base        = o.base;
    return *this; 
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &o)
{
    *this=o;
}

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::string line;
    std::string date;
    double value;
    if(file.empty())
    {
        std::cerr<<"Error: empty in file name the base!\n";
        exit(EXIT_FAILURE);
    }
    std::fstream myfile(file);
    if(!myfile.is_open())
    {
        std::cerr<<"Error: file not open!\n";
        exit(EXIT_FAILURE);
    }
    std::getline(myfile,line);
    if(line.empty())
    {
        std::cerr<<"Error: file is vide!\n";
        exit(EXIT_FAILURE);
    }
    while (std::getline(myfile,line))
    {
        std::stringstream ss(line);
        std::getline(ss,date,',');
        ss>>value;
        base[date]=value;
    }
    myfile.close();
}

void BitcoinExchange::traitement(std::string fileInput)
{
        std::string line;

        if (fileInput.empty())
        {
            std::cerr << "Error: name file is vide\n";
            exit(EXIT_FAILURE);
        }
        std::fstream file(fileInput);
        if (!file.is_open())
        {
            std::cerr << "Error: file not opened!\n";
            exit(EXIT_FAILURE);
        }
        std::getline(file, line);

        if (line != "date | value")
        {
            std::cerr << "Error: date | value\n";
            exit(EXIT_FAILURE);
        }
        while (std::getline(file, line))
        {
            double value = -1;
            std::string date;
            if (dateValuein(line, date, value) == "vrai")
            {
                if (checkeDateValue(date, value) == "vrai")
                {
                    std::map<std::string, double>::iterator itf = base.find(date);
                    if (itf != base.end())
                        std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << itf->second * value << "\n";
                    else
                    {
                        std::map<std::string, double>::iterator it = base.lower_bound(date);
                        if (it == base.end() || it != base.begin())
                        {
                            --it;
                            std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << it->second * value << "\n";
                        }
                    }
                }
                else
                    std::cout << checkeDateValue(date, value) << "\n";
            }
            else
                std::cout << dateValuein(line, date, value) << "\n";
        }
}


std::string message(std::string mess, std::string line)
{
    return mess + line;
}

bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int checkposition(std::string date)
{
    if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]) || date[4] != '-' || !isdigit(date[5]) ||
        !isdigit(date[6]) || date[7] != '-' || !isdigit(date[8]) || !isdigit(date[9]))
        return 1;
    else
        return 0;
}

std::string BitcoinExchange::checkeDateValue(std::string date, double value)
{
    if (value < 0 || value > 1000)
        return ("Error: too large a number.");

    if (date.empty() || date.size() >= 11)
        return (message("Error: bad input ", date));

    if (checkposition(date))
        return (message("Error: bad input ", date));

    double year = atof(date.substr(0, 4).c_str());
    double month = atof(date.substr(5, 2).c_str());
    double day = atof(date.substr(8, 2).c_str());

    if (year > 9999 || year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return (message("Error: bad input ", date));
    if (year == 2009 && month == 1 && day < 2)
        return (message("Error: bad input ", date));
    if (isLeapYear((int)year) == true && month == 2 && day > 28)
        return (message("Error: bad input ", date));
    if (isLeapYear((int)year) == false && month == 2 && day > 29)
        return (message("Error: bad input ", date));
    if (month == 4 && day > 30)
        return (message("Error: bad input ", date));
    if (month == 6 && day > 30)
        return (message("Error: bad input ", date));
    if (month == 9 && day > 30)
        return (message("Error: bad input ", date));
    if (month == 11 && day > 30)
        return (message("Error: bad input ", date));
    return "vrai";
}

void skip(std::string line, int &i)
{
    while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
        i++;
}

void remDate(std::string line, std::string &date, int &i)
{
    while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '|')
        date.push_back(line[i++]);
}

void skip1(std::string line, int &nubpip, int &i)
{
    while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '|' || line[i] == '\n'))
    {
        if (line[i] == '|')
            nubpip++;
        i++;
    }
}

int cheV(std::string v)
{
    int i = 0;
    int nubP = 0;
    if ((v[0] == '+' && !v[i + 1]) || (v[0] == '.' || v[v.size() - 1] == '.' || v[v.size() - 1] == '+'))
        return 1;
    while (i < (int)v.size())
    {
        if (!isdigit(v[i]) && v[i] != '+' && v[i] != '.')
            return 1;
        if (v[i] == '+' && i + 1 < (int)v.size() && !isdigit(v[i + 1]))
            return 1;
        if (isdigit(v[i]) && i + 1 < (int)v.size() && v[i + 1] == '+')
            return 1;
        if (v[i] == '.')
            nubP++;
        i++;
    }
    if (nubP > 1)
        return 1;
    return 0;
}

std::string BitcoinExchange::dateValuein(std::string line, std::string &date, double &value)
{
    std::string v;
    int i = 0;
    int nubpip = 0;

    skip(line, i);
    if (!line[i])
        return ("Error: line vide!");
    if (!line[i])
        return (message("Error: bad input ", line));
    remDate(line, date, i);
    skip1(line, nubpip, i);
    if (!line[i] || nubpip != 1)
        return (message("Error: bad input ", line));
    while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
        v.push_back(line[i++]);
    while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
        i++;
    if (line[i])
        return (message("Error: bad input ", line));
    if (cheV(v))
        return (message("Error: bad input ", v));
    value = atof(v.c_str());
    return "vrai";
}


BitcoinExchange::~BitcoinExchange(){}