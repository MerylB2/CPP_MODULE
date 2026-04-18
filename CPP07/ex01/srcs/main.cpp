#include "iter.hpp"
#include <iostream>

int main()
{
    std::string strArray[] = {"Love", "Dane", "Code", "Enjoy"};
    int intArray[] = {1, 2, 42, 78, 6, 3};
    float floatArray[] = {3.14f, 2.718f, 1.618f, 0.577f};

    std::cout << "String Array: ";
    iter(strArray, 4, print_arr<std::string>);
    std::cout << "\nInteger Array: ";
    iter(intArray, 6, print_arr<int>);
    std::cout << "\nFloat Array: ";
    iter(floatArray, 4, print_arr<float>);
    std::cout << std::endl;
    return 0;
}