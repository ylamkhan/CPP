#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string arg(av[1]);

        BitcoinExchange b("data.csv");
        if (arg.empty())
        {
            std::cerr << "Error: name empty .\n";
            exit(EXIT_FAILURE);
        }
        b.traitement(arg);
    }
    else
    {
        std::cerr << "Error: invalid argument.\n";
        exit(EXIT_FAILURE);
    }
}
