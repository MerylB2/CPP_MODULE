# CPP04 - Exercise 03 : Interface & Recap

## Objectif
Implémenter un système de **Materias** (sorts) équipables par des **Characters**, en utilisant des **interfaces** et des **classes abstraites**.

---

## Ce que cet exercice veut nous apprendre

Cet exercice est un **récapitulatif** de tout le module CPP04 et introduit les **interfaces**. Il combine :

| Concept | Où dans l'exercice | Pourquoi |
|---------|-------------------|----------|
| **Interface** | `ICharacter`, `IMateriaSource` | Définir un contrat sans implémentation |
| **Classe Abstraite** | `AMateria` | Fournir une base commune avec code partagé |
| **Polymorphisme** | `AMateria* → Ice/Cure` | Manipuler différents types via un pointeur de base |
| **Pattern Prototype** | `clone()` | Copier un objet sans connaître son type concret |
| **Pattern Factory** | `MateriaSource` | Créer des objets via une fabrique |
| **Deep Copy** | `Character` copy constructor | Éviter les dangling pointers |
| **Gestion mémoire** | `equip/unequip/delete` | Comprendre l'ownership des pointeurs |

**Message clé** : En C++ orienté objet, on programme vers des **interfaces**, pas des implémentations. Cela permet de changer l'implémentation sans modifier le code client.

```cpp
// Le code utilise ICharacter*, pas Character*
// On pourrait avoir d'autres types de personnages sans changer ce code
ICharacter* hero = new Character("hero");
hero->equip(materia);
hero->use(0, *enemy);
```

---

## Notions abordées

### 1. Interface (Pure Abstract Class)

En C++98, il n'existe pas de mot-clé `interface`. On utilise des **classes purement abstraites** : toutes les méthodes sont virtuelles pures (`= 0`).

```cpp
class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};
```

**Caractéristiques d'une interface :**
- Aucun attribut (pas de données)
- Toutes les méthodes sont `virtual ... = 0`
- Destructeur virtuel obligatoire `virtual ~IInterface() {}`
- Ne peut pas être instanciée directement

**Interfaces dans cet exercice :**
- `ICharacter` : définit le comportement d'un personnage
- `IMateriaSource` : définit une fabrique de materias

---

### 2. Classe Abstraite (Abstract Class)

Une classe avec **au moins une méthode virtuelle pure**. Elle peut avoir des attributs et des méthodes implémentées.

```cpp
class AMateria
{
    protected:
        std::string type;

    public:
        AMateria(std::string const & type);
        virtual ~AMateria() {}

        std::string const & getType() const;      // Implémentée
        virtual AMateria* clone() const = 0;      // Pure virtuelle
        virtual void use(ICharacter& target);     // Virtuelle (implémentée)
};
```

**Différence Interface vs Classe Abstraite :**

| Interface | Classe Abstraite |
|-----------|------------------|
| Aucun attribut | Peut avoir des attributs |
| Toutes méthodes = 0 | Au moins une méthode = 0 |
| Définit un contrat | Fournit une base commune |
| Préfixe `I` (convention) | Préfixe `A` (convention) |

---

### 3. Polymorphisme et Virtual

Le mot-clé `virtual` permet le **polymorphisme dynamique** : appeler la bonne méthode selon le type réel de l'objet.

```cpp
AMateria* ice = new Ice();
AMateria* cure = new Cure();

ice->use(target);   // Appelle Ice::use()
cure->use(target);  // Appelle Cure::use()
```

**Sans `virtual`** : la méthode de la classe de base serait appelée.

---

### 4. Clone Pattern (Prototype Pattern)

Permet de copier un objet sans connaître son type concret.

```cpp
class AMateria {
    virtual AMateria* clone() const = 0;
};

class Ice : public AMateria {
    AMateria* clone() const {
        return new Ice(*this);  // Deep copy
    }
};
```

