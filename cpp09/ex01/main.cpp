#include"RPN.hpp"


static int checkArg(std::string str)
{
    for (size_t i = 0; i <str.size() ; i++)
    {
        if(!isdigit(str[i])&&str[i] != '+' && str[i] !='-'&&str[i] != '*' && str[i] !='/'&&str[i] != ' ' && str[i] !='\t')
            return 1;
        if( (isdigit(str[i]) && i+1<str.size() && isdigit(str[i+1]) ) || (isdigit(str[i]) && i+1<str.size() && isOperat(str[i+1]) ))
            return 1;
        if(isOperat(str[i]) && i+1<str.size() && isOperat(str[i+1]))
            return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    if(ac==2)
    {
        std::string str(av[1]);

        if(str.empty() || checkArg(str))
        {
            if(str.empty())
                std::cerr<<"Error: empty argument!\n";
            else
                std::cerr<<"Error: invalid argument!\n";
            exit(EXIT_FAILURE);
        }
        RPN rpn(str);
    }
    else
    {
        std::cerr<<"Error: invalide argements!\n";
        exit(EXIT_FAILURE);
    }
    return 0;
}