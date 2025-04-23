#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : _N(N) {}

// addNumber: Adds a single number to the vector
void Span::addNumber(int n)
{
    if (_numbers.size() >= _N)
        throw NoSpaceException();
    _numbers.push_back(n);
}

// addRange: Adds a range of numbers to the vector
template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

// shortestSpan: Finds the shortest span
unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    unsigned int minSpan = static_cast<unsigned int>(-1);

    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

// longestSpan: Finds the longest span
unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}

// Explicit instantiation for vector iterator
template void Span::addRange<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);