**Utilisation :**
```cpp
AMateria* original = new Ice();
AMateria* copy = original->clone();  // Crée une nouvelle Ice
```

---

### 5. Factory Pattern (MateriaSource)

`MateriaSource` est une **fabrique** qui stocke des prototypes et crée des copies à la demande.

```cpp
class MateriaSource : public IMateriaSource {
    AMateria* templates[4];  // Stocke les prototypes

    void learnMateria(AMateria* m) {
        // Stocke le prototype
        templates[slot] = m;
    }

    AMateria* createMateria(std::string const& type) {
        // Cherche le prototype et retourne un clone
        for (int i = 0; i < 4; i++)
            if (templates[i] && templates[i]->getType() == type)
                return templates[i]->clone();
        return NULL;
    }
};
```

**Avantage** : Le code client n'a pas besoin de connaître les classes concrètes (`Ice`, `Cure`).

```cpp
// Sans Factory : on doit connaître les types
AMateria* ice = new Ice();

// Avec Factory : on utilise juste le nom
AMateria* ice = src->createMateria("ice");
```

---

### 7. Deep Copy vs Shallow Copy

**Shallow Copy** (copie superficielle) : copie les pointeurs, pas les données pointées.

**Deep Copy** (copie profonde) : copie les données pointées.

```cpp
// Character doit faire une deep copy de ses materias
Character::Character(const Character& other) {
    for (int i = 0; i < MAX_INVENTORY; i++) {
        if (other.materia_slots[i] != NULL)
            this->materia_slots[i] = other.materia_slots[i]->clone();  // Deep copy
        else
            this->materia_slots[i] = NULL;
    }
}
```

---

### 8. Gestion mémoire et ownership

**Règles importantes :**

1. `unequip()` ne doit PAS `delete` la materia (le sujet l'interdit)
2. Le destructeur de `Character` doit `delete` ses materias
3. `MateriaSource::learnMateria()` prend ownership de la materia passée

```cpp
// Attention aux memory leaks !
AMateria* tmp = src->createMateria("ice");
me->equip(tmp);
// Si on unequip sans sauvegarder l'adresse, on perd la référence
AMateria* saved = me->getMateria(0);
me->unequip(0);
delete saved;  // Évite le leak
```

---

## Hiérarchie des classes

```
ICharacter (Interface)          IMateriaSource (Interface)
     ^                                  ^
     |                                  |
Character                        MateriaSource


AMateria (Abstract Class)
     ^
     |
   +-+----+
   |      |
  Ice   Cure
```

---

## Compilation et exécution

```bash
make        # Compile
make re     # Recompile tout
./AMateria  # Exécute
```

**Output attendu :**
```
* shoots an ice bolt at bob *
* heals bob's wounds *
```

---

## Fichiers

| Fichier | Description |
|---------|-------------|
| `ICharacter.hpp` | Interface Character |
| `IMateriaSource.hpp` | Interface MateriaSource |
| `AMateria.hpp/cpp` | Classe abstraite Materia |
| `Ice.hpp/cpp` | Materia concrète Ice |
| `Cure.hpp/cpp` | Materia concrète Cure |
| `Character.hpp/cpp` | Classe concrète Character |
| `MateriaSource.hpp/cpp` | Classe concrète MateriaSource |

---

## Points clés à retenir

1. **Interface** = contrat pur (pas d'implémentation, préfixe `I`)
2. **Classe abstraite** = base commune avec implémentation partielle (préfixe `A`)
3. **`virtual`** = polymorphisme dynamique
4. **`= 0`** = méthode pure (doit être implémentée par les classes filles)
5. **Clone/Prototype pattern** = copier sans connaître le type concret
6. **Factory pattern** = créer des objets via une fabrique sans connaître les classes concrètes
7. **Deep copy** obligatoire pour les classes avec pointeurs
8. **Destructeur virtuel** obligatoire dans les classes de base polymorphiques
9. **Programmer vers des interfaces** = flexibilité et découplage
