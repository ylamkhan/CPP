#include "Span.hpp"

Span::Span():N(0){}
Span::~Span(){}
Span::Span(size_t N):N(N){
    if(N>LONG_MAX || N <0)
        throw std::invalid_argument("error in arg N please in range [1,LANG_MAX].");
}
Span &Span::operator=(const Span &other)
{
    if(this != &other)
    {
        this->N=other.N;
        for (size_t i = 0; i < other.S.size(); i++)
            this->S[i] = other.S[i];
    }
    return *this;
}
Span::Span(const Span &other){*this = other;}
void Span::addNumber(int nub)
{
    if(this->N>this->S.size())
       this->S.push_back(nub);
    else
        throw std::out_of_range("not found space.");
}
void Span::range_iterators(std::vector <int> &it,size_t b, size_t end)
{
    if(it.size()>this->N || end >= it.size() || b >= it.size() || end < b) 
        throw std::out_of_range("Invalid Begin or End !!");
    for (size_t i = b; i < end; i++)
        addNumber(it[i]);
}
size_t Span::shortestSpan()
{
    if(this->S.size()<2)
        throw std::range_error("Span is size infurire 2.");
    std::sort(this->S.begin(), this->S.end());
    int min = S[1] - S[0];
    for (size_t i = 1; i < S.size(); i++)
    {
        if(i + 1 < S.size() && S[i + 1] - S[i] < min)
            min = S[i + 1] - S[i];
    }
    return min;
}
size_t Span::longestSpan()
{
    if(this->S.size()<2)
        throw std::range_error("Span is size infurire 2.");
    std::sort(this->S.begin(), this->S.end(),std::greater<int>());
    return this->S[0]-S[this->S.size()-1];
}
