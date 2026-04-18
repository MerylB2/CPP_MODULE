# CPP Module 07 - Resume

Ce fichier sert de pense-bete pour resumer chaque exercice du module 07
et definir les notions essentielles liees aux templates C++.

## Regles generales du module

- Compiler en `c++` avec `-Wall -Wextra -Werror`
- Le code doit rester compatible `-std=c++98`
- Pas de `printf`, `malloc`, `free`
- Pas de `using namespace`
- Pas de STL sur ce module (pas de vector, map, algorithm...)
- Les classes doivent suivre l'Orthodox Canonical Form sauf si le sujet dit le contraire
- Les headers doivent etre autonomes et proteges contre les doubles inclusions
- **Les templates doivent etre definis dans les headers** (pas dans les .cpp)
- `nullptr` est C++11 : utiliser `NULL` ou `0` en C++98

---

## Notion essentielle : les templates

Un template permet d'ecrire du code generique qui fonctionne avec n'importe quel type.
Le compilateur genere automatiquement la bonne version selon le type utilise.

### Fonction template

```cpp
template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

min(2, 3);          // T = int,         retourne 2
min(2.5, 1.1);      // T = double,      retourne 1.1
min("a", "b");      // T = std::string, retourne "a"
```

### Classe template

```cpp
template <typename T>
class Array
{
    T* _data;
    // ...
};

Array<int>    a;   // tableau d'entiers
Array<float>  b;   // tableau de flottants
```

### Pourquoi tout dans le header ?

Le compilateur a besoin de voir la definition complete du template au moment ou il
l'instancie. Si l'implementation est dans un `.cpp` separe, le compilateur ne la
voit pas depuis un autre fichier et refuse de generer la version concrete.

Exception : les fichiers `.tpp` qui sont `#include`-s directement a la fin du header.

### Plusieurs parametres template

```cpp
template <typename T, typename F>
void iter(T* array, size_t len, F func);
// T = type des elements
// F = type de la fonction (deduit automatiquement)
```

### Instanciation explicite d'un template

Quand une fonction template est passee comme argument, le compilateur ne peut pas
deduire son type tout seul. Il faut l'instancier explicitement :

```cpp
template <typename T>
void print(T& x) { std::cout << x; }

iter(arr, 3, print);         // ERREUR : T non deductible
iter(arr, 3, print<int>);    // OK : instanciation explicite
```

---

## ex00 - Start with a few functions

### Objectif

Implementer trois fonctions template dans `whatever.hpp` :
- `swap` : echange les valeurs de deux variables
- `min`  : retourne le plus petit (si egaux, retourne le second)
- `max`  : retourne le plus grand (si egaux, retourne le second)

### Implementation

```cpp
template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;  // si egaux : a < b est faux -> retourne b (le second)
}

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;  // si egaux : a > b est faux -> retourne b (le second)
}
```

### Appel depuis le main

Le `::` indique le namespace global (pas de classe, pas de namespace std) :

```cpp
::swap(a, b);
::min(a, b);
::max(a, b);
```

### Contrainte

Les deux arguments doivent avoir le **meme type** et supporter les operateurs
de comparaison (`<`, `>`). Fonctionne avec int, float, std::string...

### A retenir pour la soutenance

- Les templates sont dans le header car le compilateur doit voir la definition
  complete au moment de l'instanciation
- `min(a, b)` quand a == b : `a < b` est faux, donc retourne `b` (le second) — conforme au sujet
- `max(a, b)` quand a == b : `a > b` est faux, donc retourne `b` (le second) — conforme au sujet
- Le `::` devant l'appel signifie "namespace global" — evite toute ambiguite avec std::min/std::max

---

## ex01 - Iter

### Objectif

Implementer une fonction template `iter` qui applique une fonction
a chaque element d'un tableau.

```cpp
template <typename T, typename F>
void iter(T* array, size_t len, F func)
{
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}
```

### Les 3 parametres

| Parametre | Type     | Role                                 |
|-----------|----------|--------------------------------------|
| `array`   | `T*`     | adresse du tableau                   |
| `len`     | `size_t` | nombre d'elements (passe par valeur) |
| `func`    | `F`      | fonction appelee sur chaque element  |

### Pourquoi deux parametres template (T et F) ?

La premiere version avec un seul template ne fonctionnait pas :

```cpp
// VERSION 1 — INCORRECTE
template <typename T>
void iter(T* array, size_t len, void (*func)(T&))
// probleme 1 : func ne peut pas prendre const T&
// probleme 2 : func ne peut pas etre un template non instancie
```

La solution est de faire de `F` un parametre template independant :

```cpp
// VERSION 2 — CORRECTE
template <typename T, typename F>
void iter(T* array, size_t len, F func)
// F est deduit automatiquement par le compilateur
// accepte n'importe quelle signature compatible
```

### Instanciation explicite obligatoire

`print_arr` est un template — quand on le passe comme argument, il faut
specifier le type car le compilateur ne peut pas le deduire tout seul :

