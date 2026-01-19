# ex02 - Classe Abstraite

## Difference avec ex01

Une seule modification : `makeSound()` devient **virtuelle pure**.

```cpp
// ex01 - Animal INSTANCIABLE
virtual void makeSound() const;

// ex02 - Animal ABSTRAITE
virtual void makeSound() const = 0;  // Le "= 0" rend la classe abstraite
```

---

## Qu'est-ce qu'une classe abstraite ?

Une classe avec au moins une **methode virtuelle pure** (`= 0`).

| Caracteristique | Classe concrete | Classe abstraite |
|-----------------|-----------------|------------------|
| `Animal a;` | OK | **ERREUR** |
| `new Animal()` | OK | **ERREUR** |
| `Animal* a = new Dog()` | OK | OK |
| Peut etre heritee | Oui | Oui |

---

## Pourquoi c'est utile ?

```cpp
// Un "Animal" generique n'a pas de sens
// Quel son fait un "Animal" ? On ne sait pas.
// Un Animal DOIT etre un Dog ou un Cat

Animal a;              // INTERDIT - pas de sens
Animal* a = new Dog(); // OK - on sait que c'est un chien
```

Une classe abstraite sert de **contrat** :
- Elle definit ce que les classes derivees DOIVENT implementer
- Elle empeche de creer des objets "incomplets"

---

## Fichiers modifies (par rapport a ex01)

| Fichier | Modification |
|---------|-------------|
| `Animal.hpp` | `makeSound() const = 0` |
| `Animal.cpp` | Supprimer/commenter `makeSound()` |
| `main.cpp` | Supprimer `new Animal()` |

Le reste (Brain, Dog, Cat, deep copy) est **identique** a ex01.
