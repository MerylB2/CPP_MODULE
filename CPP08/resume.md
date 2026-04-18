# CPP Module 08 - Resume

Ce fichier sert de pense-bête pour résumer chaque exercice du module 08
et définir les notions essentielles liées aux conteneurs, itérateurs et algorithmes STL.

## Règles générales du module

- Compiler en `c++` avec `-Wall -Wextra -Werror`
- Le code doit rester compatible `-std=c++98`
- Pas de `printf`, `malloc`, `free`
- Pas de `using namespace`
- **STL autorisée et OBLIGATOIRE** (vector, list, deque, stack, algorithm...)
- Les classes doivent suivre l'Orthodox Canonical Form sauf indication contraire
- Les headers doivent être autonomes et protégés contre les doubles inclusions
- `nullptr` est C++11 : utiliser `NULL` en C++98

---

## Notion essentielle : les conteneurs STL

Un conteneur stocke des données. Les principaux séquentiels :

```cpp
std::vector<int>  v;    // tableau dynamique, accès aléatoire O(1)
std::list<int>    l;    // liste doublement chaînée, pas d'accès aléatoire
std::deque<int>   d;    // double queue, accès aléatoire + insertion aux deux bouts
std::stack<int>   s;    // pile LIFO, non itérable nativement
```

## Notion essentielle : les itérateurs

Un itérateur se comporte comme un pointeur vers un élément du conteneur.

```cpp
std::vector<int> v = {1, 2, 3};

std::vector<int>::iterator it = v.begin();  // premier element
// v.end() pointe APRES le dernier — ne jamais le dereferencer

*it;    // lire la valeur
++it;   // avancer
it != v.end();  // condition d'arrêt
```

## Notion essentielle : les algorithmes (#include <algorithm>)

```cpp
std::find(begin, end, value);          // retourne iterator ou end si non trouve
std::min_element(begin, end);          // retourne iterator vers le min
std::max_element(begin, end);          // retourne iterator vers le max
std::sort(begin, end);                 // tri croissant en place
```

## Notion essentielle : typename dans un template

Dans un contexte template, `T::iterator` est ambigu pour le compilateur.
Il faut `typename` pour préciser que c'est un type :

```cpp
typename T::iterator it = container.begin();  // OK
T::iterator it = container.begin();           // ERREUR en C++98 template
```

---

## ex00 - Easy find

### Objectif

Fonction template `easyfind` qui cherche un entier dans n'importe quel
conteneur de séquence (vector, list, deque...) via `std::find`.

### Implementation

```cpp
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}
```

### A retenir pour la soutenance

- `std::find` retourne `end()` si non trouvé — toujours tester avant de déréférencer
- `typename T::iterator` obligatoire dans un template (sinon erreur de compilation)
- Fonctionne avec tout conteneur séquentiel : pas les associatifs (map, set)
- Throw exception si non trouvé (le sujet autorise aussi retourner une valeur d'erreur)

---

## ex01 - Span

### Objectif

Classe `Span(unsigned int N)` stockant au plus N entiers dans un `std::vector<int>`.
Calcule le plus court et le plus long écart entre les valeurs.

### Interface requise

```cpp
Span sp(5);
sp.addNumber(6);         // ajoute 1 nombre, throw si plein
sp.shortestSpan();       // plus petit écart entre deux valeurs quelconques
sp.longestSpan();        // max - min
sp.addRange(it1, it2);   // ajoute une plage via itérateurs
```

### Calculs

```cpp
// longestSpan : max - min
*std::max_element(_data.begin(), _data.end())
- *std::min_element(_data.begin(), _data.end())

// shortestSpan : tri puis diff minimale entre adjacents
std::vector<int> sorted(_data);
std::sort(sorted.begin(), sorted.end());
// puis boucle sur sorted[i] - sorted[i-1]
```

### addRange template

```cpp
template <typename InputIterator>
void addRange(InputIterator begin, InputIterator end)
{
    for (InputIterator it = begin; it != end; ++it)
        addNumber(*it);
}
```

### Exceptions

- `addNumber` quand N atteint : `throw std::length_error`
- `shortestSpan` / `longestSpan` avec 0 ou 1 element : `throw std::logic_error`

### A retenir pour la soutenance

- `std::sort` trie en place, donc on travaille sur une copie pour shortestSpan
- `addRange` est template pour accepter n'importe quel type d'itérateur
- Tester avec 10 000+ nombres via `addRange` (le sujet l'exige)
- shortestSpan nécessite au moins 2 éléments pour avoir un écart

---

## ex02 - MutantStack

### Objectif

`std::stack<T>` est non itérable. Créer `MutantStack<T>` qui hérite de
`std::stack<T>` et expose les itérateurs du conteneur interne `c`.

### Structure de std::stack

```cpp
template <typename T, typename Container = std::deque<T> >
class stack {
protected:
    Container c;   // conteneur sous-jacent, accessible aux filles
};
```

### Implementation

```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator       iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end(); }
};
```

### this->c obligatoire dans un template

```cpp
c.begin();        // ERREUR : nom de la base non visible dans un template
this->c.begin();  // OK : force la recherche dans la classe de base
```

### Utilisation

```cpp
MutantStack<int> ms;
ms.push(5);
ms.push(17);

MutantStack<int>::iterator it = ms.begin();
while (it != ms.end())
    std::cout << *it++ << std::endl;
```

### Verification avec std::list

Le sujet demande de vérifier que le même affichage est obtenu avec `std::list`
(en remplaçant `push` par `push_back`) — les deux doivent produire le même résultat.

### A retenir pour la soutenance

- `std::stack` n'est pas itérable nativement : pas de `begin()`/`end()`
- Le membre `c` (conteneur interne) est `protected` → accessible depuis la classe fille
- `this->c` obligatoire dans un template hérité d'un template
- `container_type` est le typedef de `std::stack` pour le type du conteneur interne
- `typedef typename ...::iterator` pour créer un alias de type dépendant d'un template
- L'héritage donne automatiquement toutes les méthodes de `std::stack` (push, pop, top, size...)
