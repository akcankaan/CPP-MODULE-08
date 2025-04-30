#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _numbers;

    public:
        Span(unsigned int N);

        void addNumber(int n);
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class NoSpaceException : public std::exception
        {
            const char *what() const throw()
            {
                return "No space left to add more numbers!";
            }
        };

        class NoSpanException : public std::exception
        {
            const char *what() const throw()
            {
                return "Not enough numbers to calculate span!";
            }
        };
    };
#endif
