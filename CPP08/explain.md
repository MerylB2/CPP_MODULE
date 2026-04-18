# CPP Module 08 - Explications détaillées

Thème : **Templated containers, iterators, algorithms**
C'est le module où la STL est enfin autorisée et obligatoire.

---

## Notion 1 : Les conteneurs STL

Un conteneur STL est une classe template qui stocke des données.
Il en existe plusieurs familles :

### Conteneurs séquentiels (ordre d'insertion conservé)

| Conteneur     | Description                                      | Accès aléatoire |
|---------------|--------------------------------------------------|-----------------|
| `std::vector` | Tableau dynamique (comme Array<T> de CPP07)      | Oui (`[]`)      |
| `std::list`   | Liste doublement chaînée                         | Non             |
| `std::deque`  | File double (vector amélioré)                    | Oui (`[]`)      |

### Conteneurs adaptateurs (wrappent un autre conteneur)

| Conteneur     | Description                              | Itérable ? |
|---------------|------------------------------------------|------------|
| `std::stack`  | Pile LIFO (Last In, First Out)           | Non        |
| `std::queue`  | File FIFO (First In, First Out)          | Non        |

### Conteneurs associatifs (clé → valeur)

| Conteneur  | Description                        |
|------------|------------------------------------|
| `std::map` | Dictionnaire trié par clé          |
| `std::set` | Ensemble de clés uniques triées    |

---

## Notion 2 : Les itérateurs

Un itérateur est un objet qui "pointe" vers un élément dans un conteneur.
Il se comporte comme un pointeur.

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};

std::vector<int>::iterator it = v.begin();  // pointe vers 1
std::cout << *it;   // affiche 1 (déréférencement)
++it;               // avance vers 2
std::cout << *it;   // affiche 2

it = v.end();       // pointe APRES le dernier élément (pas sur 5 !)
```

### Les deux bornes fondamentales

```
v = [1, 2, 3, 4, 5]
     ^              ^
  begin()         end()
  (premier)       (après le dernier — jamais déréférencé)
```

### Types d'itérateurs

```cpp
std::vector<int>::iterator       it;   // lecture + écriture
std::vector<int>::const_iterator it;   // lecture seule
```

### Boucle complète avec itérateur

```cpp
std::vector<int> v = {10, 20, 30};

for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";
// Affiche : 10 20 30
```

---

## Notion 3 : Les algorithmes STL (#include <algorithm>)

Les algorithmes STL travaillent sur des plages d'itérateurs [begin, end).

### std::find

Cherche la première occurrence d'une valeur dans [begin, end).
Retourne un itérateur sur l'élément trouvé, ou `end` si non trouvé.

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {3, 7, 2, 9, 1};

std::vector<int>::iterator it = std::find(v.begin(), v.end(), 9);

if (it != v.end())
    std::cout << "Trouvé : " << *it;  // Trouvé : 9
else
    std::cout << "Non trouvé";
```

### std::min_element / std::max_element

Retournent un itérateur vers le plus petit / plus grand élément.

```cpp
std::vector<int> v = {3, 7, 2, 9, 1};

std::vector<int>::iterator minIt = std::min_element(v.begin(), v.end());
std::vector<int>::iterator maxIt = std::max_element(v.begin(), v.end());

std::cout << *minIt;  // 1
std::cout << *maxIt;  // 9
```

---

## Notion 4 : Passer des itérateurs en paramètre (template)

Un des grands avantages des itérateurs : on peut écrire des fonctions
qui acceptent n'importe quel type de conteneur via deux itérateurs.

```cpp
// Fonctionne avec vector, list, deque...
template <typename InputIterator>
void addRange(InputIterator begin, InputIterator end)
{
    for (InputIterator it = begin; it != end; ++it)
        addNumber(*it);
}

// Appel :
std::vector<int> src = {1, 2, 3, 4, 5};
span.addRange(src.begin(), src.end());
```

---

## Notion 5 : std::stack et son conteneur sous-jacent

`std::stack` n'est pas un vrai conteneur : c'est un adaptateur
qui utilise `std::deque` par défaut en interne.

```cpp
template <typename T, typename Container = std::deque<T> >
class stack
{
protected:
    Container c;  // <-- le conteneur sous-jacent, accessible aux classes filles
public:
    void push(const T& val) { c.push_back(val); }
    void pop()              { c.pop_back(); }
    T& top()                { return c.back(); }
    bool empty() const      { return c.empty(); }
    size_t size() const     { return c.size(); }
    // Pas de begin()/end() -> non itérable !
};
```

Le membre `c` est **protected**, donc accessible depuis une classe fille.
C'est ce qui permet à MutantStack d'exposer les itérateurs de `c`.

---

## Notion 6 : Héritage d'un conteneur STL

Pour ex02, on hérite de `std::stack<T>` pour lui ajouter begin()/end() :

```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // begin() et end() délèguent au conteneur sous-jacent c
    typename std::stack<T>::container_type::iterator begin()
    { return this->c.begin(); }

    typename std::stack<T>::container_type::iterator end()
    { return this->c.end(); }
};
```

