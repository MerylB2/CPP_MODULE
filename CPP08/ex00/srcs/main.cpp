#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

#define REDD "\033[0;38;2;255;0;0m"
#define LIME "\033[0;38;2;0;255;0m"
#define CYAN "\033[0;38;2;0;255;255m"
#define PURP "\033[0;38;2;180;120;255m"
#define GOLD "\033[0;38;2;255;215;0m"
#define SOUL "\033[4m"
#define RST  "\033[0m"
#define BOLD "\033[1m"

static void testVector()
{
    size_t n;

    std::cout << CYAN << "\n===== Test avec std::vector =====" << RST << std::endl;
    std::cout << GOLD << "Vector Size : " << RST;
    std::cin >> n;

    std::vector<int> vec;
    for (size_t i = 0; i < n; ++i)
    {
        int val;
        std::cout << GOLD << "  vec[" << i << "] : " << RST;
        std::cin >> val;
        vec.push_back(val);
    }

    int target;
    std::cout << GOLD << "Target Value : " << RST;
    std::cin >> target;

    try {
        std::vector<int>::iterator it = easyfind(vec, target);
        std::cout << PURP << "Result : " << RST << LIME << *it << RST
            << PURP << " (Found)" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << PURP << "Result : " << RST << REDD << e.what() << RST << std::endl;
    }
}

static void testList()
{
    size_t n;

    std::cout << CYAN << "\n===== Test avec std::list =====" << RST << std::endl;
    std::cout << GOLD << "List Size: " << RST;
    std::cin >> n;

    std::list<int> lst;
    for (size_t i = 0; i < n; ++i)
    {
        int val;
        std::cout << GOLD << "  lst[" << i << "] : " << RST;
        std::cin >> val;
        lst.push_back(val);
    }

    int target;
    std::cout << GOLD << "Target Value : " << RST;
    std::cin >> target;

    try {
        std::list<int>::iterator it = easyfind(lst, target);
        std::cout << PURP << "Result : " << RST << LIME << *it << RST
            << PURP << " (Found)" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << PURP << "Result : " << RST << REDD << e.what() << RST << std::endl;
    }
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** EasyFind Tests (ex00) *********"
        << RST << std::endl;

    testVector();
    testList();

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
