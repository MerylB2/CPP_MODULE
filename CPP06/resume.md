# CPP Module 06 - Resume

Ce fichier sert de pense-bete pour resumer chaque exercice du module 06
et definir les notions essentielles liees aux casts C++.

## Regles generales du module

- Compiler en `c++` avec `-Wall -Wextra -Werror`
- Le code doit rester compatible `-std=c++98`
- Pas de `printf`, `malloc`, `free`
- Pas de `using namespace`
- Pas de STL sur ce module
- Les classes doivent suivre l'Orthodox Canonical Form, sauf si le sujet
  dit le contraire (ex02 : les classes A, B, C, Base en sont dispensees)
- Les headers doivent etre autonomes et proteges contre les doubles inclusions

### Regle supplementaire du module

**Chaque exercice doit utiliser un type de cast specifique.**
Ce choix sera justifie a la soutenance.

- ex00 : `static_cast`
- ex01 : `reinterpret_cast`
- ex02 : `dynamic_cast`

---

## Notions essentielles : les 4 casts C++

### `static_cast`

Conversion explicite entre types compatibles connue a la compilation.

- Utilise pour convertir entre types numeriques (`int` -> `float`, etc.)
- Verifie la compatibilite des types a la compilation
- Pas de verification a l'execution
- Remplace les cast C-style `(int)x` de facon plus lisible et sure

```cpp
int i = 42;
float f = static_cast<float>(i);
```

Cas d'usage : conversions scalaires, cast vers/depuis une classe de base
(sans polymorphisme), cast d'enum vers int.

---

### `reinterpret_cast`

Reinterprete les bits bruts d'une valeur comme un autre type.

- N'effectue aucune conversion : il relit simplement les memes octets
  sous un type different
- Tres bas niveau, potentiellement dangereux
- Utilise pour convertir un pointeur en entier et vice-versa (`uintptr_t`)
- Ne doit pas etre utilise pour des conversions numeriques ordinaires

```cpp
int* ptr = &i;
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
int* back = reinterpret_cast<int*>(raw);
```

Cas d'usage : serialisation de pointeurs, acces memoire bas niveau.

---

### `dynamic_cast`

Cast verifie a l'execution dans une hierarchie de classes polymorphes.

- Necessite au moins une fonction virtuelle dans la classe de base
- Retourne `NULL` (sur pointeur) ou leve `std::bad_cast` (sur reference)
  si le cast echoue
- Permet d'identifier le vrai type d'un objet via sa classe de base
- Plus lent que `static_cast` car verifie a l'execution (RTTI)

```cpp
Base* ptr = new A();
A* a = dynamic_cast<A*>(ptr); // non-NULL si ptr pointe bien vers un A
```

Cas d'usage : identifier le type reel d'un objet polymorphe,
downcast sur une hierarchie.

---

### `const_cast`

Ajoute ou retire le qualificateur `const` d'un type.

- Utile pour appeler une fonction non-const avec un objet const
- Modifier un objet reellement const via `const_cast` est un comportement
  indefini
- Rarement necessaire dans du bon code C++

```cpp
const int x = 42;
int* p = const_cast<int*>(&x); // retire le const
```

---

## ex00 - Conversion of scalar types

### Objectif

Creer une classe `ScalarConverter` avec une seule methode statique `convert()`
qui prend une `std::string` representant un litteral C++ et l'affiche converti
en `char`, `int`, `float` et `double`.

### Pourquoi la classe n'est pas instanciable

Le sujet precise que la classe ne doit pas pouvoir etre instanciee.
Pour cela, tous les constructeurs et l'operateur d'affectation sont declares
`private`.

```cpp
class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string &input);
};
```

### Types d'entree a reconnaitre

| Type    | Exemples              | Detection                              |
|---------|-----------------------|----------------------------------------|
| char    | `a`, `Z`, `+`         | longueur 1 et non numerique            |
| int     | `0`, `-42`, `42`      | `strtol` sans reste, dans INT range    |
| float   | `0.0f`, `-4.2f`       | `strtof` suivi exactement de `f`       |
| double  | `0.0`, `-4.2`, `4.2`  | `strtod` sans reste, contient un `.`   |

### Pseudo-litteraux a gerer

| Input                      | float   | double |
|----------------------------|---------|--------|
| `nan` ou `nanf`            | `nanf`  | `nan`  |
| `+inf`, `+inff`, `inf`, `inff` | `+inff` | `+inf` |
| `-inf` ou `-inff`          | `-inff` | `-inf` |

Pour les pseudo-litteraux : `char` et `int` sont toujours `impossible`.

### Regles d'affichage

- Si `char` est non affichable (`!isprint`) : `char: Non displayable`
- Si la conversion n'a pas de sens ou deborde : `char: impossible`, etc.
- Les `float` s'affichent avec `f` en suffixe : `42.0f`
- Precision minimale a 1 decimal : `std::fixed << std::setprecision(1)`

### Exemple de sortie attendue (sujet)

```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

### Cast utilise

`static_cast` pour toutes les conversions numeriques :

```cpp
static_cast<int>(c)
static_cast<float>(i)
static_cast<double>(f)
```

### Logique de detection dans `convert()`

La detection suit un ordre strict avec retour immediat des qu'un type est trouvé :

```
pseudoLiterals -> isChar -> isInt -> isFloat -> isDouble
```

Si aucun type ne correspond : tout affiche `impossible`.

### A retenir pour la soutenance

- La classe ne peut pas etre instanciee : tous les constructeurs sont prives
- Le cast utilise est `static_cast` : conversion sure et explicite entre
  types numeriques compatibles
- La detection du type se fait depuis la forme de la string, pas depuis
  le type C++ lui-meme
- `0` est un int, `0.0` est un double, `0.0f` est un float, `'\0'` est un char

---

## ex01 - Serialization

*(a completer)*

---

## ex02 - Identify real type

*(a completer)*
