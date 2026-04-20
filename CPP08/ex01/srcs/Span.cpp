#include "Span.hpp"
#include <algorithm>

// constructeur par defaut
Span::Span(unsigned int N) : _maxSize(N) 
{
}

// constructeur de copie
Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data)
{
}

// operateur d'affectation pour copier les données d'un objet à un autre
Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

// destructeur
Span:: ~Span() {}

// ajout d'un num au span
void Span::addNumber(int num)
{
    if (_data.size() >= _maxSize)
        throw std::length_error("Span already full");
    _data.push_back(num);
}

// calcul du plus petit écart minimal entre deux nombres adjacents dans le vecteur trié
int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::length_error("Numbers are not enough to find a span");
    
    // copie du vecteur et tri pour trouver les plus petits écarts
    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i)
        shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
    return shortest;
}

// calcul du plus grand écart entre deux nombres
// le plus grand etant la diff entre le max et le min
int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::length_error("Numbers are not enough to find a span");
    int maxLong = *std::max_element(_data.begin(), _data.end());
    int minLong =  *std::min_element(_data.begin(), _data.end());
    return maxLong - minLong;
}

