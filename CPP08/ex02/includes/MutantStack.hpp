#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other)
        {
            std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack() {}

    // typedef me permet de faire des alias de types pour simplifier la syntaxe et rendre le code plus lisible,
    // Ici on crée des alias pour les types d'itérateurs de la classe de base std::stack<T>
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    //les methodes pour obtenir les iterateurs de l Stack
    iterator begin()  { return this->c.begin();  }
    iterator end()    { return this->c.end();    }
    const_iterator begin() const { return this->c.begin();  }
    const_iterator end()   const { return this->c.end();    }
};

#endif