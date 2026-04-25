#include "../ex00/includes/easyfind.hpp"
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
    std::cout << CYAN << "\n===== Test avec std::vector =====" << RST << std::endl;

    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(42);
    vec.push_back(9);
    vec.push_back(1);

    // trouve
    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << GOLD << "easyfind(vec, 42) : " << RST << LIME << *it << " (Found)" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << REDD << e.what() << RST << std::endl;
    }

    // non trouve
    try {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << GOLD << "easyfind(vec, 99) : " << RST << LIME << *it << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << GOLD << "easyfind(vec, 99) : " << RST << REDD << e.what() << RST << std::endl;
    }

    // valeur negative
    vec.push_back(-5);
    try {
        std::vector<int>::iterator it = easyfind(vec, -5);
        std::cout << GOLD << "easyfind(vec, -5) : " << RST << LIME << *it << " (Found)" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << REDD << e.what() << RST << std::endl;
    }

    // conteneur vide
    std::vector<int> empty;
    try {
        easyfind(empty, 1);
    } catch (const std::exception& e) {
        std::cout << GOLD << "easyfind(empty, 1) : " << RST << REDD << e.what() << RST << std::endl;
    }
}

static void testList()
{
    std::cout << CYAN << "\n===== Test avec std::list =====" << RST << std::endl;

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    // trouve
    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << GOLD << "easyfind(lst, 20) : " << RST << LIME << *it << " (Found)" << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << REDD << e.what() << RST << std::endl;
    }

    // non trouve
    try {
        std::list<int>::iterator it = easyfind(lst, 99);
        std::cout << GOLD << "easyfind(lst, 99) : " << RST << LIME << *it << RST << std::endl;
    } catch (const std::exception& e) {
        std::cout << GOLD << "easyfind(lst, 99) : " << RST << REDD << e.what() << RST << std::endl;
    }

    // liste vide
    std::list<int> empty;
    try {
        easyfind(empty, -5);
    } catch (const std::exception& e) {
        std::cout << GOLD << "easyfind(empty, -5) : " << RST << REDD << e.what() << RST << std::endl;
    }
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** EasyFind Tests - Simple (ex00) *********"
        << RST << std::endl;

    testVector();
    testList();

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
