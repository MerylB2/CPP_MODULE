#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define REDD "\033[0;38;2;255;0;0m"
#define LIME "\033[0;38;2;0;255;0m"
#define CYAN "\033[0;38;2;0;255;255m"
#define PURP "\033[0;38;2;180;120;255m"
#define GOLD "\033[0;38;2;255;215;0m"
#define SOUL "\033[4m"
#define RST  "\033[0m"
#define BOLD "\033[1m"

// Test du sujet avec MutantStack
static void testMutantStack()
{
    std::cout << CYAN << "\n===== Test MutantStack (Main du Sujet) =====" << RST << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << GOLD << "top()  : " << RST << LIME << mstack.top() << RST << std::endl;

    mstack.pop();
    std::cout << GOLD << "size() : " << RST << LIME << mstack.size() << RST << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it  = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << PURP << "\nIteration via iterateurs : " << RST << std::endl;
    while (it != ite)
    {
        std::cout << LIME << "  " << *it << RST << std::endl;
        ++it;
    }

    // copie dans un std::stack classique (demande par le sujet)
    std::stack<int> s(mstack);
    std::cout << GOLD << "\nCopie dans std::stack, size : " << RST << LIME << s.size() << RST << std::endl;
}

// Meme test avec std::list pour verifier que les sorties sont identiques
static void testList()
{
    std::cout << CYAN << "\n===== Même test avec std::list =====" << RST << std::endl;

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);
    std::cout << GOLD << "back() : " << RST << LIME << lst.back() << RST << std::endl;

    lst.pop_back();
    std::cout << GOLD << "size() : " << RST << LIME << lst.size() << RST << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator it  = lst.begin();
    std::list<int>::iterator ite = lst.end();

    ++it;
    --it;

    std::cout << PURP << "\nIteration via iterateurs : " << RST << std::endl;
    while (it != ite)
    {
        std::cout << LIME << "  " << *it << RST << std::endl;
        ++it;
    }
}

// Test interactif
static void testInteractif()
{
    size_t n;

    std::cout << CYAN << "\n===== Test interactif =====" << RST << std::endl;
    std::cout << GOLD << "Nombre de valeurs à empiler : " << RST;
    std::cin >> n;

    MutantStack<int> ms;
    for (size_t i = 0; i < n; ++i)
    {
        int val;
        std::cout << GOLD << "  push [" << i << "] : " << RST;
        std::cin >> val;
        ms.push(val);
    }

    std::cout << PURP << "\nContenu via iterateurs (bas -> haut) : " << RST << LIME;
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << RST << std::endl;

    std::cout << GOLD << "top()  : " << RST << LIME << ms.top() << RST << std::endl;
    std::cout << GOLD << "size() : " << RST << LIME << ms.size() << RST << std::endl;
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** MutantStack Tests (ex02) *********"
        << RST << std::endl;

    testMutantStack();
    testList();
    testInteractif();

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
