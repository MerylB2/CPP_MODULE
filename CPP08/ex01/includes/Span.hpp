#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _data;
    
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
        template <typename InputIt>
        void addRange_It(InputIt begin, InputIt end);
};

template <typename InputIt>
void Span::addRange_It(InputIt begin, InputIt end)
{
    for (InputIt it = begin; it != end; ++it)
        addNumber(*it);
}

#endif