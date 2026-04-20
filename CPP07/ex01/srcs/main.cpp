#include "iter.hpp"
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
    size_t n;

    std::cout << CYAN << "\n===== Test avec int =====" << RST << std::endl;
    std::cout << GOLD << "Taille du tableau : " << RST;
    std::cin >> n;

    int *arr = new int[n];
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << GOLD << "  arr[" << i << "] : " << RST;
        std::cin >> arr[i];
    }

    std::cout << PURP << "\nContenu via iter : " << RST << LIME;
    iter(arr, n, print_arr<int>);
    std::cout << RST << std::endl;

    delete[] arr;
}

static void testStrings()
{
    size_t n;

    std::cout << CYAN << "\n===== Test avec string =====" << RST << std::endl;
    std::cout << GOLD << "Taille du tableau : " << RST;
    std::cin >> n;

    std::string *arr = new std::string[n];
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << GOLD << "  arr[" << i << "] : " << RST;
        std::cin >> arr[i];
    }

    std::cout << PURP << "\nContenu via iter : " << RST << LIME;
    iter(arr, n, print_arr<std::string>);
    std::cout << RST << std::endl;

    delete[] arr;
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** Iter Tests (ex01) *********"
        << RST << std::endl;

    testInts();
    testStrings();

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
