# Factory Pattern (Patron de Fabrique)

Le **Factory Pattern** est un design pattern qui permet de **créer des objets sans exposer la logique de création** au code client.

---

## Principe

Au lieu de faire `new Ice()` directement, on passe par une "fabrique" :

```cpp
// SANS Factory : le code client doit connaître les classes concrètes
AMateria* m1 = new Ice();
AMateria* m2 = new Cure();

// AVEC Factory : le code client utilise juste un nom (string)
AMateria* m1 = src->createMateria("ice");
AMateria* m2 = src->createMateria("cure");
```

---

## Dans ex03 : MateriaSource

```
┌─────────────────────────────────────────────────────┐
│  MateriaSource (Factory)                            │
│  ┌─────────────────────────────────────────┐        │
│  │ templates[4] : prototypes stockés       │        │
│  │   [0] Ice*                              │        │
│  │   [1] Cure*                             │        │
│  │   [2] NULL                              │        │
│  │   [3] NULL                              │        │
│  └─────────────────────────────────────────┘        │
│                                                     │
│  learnMateria(Ice*)  → stocke le prototype          │
│  createMateria("ice") → retourne Ice->clone()       │
└─────────────────────────────────────────────────────┘
```

---

## Avantages

| Sans Factory | Avec Factory |
|--------------|--------------|
| Code couplé aux classes concrètes | Code découplé |
| Doit modifier le code pour ajouter un type | Juste ajouter un prototype |
| `new Ice()`, `new Cure()` partout | `createMateria("type")` |

---

## Cas d'usage réel

Imagine un jeu vidéo avec 100 types de sorts. Sans factory, tu aurais :

```cpp
if (type == "ice") return new Ice();
else if (type == "fire") return new Fire();
else if (type == "thunder") return new Thunder();
// ... 97 autres if/else
```

Avec factory + prototype :

```cpp
// On enregistre les prototypes une fois
factory.learn(new Ice());
factory.learn(new Fire());
// ...

// Ensuite, création simple
AMateria* spell = factory.create("ice");  // Clone automatique
```

---

## Factory + Prototype

Le Factory Pattern est souvent combiné avec le **Prototype Pattern** (comme ici avec `clone()`).

```
┌────────────┐     learnMateria()     ┌─────────────────┐
│   Client   │ ───────────────────────▶│  MateriaSource  │
└────────────┘                         │    (Factory)    │
      │                                └────────┬────────┘
      │ createMateria("ice")                    │
      │                                         │ stocke prototypes
      ▼                                         ▼
┌────────────┐                         ┌─────────────────┐
│  AMateria* │ ◀─── clone() ───────────│   Ice (proto)   │
│  (copie)   │                         │   Cure (proto)  │
└────────────┘                         └─────────────────┘
```

---

## Résumé

- **Factory** = fabrique qui crée des objets
- **Prototype** = modèle qu'on clone
- **Avantage** = le code client ne connaît pas les classes concrètes
- **Flexibilité** = ajouter un nouveau type = juste `learnMateria(new NewType())`
