#include "../ex02/includes/MutantStack.hpp"
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

// Test exact du sujet
static void testSubject()
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

// Meme test avec std::list — les sorties doivent etre identiques
static void testList()
{
    std::cout << CYAN << "\n===== Meme test avec std::list =====" << RST << std::endl;

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

// Tests supplementaires
static void testExtra()
{
    std::cout << CYAN << "\n===== Tests supplementaires =====" << RST << std::endl;

    // stack vide — ms.empty() herite de std::stack — top() sur stack vide = segfault
    MutantStack<int> empty;
    std::cout << GOLD << "Stack vide empty() : " << RST << LIME << empty.empty() << RST << std::endl;
    std::cout << GOLD << "Stack vide size()  : " << RST << LIME << empty.size() << RST << std::endl;

    // iterateurs const
    MutantStack<int> ms;
    ms.push(10);
    ms.push(20);
    ms.push(30);

    std::cout << PURP << "\nConst iterateur : " << RST << LIME;
    const MutantStack<int> cms(ms);
    for (MutantStack<int>::const_iterator cit = cms.begin(); cit != cms.end(); ++cit)
        std::cout << *cit << " ";
    std::cout << RST << std::endl;
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** MutantStack Tests - Simple (ex02) *********"
        << RST << std::endl;

    testSubject();
    testList();
    testExtra();

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}
