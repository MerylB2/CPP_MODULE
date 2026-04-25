# CPP Module 08 - Resume

Ce fichier sert de pense-bête pour résumer chaque exercice du module 08
et définir les notions essentielles liées aux conteneurs, itérateurs et algorithmes STL.

## STL — Standard Template Library

Bibliothèque standard du C++ composée de trois piliers :

- **Conteneurs** — structures de données prêtes à l'emploi (`vector`, `list`, `map`, `stack`...)
- **Itérateurs** — objets pour parcourir les conteneurs (se comportent comme des pointeurs)
- **Algorithmes** — fonctions génériques (`sort`, `find`, `min_element`...)

Le mot **Template** vient du fait que tout est implémenté avec des templates :
`std::vector<int>`, `std::vector<std::string>`... une seule implémentation, tous les types.

---

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

### Robustesse du main — gestion cin avec getline

**Problème avec `cin >>`** : lit token par token, pas ligne par ligne.
`"1 abc"` → cin lit `1` (succès), `"abc"` reste dans le buffer et empoisonne
les lectures suivantes → comportement imprévisible.

**Solution : `getline` + `istringstream`** (C++98 compatible)

```cpp
#include <sstream>  // std::istringstream, std::ostringstream

static bool readInt(const std::string& prompt, int& out)
{
    std::string line;
    std::cout << prompt;
    if (!std::getline(std::cin, line))  // lit toute la ligne
        return false;
    std::istringstream iss(line);
    char extra;
    // si extra peut etre lu, il reste du contenu ("1 abc" → invalide)
    if (!(iss >> out) || iss >> extra)
        return false;
    return true;
}
```

`getSize` redemande tant que la saisie est invalide :
```cpp
static size_t getSize(const std::string& prompt)
{
    int n;
    while (true)
    {
        if (!readInt(prompt, n) || n < 0)
            std::cout << "Invalid input, entrez un entier positif." << std::endl;
        else
            return static_cast<size_t>(n);
    }
}
```

`ostringstream` pour construire le prompt avec l'index (compatible C++98) :
```cpp
std::ostringstream oss;
oss << "  vec[" << i << "] : ";
readInt(oss.str(), val);
```

**Pourquoi `iss >> extra` et pas `iss.peek() != EOF` ?**
`std::char_traits<char>::eof()` est techniquement C++98 mais lourd.
`iss >> extra` est plus simple : si on peut lire un char supplémentaire,
il reste du contenu → invalide.

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

Permet d'ajouter plusieurs nombres d'un coup via deux itérateurs,
au lieu d'appeler `addNumber` une fois par valeur. Obligatoire pour
tester avec 10 000+ nombres sans écrire 10 000 appels.

```cpp
template <typename InputIterator>
void addRange(InputIterator begin, InputIterator end)
{
    for (InputIterator it = begin; it != end; ++it)
        addNumber(*it);
}
```

Sans addRange — ingérable :
```cpp
sp.addNumber(1);
sp.addNumber(2);
// ... 9998 appels de plus
```

Avec addRange — en une ligne :
```cpp
std::vector<int> src;
// remplir src...
sp.addRange(src.begin(), src.end());  // ajoute tout d'un coup
```

C'est un template pour accepter n'importe quel type d'itérateur
(vector, list, deque...) avec une seule implémentation.

### Exemple du sujet et vérification

```cpp
Span sp(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
sp.shortestSpan();  // → 2
sp.longestSpan();   // → 14
```

Après tri : {3, 6, 9, 11, 17}
- shortestSpan : 11 - 9 = 2 (écart minimal entre adjacents)
- longestSpan  : 17 - 3 = 14 (max - min)

### Exceptions

- `addNumber` quand N atteint : `throw std::length_error`
- `shortestSpan` / `longestSpan` avec 0 ou 1 element : `throw std::length_error`

### Overflow — retourner long au lieu de int

`shortestSpan` et `longestSpan` retournent `long` pour eviter l'overflow :

```cpp
// Si on stocke INT_MIN (-2147483648) et INT_MAX (2147483647) :
int result = INT_MAX - INT_MIN;   // OVERFLOW : depasse int
long result = (long)INT_MAX - INT_MIN;  // OK : tient dans long
```

Le type de retour dans le header doit etre `long` :
```cpp
long shortestSpan() const;
long longestSpan() const;
```

### size() — methode ajoutee

Non requise par le sujet mais utile pour verifier si le Span est plein
avant un test d'ajout :

```cpp
size_t Span::size() const { return _data.size(); }

// dans le main :
if (sp.size() == n)  // span vraiment plein → tester addNumber
    sp.addNumber(42);
```

### Robustesse du main — gestion cin

