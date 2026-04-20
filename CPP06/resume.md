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
En C++98, un cast est une conversion de type — transformer une valeur d'un type en
un autre.
                                                                                   
---                                                                                
Les 4 casts C++98                                                                  
                                                                                   
1. static_cast — cast classique
```cpp                                                                                   
double x = 3.14;
int n = static_cast<int>(x);  // 3
```                                               
Utilisé pour conversions numériques, pointeurs liés par héritage. Le plus courant. 
                                                                                   
---                                                                                
2. dynamic_cast — cast polymorphique (runtime)                                     
```cpp                                                                                   
Animal* a = new Chien();
Chien* c = dynamic_cast<Chien*>(a);  // OK                                         
Chat* ch = dynamic_cast<Chat*>(a);   // retourne nullptr
```                          
Vérifie le type à l'exécution. Nécessite au moins une fonction virtuelle dans la
classe. Retourne nullptr si ça échoue (pointeurs) ou lève std::bad_cast            
(références).   
                                                                                   
---             
3. const_cast — enlève/ajoute const
```cpp                                                                                   
const int x = 42;
int* p = const_cast<int*>(&x);
```                                                    
Utilisé rarement — surtout pour interfacer avec du vieux code qui ne respecte pas  
const.                                                                             
                                                                                   
---                                                                                
4. reinterpret_cast — réinterprétation brute
```cpp                                                                                   
int n = 42;
char* p = reinterpret_cast<char*>(&n);
```                                             
Réinterprète les bits bruts. Dangereux, à éviter sauf cas très bas niveau.         
                                                                                   
---                                                                                
A éviter : le cast C-style                                                         
```cpp                                                                                   
int n = (int)3.14;  // fonctionne mais dangereux
```
Il fait n'importe lequel des 4 casts ci-dessus sans le dire — difficile à débugger.
                                                                                   
---                                                                                
Règle simple : utilise static_cast par défaut, dynamic_cast pour le polymorphisme, 
les autres rarement.

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

### Objectif

Creer une classe `Serializer` avec deux methodes statiques :
- `serialize(Data* ptr)` → convertit un pointeur en `uintptr_t`
- `deserialize(uintptr_t raw)` → reconvertit le `uintptr_t` en `Data*`

Puis verifier que le pointeur recupere apres deserialisation est identique
au pointeur original.

### Qu'est-ce que `uintptr_t`

`uintptr_t` est un type entier non signe garanti assez grand pour contenir
un pointeur. Il est defini dans `<stdint.h>` (C++98) ou `<cstdint>`.

Il permet de stocker une adresse memoire sous forme d'entier — c'est ce
qu'on appelle la serialisation d'un pointeur.

### Pourquoi `reinterpret_cast`

`reinterpret_cast` reinterprete les bits bruts d'une valeur sans aucune
conversion. C'est le seul cast capable de convertir un pointeur en entier
et vice-versa.

```cpp
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
```

`static_cast` ne peut pas faire cette conversion : il ne connait pas
de relation de type entre `Data*` et `uintptr_t`.

### La structure `Data`

Le sujet exige que `Data` soit non vide (au moins un membre).
Elle peut contenir plusieurs membres pour rendre le test plus expressif :

```cpp
struct Data
{
    int         value;
    double      ratio;
    std::string label;
};
```

### Ce que le test verifie

1. Creer un objet `Data` avec des valeurs
2. Serialiser son adresse → `uintptr_t`
3. Deserialiser → recuperer un `Data*`
4. Verifier que `&data == result` (meme adresse)
5. Verifier que les membres sont identiques

### A retenir pour la soutenance

- `reinterpret_cast` est utilise car il convertit des types sans relation
- `uintptr_t` garantit que l'entier est assez grand pour un pointeur
- La serialisation ne copie pas les donnees : elle stocke l'adresse
- `&data == result` doit etre `true` si la serialisation est correcte

---

## ex02 - Identify real type

### Objectif

Creer trois classes vides `A`, `B`, `C` heritant d'une classe de base `Base`
qui possede un destructeur virtuel. Implementer trois fonctions :
- `Base* generate(void)` : instancie aleatoirement A, B ou C et retourne un `Base*`
- `void identify(Base* p)` : identifie le vrai type via `dynamic_cast` sur pointeur
- `void identify(Base& p)` : identifie le vrai type via `dynamic_cast` sur reference

### Pourquoi le destructeur virtuel est obligatoire

`dynamic_cast` repose sur le RTTI (Run-Time Type Information), qui n'est disponible
que pour les classes polymorphes. Une classe est polymorphe si elle possede au moins
une fonction virtuelle. Le destructeur virtuel de `Base` suffit.

Sans lui, `dynamic_cast` ne compile pas sur une classe non-polymorphe.

### Pourquoi A, B, C ne suivent pas la forme canonique

Le sujet le precise explicitement : ces classes etant vides, la forme canonique
n'est pas requise. `Base` non plus.

### identify sur pointeur

`dynamic_cast<T*>(p)` retourne `NULL` si le cast echoue. On enchaine les tests :

```cpp
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        // c'est un A
    else if (dynamic_cast<B*>(p))
        // c'est un B
    else if (dynamic_cast<C*>(p))
        // c'est un C
}
```

### identify sur reference

`dynamic_cast<T&>(p)` leve `std::bad_cast` si le cast echoue.
On utilise un bloc try/catch par type, en ignorant silencieusement l'exception :

```cpp
void identify(Base& p)
{
    try { (void)dynamic_cast<A&>(p); /* c'est un A */ return; }
    catch(const std::exception&) {}

    try { (void)dynamic_cast<B&>(p); /* c'est un B */ return; }
    catch(const std::exception&) {}

    try { (void)dynamic_cast<C&>(p); /* c'est un C */ return; }
    catch(const std::exception&) {}
}
```

Les catch ne doivent pas afficher l'exception : c'est un echec attendu,
pas une erreur.

### generate()

Utilise `srand(time(NULL))` dans `main` et `rand() % 3` dans `generate` :

```cpp
Base* generate(void)
{
    switch (rand() % 3)
    {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
}
```

### A retenir pour la soutenance

- `dynamic_cast` necessite une classe polymorphe (au moins une fonction virtuelle)
- Sur pointeur : retourne `NULL` en cas d'echec → pas d'exception
- Sur reference : leve `std::bad_cast` en cas d'echec → try/catch obligatoire
- Les catch doivent etre silencieux car l'echec est prevu (on teste les types un par un)
- `delete` sur le `Base*` retourne par `generate` appelle bien le destructeur
  de la classe derivee grace au destructeur virtuel
