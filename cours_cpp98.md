# Cours Complet C++98 - Norme std=c++98

## Table des matières
1. [Les fondamentaux](#1-les-fondamentaux)
2. [Programmation Orientée Objet](#2-programmation-orientée-objet)
3. [Les namespaces et std::](#3-les-namespaces-et-std)
4. [Constructeurs et Destructeurs](#4-constructeurs-et-destructeurs)
5. [Gestion de la mémoire](#5-gestion-de-la-mémoire)
6. [Templates](#6-templates)
7. [La STL (Standard Template Library)](#7-la-stl-standard-template-library)
8. [Références et pointeurs](#8-références-et-pointeurs)
9. [Exceptions](#9-exceptions)
10. [Outils utiles - stringstream](#10-outils-utiles---stringstream)

---

## 1. Les fondamentaux

### 1.1 Types de base

```cpp
int entier = 42;
char caractere = 'A';
float decimal = 3.14f;
double decimalDouble = 3.14159;
bool boolean = true;

// Variantes
short petit = 100;
long grand = 1000000L;
unsigned int positif = 42;
```

### 1.2 Compilation séparée

**Fichier header (.hpp / .h)** : Contient les déclarations

```cpp
// Personne.hpp
#ifndef PERSONNE_HPP
# define PERSONNE_HPP

# include <string>

class Personne {
private:
    std::string _nom;
    int _age;

public:
    Personne(void);
    ~Personne(void);
    
    void sePresenter(void) const;
};

#endif
```

**Fichier source (.cpp)** : Contient les définitions

```cpp
// Personne.cpp
#include "Personne.hpp"
#include <iostream>

Personne::Personne(void) : _nom("Inconnu"), _age(0) {
    std::cout << "Personne créée" << std::endl;
}

Personne::~Personne(void) {
    std::cout << "Personne détruite" << std::endl;
}

void Personne::sePresenter(void) const {
    std::cout << "Je m'appelle " << this->_nom << std::endl;
}
```

**Guards d'inclusion** : Évitent les inclusions multiples
```cpp
#ifndef FICHIER_HPP  // Si pas défini
# define FICHIER_HPP // Alors défini
// ... contenu ...
#endif               // Fin
```

---

## 2. Programmation Orientée Objet

### 2.1 Qu'est-ce que la POO ?

La **Programmation Orientée Objet** organise le code autour d'objets qui combinent :
- **Données** (attributs)
- **Comportements** (méthodes)

**Les quatre piliers** :
1. **Encapsulation** : Cacher les détails d'implémentation
2. **Abstraction** : Simplifier la complexité
3. **Héritage** : Réutiliser du code
4. **Polymorphisme** : Une interface, plusieurs implémentations

### 2.2 Les classes

Une **classe** est un modèle qui définit la structure d'objets.

```cpp
class Rectangle {
private:
    double _largeur;
    double _hauteur;

public:
    Rectangle(void);
    Rectangle(double l, double h);
    ~Rectangle(void);
    
    double calculerAire(void) const;
    void afficher(void) const;
};
```

**Différence class vs struct** :
- `class` : membres **privés** par défaut
- `struct` : membres **publics** par défaut

```cpp
class MaClasse {
    int x;  // privé par défaut
};

struct MaStructure {
    int x;  // public par défaut
};
```

### 2.3 Modificateurs d'accès

#### `private` (privé)
Accessible **uniquement** à l'intérieur de la classe.

```cpp
class CompteBancaire {
private:
    double _solde;  // Protégé de l'extérieur
    
public:
    void deposer(double montant) {
        this->_solde += montant;  // OK depuis l'intérieur
    }
};

int main() {
    CompteBancaire compte;
    // compte._solde = 1000;  // ✗ ERREUR : _solde est privé
    compte.deposer(1000);     // ✓ OK : méthode publique
}
```

#### `public` (public)
Accessible **partout**.

```cpp
class Personne {
public:
    void direBonjour(void) {
        std::cout << "Bonjour !" << std::endl;
    }
};

int main() {
    Personne p;
    p.direBonjour();  // ✓ OK : méthode publique
}
```

#### `protected` (protégé)
Accessible dans la classe ET les classes dérivées (héritage).

```cpp
class Animal {
protected:
    std::string _espece;  // Accessible aux classes filles
    
public:
    Animal(std::string espece) : _espece(espece) {}
};

class Chien : public Animal {
public:
    Chien(void) : Animal("Canis familiaris") {}
    
    void afficherEspece(void) {
        std::cout << this->_espece << std::endl;  // ✓ OK : protected
    }
};
```

### 2.4 Instances (Objets)

Une **instance** est un objet concret créé à partir d'une classe.

```cpp
class Voiture {
private:
    std::string _marque;
    int _vitesse;

public:
    Voiture(std::string marque) : _marque(marque), _vitesse(0) {}
    
    void accelerer(void) {
        this->_vitesse += 10;
    }
};

int main() {
    Voiture v1("Peugeot");  // Instance 1
    Voiture v2("Renault");  // Instance 2
    
    v1.accelerer();  // Chaque instance a ses propres données
    v2.accelerer();
    v2.accelerer();
    
    // v1._vitesse = 10
    // v2._vitesse = 20
}
```

### 2.5 Getters et Setters

Méthodes pour accéder et modifier les attributs privés de manière contrôlée.

```cpp
class Etudiant {
private:
    std::string _nom;
    int _note;

public:
    Etudiant(void) : _nom(""), _note(0) {}
    
    // GETTERS (lecture)
    std::string getNom(void) const {
        return this->_nom;
    }
    
    int getNote(void) const {
        return this->_note;
    }
    
    // SETTERS (écriture)
    void setNom(const std::string& nom) {
        this->_nom = nom;
    }
    
    void setNote(int note) {
        // Validation : note entre 0 et 20
        if (note >= 0 && note <= 20) {
            this->_note = note;
        } else {
            std::cout << "Note invalide !" << std::endl;
        }
    }
};

int main() {
    Etudiant e;
    
    e.setNom("Alice");
    e.setNote(18);
    
    std::cout << e.getNom() << " : " << e.getNote() << "/20" << std::endl;
    
    // e._nom = "Bob";  // ✗ ERREUR : _nom est privé
}
```

**Pourquoi utiliser des getters/setters ?**
- ✅ **Encapsulation** : Protection des données
- ✅ **Validation** : Contrôle des valeurs
- ✅ **Flexibilité** : Modification de l'implémentation interne sans casser le code

**Conventions** :
- Attributs privés : `_attribut` (underscore)
- Getters : `getAttribut()` et sont `const`
- Setters : `setAttribut(valeur)`

### 2.6 Le pointeur `this`

`this` est un pointeur vers l'instance courante.

```cpp
class Point {
private:
    int _x;
    int _y;

public:
    Point(int x, int y) : _x(x), _y(y) {}
    
    void setX(int x) {
        this->_x = x;  // this pointe vers l'objet courant
        // _x = x;     // Équivalent (peut être ambigu)
    }
    
    Point* clone(void) {
        return this;  // Retourne un pointeur vers soi-même
    }
    
    void afficher(void) const {
        std::cout << "(" << this->_x << ", " << this->_y << ")" << std::endl;
    }
};
```

**Utilisation typique** : Différencier paramètre et attribut ayant le même nom.

```cpp
class Cercle {
private:
    double rayon;

public:
    // Sans this : ambigu
    void setRayon(double rayon) {
        this->rayon = rayon;  // this->rayon (attribut) = rayon (paramètre)
    }
};
```

### 2.7 `this->` en détail

#### Qu'est-ce que `this->` ?

`this` est un **pointeur constant** vers l'objet courant. Dans une méthode, `this` contient l'adresse de l'instance qui a appelé la méthode.

```cpp
class Exemple {
private:
    int _valeur;

public:
    void afficherAdresse(void) {
        std::cout << "Adresse de l'objet : " << this << std::endl;
        std::cout << "Adresse de _valeur : " << &(this->_valeur) << std::endl;
    }
};

int main() {
    Exemple obj1;
    Exemple obj2;
    
    obj1.afficherAdresse();  // this pointe vers obj1
    obj2.afficherAdresse();  // this pointe vers obj2
}
```

#### Quand utiliser `this->` ?

##### 1. Lever l'ambiguïté (paramètre = attribut)

```cpp
class Personne {
private:
    std::string nom;
    int age;

public:
    // ❌ Sans this : ERREUR ou comportement indéfini
    void setNom(std::string nom) {
        nom = nom;  // Assigne le paramètre à lui-même !
    }
    
    // ✅ Avec this : CLAIR
    void setNom2(std::string nom) {
        this->nom = nom;  // Assigne le paramètre à l'attribut
    }
    
    // ✅ Alternative : nommer différemment
    void setNom3(std::string newNom) {
        nom = newNom;  // Pas d'ambiguïté
    }
};
```

##### 2. Clarté et lisibilité du code

Même sans ambiguïté, `this->` rend le code plus explicite.

```cpp
class Rectangle {
private:
    double _largeur;
    double _hauteur;

public:
    double calculerAire(void) const {
        // Sans this
        return _largeur * _hauteur;
        
        // Avec this (plus explicite)
        return this->_largeur * this->_hauteur;
    }
    
    void afficher(void) const {
        std::cout << "Largeur: " << this->_largeur << std::endl;
        std::cout << "Hauteur: " << this->_hauteur << std::endl;
    }
};
```

**Convention 42/École** : Souvent on utilise `this->` systématiquement pour clarifier qu'on accède à un membre de la classe.

##### 3. Retourner l'objet lui-même (chaînage)

```cpp
class Calculatrice {
private:
    int _resultat;

public:
    Calculatrice(void) : _resultat(0) {}
    
    Calculatrice& ajouter(int x) {
        this->_resultat += x;
        return *this;  // Retourne l'objet courant
    }
    
    Calculatrice& multiplier(int x) {
        this->_resultat *= x;
        return *this;
    }
    
    int getResultat(void) const {
        return this->_resultat;
    }
};

int main() {
    Calculatrice calc;
    
    // Chaînage de méthodes
    calc.ajouter(5).multiplier(2).ajouter(10);
    
    std::cout << calc.getResultat() << std::endl;  // 20
}
```

##### 4. Passer l'objet à une fonction

```cpp
class Point {
private:
    int _x, _y;

public:
    Point(int x, int y) : _x(x), _y(y) {}
    
    void enregistrer(void) {
        // Passer l'objet courant à une fonction externe
        sauvegarderDansDB(this);
    }
    
    void afficherAvecHelper(void) {
        helperAffichage(this);
    }
};

void sauvegarderDansDB(Point* p) {
    // Sauvegarde le point
}

void helperAffichage(Point* p) {
    // Affiche le point
}
```

##### 5. Comparaison avec un autre objet

```cpp
class Point {
private:
    int _x, _y;

public:
    Point(int x, int y) : _x(x), _y(y) {}
    
    bool estEgal(const Point& autre) const {
        return (this->_x == autre._x && this->_y == autre._y);
    }
    
    bool operator==(const Point& autre) const {
        return this->estEgal(autre);
    }
};
```

##### 6. Protection contre l'auto-affectation

```cpp
class Tableau {
private:
    int* _data;
    int _taille;

public:
    Tableau& operator=(const Tableau& rhs) {
        // Vérifier si on s'assigne à soi-même
        if (this == &rhs) {  // Comparer les adresses
            return *this;
        }
        
        // Sinon, faire la copie
        delete[] this->_data;
        this->_taille = rhs._taille;
        this->_data = new int[rhs._taille];
        for (int i = 0; i < this->_taille; i++) {
            this->_data[i] = rhs._data[i];
        }
        
        return *this;
    }
};
```

#### `this` vs `*this`

```cpp
class Demo {
private:
    int _valeur;

public:
    Demo(int v) : _valeur(v) {}
    
    void exemple(void) {
        // this est un POINTEUR
        Demo* ptr = this;
        std::cout << "Type de this : Demo*" << std::endl;
        std::cout << "Adresse : " << this << std::endl;
        
        // *this est l'OBJET lui-même
        Demo& obj = *this;
        std::cout << "Type de *this : Demo&" << std::endl;
        
        // Accès aux membres
        this->_valeur = 10;  // Via pointeur (->)
        (*this)._valeur = 10;  // Via déréférencement (.)
    }
    
    // Retourner un pointeur
    Demo* getPointer(void) {
        return this;
    }
    
    // Retourner une référence
    Demo& getReference(void) {
        return *this;
    }
    
    // Retourner une copie
    Demo getCopy(void) {
        return *this;
    }
};
```

#### Cas pratiques complets

##### Exemple 1 : Classe avec et sans `this->`

```cpp
class Compte {
private:
    std::string _titulaire;
    double _solde;

public:
    Compte(std::string titulaire, double solde) 
        : _titulaire(titulaire), _solde(solde) {}
    
    // Version sans this-> (possible car pas d'ambiguïté)
    void deposerV1(double montant) {
        _solde += montant;
    }
    
    // Version avec this-> (plus explicite)
    void deposerV2(double montant) {
        this->_solde += montant;
    }
    
    // Obligatoire avec this-> (ambiguïté)
    void setTitulaire(std::string titulaire) {
        this->_titulaire = titulaire;  // OBLIGATOIRE
        // titulaire = titulaire;      // ✗ N'affecte pas l'attribut !
    }
    
    void afficher(void) const {
        std::cout << "Titulaire: " << this->_titulaire << std::endl;
        std::cout << "Solde: " << this->_solde << std::endl;
    }
};
```

##### Exemple 2 : Builder pattern avec chaînage

```cpp
class Pizza {
private:
    std::string _pate;
    std::string _sauce;
    bool _fromage;
    bool _champignons;
    bool _olives;

public:
    Pizza(void) : _pate("classique"), _sauce("tomate"), 
                  _fromage(true), _champignons(false), _olives(false) {}
    
    Pizza& avecPate(std::string pate) {
        this->_pate = pate;
        return *this;  // Retourne l'objet pour chaînage
    }
    
    Pizza& avecSauce(std::string sauce) {
        this->_sauce = sauce;
        return *this;
    }
    
    Pizza& avecChampignons(void) {
        this->_champignons = true;
        return *this;
    }
    
    Pizza& avecOlives(void) {
        this->_olives = true;
        return *this;
    }
    
    void afficher(void) const {
        std::cout << "Pizza: " << this->_pate << ", " << this->_sauce;
        if (this->_fromage) std::cout << ", fromage";
        if (this->_champignons) std::cout << ", champignons";
        if (this->_olives) std::cout << ", olives";
        std::cout << std::endl;
    }
};

int main() {
    Pizza pizza;
    
    // Chaînage de méthodes
    pizza.avecPate("fine")
         .avecSauce("crème")
         .avecChampignons()
         .avecOlives();
    
    pizza.afficher();
    // Pizza: fine, crème, fromage, champignons, olives
}
```

##### Exemple 3 : Copie profonde avec this

```cpp
class Liste {
private:
    int* _data;
    int _taille;

public:
    Liste(int taille) : _taille(taille) {
        this->_data = new int[taille];
        for (int i = 0; i < taille; i++) {
            this->_data[i] = 0;
        }
    }
    
    ~Liste(void) {
        delete[] this->_data;
    }
    
    Liste(const Liste& src) : _taille(src._taille) {
        this->_data = new int[src._taille];
        for (int i = 0; i < this->_taille; i++) {
            this->_data[i] = src._data[i];
        }
    }
    
    Liste& operator=(const Liste& rhs) {
        // Protection auto-affectation
        if (this == &rhs) {
            return *this;
        }
        
        // Libérer ancienne mémoire
        delete[] this->_data;
        
        // Copier nouvelles données
        this->_taille = rhs._taille;
        this->_data = new int[rhs._taille];
        for (int i = 0; i < this->_taille; i++) {
            this->_data[i] = rhs._data[i];
        }
        
        return *this;
    }
    
    int& operator[](int index) {
        return this->_data[index];
    }
};
```

#### `this` dans les méthodes const

Dans une méthode `const`, `this` est de type `const Classe*`.

```cpp
class Exemple {
private:
    int _valeur;
    mutable int _cache;  // mutable : modifiable même dans const

public:
    Exemple(int v) : _valeur(v), _cache(0) {}
    
    void nonConst(void) {
        // this est de type : Exemple*
        this->_valeur = 10;  // ✓ OK
    }
    
    void estConst(void) const {
        // this est de type : const Exemple*
        // this->_valeur = 10;  // ✗ ERREUR : modification interdite
        
        std::cout << this->_valeur << std::endl;  // ✓ OK : lecture
        
        this->_cache = 100;  // ✓ OK : mutable
    }
};
```

#### Différences avec d'autres langages

| Langage | Équivalent de `this` |
|---------|---------------------|
| C++ | `this` (pointeur) |
| Java | `this` (référence) |
| Python | `self` (convention) |
| JavaScript | `this` (contexte) |

```cpp
// En C++, this est un POINTEUR
this->membre      // Accès via pointeur
(*this).membre    // Équivalent (déréférencement)

// En Java/JavaScript, this est une RÉFÉRENCE
this.membre       // Accès direct
```

#### Erreurs courantes

##### Erreur 1 : Oublier `this->` avec ambiguïté

```cpp
class Mauvais {
private:
    int valeur;

public:
    void setValeur(int valeur) {
        valeur = valeur;  // ✗ Assigne le paramètre à lui-même !
    }
};

class Bon {
private:
    int valeur;

public:
    void setValeur(int valeur) {
        this->valeur = valeur;  // ✓ Correct
    }
};
```

##### Erreur 2 : Retourner `this` au lieu de `*this`

```cpp
class Demo {
public:
    Demo& maMethode(void) {
        // return this;   // ✗ ERREUR : this est Demo*, pas Demo&
        return *this;     // ✓ Correct
    }
};
```

##### Erreur 3 : Utiliser `this` hors d'une méthode

```cpp
class Erreur {
private:
    int x;
    // int y = this->x;  // ✗ ERREUR : this n'existe pas ici

public:
    Erreur(void) {
        this->x = 10;  // ✓ OK : dans une méthode
    }
};
```

#### Résumé

| Usage | Exemple |
|-------|---------|
| Lever ambiguïté | `this->nom = nom;` |
| Clarifier le code | `return this->_valeur;` |
| Retourner l'objet | `return *this;` |
| Chaînage | `obj.method1().method2();` |
| Auto-affectation | `if (this == &rhs)` |
| Passer à fonction | `fonction(this);` |

**Convention recommandée** : Utiliser `this->` systématiquement pour :
- ✅ Tous les accès aux attributs (clarté maximale)
- ✅ Lever toute ambiguïté
- ✅ Rendre le code plus maintenable

**Note École 42** : Beaucoup de projets demandent l'utilisation systématique de `this->` pour accéder aux membres de la classe.

### 2.7 Héritage

Permet à une classe d'hériter des propriétés et méthodes d'une autre.

```cpp
// Classe de base (parent)
class Forme {
protected:
    std::string _couleur;

public:
    Forme(std::string couleur) : _couleur(couleur) {}
    
    virtual void afficher(void) const {
        std::cout << "Forme de couleur " << this->_couleur << std::endl;
    }
    
    virtual ~Forme(void) {}
};

// Classe dérivée (enfant)
class Cercle : public Forme {
private:
    double _rayon;

public:
    Cercle(std::string couleur, double rayon) 
        : Forme(couleur), _rayon(rayon) {}
    
    void afficher(void) const {
        std::cout << "Cercle " << this->_couleur 
                  << " de rayon " << this->_rayon << std::endl;
    }
};

int main() {
    Forme f("rouge");
    Cercle c("bleu", 5.0);
    
    f.afficher();  // Forme de couleur rouge
    c.afficher();  // Cercle bleu de rayon 5
    
    // Polymorphisme
    Forme* ptr = &c;
    ptr->afficher();  // Cercle bleu de rayon 5 (grâce à virtual)
}
```

**Types d'héritage** :
- `public` : Les membres publics restent publics
- `protected` : Les membres publics deviennent protégés
- `private` : Les membres publics deviennent privés

**Fonctions virtuelles** :
- `virtual` : Permet le polymorphisme
- `virtual ... = 0` : Fonction virtuelle pure (classe abstraite)

```cpp
class Animal {
public:
    virtual void crier(void) const = 0;  // Fonction pure
    virtual ~Animal(void) {}
};

class Chat : public Animal {
public:
    void crier(void) const {
        std::cout << "Miaou !" << std::endl;
    }
};
```

---

## 3. Les namespaces et std::

### 3.1 Qu'est-ce qu'un namespace ?

Un **namespace** (espace de noms) est un conteneur qui regroupe des identifiants pour éviter les conflits.

```cpp
namespace Geometrie {
    class Point {
        int x, y;
    };
    
    void afficher(void) {
        std::cout << "Géométrie" << std::endl;
    }
}

namespace Physique {
    class Point {
        double x, y, z;
    };
    
    void afficher(void) {
        std::cout << "Physique" << std::endl;
    }
}

int main() {
    Geometrie::Point p1;  // Point 2D
    Physique::Point p2;   // Point 3D
    
    Geometrie::afficher();  // Géométrie
    Physique::afficher();   // Physique
}
```

### 3.2 Le namespace `std::`

`std::` est le namespace de la bibliothèque standard C++.

```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string texte = "Bonjour";
    std::vector<int> nombres;
    std::cout << texte << std::endl;
}
```

**Opérateur de résolution de portée** : `::`

### 3.3 Les alternatives à std::

#### Option 1 : `using namespace std;` (DÉCONSEILLÉ)

```cpp
#include <iostream>
#include <string>

using namespace std;  // Importe TOUT std

int main() {
    string texte = "Bonjour";  // Plus besoin de std::
    cout << texte << endl;
    vector<int> v;
}
```

**⚠️ Problèmes** :
- Pollue l'espace de noms
- Risque de conflits
- Code moins clair

**JAMAIS dans les fichiers .hpp !**

#### Option 2 : `using` déclarations spécifiques (OK)

```cpp
#include <iostream>

using std::cout;
using std::endl;

int main() {
    cout << "Bonjour" << endl;  // OK
    
    std::vector<int> v;  // vector pas importé, on doit écrire std::
}
```

#### Option 3 : Toujours `std::` (RECOMMANDÉ pour .hpp)

```cpp
#include <iostream>

int main() {
    std::cout << "Bonjour" << std::endl;  // Explicite et clair
}
```

### 3.4 Créer son propre namespace

```cpp
namespace MaBibliotheque {
    class Calculatrice {
    public:
        static int addition(int a, int b) {
            return a + b;
        }
    };
    
    const double PI = 3.14159;
}

int main() {
    int somme = MaBibliotheque::Calculatrice::addition(5, 3);
    double perimetre = 2 * MaBibliotheque::PI * 10;
}
```

### 3.5 Namespace anonyme

Crée des identifiants privés au fichier.

```cpp
// Dans fichier.cpp
namespace {
    void fonctionPrivee(void) {
        // Visible seulement dans ce fichier
    }
}

void fonctionPublique(void) {
    fonctionPrivee();  // OK
}
```

**Équivalent à** `static` en C pour les fonctions.

---

## 4. Constructeurs et Destructeurs

### 4.1 Constructeurs

Un **constructeur** initialise un objet lors de sa création.

**Caractéristiques** :
- ✅ Même nom que la classe
- ✅ Pas de type de retour
- ✅ Peut être surchargé
- ✅ Appelé automatiquement

#### Constructeur par défaut

```cpp
class Voiture {
private:
    std::string _marque;
    int _annee;

public:
    // Constructeur par défaut (sans paramètres)
    Voiture(void) {
        this->_marque = "Inconnue";
        this->_annee = 2000;
        std::cout << "Voiture créée (défaut)" << std::endl;
    }
};

int main() {
    Voiture v;  // Appelle le constructeur par défaut
}
```

**⚠️ Important** : Si vous définissez un constructeur avec paramètres, le constructeur par défaut automatique n'est plus généré !

```cpp
class Test {
public:
    Test(int x) {}  // On définit un constructeur avec paramètre
};

int main() {
    Test t1(5);   // ✓ OK
    Test t2;      // ✗ ERREUR : pas de constructeur par défaut
}
```

#### Constructeur avec paramètres

```cpp
class Rectangle {
private:
    double _largeur;
    double _hauteur;

public:
    Rectangle(double l, double h) {
        this->_largeur = l;
        this->_hauteur = h;
    }
};

int main() {
    Rectangle r1(10.5, 5.2);
    Rectangle r2(3.0, 4.0);
}
```

#### Surcharge de constructeurs

```cpp
class Point {
private:
    int _x;
    int _y;

public:
    // Constructeur 1 : sans paramètres
    Point(void) : _x(0), _y(0) {
        std::cout << "Point(0, 0)" << std::endl;
    }
    
    // Constructeur 2 : avec 1 paramètre
    Point(int val) : _x(val), _y(val) {
        std::cout << "Point(" << val << ", " << val << ")" << std::endl;
    }
    
    // Constructeur 3 : avec 2 paramètres
    Point(int x, int y) : _x(x), _y(y) {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1;         // Appelle Point(void)
    Point p2(5);      // Appelle Point(int)
    Point p3(3, 7);   // Appelle Point(int, int)
}
```

#### Constructeur de copie

Crée un objet comme copie d'un autre.

```cpp
class Livre {
private:
    std::string _titre;
    int _pages;

public:
    Livre(std::string titre, int pages) 
        : _titre(titre), _pages(pages) {}
    
    // Constructeur de copie
    Livre(const Livre& src) {
        std::cout << "Copie de livre" << std::endl;
        this->_titre = src._titre;
        this->_pages = src._pages;
    }
    
    void afficher(void) const {
        std::cout << this->_titre << " (" << this->_pages << " pages)" << std::endl;
    }
};

int main() {
    Livre l1("C++ Guide", 500);
    
    Livre l2(l1);      // Appelle constructeur de copie
    Livre l3 = l1;     // Appelle aussi constructeur de copie !
    
    l1.afficher();
    l2.afficher();
}
```

**Signature obligatoire** : `Classe(const Classe& src)`
- `const` : pour pouvoir copier des objets constants
- `&` : référence (évite copie infinie)

### 4.2 Liste d'initialisation

**Méthode recommandée** pour initialiser les attributs.

```cpp
class Etudiant {
private:
    std::string _nom;
    int _age;
    double _moyenne;

public:
    // ❌ Méthode 1 : Initialisation dans le corps
    Etudiant(std::string nom, int age, double moy) {
        this->_nom = nom;
        this->_age = age;
        this->_moyenne = moy;
    }
    
    // ✅ Méthode 2 : Liste d'initialisation (RECOMMANDÉ)
    Etudiant(std::string nom, int age, double moy) 
        : _nom(nom), _age(age), _moyenne(moy) {
        // Corps vide, tout est déjà initialisé
    }
};
```

**Avantages** :
- Plus efficace (pas de construction puis assignation)
- Obligatoire pour : `const`, références, objets sans constructeur par défaut

```cpp
class Demo {
private:
    const int _id;          // const
    int& _ref;              // référence
    std::string _texte;

public:
    // ✅ OBLIGATOIRE pour _id et _ref
    Demo(int id, int& r, std::string txt) 
        : _id(id), _ref(r), _texte(txt) {
    }
};
```

**⚠️ Ordre d'initialisation** : Les membres sont initialisés dans l'ordre de leur **déclaration**, pas dans l'ordre de la liste !

```cpp
class Ordre {
private:
    int _a;
    int _b;

public:
    // ⚠️ ATTENTION : _a est initialisé AVANT _b (ordre déclaration)
    Ordre(int val) : _b(val), _a(_b * 2) {
        // Comportement indéfini ! _b pas encore initialisé quand on fait _b * 2
    }
    
    // ✅ CORRECT
    Ordre(int val) : _a(val), _b(_a * 2) {
        // OK : _a initialisé en premier
    }
};
```

### 4.3 Destructeurs

Un **destructeur** libère les ressources lors de la destruction d'un objet.

**Caractéristiques** :
- ✅ Nom : `~NomClasse()`
- ✅ Pas de paramètres
- ✅ Pas de type de retour
- ✅ Un seul par classe (pas de surcharge)
- ✅ Appelé automatiquement

```cpp
class Fichier {
private:
    int* _buffer;

public:
    Fichier(void) {
        this->_buffer = new int[100];
        std::cout << "Fichier ouvert" << std::endl;
    }
    
    ~Fichier(void) {
        delete[] this->_buffer;
        std::cout << "Fichier fermé" << std::endl;
    }
};

int main() {
    Fichier f;
    // Utilisation...
    return 0;  // Destructeur appelé automatiquement
}
```

**Quand est-il appelé ?**

```cpp
void fonction() {
    Fichier f1;         // Constructeur
    
    {
        Fichier f2;     // Constructeur
    }                   // Destructeur f2 (fin de portée)
    
    Fichier* f3 = new Fichier();
    delete f3;          // Destructeur f3 (manuel)
    
}                       // Destructeur f1 (fin fonction)
```

### 4.4 Forme Canonique Orthodoxe

**Toute classe devrait implémenter** :

```cpp
class MaClasse {
private:
    int* _data;

public:
    // 1. Constructeur par défaut
    MaClasse(void);
    
    // 2. Constructeur de copie
    MaClasse(const MaClasse& src);
    
    // 3. Opérateur d'affectation
    MaClasse& operator=(const MaClasse& rhs);
    
    // 4. Destructeur
    ~MaClasse(void);
};
```

**Exemple complet** :

```cpp
class Tableau {
private:
    int* _data;
    int _taille;

public:
    // 1. Constructeur par défaut
    Tableau(void) : _data(NULL), _taille(0) {
        std::cout << "Constructeur par défaut" << std::endl;
    }
    
    // Constructeur avec taille
    Tableau(int taille) : _taille(taille) {
        this->_data = new int[taille];
        for (int i = 0; i < taille; i++) {
            this->_data[i] = 0;
        }
        std::cout << "Constructeur(" << taille << ")" << std::endl;
    }
    
    // 2. Constructeur de copie
    Tableau(const Tableau& src) : _taille(src._taille) {
        std::cout << "Constructeur de copie" << std::endl;
        this->_data = new int[src._taille];  // Copie profonde
        for (int i = 0; i < this->_taille; i++) {
            this->_data[i] = src._data[i];
        }
    }
    
    // 3. Opérateur d'affectation
    Tableau& operator=(const Tableau& rhs) {
        std::cout << "Opérateur d'affectation" << std::endl;
        
        if (this != &rhs) {  // Protection auto-affectation
            delete[] this->_data;
            
            this->_taille = rhs._taille;
            this->_data = new int[rhs._taille];
            for (int i = 0; i < this->_taille; i++) {
                this->_data[i] = rhs._data[i];
            }
        }
        return *this;
    }
    
    // 4. Destructeur
    ~Tableau(void) {
        std::cout << "Destructeur" << std::endl;
        delete[] this->_data;
    }
    
    // Méthodes utiles
    int& operator[](int index) {
        return this->_data[index];
    }
};

int main() {
    Tableau t1(5);       // Constructeur(5)
    t1[0] = 10;
    t1[1] = 20;
    
    Tableau t2(t1);      // Constructeur de copie
    
    Tableau t3;          // Constructeur par défaut
    t3 = t1;             // Opérateur d'affectation
    
    return 0;            // 3 destructeurs appelés (ordre inverse)
}
```

**Différence constructeur de copie vs opérateur d'affectation** :

```cpp
Tableau t1(5);

Tableau t2(t1);    // Constructeur de copie (création + init)
Tableau t3 = t1;   // Constructeur de copie aussi !

Tableau t4;        // Constructeur par défaut
t4 = t1;           // Opérateur d'affectation (objet existe déjà)
```

### 4.5 Ordre d'appel

#### Objets locaux
```cpp
void test() {
    Personne p1("Alice");
    Personne p2("Bob");
    Personne p3("Charlie");
}
// Destructeurs en ordre INVERSE : p3, p2, p1 (LIFO)
```

#### Composition (objets membres)
```cpp
class Moteur {
public:
    Moteur() { std::cout << "Moteur créé" << std::endl; }
    ~Moteur() { std::cout << "Moteur détruit" << std::endl; }
};

class Voiture {
private:
    Moteur _moteur;

public:
    Voiture() { std::cout << "Voiture créée" << std::endl; }
    ~Voiture() { std::cout << "Voiture détruite" << std::endl; }
};

// Ordre :
// 1. Moteur créé (membre en premier)
// 2. Voiture créée
// 3. Voiture détruite
// 4. Moteur détruit (membre en dernier)
```

#### Héritage
```cpp
class Animal {
public:
    Animal() { std::cout << "Animal créé" << std::endl; }
    ~Animal() { std::cout << "Animal détruit" << std::endl; }
};

class Chien : public Animal {
public:
    Chien() { std::cout << "Chien créé" << std::endl; }
    ~Chien() { std::cout << "Chien détruit" << std::endl; }
};

// Ordre :
// 1. Animal créé (parent en premier)
// 2. Chien créé
// 3. Chien détruit
// 4. Animal détruit (parent en dernier)
```

---

## 5. Gestion de la mémoire

### 5.1 Allocation dynamique

En C++98, on utilise `new` et `delete` (pas de smart pointers).

```cpp
// Allocation simple
int* ptr = new int;        // Alloue un int
*ptr = 42;
delete ptr;                // Libère la mémoire

// Allocation avec initialisation
int* ptr2 = new int(100);  // Alloue et initialise à 100
delete ptr2;

// Allocation tableau
int* tab = new int[10];    // Alloue un tableau de 10 int
for (int i = 0; i < 10; i++) {
    tab[i] = i * 10;
}
delete[] tab;              // ⚠️ delete[] pour les tableaux !
```

**⚠️ RÈGLES CRITIQUES** :
- `new` → `delete`
- `new[]` → `delete[]`
- Jamais `delete` sur `new[]` (comportement indéfini)
- Libérer toute mémoire allouée (éviter fuites)

### 5.2 Exemple avec classe

```cpp
class Personne {
private:
    std::string _nom;
    int* _notes;
    int _nbNotes;

public:
    Personne(std::string nom, int nb) : _nom(nom), _nbNotes(nb) {
        this->_notes = new int[nb];  // Allocation
        for (int i = 0; i < nb; i++) {
            this->_notes[i] = 0;
        }
    }
    
    ~Personne(void) {
        delete[] this->_notes;  // Libération dans le destructeur
    }
    
    // Constructeur de copie (copie profonde)
    Personne(const Personne& src) : _nom(src._nom), _nbNotes(src._nbNotes) {
        this->_notes = new int[src._nbNotes];  // Nouvelle allocation
        for (int i = 0; i < this->_nbNotes; i++) {
            this->_notes[i] = src._notes[i];    // Copie des valeurs
        }
    }
};
```

### 5.3 Fuites mémoire

**Fuite mémoire** : Mémoire allouée jamais libérée.

```cpp
void fuiteMemoire() {
    int* ptr = new int[1000];
    // ... code ...
    // ⚠️ Pas de delete[] ! Fuite mémoire !
}

void correct() {
    int* ptr = new int[1000];
    // ... code ...
    delete[] ptr;  // ✓ Mémoire libérée
}
```

**En cas d'exception** :

```cpp
void risque() {
    int* ptr = new int[1000];
    
    if (erreur) {
        throw std::exception();  // ⚠️ ptr jamais libéré !
    }
    
    delete[] ptr;
}

void securise() {
    int* ptr = new int[1000];
    
    try {
        if (erreur) {
            throw std::exception();
        }
    } catch (...) {
        delete[] ptr;  // Libération même en cas d'exception
        throw;
    }
    
    delete[] ptr;
}
```

---

## 6. Templates

Les **templates** permettent la programmation générique.

### 6.1 Template de fonction

```cpp
// Template de fonction
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(10, 20) << std::endl;           // int
    std::cout << max(3.14, 2.71) << std::endl;       // double
    std::cout << max<int>(10, 20) << std::endl;      // Explicite
    
    // std::string nécessite operator>
    std::cout << max(std::string("abc"), std::string("def")) << std::endl;
}
```

### 6.2 Template de classe

```cpp
template <typename T>
class Boite {
private:
    T _contenu;

public:
    Boite(T contenu) : _contenu(contenu) {}
    
    T getContenu(void) const {
        return this->_contenu;
    }
    
    void setContenu(T contenu) {
        this->_contenu = contenu;
    }
};

int main() {
    Boite<int> boiteInt(42);
    Boite<std::string> boiteStr("Hello");
    Boite<double> boiteDouble(3.14);
    
    std::cout << boiteInt.getContenu() << std::endl;
    std::cout << boiteStr.getContenu() << std::endl;
}
```

### 6.3 Template avec plusieurs types

```cpp
template <typename K, typename V>
class Paire {
private:
    K _cle;
    V _valeur;

public:
    Paire(K cle, V valeur) : _cle(cle), _valeur(valeur) {}
    
    K getCle(void) const { return this->_cle; }
    V getValeur(void) const { return this->_valeur; }
};

int main() {
    Paire<std::string, int> age("Alice", 25);
    Paire<int, double> note(1, 18.5);
    
    std::cout << age.getCle() << " : " << age.getValeur() << std::endl;
}
```

### 6.4 Spécialisation de template

```cpp
// Template général
template <typename T>
class Afficheur {
public:
    static void afficher(T valeur) {
        std::cout << "Valeur : " << valeur << std::endl;
    }
};

// Spécialisation pour bool
template <>
class Afficheur<bool> {
public:
    static void afficher(bool valeur) {
        std::cout << (valeur ? "Vrai" : "Faux") << std::endl;
    }
};

int main() {
    Afficheur<int>::afficher(42);      // Valeur : 42
    Afficheur<bool>::afficher(true);   // Vrai
}
```

---

## 7. La STL (Standard Template Library)

### 7.1 Conteneurs séquentiels

#### `std::vector` - Tableau dynamique

```cpp
#include <vector>

std::vector<int> vec;

// Ajout
vec.push_back(10);
vec.push_back(20);
vec.push_back(30);

// Accès
std::cout << vec[0] << std::endl;      // 10
std::cout << vec.at(1) << std::endl;   // 20 (avec vérification)

// Taille
std::cout << vec.size() << std::endl;  // 3

// Parcours
for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
}

// Parcours avec itérateurs
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}

// Suppression
vec.pop_back();  // Retire le dernier élément
```

#### `std::list` - Liste doublement chaînée

```cpp
#include <list>

std::list<int> lst;

lst.push_back(10);
lst.push_front(5);
lst.push_back(20);

// Parcours
for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it << " ";  // 5 10 20
}
```

#### `std::deque` - Double-ended queue

```cpp
#include <deque>

std::deque<int> dq;

dq.push_back(10);
dq.push_front(5);
dq.push_back(20);

std::cout << dq.front() << std::endl;  // 5
std::cout << dq.back() << std::endl;   // 20
```

### 7.2 Conteneurs associatifs

#### `std::map` - Tableau associatif (clé → valeur)

```cpp
#include <map>

std::map<std::string, int> ages;

// Insertion
ages["Alice"] = 25;
ages["Bob"] = 30;
ages.insert(std::make_pair("Charlie", 35));

// Accès
std::cout << ages["Alice"] << std::endl;  // 25

// Vérifier existence
if (ages.find("David") != ages.end()) {
    std::cout << "David trouvé" << std::endl;
} else {
    std::cout << "David non trouvé" << std::endl;
}

// Parcours
for (std::map<std::string, int>::iterator it = ages.begin(); 
     it != ages.end(); ++it) {
    std::cout << it->first << " : " << it->second << std::endl;
}
```

#### `std::set` - Ensemble (valeurs uniques, triées)

```cpp
#include <set>

std::set<int> nombres;

nombres.insert(5);
nombres.insert(2);
nombres.insert(8);
nombres.insert(2);  // Ignoré (déjà présent)

// Parcours (ordre : 2, 5, 8)
for (std::set<int>::iterator it = nombres.begin(); it != nombres.end(); ++it) {
    std::cout << *it << " ";
}

// Recherche
if (nombres.find(5) != nombres.end()) {
    std::cout << "5 trouvé" << std::endl;
}
```

### 7.3 Adaptateurs de conteneurs

#### `std::stack` - Pile (LIFO)

```cpp
#include <stack>

std::stack<int> pile;

pile.push(10);
pile.push(20);
pile.push(30);

std::cout << pile.top() << std::endl;  // 30
pile.pop();
std::cout << pile.top() << std::endl;  // 20
```

#### `std::queue` - File (FIFO)

```cpp
#include <queue>

std::queue<int> file;

file.push(10);
file.push(20);
file.push(30);

std::cout << file.front() << std::endl;  // 10
file.pop();
std::cout << file.front() << std::endl;  // 20
```

### 7.4 Itérateurs

Les itérateurs sont des objets qui pointent vers des éléments de conteneurs.

```cpp
std::vector<int> vec;
vec.push_back(10);
vec.push_back(20);
vec.push_back(30);

// Iterator
std::vector<int>::iterator it;
for (it = vec.begin(); it != vec.end(); ++it) {
    *it *= 2;  // Modification
    std::cout << *it << " ";
}

// Const iterator
std::vector<int>::const_iterator cit;
for (cit = vec.begin(); cit != vec.end(); ++cit) {
    // *cit = 0;  // ✗ ERREUR : const
    std::cout << *cit << " ";
}

// Reverse iterator
std::vector<int>::reverse_iterator rit;
for (rit = vec.rbegin(); rit != vec.rend(); ++rit) {
    std::cout << *rit << " ";  // Ordre inverse
}
```

### 7.5 Algorithmes

```cpp
#include <algorithm>
#include <vector>

std::vector<int> vec;
vec.push_back(30);
vec.push_back(10);
vec.push_back(20);

// Tri
std::sort(vec.begin(), vec.end());  // 10, 20, 30

// Recherche
std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 20);
if (it != vec.end()) {
    std::cout << "20 trouvé à la position " << (it - vec.begin()) << std::endl;
}

// Compter
int count = std::count(vec.begin(), vec.end(), 20);

// Minimum/Maximum
int min = *std::min_element(vec.begin(), vec.end());
int max = *std::max_element(vec.begin(), vec.end());

// Inverser
std::reverse(vec.begin(), vec.end());  // 30, 20, 10
```

---

## 8. Références et pointeurs

### 8.1 Pointeurs

Un **pointeur** contient l'adresse mémoire d'une variable.

```cpp
int nombre = 42;
int* ptr = &nombre;  // ptr contient l'adresse de nombre

std::cout << nombre << std::endl;    // 42 (valeur)
std::cout << &nombre << std::endl;   // 0x7fff... (adresse)
std::cout << ptr << std::endl;       // 0x7fff... (même adresse)
std::cout << *ptr << std::endl;      // 42 (déréférencement)

*ptr = 100;  // Modifie nombre via le pointeur
std::cout << nombre << std::endl;    // 100
```

**Opérateurs** :
- `&` : Adresse de
- `*` : Déréférencement

**Pointeur NULL** :
```cpp
int* ptr = NULL;  // ou 0 en C++98 (pas nullptr)

if (ptr == NULL) {
    std::cout << "Pointeur null" << std::endl;
}
```

### 8.2 Références

Une **référence** est un alias pour une variable existante.

```cpp
int nombre = 42;
int& ref = nombre;  // ref est un alias de nombre

std::cout << nombre << std::endl;  // 42
std::cout << ref << std::endl;     // 42

ref = 100;  // Modifie nombre
std::cout << nombre << std::endl;  // 100
```

**Différences pointeur vs référence** :

| Pointeur | Référence |
|----------|-----------|
| Peut être NULL | Ne peut pas être NULL |
| Peut être réassigné | Ne peut pas être réassigné |
| Nécessite `*` pour déréférence | Utilisation directe |
| Syntaxe : `int* ptr` | Syntaxe : `int& ref` |

```cpp
int a = 10, b = 20;

// Pointeur
int* ptr = &a;
*ptr = 15;      // a = 15
ptr = &b;       // Réassignation
*ptr = 25;      // b = 25

// Référence
int& ref = a;
ref = 15;       // a = 15
// ref = b;     // ✗ N'est pas une réassignation, c'est a = b
int& ref2 = b;  // Il faut créer une nouvelle référence
```

### 8.3 Passage par valeur, pointeur, référence

```cpp
// Passage par valeur (copie)
void parValeur(int x) {
    x = 100;  // Ne modifie pas l'original
}

// Passage par pointeur
void parPointeur(int* ptr) {
    *ptr = 100;  // Modifie l'original
}

// Passage par référence
void parReference(int& ref) {
    ref = 100;  // Modifie l'original
}

int main() {
    int nombre = 42;
    
    parValeur(nombre);
    std::cout << nombre << std::endl;  // 42 (pas changé)
    
    parPointeur(&nombre);
    std::cout << nombre << std::endl;  // 100
    
    parReference(nombre);
    std::cout << nombre << std::endl;  // 100
}
```

**Quand utiliser quoi ?**
- **Valeur** : Petits types (int, char), pas de modification
- **Référence const** : Gros objets, lecture seule
- **Référence** : Modification de l'original
- **Pointeur** : Optionnel (peut être NULL), tableaux

```cpp
// Lecture seule de gros objet
void afficher(const std::string& str) {
    std::cout << str << std::endl;
    // str = "test";  // ✗ ERREUR : const
}

// Modification
void modifier(std::string& str) {
    str += " modifié";
}

// Optionnel
void traiter(int* ptr) {
    if (ptr != NULL) {
        std::cout << *ptr << std::endl;
    }
}
```

---

## 9. Exceptions

Les exceptions permettent la gestion d'erreurs.

### 9.1 Syntaxe de base

```cpp
try {
    // Code susceptible de lever une exception
    if (erreur) {
        throw std::exception();
    }
} catch (std::exception& e) {
    // Gestion de l'exception
    std::cout << "Erreur : " << e.what() << std::endl;
}
```

### 9.2 Types d'exceptions

```cpp
#include <stdexcept>

try {
    throw std::runtime_error("Erreur d'exécution");
} catch (std::runtime_error& e) {
    std::cout << e.what() << std::endl;
}

try {
    throw std::invalid_argument("Argument invalide");
} catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
}

try {
    throw std::out_of_range("Hors limites");
} catch (std::out_of_range& e) {
    std::cout << e.what() << std::endl;
}
```

### 9.3 Exceptions personnalisées

```cpp
class MonException : public std::exception {
private:
    std::string _message;

public:
    MonException(const std::string& msg) : _message(msg) {}
    
    virtual ~MonException() throw() {}
    
    virtual const char* what() const throw() {
        return this->_message.c_str();
    }
};

void fonction() {
    throw MonException("Erreur personnalisée");
}

int main() {
    try {
        fonction();
    } catch (MonException& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
}
```

### 9.4 Blocs catch multiples

```cpp
try {
    // Code...
    throw std::runtime_error("Erreur");
    
} catch (std::runtime_error& e) {
    std::cout << "Runtime error: " << e.what() << std::endl;
    
} catch (std::exception& e) {
    std::cout << "Exception générale: " << e.what() << std::endl;
    
} catch (...) {
    std::cout << "Exception inconnue" << std::endl;
}
```

**⚠️ Ordre important** : Attraper du plus spécifique au plus général !

### 9.5 Spécification d'exception (C++98)

```cpp
// Fonction qui peut lever std::runtime_error
void fonction1() throw(std::runtime_error) {
    throw std::runtime_error("Erreur");
}

// Fonction qui ne lève pas d'exception
void fonction2() throw() {
    // Code sans exception
}

// Fonction qui peut lever n'importe quoi
void fonction3() {
    throw 42;
}
```

**Note** : Les spécifications d'exception sont dépréciées en C++11 et retirées en C++17.

---

## 10. Outils utiles - stringstream

### 10.1 Qu'est-ce que stringstream ?

`std::stringstream` permet de traiter une chaîne comme un flux (stream).

```cpp
#include <sstream>
#include <string>

std::stringstream ss;
ss << "Bonjour" << " " << 42;

std::string resultat = ss.str();  // "Bonjour 42"
```

### 10.2 Conversions de types

#### String → Int

```cpp
std::string texte = "123";
std::stringstream ss(texte);
int nombre;

if (ss >> nombre) {
    std::cout << "Conversion réussie : " << nombre << std::endl;
} else {
    std::cout << "Échec de conversion" << std::endl;
}
```

#### Int → String

```cpp
int nombre = 42;
std::stringstream ss;
ss << nombre;
std::string texte = ss.str();  // "42"
```

#### Validation complète

```cpp
std::string input = "123";
std::stringstream ss(input);
int nombre;

// Vérifie conversion ET qu'il n'y a rien après
if ((ss >> nombre) && ss.eof()) {
    std::cout << "Valide : " << nombre << std::endl;
} else {
    std::cout << "Invalide" << std::endl;
}

// Exemples :
// "123"    → Valide
// "123abc" → Invalide (reste "abc")
// "abc"    → Invalide (conversion échoue)
```

### 10.3 Parser des données

```cpp
std::string ligne = "Alice 25 1.75";
std::stringstream ss(ligne);

std::string nom;
int age;
double taille;

ss >> nom >> age >> taille;

std::cout << "Nom: " << nom << std::endl;
std::cout << "Age: " << age << std::endl;
std::cout << "Taille: " << taille << std::endl;
```

### 10.4 Split une chaîne

```cpp
#include <vector>

std::vector<std::string> split(const std::string& str) {
    std::vector<std::string> resultat;
    std::stringstream ss(str);
    std::string mot;
    
    while (ss >> mot) {
        resultat.push_back(mot);
    }
    
    return resultat;
}

int main() {
    std::string phrase = "Bonjour tout le monde";
    std::vector<std::string> mots = split(phrase);
    
    for (size_t i = 0; i < mots.size(); i++) {
        std::cout << mots[i] << std::endl;
    }
}
```

### 10.5 Construire une chaîne complexe

```cpp
std::string creerMessage(const std::string& nom, int age, double score) {
    std::stringstream ss;
    
    ss << "Joueur: " << nom;
    ss << ", Age: " << age;
    ss << ", Score: " << score;
    
    return ss.str();
}

int main() {
    std::string msg = creerMessage("Alice", 25, 95.5);
    std::cout << msg << std::endl;
    // Joueur: Alice, Age: 25, Score: 95.5
}
```

### 10.6 Méthodes utiles

```cpp
std::stringstream ss;

// État
ss.good();      // Tout va bien ?
ss.eof();       // Fin du flux ?
ss.fail();      // Échec d'opération ?
ss.bad();       // Erreur grave ?

// Manipulation
ss.clear();     // Réinitialiser l'état
ss.str("");     // Vider le contenu
ss.str("text"); // Définir nouveau contenu

// Position
ss.tellg();     // Position de lecture
ss.seekg(0);    // Retour au début
```

### 10.7 Exemple complet : Validation d'entrée

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <limits>

int demanderEntier(const std::string& message, int min, int max) {
    while (true) {
        std::cout << message;
        
        std::string input;
        if (!std::getline(std::cin, input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Erreur de lecture" << std::endl;
            continue;
        }
        
        std::stringstream ss(input);
        int nombre;
        
        if (!(ss >> nombre) || !(ss.eof())) {
            std::cout << "Veuillez entrer un nombre valide." << std::endl;
            continue;
        }
        
        if (nombre < min || nombre > max) {
            std::cout << "Nombre hors limites (" << min << "-" << max << ")" << std::endl;
            continue;
        }
        
        return nombre;
    }
}

int main() {
    int age = demanderEntier("Entrez votre âge (0-120) : ", 0, 120);
    std::cout << "Votre âge : " << age << std::endl;
    
    return 0;
}
```

---

## Points clés à retenir

### ✅ Bonnes pratiques C++98

1. **Toujours** utiliser la liste d'initialisation dans les constructeurs
2. **Toujours** implémenter la forme canonique orthodoxe pour les classes gérant des ressources
3. **Libérer** toute mémoire allouée avec `new` (utiliser `delete`)
4. Utiliser `std::` explicitement dans les fichiers `.hpp`
5. Marquer les méthodes qui ne modifient pas l'objet avec `const`
6. Protéger les includes avec des guards (`#ifndef`/`#define`/`#endif`)
7. Préférer les références const pour passer de gros objets

### ⚠️ Pièges courants

1. Oublier `delete` après `new` (fuite mémoire)
2. Utiliser `delete` sur `new[]` (utiliser `delete[]`)
3. Ne pas implémenter le constructeur de copie (copie superficielle par défaut)
4. Oublier de vérifier `NULL` avant déréférencement
5. Ne pas respecter l'ordre d'initialisation dans la liste
6. Utiliser `using namespace std;` dans les `.hpp`

### 🎯 Limitations C++98

**Pas de** :
- `auto`
- `nullptr` (utiliser `NULL` ou `0`)
- Range-based for loops (`for (int x : vec)`)
- Lambda functions
- Smart pointers (`unique_ptr`, `shared_ptr`)
- Move semantics
- Initializer lists `{}`
- `override` et `final`

---

## Exemple de projet complet

```cpp
// Student.hpp
#ifndef STUDENT_HPP
# define STUDENT_HPP

# include <string>
# include <iostream>

class Student {
private:
    std::string _name;
    int _age;
    double* _grades;
    int _gradeCount;

public:
    // Constructeurs
    Student(void);
    Student(const std::string& name, int age);
    Student(const Student& src);
    
    // Destructeur
    ~Student(void);
    
    // Opérateur d'affectation
    Student& operator=(const Student& rhs);
    
    // Getters
    std::string getName(void) const;
    int getAge(void) const;
    double getAverage(void) const;
    
    // Setters
    void setName(const std::string& name);
    void setAge(int age);
    
    // Méthodes
    void addGrade(double grade);
    void display(void) const;
};

#endif

// Student.cpp
#include "Student.hpp"

Student::Student(void) 
    : _name("Unknown"), _age(0), _grades(NULL), _gradeCount(0) {
    std::cout << "Default constructor called" << std::endl;
}

Student::Student(const std::string& name, int age) 
    : _name(name), _age(age), _grades(NULL), _gradeCount(0) {
    std::cout << "Parametric constructor called" << std::endl;
}

Student::Student(const Student& src) 
    : _name(src._name), _age(src._age), _gradeCount(src._gradeCount) {
    std::cout << "Copy constructor called" << std::endl;
    
    if (src._gradeCount > 0) {
        this->_grades = new double[src._gradeCount];
        for (int i = 0; i < this->_gradeCount; i++) {
            this->_grades[i] = src._grades[i];
        }
    } else {
        this->_grades = NULL;
    }
}

Student::~Student(void) {
    std::cout << "Destructor called" << std::endl;
    delete[] this->_grades;
}

Student& Student::operator=(const Student& rhs) {
    std::cout << "Assignment operator called" << std::endl;
    
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_age = rhs._age;
        
        delete[] this->_grades;
        
        this->_gradeCount = rhs._gradeCount;
        if (rhs._gradeCount > 0) {
            this->_grades = new double[rhs._gradeCount];
            for (int i = 0; i < this->_gradeCount; i++) {
                this->_grades[i] = rhs._grades[i];
            }
        } else {
            this->_grades = NULL;
        }
    }
    
    return *this;
}

std::string Student::getName(void) const {
    return this->_name;
}

int Student::getAge(void) const {
    return this->_age;
}

double Student::getAverage(void) const {
    if (this->_gradeCount == 0)
        return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < this->_gradeCount; i++) {
        sum += this->_grades[i];
    }
    return sum / this->_gradeCount;
}

void Student::setName(const std::string& name) {
    this->_name = name;
}

void Student::setAge(int age) {
    if (age >= 0 && age <= 120) {
        this->_age = age;
    }
}

void Student::addGrade(double grade) {
    double* newGrades = new double[this->_gradeCount + 1];
    
    for (int i = 0; i < this->_gradeCount; i++) {
        newGrades[i] = this->_grades[i];
    }
    newGrades[this->_gradeCount] = grade;
    
    delete[] this->_grades;
    this->_grades = newGrades;
    this->_gradeCount++;
}

void Student::display(void) const {
    std::cout << "Name: " << this->_name << std::endl;
    std::cout << "Age: " << this->_age << std::endl;
    std::cout << "Average: " << this->getAverage() << std::endl;
}

// main.cpp
#include "Student.hpp"

int main() {
    Student s1("Alice", 20);
    s1.addGrade(15.5);
    s1.addGrade(18.0);
    s1.addGrade(16.5);
    s1.display();
    
    Student s2(s1);  // Copie
    s2.setName("Bob");
    s2.display();
    
    Student s3;
    s3 = s1;  // Affectation
    s3.setName("Charlie");
    s3.display();
    
    return 0;
}
```

---

**Fin du cours C++98**