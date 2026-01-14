# Orthodox Canonical Form (OCF) en C++

## Définition

La **Orthodox Canonical Form** est un ensemble de 4 méthodes fondamentales que toute classe C++ bien conçue devrait implémenter pour gérer correctement la copie et l'affectation d'objets.

## Les 4 Composants de l'OCF

### 1. Constructeur par Défaut
```cpp
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
```
- **Rôle** : Initialise un objet sans paramètres
- **Quand utilisé** : `Fixed a;` ou `Fixed a = Fixed();`
- **Important** : Doit initialiser tous les attributs à des valeurs par défaut sensées

### 2. Destructeur
```cpp
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
```
- **Rôle** : Nettoie les ressources allouées par l'objet
- **Quand appelé** : Automatiquement quand l'objet sort de portée
- **Important** : Libérer la mémoire, fermer les fichiers, etc.

### 3. Constructeur de Copie
```cpp
Fixed::Fixed(const Fixed &other) : value(other.value)
{
    std::cout << "Copy constructor called" << std::endl;
}
```
- **Rôle** : Crée un nouvel objet à partir d'un objet existant
- **Quand utilisé** :
  ```cpp
  Fixed a(10);
  Fixed b(a);        // Copy constructor
  Fixed c = a;       // Copy constructor aussi !
  function(a);       // Copy constructor (passage par valeur)
  return a;          // Copy constructor (retour par valeur)
  ```

### 4. Copy Assignment Operator (Opérateur d'Affectation de Copie)
```cpp
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)        // Auto-affectation check
        this->value = other.value;
    return *this;
}
```

## Copy Assignment Operator - Explication Détaillée

### Signature Complète
```cpp
Fixed &Fixed::operator=(const Fixed &other)
```

**Décomposition :**
- `Fixed &` : Retourne une référence vers l'objet courant
- `operator=` : Surcharge l'opérateur d'affectation `=`
- `const Fixed &other` : Prend l'objet source en référence constante

### Quand est-il appelé ?
```cpp
Fixed a(10);
Fixed b(5);
b = a;           // Copy assignment operator appelé ici
```

**Différence cruciale :**
```cpp
Fixed a(10);
Fixed b = a;     // Copy CONSTRUCTOR (nouvel objet)
Fixed c(5);
c = a;           // Copy ASSIGNMENT (objet existant)
```

### Vérification d'Auto-Affectation
```cpp
if (this != &other)
```

**Pourquoi c'est crucial :**
```cpp
Fixed a(10);
a = a;  // Sans cette vérification, on pourrait avoir des problèmes !
```

**Exemple problématique sans vérification :**
```cpp
// Classe avec pointeur (exemple hypothétique)
MyClass &MyClass::operator=(const MyClass &other)
{
    delete[] this->data;           // On détruit nos données
    this->data = new int[other.size];
    // Si other == this, on vient de détruire other.data aussi !
    copy(other.data, this->data);  // ERREUR : other.data est invalide
    return *this;
}
```

### Pourquoi Retourner `*this` ?
```cpp
return *this;
```

**Permet le chaînage d'affectations :**
```cpp
Fixed a, b, c;
a = b = c = Fixed(42);  // Équivalent à : a = (b = (c = Fixed(42)))
```

## Exemple Complet avec Traces
```cpp
#include <iostream>

class Fixed
{
private:
    int value;
    static const int fractionalBits = 8;

public:
    // 1. Default constructor
    Fixed() : value(0) {
        std::cout << "Default constructor called" << std::endl;
    }
    
    // 2. Destructor  
    ~Fixed() {
        std::cout << "Destructor called" << std::endl;
    }
    
    // 3. Copy constructor
    Fixed(const Fixed &other) : value(other.value) {
        std::cout << "Copy constructor called" << std::endl;
    }
    
    // 4. Copy assignment operator
    Fixed &operator=(const Fixed &other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other)
            this->value = other.value;
        return *this;
    }
};

int main() {
    Fixed a;        // Default constructor
    Fixed b(a);     // Copy constructor
    Fixed c = a;    // Copy constructor (pas assignment!)
    
    c = b;          // Copy assignment operator
    
    return 0;       // 3 destructors appelés (a, b, c)
}
```

## Cas Particulier : Attributs `const`

Dans la classe Point de l'ex03 :
```cpp
class Point
{
private:
    Fixed const x;  // const !
    Fixed const y;  // const !

public:
    Point &operator=(const Point &other)
    {
        // On ne peut PAS modifier x et y car ils sont const
        // Donc on ne fait rien, mais on doit quand même implémenter
        (void)other;  // Évite le warning "unused parameter"
        return *this;
    }
};
```

## Règle des 3/5/0

- **Règle des 3** : Si vous implémentez un (destructeur, copy constructor, copy assignment), implémentez les 3
- **Règle des 5** : Ajoute move constructor et move assignment (C++11)
- **Règle des 0** : Si possible, n'implémentez aucun (utilisez les versions par défaut)

## Erreurs Communes

### 1. Oublier la vérification d'auto-affectation
```cpp
// MAUVAIS
Fixed &operator=(const Fixed &other) {
    this->value = other.value;  // Problématique si this == &other
    return *this;
}
```

### 2. Ne pas retourner `*this`
```cpp
// MAUVAIS
void operator=(const Fixed &other) {  // void au lieu de Fixed&
    if (this != &other)
        this->value = other.value;
    // Pas de return
}
```

### 3. Confondre copy constructor et copy assignment
```cpp
Fixed a(10);
Fixed b = a;    // Copy constructor (nouvel objet b)
Fixed c;
c = a;          // Copy assignment (objet c existe déjà)
```

L'Orthodox Canonical Form garantit que vos objets peuvent être copiés et affectés de manière sûre et prévisible.