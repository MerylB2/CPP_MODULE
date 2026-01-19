# CPP Module 04 - Polymorphisme & Classes Abstraites

## Les 4 piliers de la POO

| Concept | Description |
|---------|-------------|
| **Encapsulation** | Cacher les donnees (private/protected/public) |
| **Heritage** | Une classe herite d'une autre |
| **Polymorphisme** | Meme methode, comportements differents |
| **Abstraction** | Simplifier en cachant la complexite |

---

## Encapsulation

C'est le fait de **cacher les donnees** a l'interieur d'une classe et controler l'acces.

```cpp
class Animal
{
    private:           // Donnees cachees
        std::string name;
        int age;

    public:            // Interface publique
        void setAge(int a);   // Seul moyen de modifier age
        int getAge() const;
};
```

**Pourquoi ?**
- Empeche la modification directe (`animal.age = -50;` impossible)
- Les methodes peuvent valider les donnees
- Mots-cles : `private`, `protected`, `public`

---

## Polymorphisme

Du grec "plusieurs formes" - une meme methode peut avoir **differents comportements** selon la classe.

### Exemple sans virtual (statique)

```cpp
class Animal {
    void makeSound();  // Version Animal
};

class Dog : public Animal {
    void makeSound();  // Version Dog (redefinit)
};

Animal* a = new Dog();
a->makeSound();  // Appelle Animal::makeSound() !!! (mauvais)
```

### Exemple avec virtual (dynamique)

```cpp
class Animal {
    virtual void makeSound();  // "virtual" active le polymorphisme
};

class Dog : public Animal {
    void makeSound();  // Override automatique
};

Animal* a = new Dog();
a->makeSound();  // Appelle Dog::makeSound() (correct!)
```

**Le mot-cle `virtual`** permet au programme de choisir la bonne methode **a l'execution** (runtime) selon le type reel de l'objet.

---

## Classe Abstraite

Une classe avec au moins une **methode virtuelle pure** (`= 0`).

```cpp
class Animal
{
    public:
        virtual void makeSound() = 0;  // Virtuelle pure : pas d'implementation
        virtual ~Animal() {}           // Destructeur virtuel obligatoire
};
```

**Regles :**
- On **ne peut pas instancier** une classe abstraite (`Animal a;` erreur)
- Les classes derivees **doivent implementer** les methodes pures
- Sert de **contrat/interface** pour les classes derivees

```cpp
class Dog : public Animal
{
    public:
        void makeSound() { std::cout << "Woof!" << std::endl; }  // Obligatoire
};

// Animal a;        // ERREUR : classe abstraite
Animal* a = new Dog();  // OK : Dog est concrete
a->makeSound();         // "Woof!"
```

---

## Destructeur Virtuel

**Obligatoire** quand on utilise le polymorphisme !

```cpp
class Animal {
    public:
        virtual ~Animal() {}  // IMPORTANT : virtual
};

class Dog : public Animal {
    private:
        char* data;
    public:
        ~Dog() { delete[] data; }  // Doit etre appele !
};

Animal* a = new Dog();
delete a;  // Sans virtual ~Animal() -> fuite memoire (Dog::~Dog() pas appele)
           // Avec virtual ~Animal() -> OK, appelle Dog::~Dog() puis Animal::~Animal()
```

---

## Interface (classe abstraite pure)

Une classe avec **uniquement** des methodes virtuelles pures.

```cpp
class IAnimal  // Convention : prefixe "I" pour Interface
{
    public:
        virtual void makeSound() = 0;
        virtual void move() = 0;
        virtual ~IAnimal() {}
};
```

---

## Difference entre virtual CPP03 et CPP04

Le mot-cle `virtual` a deux utilisations differentes :

### CPP03 - Heritage virtuel (Diamond Problem)

```cpp
// ScavTrap.hpp et FragTrap.hpp
class ScavTrap : virtual public ClapTrap  // Heritage virtuel
class FragTrap : virtual public ClapTrap
```

