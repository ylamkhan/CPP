#include "PmergeMe.hpp"

// numbre de points;
// fin pipe;
// fin sign
static int checkarg(std::string arg)
{
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (!isdigit(arg[i]) && arg[i] != ' ' && arg[i] != '\t' && arg[i] != '+')
            return 1;
        if (arg[i] == '+' && i + 1 < arg.size() && !isdigit(arg[i + 1]))
            return 1;
        if (i && arg[i] == '+' && isdigit(arg[i - 1]))
            return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        std::string arg;
        int i = 1;
        while (i < ac)
        {
            std::string ch(av[i]);
            if (!ch.empty())
            {
                ch.push_back(' ');
                arg += ch;
            }
            i++;
        }
        if (checkarg(arg))
        {
            std::cerr << "Error: invalid argument!\n";
            exit(EXIT_FAILURE);
        }
        PmergeMe pmergeme(arg);
        pmergeme.run();
        pmergeme.diysplay();
    }
    else
    {
        std::cerr << "Error: invalid argument!\n";
        exit(EXIT_FAILURE);
    }
    return 0;
}