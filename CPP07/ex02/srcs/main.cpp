#include <iostream>
#include <string>
#include <Array.hpp>

#define REDD "\033[0;38;2;255;0;0m"
#define LIME "\033[0;38;2;0;255;0m"
#define CYAN "\033[0;38;2;0;255;255m"
#define PURP "\033[0;38;2;180;120;255m"
#define GOLD "\033[0;38;2;255;215;0m"
#define SOUL "\033[4m"
#define RST  "\033[0m"
#define BOLD "\033[1m"

static void sep(const std::string& title)
{
    std::cout << CYAN << "\n===== " << title << " =====" << RST << std::endl;
}

static void testConstructors()
{
    sep("Constructeurs");

    Array<int> empty;
    std::cout << GOLD << "empty.size()     = " << LIME << empty.size() << RST << std::endl;

    Array<int> nums(5);
    std::cout << GOLD << "nums(5).size()   = " << LIME << nums.size() << RST << std::endl;
    std::cout << GOLD << "nums initialises : " << LIME;
    for (size_t i = 0; i < nums.size(); ++i)
        std::cout << nums[i] << " ";
    std::cout << RST << std::endl;
}

static void testCopyAndAssign()
{
    sep("Copie profonde");

    Array<int> a(3);
    a[0] = 10; a[1] = 20; a[2] = 30;

    Array<int> b(a);
    Array<int> c;
    c = a;

    b[0] = 42;
    c[1] = 37;

    std::cout << GOLD << "a : " << LIME << a[0] << " " << a[1] << " " << a[2] << RST << std::endl;
    std::cout << GOLD << "b : " << LIME << b[0] << " " << b[1] << " " << b[2]
        << PURP << " (b[0] modifie)" << RST << std::endl;
    std::cout << GOLD << "c : " << LIME << c[0] << " " << c[1] << " " << c[2]
        << PURP << " (c[1] modifie)" << RST << std::endl;
}

static void testConst()
{
    sep("operator[] const");

    Array<int> a(3);
    a[0] = 7; a[1] = 8; a[2] = 9;

    const Array<int> constArr(a);
    std::cout << GOLD << "constArr[0] = " << LIME << constArr[0] << RST << std::endl;
    std::cout << GOLD << "constArr[1] = " << LIME << constArr[1] << RST << std::endl;
}

static void testOutOfBounds()
{
    sep("Hors bornes");

    Array<int> a(5);

    try {
        a[10] = 0;
    } catch (const std::exception& e) {
        std::cout << GOLD << "a[10]    -> " << REDD << "exception : " << e.what() << RST << std::endl;
    }
    try {
        a[-2] = 0;
    } catch (const std::exception& e) {
        std::cout << GOLD << "a[-2]    -> " << REDD << "exception : " << e.what() << RST << std::endl;
    }

    Array<int> empty;
    try {
        empty[0] = 0;
    } catch (const std::exception& e) {
        std::cout << GOLD << "empty[0] -> " << REDD << "exception : " << e.what() << RST << std::endl;
    }
}

static void testTypes()
{
    sep("Types differents");

    Array<float> floats(3);
    floats[0] = 3.14f; floats[1] = 2.71f; floats[2] = 1.41f;
    std::cout << GOLD << "float  : " << LIME
        << floats[0] << " " << floats[1] << " " << floats[2] << RST << std::endl;

    Array<std::string> words(3);
    words[0] = "Love"; words[1] = "Dance"; words[2] = "Enjoy";
    std::cout << GOLD << "string : " << LIME
        << words[0] << " " << words[1] << " " << words[2] << RST << std::endl;
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** Array Tests (ex02) *********"
        << RST << std::endl;

    testConstructors();
    testCopyAndAssign();
    testConst();
    testOutOfBounds();
    testTypes();

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
