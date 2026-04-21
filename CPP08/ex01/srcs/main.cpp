#include "Span.hpp"
#include <iostream>
#include <vector>

#define REDD "\033[0;38;2;255;0;0m"
#define LIME "\033[0;38;2;0;255;0m"
#define CYAN "\033[0;38;2;0;255;255m"
#define PURP "\033[0;38;2;180;120;255m"
#define GOLD "\033[0;38;2;255;215;0m"
#define SOUL "\033[4m"
#define RST  "\033[0m"
#define BOLD "\033[1m"

static size_t getSize(const std::string& prompt)
{
	int n;
	std::cout << prompt;
	std::cin >> n;
	if (std::cin.fail() || n < 0)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		throw std::runtime_error("Invalid Input");
	}
	return static_cast<size_t>(n);
}

static void testAddNumber()
{
    unsigned int n;

    std::cout << CYAN << "\n===== Test addNumber =====" << RST << std::endl;
    try { n = getSize(GOLD "Capacite du Span : " RST); }
    catch (const std::exception& e) {
        std::cout << REDD << e.what() << RST << std::endl;
        return;
    }

    Span sp(n);

    for (unsigned int i = 0; i < n; ++i)
    {
        int val;
        std::cout << GOLD << "  Nombre [" << i << "] : " << RST;
        if (!(std::cin >> val))
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << REDD << "Invalid input !" << RST << std::endl;
            break;
        }
        sp.addNumber(val);
    }

    try {
        std::cout << PURP << "\nshortestSpan : " << RST << LIME << sp.shortestSpan() << RST << std::endl;
        std::cout << PURP << "longestSpan  : " << RST << LIME << sp.longestSpan() << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << REDD << "Exception : " << e.what() << RST << std::endl;
    }

    // test ajout quand plein
    std::cout << GOLD << "\nTentative d'ajout quand plein : " << RST;
    try {
        sp.addNumber(42);
        std::cout << REDD << "Aucune exception levee !" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << LIME << "Exception : " << e.what() << RST << std::endl;
    }
}

static void testAddRange()
{
    std::cout << CYAN << "\n===== Tests using a range of iterators (10 000 nombres) =====" << RST << std::endl;

    std::vector<int> src;
    for (int i = 0; i < 10000; ++i)
        src.push_back(i);

    Span sp(10000);
    sp.addRange_It(src.begin(), src.end());

    try {
        std::cout << PURP << "shortestSpan : " << RST << LIME << sp.shortestSpan() << RST << std::endl;
        std::cout << PURP << "longestSpan  : " << RST << LIME << sp.longestSpan() << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << REDD << "Exception : " << e.what() << RST << std::endl;
    }
}

static void testEdgeCases()
{
    std::cout << CYAN << "\n===== Test avec les cas limites =====" << RST << std::endl;

    // span vide
    Span empty(5);
    std::cout << GOLD << "shortestSpan sur Span vide : " << RST;
    try {
        empty.shortestSpan();
        std::cout << REDD << "Aucune exception levée !" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << LIME << "Exception : " << e.what() << RST << std::endl;
    }

    // span avec un seul element
    Span one(5);
    one.addNumber(42);
    std::cout << GOLD << "longestSpan sur Span a 1 element : " << RST;
    try {
        one.longestSpan();
        std::cout << REDD << "Aucune exception levée !" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << LIME << "Exception : " << e.what() << RST << std::endl;
    }
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** Span Tests (ex01) *********"
        << RST << std::endl;

    testAddNumber();
    testAddRange();
    testEdgeCases();

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
