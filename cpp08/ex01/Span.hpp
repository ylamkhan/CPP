#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <set>
#include <climits>

class Span
{
private:
    size_t N;
    std::vector<int> S;
public:
    Span();
    ~Span();
    Span(size_t N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    void addNumber(int nub);
    void range_iterators(std::vector <int> &it,size_t b, size_t end);
    size_t shortestSpan();
    size_t longestSpan();
};



#endif