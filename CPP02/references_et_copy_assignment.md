# Références et Copy Assignment Operator en C++

## Le référencement (`&`)

Le `&` a deux usages principaux :

### 1. Obtenir l'adresse mémoire d'une variable
```cpp
int x = 42;
int* ptr = &x;  // ptr contient l'adresse de x
```

### 2. Déclarer une référence (alias)
```cpp
int x = 42;
int& ref = x;  // ref est un alias de x, pas une copie

ref = 100;     // modifie x directement
std::cout << x; // affiche 100
```

Une référence c'est comme un **deuxième nom** pour la même variable. Pas de copie, pas de nouvelle mémoire allouée.

**Utilité principale** : éviter les copies coûteuses dans les paramètres de fonction :
```cpp
void afficher(const std::string& s);  // pas de copie de la string
```

---

## Le Copy Assignment Operator (`operator=`)

C'est l'opérateur qui définit ce qui se passe quand tu fais :
```cpp
Fixed a;
Fixed b;
b = a;  // <-- copy assignment operator appelé ici
```

### Signature typique :
```cpp
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)  // évite l'auto-affectation (a = a)
    {
        this->_value = other._value;  // copie les attributs
    }
    return *this;  // retourne une référence sur l'objet courant
}
```

### Pourquoi retourner `Fixed&` ?
Pour permettre les affectations chaînées :
```cpp
a = b = c;  // c est copié dans b, puis b est copié dans a
```

### Différence avec le constructeur de copie :
```cpp
Fixed a;       
Fixed b(a);   // constructeur de copie (création)
Fixed c = a;  // constructeur de copie aussi (création)

Fixed d;
d = a;        // copy assignment operator (objet déjà existant)
```

| Situation | Opérateur appelé |
|-----------|------------------|
| `Fixed b(a);` | Constructeur de copie |
| `Fixed b = a;` | Constructeur de copie |
| `b = a;` (b existe déjà) | Copy assignment operator |

---

## L'opérateur d'insertion (`operator<<`)

Permet d'utiliser `std::cout` avec ta classe :
```cpp
Fixed a(42.5f);
std::cout << a << std::endl;  // affiche la valeur de a directement
```

Sans cette surcharge, `std::cout << a` ne compilerait pas.

### Signature :
```cpp
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
```

| Partie | Signification |
|--------|---------------|
| `std::ostream&` | Retourne le flux pour chaîner : `cout << a << b` |
| `std::ostream &out` | Le flux de sortie (cout, fichier, etc.) |
| `const Fixed &fixed` | L'objet à afficher (const car on ne le modifie pas) |

### Implémentation typique :
```cpp
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
```

---

## L'Epsilon (ε) - Plus petite valeur représentable

L'epsilon est la plus petite valeur ε telle que `1 + ε > 1`.

### Pour la classe Fixed (8 bits fractionnaires)
```
ε = 1 / 2^8 = 1 / 256 = 0.00390625
```
C'est la plus petite "marche" possible entre deux valeurs.

### Pour les types standards C++

| Type | Epsilon |
|------|---------|
| `float` | ~1.19 × 10⁻⁷ |
| `double` | ~2.22 × 10⁻¹⁶ |

```cpp
#include <limits>
std::numeric_limits<float>::epsilon();   // 1.19209e-07
std::numeric_limits<double>::epsilon();  // 2.22045e-16
```

Pour le projet Fixed avec 8 bits fractionnaires : **ε = 0.00390625** (ou `1.0f / 256`).