Meme principe que ex00 : `getSize` avec `cin.fail()` + `cin.clear()` + `cin.ignore`.
Compteur `added` pour savoir si la boucle s'est terminee normalement ou sur un break.

### A retenir pour la soutenance

- `std::sort` trie en place, donc on travaille sur une copie pour shortestSpan
- `addRange` est template pour accepter n'importe quel type d'itérateur
- Tester avec 10 000+ nombres via `addRange` (le sujet l'exige)
- shortestSpan nécessite au moins 2 éléments pour avoir un écart
- Retourner `long` pour eviter l'overflow avec INT_MIN/INT_MAX

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

### Robustesse du main — top() sur stack vide

`top()` sur un stack vide provoque un segfault (UB). Toujours verifier avec `empty()` :

```cpp
// ms.empty() herite de std::stack — top() sur stack vide = UB/segfault
if (!ms.empty())
    std::cout << ms.top() << std::endl;
else
    std::cout << "(stack vide)" << std::endl;
```

### Narrowing conversion size_t → unsigned int

`getSize` retourne `size_t` (64-bit). Le constructeur `Span(unsigned int N)`
attend un `unsigned int` (32-bit). Le code passe `n` directement sans cast :

```cpp
size_t n = getSize(...);
Span sp(n);              // conversion implicite size_t → unsigned int
for (size_t i = 0; i < n; ++i)
```

Pas de problème en pratique car `getSize` lit dans un `int` d'abord —
la valeur est donc toujours <= INT_MAX, qui tient dans `unsigned int`.

### Points cles a retenir

- `std::stack<T>` a un membre `protected c` — le conteneur interne (`std::deque<T>` par défaut)
- `this->c` obligatoire (pas juste `c`) dans un template hérité d'un template :
  ```cpp
  c.begin();        // ERREUR : nom de la base non visible dans un template
  this->c.begin();  // OK
  ```
- `container_type` = typedef de `std::stack` pour le type du conteneur interne
- `typedef typename ...` pour créer un alias sur un type dépendant d'un template :
  ```cpp
  typedef typename std::stack<T>::container_type::iterator iterator;
  ```

### A retenir pour la soutenance

- `std::stack` n'est pas itérable nativement : pas de `begin()`/`end()`
- Le membre `c` (conteneur interne) est `protected` → accessible depuis la classe fille
- `this->c` obligatoire dans un template hérité d'un template
- `container_type` est le typedef de `std::stack` pour le type du conteneur interne
- `typedef typename ...::iterator` pour créer un alias de type dépendant d'un template
- L'héritage donne automatiquement toutes les méthodes de `std::stack` (push, pop, top, size...)

---

## Cas de tests

### ex00 — easyfind

| Test | Taille | Valeurs | Chercher | Résultat attendu |
|---|---|---|---|---|
| Trouvé normal | 5 | 3 7 42 9 1 | 42 | Found |
| Non trouvé | 5 | 3 7 42 9 1 | 99 | exception |
| Conteneur vide | 0 | — | 5 | exception |
| 1 seul element, trouvé | 1 | 7 | 7 | Found |
| Valeur negative | 3 | -5 0 10 | -5 | Found |
| Saisie invalide (taille) | abc | — | — | "Invalid size input" |
| Saisie invalide (valeur) | 3 | 1 xyz | — | "Invalid input, skipping" |

### ex01 — Span

| Test | Capacite | Valeurs | Résultat attendu |
|---|---|---|---|
| Sujet exact | 5 | 6 3 17 9 11 | shortest=2, longest=14 |
| Span vide | testEdgeCases auto | — | exception |
| 1 element | testEdgeCases auto | — | exception |
| Tous identiques | 3 | 5 5 5 | shortest=0, longest=0 |
| Valeurs negatives | 3 | -10 0 10 | shortest=10, longest=20 |
| Overflow (long) | 2 | -2147483648 2147483647 | shortest=4294967295, longest=4294967295 |
| Saisie invalide | 3 | 1 abc | "Invalid input", puis exception si <2 |
| addRange 10 000 | auto | 0..9999 | shortest=1, longest=9999 |

Note : `shortestSpan` et `longestSpan` retournent `long` pour eviter l'overflow avec INT_MIN/INT_MAX.

### ex02 — MutantStack

| Test | Valeurs | Résultat attendu |
|---|---|---|
| Sujet exact | auto hardcode | 17 / 1 / 5 3 5 737 0 |
| Stack vide | 0 | "(stack vide)" |
| 1 valeur | 1 → 42 | top=42, size=1 |
| Saisie invalide taille | abc | "Invalid Input" |
| Saisie invalide valeur | 3 → 1 abc | "Invalid input !", size=1 |
