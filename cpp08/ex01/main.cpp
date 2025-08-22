#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(100);
        std::vector <int> t;
        for(int i=0; i<90 ; i++)
            t.push_back(i);
        sp.range_iterators(t,20, 10);
        // sp.addNumber(6);
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}