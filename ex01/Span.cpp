#include"Span.hpp"
#include <exception>


Span::Span(unsigned int N): _N(N)
{}

Span::Span(const Span &other): _N(other._N), _numbers(other._numbers)
{}

Span &Span::operator=(const Span &other)
{
    if(this != &other)
    {
        _N = other._N;
        _numbers = other._numbers;
    }
    return(*this);
}

Span::~Span(){}

void Span::addNumber(int number)
{
    if(_numbers.size() >= _N)
    {
        throw std::runtime_error("Not added");
    }
    _numbers.push_back(number);
    
}

int Span::shortestSpan()
{
    if(_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");
    
    std::vector<int> temp = _numbers;
    std::sort(temp.begin(), temp.end());

    int shortest = INT_MAX;
    for(size_t i = 1; i < temp.size(); i++)
    {
        int span = temp[i] - temp[i - 1];
        if(span < shortest)
            shortest = span;

    }
    return(shortest);
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}