**But** : Eviter la duplication de la classe de base lors d'un heritage multiple.

```
Sans virtual:              Avec virtual:
    ClapTrap  ClapTrap         ClapTrap
        \      /                  |
     ScavTrap FragTrap      ScavTrap FragTrap
          \  /                   \  /
       DiamondTrap            DiamondTrap

(2 copies de ClapTrap)    (1 seule copie)
```

### CPP04 - Methode virtuelle (Polymorphisme)

```cpp
// Animal.hpp
class Animal {
    virtual void makeSound() const;  // Methode virtuelle
    virtual ~Animal();               // Destructeur virtuel
};
```

**But** : Permettre a une methode d'avoir un comportement different selon le type reel de l'objet.

```cpp
Animal* a = new Dog();
a->makeSound();  // Avec virtual    -> "Woof!" (Dog)
                 // Sans virtual    -> "* generic sound *" (Animal)
```

### Tableau comparatif

| CPP03 | CPP04 |
|-------|-------|
| `virtual public BaseClass` | `virtual void method()` |
| Heritage virtuel | Methode virtuelle |
| Evite duplication de la base | Active le polymorphisme |
| Probleme du diamant | Comportement dynamique |

---

## Resume

| Terme | Definition |
|-------|------------|
| `virtual` (heritage) | Evite duplication dans heritage multiple (CPP03) |
| `virtual` (methode) | Active le polymorphisme dynamique (CPP04) |
| `= 0` | Methode virtuelle pure (pas d'implementation) |
| Classe abstraite | Contient au moins une methode `= 0` |
| Interface | Classe avec uniquement des methodes `= 0` |
| Destructeur virtuel | Obligatoire pour le polymorphisme |

---

## Ordre de construction/destruction avec polymorphisme

```
Construction : Base -> Derivee (comme heritage normal)
Destruction  : Derivee -> Base (grace au destructeur virtuel)
```

---

## Deep Copy vs Shallow Copy (ex01)

### Shallow Copy (copie superficielle) - MAUVAIS

```cpp
class Dog {
    Brain* brain;  // Pointeur
};

Dog a;
Dog b = a;  // Shallow copy : copie juste le POINTEUR
```

```
a.brain -----> [Brain data]
               ^
b.brain -------+   (MEME adresse!)
```

**Problemes :**
1. Modifier `b.brain` modifie aussi `a.brain` (meme memoire)
2. Quand `a` est detruit -> `delete brain`
3. Quand `b` est detruit -> `delete brain` **DOUBLE FREE = CRASH**

### Deep Copy (copie profonde) - CORRECT

```cpp
Dog::Dog(const Dog& other) {
    this->brain = new Brain(*other.brain);  // NOUVEAU Brain
}
```

```
a.brain -----> [Brain data A]

b.brain -----> [Brain data B]   (adresse DIFFERENTE, contenu copie)
```

**Avantages :**
1. Chaque objet a sa propre memoire
2. Modifier `b` n'affecte pas `a`
3. Pas de double free

---

## Rule of Three (C++98)

Si une classe a un **pointeur membre**, tu DOIS implementer :

| Methode | Pourquoi |
|---------|----------|
| **Destructeur** `~Dog()` | Liberer la memoire (`delete brain`) |
| **Copy constructor** `Dog(const Dog&)` | Deep copy a la construction |
| **Copy assignment** `operator=` | Deep copy a l'affectation |

```cpp
class Dog {
    Brain* brain;
public:
    Dog();                              // Constructeur : new Brain()
    Dog(const Dog& other);              // Copy : new Brain(*other.brain)
    Dog& operator=(const Dog& other);   // Assign : *brain = *other.brain
    ~Dog();                             // Destructeur : delete brain
};
```

**Si tu oublies un des trois** -> bugs memoire garantis (double free, fuite, corruption)
