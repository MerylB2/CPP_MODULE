#include "whatever.hpp"
#include <iostream>
#include <string>

#define REDD "\033[0;38;2;255;0;0m"
#define LIME "\033[0;38;2;0;255;0m"
#define CYAN "\033[0;38;2;0;255;255m"
#define PURP "\033[0;38;2;180;120;255m"
#define GOLD "\033[0;38;2;255;215;0m"
#define SOUL "\033[4m"
#define RST  "\033[0m"
#define BOLD "\033[1m"

static void testInts()
{
    int a, b;

    std::cout << CYAN << "\n===== Test avec int =====" << RST << std::endl;
    std::cout << GOLD << "Entier a : " << RST;
    std::cin >> a;
    std::cout << GOLD << "Entier b : " << RST;
    std::cin >> b;

    std::cout << PURP << "\nAvant swap : " << RST
        << "a = " << LIME << a << RST
        << ", b = " << LIME << b << RST << std::endl;
    ::swap(a, b);
    std::cout << PURP << "Apres swap : " << RST
        << "a = " << LIME << a << RST
        << ", b = " << LIME << b << RST << std::endl;
    std::cout << GOLD << "min(a, b)  = " << LIME << ::min(a, b) << RST << std::endl;
    std::cout << GOLD << "max(a, b)  = " << LIME << ::max(a, b) << RST << std::endl;
}

static void testStrings()
{
    std::string c, d;

    std::cout << CYAN << "\n===== Test avec string =====" << RST << std::endl;
    std::cout << GOLD << "String c : " << RST;
    std::cin >> c;
    std::cout << GOLD << "String d : " << RST;
    std::cin >> d;

    std::cout << PURP << "\nAvant swap : " << RST
        << "c = " << LIME << c << RST
        << ", d = " << LIME << d << RST << std::endl;
    ::swap(c, d);
    std::cout << PURP << "Apres swap : " << RST
        << "c = " << LIME << c << RST
        << ", d = " << LIME << d << RST << std::endl;
    std::cout << GOLD << "min(c, d)  = " << LIME << ::min(c, d) << RST << std::endl;
    std::cout << GOLD << "max(c, d)  = " << LIME << ::max(c, d) << RST << std::endl;
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** Whatever Tests (ex00) *********"
        << RST << std::endl;

    testInts();
    testStrings();

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
