#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<string>
#include<stack>
#include<list>


class RPN
{
    private:
        std::stack<long> stkA;      
        RPN();
        RPN &operator=(const RPN &o);
        RPN(const RPN &o);
    public:
        RPN(std::string arg);
        ~RPN();
        long doOperation(long a, long b, char op);
};
int isOperat(char c);
#endif