`container_type` est un typedef défini dans `std::stack` qui vaut
`std::deque<T>` par défaut. On récupère ainsi son type d'itérateur.

---

## ex00 — Easy find

### Objectif

Écrire une fonction template `easyfind` qui cherche un entier
dans un conteneur de séquence (vector, list, deque...).

### Signature

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value);
```

- `T` = le type du conteneur (ex: `std::vector<int>`)
- `T::iterator` = le type d'itérateur du conteneur
- `value` = l'entier à trouver

### Implémentation

```cpp
#include <algorithm>   // std::find
#include <stdexcept>   // std::runtime_error

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}
```

### Appel

```cpp
std::vector<int> v = {3, 7, 42, 9};

try {
    std::vector<int>::iterator it = easyfind(v, 42);
    std::cout << "Trouvé : " << *it;
} catch (std::exception& e) {
    std::cout << "Erreur : " << e.what();
}
```

### Pourquoi `typename T::iterator` ?

Quand `T` est un type template (pas encore connu), le compilateur
ne sait pas si `T::iterator` est un type ou une valeur statique.
Le mot-clé `typename` lui indique explicitement que c'est un type.

```cpp
typename T::iterator it;   // OK : indique que c'est un type
T::iterator it;            // ERREUR en C++98 dans un contexte template
```

---

## ex01 — Span

### Objectif

Classe `Span` qui stocke au plus N entiers dans un `std::vector<int>`,
avec calcul du plus court et du plus long écart entre les valeurs.

### Interface

```cpp
Span sp(5);          // max 5 éléments
sp.addNumber(6);     // ajoute 6
sp.addNumber(3);     // ajoute 3
sp.shortestSpan();   // retourne le plus petit écart entre deux valeurs
sp.longestSpan();    // retourne le plus grand écart (max - min)

// Ajout en masse via iterateurs
std::vector<int> src = {1, 2, 3, 4, 5};
sp.addRange(src.begin(), src.end());
```

### Calcul du shortestSpan

Algorithme : trier le vecteur, puis chercher la différence minimale
entre deux éléments adjacents.

```cpp
// Copie du vecteur trié
std::vector<int> sorted(_data);
std::sort(sorted.begin(), sorted.end());

int shortest = sorted[1] - sorted[0];
for (size_t i = 2; i < sorted.size(); ++i)
{
    int diff = sorted[i] - sorted[i - 1];
    if (diff < shortest)
        shortest = diff;
}
```

### Calcul du longestSpan

Trivial : max - min.

```cpp
int longest = *std::max_element(_data.begin(), _data.end())
            - *std::min_element(_data.begin(), _data.end());
```

### addRange avec itérateurs

```cpp
template <typename InputIterator>
void addRange(InputIterator begin, InputIterator end)
{
    for (InputIterator it = begin; it != end; ++it)
        addNumber(*it);
}
```

### Exceptions

- `addNumber` quand plein : throw `std::length_error`
- `shortestSpan` / `longestSpan` avec 0 ou 1 élément : throw `std::logic_error`

---

## ex02 — MutantStack

### Objectif

Rendre `std::stack<T>` itérable en héritant dedans et en exposant
les itérateurs du conteneur sous-jacent `c`.

### Structure de std::stack

```cpp
// Simplifié
template <typename T, typename Container = std::deque<T> >
class stack {
protected:
    Container c;    // conteneur interne accessible aux filles
};
```

### MutantStack

```cpp
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

    // Type aliases pour simplifier
    typedef typename std::stack<T>::container_type::iterator       iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end(); }
};
```

### Pourquoi `this->c` et pas juste `c` ?

Dans un template hérité d'un template, les noms du parent ne sont pas
visibles directement. Il faut `this->c` ou `std::stack<T>::c` pour
que le compilateur sache que c'est le membre hérité.

```cpp
// Dans un template :
c.begin();          // ERREUR : c non trouvé dans le scope courant
this->c.begin();    // OK : cherche dans la classe de base
```

### Utilisation

```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);

std::cout << mstack.top();  // 17

MutantStack<int>::iterator it  = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();

while (it != ite)
{
    std::cout << *it << std::endl;
    ++it;
}
```

### Vérification avec std::list

Le sujet demande de vérifier que le même code avec `std::list` donne
le même résultat (en remplaçant `push` par `push_back`) :

```cpp
std::list<int> lst;
lst.push_back(5);
lst.push_back(17);

for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    std::cout << *it << std::endl;
// Doit afficher la même chose que MutantStack
```

---

## Récapitulatif des includes nécessaires

| Header        | Contenu utilisé                              |
|---------------|----------------------------------------------|
| `<vector>`    | `std::vector`                                |
| `<list>`      | `std::list`                                  |
| `<deque>`     | `std::deque`                                 |
| `<stack>`     | `std::stack`                                 |
| `<algorithm>` | `std::find`, `std::sort`, `std::min_element`, `std::max_element` |
| `<stdexcept>` | `std::runtime_error`, `std::logic_error`, `std::length_error` |
