#include "RPN.hpp"

int isOperat(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else
        return 0;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &o)
{
    if (this != &o)
        stkA = o.stkA;
    return *this;
}

RPN::RPN(const RPN &o)
{
    *this = o;
}

long RPN::doOperation(long a, long b, char op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else
    {
        if (!b)
        {
            std::cerr << "Error: Division by Zero!\n";
            exit(EXIT_FAILURE);
        }
        return a / b;
    }
}

RPN::RPN(std::string arg)
{
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (isdigit(arg[i]))
        {
            std::string ch;
            ch.push_back(arg[i]);
            stkA.push(std::strtol(ch.c_str(), NULL, 10));
        }
        else if (isOperat(arg[i]))
        {
            if (stkA.size() < 2)
            {
                std::cerr << "Error: size stack  isn't two!\n";
                exit(EXIT_FAILURE);
            }
            double d1 = stkA.top();
            stkA.pop();
            double d2 = d2 = stkA.top();
            stkA.pop();
            stkA.push(doOperation(d2, d1, arg[i]));
        }
    }
    if (stkA.size() == 1)
    {
        std::cout << stkA.top() << "\n";
        exit(EXIT_SUCCESS);
    }
    else
    {
        std::cout << "Error: \n";
        exit(EXIT_FAILURE);
    }
}