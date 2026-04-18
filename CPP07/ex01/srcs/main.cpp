#include "iter.hpp"
#include <iostream>

#define REDD "\033[0;38;2;255;0;0m"
#define LIME "\033[0;38;2;0;255;0m"
#define CYAN "\033[0;38;2;0;255;255m"
#define PURP "\033[0;38;2;180;120;255m"
#define GOLD "\033[0;38;2;255;215;0m"
#define SOUL "\033[4m"
#define RST  "\033[0m"
#define BOLD "\033[1m"

int main()
{
    std::string strArray[] = {"Love", "Dane", "Code", "Enjoy"};
    int intArray[] = {1, 2, 42, 78, 6, 3};
    float floatArray[] = {3.14f, 2.718f, 1.618f, 0.577f};

    std::cout << BOLD << GOLD << SOUL
        << "\n******** Iter Tests (ex01) *********"
        << RST << std::endl;

    std::cout << CYAN << "\nString Array: " << RST;
    iter(strArray, 4, print_arr<std::string>);

    std::cout << CYAN << "\nInteger Array: " << RST;
    iter(intArray, 6, print_arr<int>);

    std::cout << CYAN << "\nFloat Array: " << RST;
    iter(floatArray, 4, print_arr<float>);

    std::cout << std::endl << std::endl;
    return 0;
}