```cpp
template <typename T>
void print_arr(T& x) { std::cout << x << " "; }

iter(intArray, 6, print_arr<int>);         // OK
iter(strArray, 4, print_arr<std::string>); // OK
iter(intArray, 6, print_arr);              // ERREUR : T de print_arr non deductible
```

### const et non-const

Avec `F` comme parametre template, `iter` accepte les deux :

```cpp
void affiche(const int& x) { std::cout << x; }  // const ref -> OK
void double_val(int& x)    { x *= 2; }           // non-const ref -> OK

iter(arr, 3, affiche);     // F = void(*)(const int&)
iter(arr, 3, double_val);  // F = void(*)(int&)
```

### A retenir pour la soutenance

- `T` est le type des elements du tableau, `F` est le type de la fonction
- Deux parametres template pour accepter n'importe quelle signature de fonction
- Un template passe comme argument doit etre instancie explicitement : `print_arr<int>`
- `size_t` est le bon type pour une taille de tableau (toujours positif)
- La version a un seul template `void (*func)(T&)` est incomplete : elle refuse `const T&`
  et refuse les fonctions template non instanciees

---

## ex02 - Array

### Objectif

Implementer une classe template `Array<T>` qui se comporte comme un tableau
dynamique securise.

### Interface requise par le sujet

```cpp
Array<int> a;           // tableau vide
Array<int> b(5);        // 5 entiers initialises par defaut (0 pour int)
Array<int> c(b);        // copie profonde
c = b;                  // affectation profonde
b[0];                   // acces par subscript
b[999];                 // leve std::exception si hors bornes
b.size();               // retourne le nombre d'elements (const)
```

### Structure des fichiers

```
includes/
  Array.hpp   <- declaration de la classe + #include "Array.tpp" a la fin
  Array.tpp   <- implementation de toutes les methodes
srcs/
  main.cpp    <- seul fichier compile (Array.tpp n'est JAMAIS dans SRC)
```

`Array.hpp` contient uniquement la declaration :

```cpp
template <typename T>
class Array
{
    private:
        T*     _array;
        size_t _size;
    public:
        Array();
        Array(size_t n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        T&       operator[](size_t index);
        const T& operator[](size_t index) const;
        size_t   size() const;
};

#include "Array.tpp"  // inclus a la fin du header, pas compile separement
```

`Array.tpp` contient l'implementation de chaque methode :

```cpp
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(size_t n) : _array(new T[n]()), _size(n) {}

// ... etc
```

### Erreurs a eviter dans le Makefile

```makefile
SRC = main.cpp Array.tpp   # FAUX : Array.tpp n'est pas un .cpp
SRC = main.cpp             # CORRECT
```

Si `Array.tpp` est mis dans `SRC`, make essaie de le compiler comme un `.cpp`
et echoue car le pattern `%.o: %.cpp` ne matche pas les `.tpp`.

### new T[n]() — initialisation par defaut

Le `()` apres `new T[n]` initialise les elements a leur valeur par defaut :
- `int` → 0
- `float` → 0.0f
- `std::string` → ""

Sans `()`, les elements auraient des valeurs indeterminees pour les types primitifs.

### Copie profonde (deep copy)

La copie profonde alloue un nouveau tableau et copie les valeurs une par une.
Modifier la copie ne modifie pas l'original.

```cpp
Array<int> a(3);  a[0] = 42;
Array<int> b(a);  b[0] = 99;  // a[0] est toujours 42
```

Sans deep copy (shallow copy), `a` et `b` partageraient le meme `_array`
et modifier l'un modifierait l'autre — et le destructeur libererait
deux fois la meme memoire (double free).

### operator[] const et non-const

Deux surcharges sont necessaires :
- La version non-const : permet de lire et ecrire `arr[0] = 42`
- La version const : permet la lecture seule sur un objet `const Array<T>`

```cpp
Array<int> a(3);
a[0] = 42;                    // appelle T& operator[]

const Array<int> b(a);
std::cout << b[0];            // appelle const T& operator[] const
// b[0] = 99;                 // ERREUR de compilation : objet const
```

### numbers[-2] → exception

`-2` est un `int` negatif converti en `size_t` (type non signe)
→ devient une tres grande valeur positive
→ superieure a `_size`
→ exception levee

Le comportement est correct sans traitement special.

### nullptr interdit en C++98

```cpp
Array() : _array(nullptr), _size(0) {}  // ERREUR : nullptr est C++11
Array() : _array(NULL), _size(0) {}     // CORRECT en C++98
```

### A retenir pour la soutenance

- `new T[n]()` : le `()` initialise les elements a leur valeur par defaut
- La copie profonde est obligatoire : chaque instance possede son propre tableau
- `operator[]` existe en deux versions : `T&` (non-const) et `const T&` (const)
- `size_t` est non signe : passer `-2` depasse automatiquement `_size` → exception
- Le `.tpp` est dans `includes/`, inclus par `Array.hpp`, jamais compile directement
- `delete[]` dans le destructeur : indispensable pour eviter les fuites memoire
- `nullptr` est interdit en C++98 : utiliser `NULL`
