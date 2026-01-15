# CPP Module 03 - Inheritance (Héritage)

## Objectif du module

Le but du **Module 03** est d'apprendre l'**héritage** en C++.

## Concepts clés enseignés

### 1. Héritage simple (ex00 → ex02)
- Une classe dérivée (ScavTrap, FragTrap) hérite d'une classe de base (ClapTrap)
- Syntaxe : `class ScavTrap : public ClapTrap`

### 2. protected vs private
- `private` : accessible uniquement dans la classe elle-même
- `protected` : accessible dans la classe ET ses classes dérivées
- C'est pourquoi on passe les attributs de ClapTrap en `protected` à partir de ex01

### 3. Chaîne de construction/destruction
- **Construction** : classe de base d'abord (ClapTrap), puis dérivée (ScavTrap)
- **Destruction** : inverse - dérivée d'abord, base ensuite

### 4. Redéfinition de méthodes (override)
- ScavTrap redéfinit `attack()` avec son propre message
- FragTrap utilise celle de ClapTrap (héritée)

### 5. ex03 (bonus) : Héritage multiple et problème du diamant
- DiamondTrap hérite de ScavTrap ET FragTrap
- Utilisation de `virtual` pour éviter la duplication de ClapTrap

## Qu'est-ce que l'héritage ?

L'**héritage** permet à une classe (dérivée) de récupérer automatiquement les attributs et méthodes d'une autre classe (base).

### Syntaxe de base

```cpp
class ClapTrap           // Classe de base
{
    protected:
        std::string name;
        int hit_pts;
};

class ScavTrap : public ClapTrap   // ScavTrap hérite de ClapTrap
{
    // ScavTrap a automatiquement name et hit_pts !
};
```

### Ce que la classe dérivée obtient automatiquement

| Élément | Hérité ? |
|---------|----------|
| Attributs `protected` | ✅ Oui, accessibles |
| Attributs `private` | ✅ Hérités mais inaccessibles |
| Méthodes `public` | ✅ Oui |
| Constructeurs | ❌ Non (mais appelés automatiquement) |
| Destructeur | ❌ Non (mais appelé automatiquement) |

### Pourquoi utiliser l'héritage ?

1. **Éviter la duplication** : ClapTrap a `attack()`, `takeDamage()`, `beRepaired()`. ScavTrap et FragTrap les héritent sans réécrire le code.

2. **Spécialisation** : ScavTrap peut redéfinir `attack()` avec son propre comportement, tout en gardant les autres méthodes de ClapTrap.

3. **Organisation** : Hiérarchie logique du code (ClapTrap → ScavTrap/FragTrap → DiamondTrap).

### Ordre de construction/destruction (LIFO)

```
Construction d'un ScavTrap :
1. ClapTrap() appelé en premier (base)
2. ScavTrap() appelé ensuite (dérivée)

Destruction d'un ScavTrap :
1. ~ScavTrap() appelé en premier (dérivée)
2. ~ClapTrap() appelé ensuite (base)
```

C'est pourquoi dans les logs on voit :
```
ClapTrap default constructor called    // Base d'abord
ScavTrap default constructor called    // Dérivée ensuite
...
ScavTrap destructor called             // Dérivée d'abord
ClapTrap destructor called             // Base ensuite
```

## Résumé

C'est une introduction progressive à la POO et à la réutilisation de code via l'héritage.
