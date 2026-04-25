#include "../ex01/includes/Span.hpp"
#include <iostream>
#include <vector>
#include <climits>   // INT_MIN, INT_MAX

#define REDD "\033[0;38;2;255;0;0m"
#define LIME "\033[0;38;2;0;255;0m"
#define CYAN "\033[0;38;2;0;255;255m"
#define PURP "\033[0;38;2;180;120;255m"
#define GOLD "\033[0;38;2;255;215;0m"
#define SOUL "\033[4m"
#define RST  "\033[0m"
#define BOLD "\033[1m"

static void testSubject()
{
    std::cout << CYAN << "\n===== Test du sujet =====" << RST << std::endl;

    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << GOLD << "shortestSpan : " << RST << LIME << sp.shortestSpan() << RST << std::endl;  // 2
    std::cout << GOLD << "longestSpan  : " << RST << LIME << sp.longestSpan() << RST << std::endl;   // 14
}

static void testAddRange()
{
    std::cout << CYAN << "\n===== Test addRange (10 000 nombres) =====" << RST << std::endl;

    std::vector<int> src;
    for (int i = 0; i < 10000; ++i)
        src.push_back(i);

    Span sp(10000);
    sp.addRange_It(src.begin(), src.end());

    std::cout << GOLD << "shortestSpan : " << RST << LIME << sp.shortestSpan() << RST << std::endl;  // 1
    std::cout << GOLD << "longestSpan  : " << RST << LIME << sp.longestSpan() << RST << std::endl;   // 9999
}

static void testEdgeCases()
{
    std::cout << CYAN << "\n===== Test cas limites =====" << RST << std::endl;

    // span vide
    Span empty(5);
    try {
        empty.shortestSpan();
        std::cout << REDD << "Aucune exception levee !" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << GOLD << "Span vide shortestSpan : " << RST << LIME << e.what() << RST << std::endl;
    }

    // span avec 1 element
    Span one(5);
    one.addNumber(42);
    try {
        one.longestSpan();
        std::cout << REDD << "Aucune exception levee !" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << GOLD << "Span 1 elem longestSpan : " << RST << LIME << e.what() << RST << std::endl;
    }

    // ajout quand plein
    Span full(3);
    full.addNumber(1);
    full.addNumber(2);
    full.addNumber(3);
    try {
        full.addNumber(4);
        std::cout << REDD << "Aucune exception levee !" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << GOLD << "addNumber quand plein : " << RST << LIME << e.what() << RST << std::endl;
    }

    // tous identiques
    Span same(3);
    same.addNumber(5);
    same.addNumber(5);
    same.addNumber(5);
    std::cout << GOLD << "Tous identiques shortestSpan : " << RST << LIME << same.shortestSpan() << RST << std::endl;  // 0
    std::cout << GOLD << "Tous identiques longestSpan  : " << RST << LIME << same.longestSpan() << RST << std::endl;   // 0

    // valeurs negatives
    Span neg(3);
    neg.addNumber(-10);
    neg.addNumber(0);
    neg.addNumber(10);
    std::cout << GOLD << "Negatifs shortestSpan : " << RST << LIME << neg.shortestSpan() << RST << std::endl;  // 10
    std::cout << GOLD << "Negatifs longestSpan  : " << RST << LIME << neg.longestSpan() << RST << std::endl;   // 20

    // overflow : INT_MIN et INT_MAX → retour en long
    Span overflow(2);
    overflow.addNumber(INT_MIN);
    overflow.addNumber(INT_MAX);
    std::cout << GOLD << "INT_MIN/INT_MAX shortestSpan : " << RST << LIME << overflow.shortestSpan() << RST << std::endl;
    std::cout << GOLD << "INT_MIN/INT_MAX longestSpan  : " << RST << LIME << overflow.longestSpan() << RST << std::endl;
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** Span Tests - Simple (ex01) *********"
        << RST << std::endl;

    testSubject();
    testAddRange();
    testEdgeCases();

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
