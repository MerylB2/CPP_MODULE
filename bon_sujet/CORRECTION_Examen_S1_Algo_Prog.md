# CORRECTION - Examen Semestre 1
## Module Algorithmique & Programmation
**TC101 - Python & JavaScript**

**Formatrice :** Mme Méryl BITEE  
**Barème total :** /100 points

---

## PARTIE 1 : QUESTIONS DE COURS (30 points)

### Question 1.1 : Algorithmique et Représentation (8 points)

#### a) Qu'est-ce qu'un algorithme ? (4 points)

**Réponse attendue :**

Un algorithme est une suite finie d'instructions précises et non ambiguës qui permettent de résoudre un problème ou d'effectuer une tâche.

**Deux caractéristiques importantes :**
1. **Finitude** : L'algorithme doit se terminer après un nombre fini d'étapes
2. **Exactitude** : L'algorithme doit produire le résultat correct pour toutes les entrées valides

**Autres caractéristiques acceptables :**
- Généralité : fonctionne pour une classe de problèmes
- Définition précise : chaque étape est clairement définie
- Efficacité : utilise des ressources de manière raisonnable

**Barème :**
- Définition correcte : 2 points
- Première caractéristique : 1 point
- Deuxième caractéristique : 1 point

---

#### b) Différence organigramme vs pseudo-code (4 points)

**Réponse attendue :**

**Différence :**
- **Organigramme** : Représentation graphique/visuelle utilisant des symboles géométriques (rectangles pour actions, losanges pour conditions, flèches pour le flux)
- **Pseudo-code** : Représentation textuelle en langage naturel structuré, proche de la programmation mais sans syntaxe stricte

**Exemple : "Vérifier si un nombre est positif, négatif ou nul"**

**Pseudo-Code :**
```
ALGORITHME VerifierNombre
DEBUT
    Lire nombre
    
    SI nombre > 0 ALORS
        Afficher "Positif"
    SINON SI nombre < 0 ALORS
        Afficher "Négatif"
    SINON
        Afficher "Nul"
    FIN SI
FIN
```

**Organigramme :**
```
        ┌─────────────┐
        │   Début     │
        └──────┬──────┘
               │
        ┌──────▼──────┐
        │ Lire nombre │
        └──────┬──────┘
               │
         ┌─────▼─────┐
         │ nombre > 0│ ───OUI──► Afficher "Positif"
         └─────┬─────┘                  │
               │NON                     │
         ┌─────▼─────┐                  │
         │ nombre < 0│ ───OUI──► Afficher "Négatif"
         └─────┬─────┘                  │
               │NON                     │
        ┌──────▼──────┐                 │
        │Afficher "Nul"│                │
        └──────┬──────┘                 │
               └────────────────────────┘
               │
        ┌──────▼──────┐
        │     Fin     │
        └─────────────┘
```

**Barème :**
- Explication organigramme : 1 point
- Explication pseudo-code : 1 point
- Exemple pseudo-code correct : 1 point
- Exemple organigramme avec symboles : 1 point

**Note :** L'organigramme peut être dessiné à la main, tant qu'il contient les bons symboles (losanges pour conditions, rectangles pour actions)

---

### Question 1.2 : Types de données et Variables (7 points)

#### a) Types de valeurs Python (4 points)

**Réponse attendue :**

| Valeur | Type | Explication |
|--------|------|-------------|
| `42` | `int` | Nombre entier (sans décimales) |
| `"42"` | `str` | Chaîne de caractères (entre guillemets) |
| `3.14` | `float` | Nombre à virgule flottante (avec décimales) |
| `True` | `bool` | Valeur booléenne (Vrai ou Faux) |

**Barème :**
- Chaque type correct : 0,5 point × 4 = 2 points
- Chaque explication pertinente : 0,5 point × 4 = 2 points
- **Total : 4 points**

---

#### b) Créer une liste et accéder au premier élément (3 points)

**Réponse attendue :**

**Version 1 (code complet) :**
```python
# Créer une liste
ma_liste = [10, 20, 30, 40]

# Accéder au premier élément (index 0)
premier = ma_liste[0]  # Vaut 10
print(premier)  # Affiche 10
```

**Version 2 (explication textuelle) :**
```
Pour créer une liste en Python, on utilise des crochets [ ] avec des éléments séparés par des virgules.
Exemple : ma_liste = [10, 20, 30]

Pour accéder au premier élément, on utilise l'index 0 entre crochets.
Exemple : ma_liste[0] retourne le premier élément.
```

**Barème :**
- Syntaxe de création correcte : 1,5 point
- Accès avec index [0] : 1,5 point
- **Total : 3 points**

**Variantes acceptées :**
- Avec ou sans variable intermédiaire
- Avec `print()` ou sans

---

### Question 1.3 : Complexité algorithmique (8 points)

#### a) Complexité de la fonction chercher() (4 points)

**Code :**
```python
def chercher(liste, element):
    for item in liste:
        if item == element:
            return True
    return False
```

**Réponse attendue :**

**Complexité : O(N)**

**Justification :**
La fonction parcourt la liste élément par élément avec une boucle `for`. Dans le pire des cas (l'élément n'est pas dans la liste ou est en dernière position), elle doit examiner tous les N éléments de la liste. Le temps d'exécution est donc proportionnel à la taille de la liste.

**Barème :**
- Complexité O(N) correcte : 2 points
- Justification claire et correcte : 2 points
- **Total : 4 points**

**Justifications acceptables :**
- "Parcours complet dans le pire cas"
- "Boucle qui examine chaque élément"
- "Proportionnel au nombre d'éléments"

---

#### b) Comparaison Tri à bulles vs Tri fusion (4 points)

**Réponse attendue :**

**Comparaison :**
- **Tri à bulles (Bubble Sort)** : O(N²) dans le cas moyen et pire cas
- **Tri fusion (Merge Sort)** : O(N log N) dans tous les cas

**Choix pour une grande liste :**
Je choisirais le **Tri fusion** car sa complexité O(N log N) est bien meilleure que O(N²) pour de grandes quantités de données.

**Exemple concret :**
- Pour N = 1000 éléments :
  - Tri à bulles : environ 1 000 000 d'opérations
  - Tri fusion : environ 10 000 opérations
  
Le tri fusion est donc beaucoup plus rapide pour trier de grandes listes.

**Barème :**
- Complexité Bubble Sort correcte : 1 point
- Complexité Merge Sort correcte : 1 point
- Choix justifié (Merge Sort) : 1 point
- Explication de la différence d'efficacité : 1 point
- **Total : 4 points**

---

### Question 1.4 : Python et JavaScript (7 points)

#### a) [PYTHON] Fonction multiplier (4 points)

**Réponse attendue :**

**Version complète :**
```python
def multiplier(a, b):
    resultat = a * b
    return resultat

# Utilisation
print(multiplier(4, 5))  # Affiche 20
```

**Version simplifiée (aussi acceptée) :**
```python
def multiplier(a, b):
    return a * b
```

**Barème :**
- Définition avec `def` : 0,5 point
- Nom correct `multiplier` : 0,5 point
- Deux paramètres (a, b) : 0,5 point
- Calcul du produit `a * b` : 1,5 point
- Instruction `return` : 1 point
- **Total : 4 points**

**Pénalités :**
- Si utilise `print()` au lieu de `return` : -1 point
- Si syntaxe incorrecte : -0,5 point

---

#### b) [JAVASCRIPT] let, const et var (3 points)

**Réponse attendue :**

**Explication :**

- **`let`** : Déclare une variable modifiable, portée de bloc (block scope), ne peut pas être redéclarée
- **`const`** : Déclare une constante, valeur non modifiable après déclaration, portée de bloc
- **`var`** : Ancienne méthode, portée de fonction, peut être redéclarée (à éviter en JavaScript moderne)

**Exemples :**

```javascript
// let - variable modifiable
let age = 25;
age = 26;  // OK : modification autorisée

// const - constante
const PI = 3.14;
PI = 3.15;  // ERREUR : modification interdite

// var - ancienne méthode
var nom = "Alice";
var nom = "Bob";  // OK mais déconseillé
```

**Barème :**
- Explication `let` : 0,5 point + exemple : 0,5 point = 1 point
- Explication `const` : 0,5 point + exemple : 0,5 point = 1 point
- Explication `var` : 0,5 point + exemple : 0,5 point = 1 point
- **Total : 3 points**

**Note :** Si l'étudiant n'explique que `let` et `const` (oublie `var`) : 2/3

---

## PARTIE 2 : QCM (25 points)

**Barème :** 1,25 point par bonne réponse × 20 questions = 25 points

### Section A : Python/JavaScript (15 points)

| Question | Réponse correcte | Explication |
|----------|------------------|-------------|
| 2.1 | **B) [1, 2, 3, 4]** | `y` est une référence à `x`, donc modifier `y` modifie aussi `x` |
| 2.2 | **B) string.upper()** | Méthode Python pour convertir en majuscules |
| 2.3 | **B) 4** | `append([4, 5])` ajoute la liste comme un seul élément |
| 2.4 | **B) "53"** | En JS, `+` concatène les chaînes, donc "5" + 3 = "53" |
| 2.5 | **B) list.sort()** | Trie la liste sur place (modifie l'original) |
| 2.6 | **B) Passe à l'itération suivante** | `continue` saute le reste de la boucle actuelle |
| 2.7 | **A) O(1)** | `append()` ajoute en temps constant |
| 2.8 | **A) [0] * 10** | Crée une liste de 10 zéros |
| 2.9 | **B) False** | Une chaîne vide est évaluée à `False` |
| 2.10 | **A) var {name, age} = person** | Destructuring d'objet en JavaScript |
| 2.11 | **B) Retourne ["Hello", "World"]** | `split()` sépare sur les espaces |
| 2.12 | **A) "ell"** | Slicing de l'index 1 à 3 (4 exclu) |

### Section B : Git & GitHub (10 points)

| Question | Réponse correcte | Explication |
|----------|------------------|-------------|
| 2.13 | **C) git init** | Initialise un nouveau dépôt Git |
| 2.14 | **B) git status** | Affiche l'état des fichiers |
| 2.15 | **B) Ajoute tous les fichiers modifiés** | `.` signifie "tous les fichiers" |
| 2.16 | **B) git commit -m "message"** | Valide les changements avec un message |
| 2.17 | **B) Envoie les commits locaux vers le dépôt distant** | Push = pousser vers le serveur |
| 2.18 | **C) git pull** | Récupère ET fusionne les modifications distantes |
| 2.19 | **B) Une ligne de développement indépendante** | Définition d'une branche |
| 2.20 | **C) git checkout -b nouvelle-branche** | Crée et bascule en une commande |

---

## PARTIE 3 : EXERCICES PRATIQUES (45 points)

### Exercice 3.1 : Conversion de température (10 points)

**Solution Python :**

```python
# Lecture de la température en Celsius
celsius = float(input())

# Conversion en Fahrenheit
fahrenheit = (celsius * 9/5) + 32

# Affichage avec 2 décimales
print(f"{fahrenheit:.2f}")
```

**Solution JavaScript :**

```javascript
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('', (celsius) => {
    const fahrenheit = (parseFloat(celsius) * 9/5) + 32;
    console.log(fahrenheit.toFixed(2));
    rl.close();
});
```

**Grille de notation :**
- Lecture de la température : 2 pts
- Conversion avec `float()` ou `parseFloat()` : 1 pt
- Application correcte de la formule : 3 pts
- Formatage avec 2 décimales (`.2f` ou `toFixed(2)`) : 3 pts
- Gestion des cas limites (tests passent) : 1 pt
- **Total : 10 points**

**Tests de validation :**
- C = 0 → F = 32.00 ✓
- C = 100 → F = 212.00 ✓
- C = -40 → F = -40.00 ✓
- C = 25.5 → F = 77.90 ✓

---

### Exercice 3.2 : Année bissextile (12 points)

**Solution Python :**

```python
# Lecture de l'année
annee = int(input())

# Logique bissextile
if annee % 400 == 0:
    print("Bissextile")
elif annee % 100 == 0:
    print("Non bissextile")
elif annee % 4 == 0:
    print("Bissextile")
else:
    print("Non bissextile")
```

**Solution alternative (plus concise) :**

```python
annee = int(input())

if (annee % 4 == 0 and annee % 100 != 0) or (annee % 400 == 0):
    print("Bissextile")
else:
    print("Non bissextile")
```

**Solution JavaScript :**

```javascript
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('', (input) => {
    const annee = parseInt(input);
    
    if (annee % 400 === 0) {
        console.log("Bissextile");
    } else if (annee % 100 === 0) {
        console.log("Non bissextile");
    } else if (annee % 4 === 0) {
        console.log("Bissextile");
    } else {
        console.log("Non bissextile");
    }
    
    rl.close();
});
```

**Grille de notation :**
- Lecture de l'année avec conversion `int()` : 1 pt
- Test divisible par 4 : 3 pts
- Test exception 100 : 3 pts
- Test exception 400 : 3 pts
- Affichage correct : 2 pts
- **Total : 12 points**

**Tests de validation :**
- 2000 → Bissextile ✓
- 1900 → Non bissextile ✓
- 2024 → Bissextile ✓
- 2023 → Non bissextile ✓

---

### Exercice 3.3 : Table de multiplication (10 points)

**Solution Python :**

```python
# Lecture du nombre
n = int(input())

# Boucle for de 1 à 10
for i in range(1, 11):
    resultat = n * i
    print(f"{n} x {i} = {resultat}")
```

**Solution JavaScript :**

```javascript
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('', (input) => {
    const n = parseInt(input);
    
    for (let i = 1; i <= 10; i++) {
        const resultat = n * i;
        console.log(`${n} x ${i} = ${resultat}`);
    }
    
    rl.close();
});
```

**Grille de notation :**
- Lecture de N avec conversion : 2 pts
- Boucle `for` de 1 à 10 correcte : 3 pts
- Calcul du produit correct : 2 pts
- Formatage exact "N x i = résultat" : 3 pts
- **Total : 10 points**

**Test de validation :**
Pour N = 7 :
```
7 x 1 = 7
7 x 2 = 14
7 x 3 = 21
7 x 4 = 28
7 x 5 = 35
7 x 6 = 42
7 x 7 = 49
7 x 8 = 56
7 x 9 = 63
7 x 10 = 70
```

---

### Exercice 3.4 : Débogage - Analyseur de liste (13 points)

#### LISTE DES 10 ERREURS DANS LE CODE :

| # | Ligne | Erreur | Type | Correction |
|---|-------|--------|------|------------|
| 1 | `n = input(...)` | `n` reste une chaîne | Type | `n = int(input(...))` |
| 2 | `nombres = input().split()` | Reste liste de chaînes | Type | Convertir en entiers |
| 3 | `minimum = 0` | Mauvaise initialisation | Logique | `minimum = nombres[0]` |
| 4 | `maximum = 0` | Mauvaise initialisation | Logique | `maximum = nombres[0]` |
| 5 | `range(n)` | n est string si erreur 1 | Type | n doit être int |
| 6 | `nombre = nombres[i]` | Reste string | Type | `nombre = int(nombres[i])` |
| 7 | `if nombre < maximum` | Mauvaise condition | Logique | `if nombre > maximum` |
| 8 | `if nombre % 2 = 0` | Syntaxe incorrecte | Syntaxe | `if nombre % 2 == 0` |
| 9 | `impairs = pairs + 1` | Mauvaise variable | Logique | `impairs = impairs + 1` |
| 10 | `moyenne = somme / len(nombres)` | Pas de format 2 déc. | Format | `round(moyenne, 2)` |

#### CODE CORRIGÉ :

```python
# Programme d'analyse de liste (CORRIGÉ)

# Lecture des données
n = int(input("Nombre d'éléments: "))  # ERREUR 1 CORRIGÉE
print("Entrez les nombres séparés par des espaces:")
nombres_str = input().split()

# Conversion en entiers - ERREUR 2 CORRIGÉE
nombres = []
for num_str in nombres_str:
    nombres.append(int(num_str))

# Initialisation des variables - ERREURS 3 et 4 CORRIGÉES
somme = 0
minimum = nombres[0]  # Initialiser avec le premier élément
maximum = nombres[0]  # Initialiser avec le premier élément
pairs = 0
impairs = 0

# Calculs
for i in range(n):  # n est maintenant int (erreur 5 corrigée)
    nombre = int(nombres[i])  # ERREUR 6 CORRIGÉE (ou déjà int si conversion faite avant)
    
    # Somme
    somme = somme + nombre
    
    # Min et Max
    if nombre < minimum:
        minimum = nombre
    if nombre > maximum:  # ERREUR 7 CORRIGÉE : > au lieu de <
        maximum = nombre
    
    # Pairs et impairs
    if nombre % 2 == 0:  # ERREUR 8 CORRIGÉE : == au lieu de =
        pairs = pairs + 1
    else:
        impairs = impairs + 1  # ERREUR 9 CORRIGÉE : impairs au lieu de pairs

# Calcul de la moyenne avec 2 décimales - ERREUR 10 CORRIGÉE
moyenne = round(somme / len(nombres), 2)

# Affichage
print("=== ANALYSE DE LA LISTE ===")
print("Nombre d'éléments:", len(nombres))
print("Somme:", somme)
print(f"Moyenne: {moyenne:.2f}")
print("Minimum:", minimum)
print("Maximum:", maximum)
print("Nombres pairs:", pairs)
print("Nombres impairs:", impairs)
```

**VERSION OPTIMISÉE (bonus) :**

```python
# Version plus pythonique
n = int(input())
nombres = list(map(int, input().split()))

# Initialisation
somme = 0
minimum = nombres[0]
maximum = nombres[0]
pairs = 0
impairs = 0

# Calculs
for nombre in nombres:
    somme += nombre
    
    if nombre < minimum:
        minimum = nombre
    if nombre > maximum:
        maximum = nombre
    
    if nombre % 2 == 0:
        pairs += 1
    else:
        impairs += 1

# Moyenne
moyenne = somme / len(nombres)

# Affichage
print("=== ANALYSE DE LA LISTE ===")
print(f"Nombre d'éléments: {len(nombres)}")
print(f"Somme: {somme}")
print(f"Moyenne: {moyenne:.2f}")
print(f"Minimum: {minimum}")
print(f"Maximum: {maximum}")
print(f"Nombres pairs: {pairs}")
print(f"Nombres impairs: {impairs}")
```

**Grille de notation :**

**Partie 1 : Identification des erreurs (7 points)**
- Minimum 7 erreurs identifiées correctement sur 10
- 1 point par erreur correctement identifiée
- Si plus de 7 erreurs trouvées : bonus possible

**Partie 2 : Code corrigé fonctionnel (6 points)**
- Conversion de n en int : 0,5 pt
- Conversion des nombres en int : 1 pt
- Initialisation min/max correcte : 1 pt
- Condition maximum corrigée : 1 pt
- Syntaxe `==` pour comparaison : 0,5 pt
- Variable impairs correcte : 1 pt
- Format moyenne 2 décimales : 1 pt

**Total : 13 points**

**Test de validation :**
```
Entrée:
6
12 7 23 8 15 4

Sortie attendue:
=== ANALYSE DE LA LISTE ===
Nombre d'éléments: 6
Somme: 69
Moyenne: 11.50
Minimum: 4
Maximum: 23
Nombres pairs: 3
Nombres impairs: 3
```

---

## RÉCAPITULATIF DES BARÈMES

| Partie | Points | Détail |
|--------|--------|--------|
| **PARTIE 1** | **/30** | Questions de cours |
| Question 1.1 | 8 pts | Algorithmique (4+4) |
| Question 1.2 | 7 pts | Types de données (4+3) |
| Question 1.3 | 8 pts | Complexité (4+4) |
| Question 1.4 | 7 pts | Python/JavaScript (4+3) |
| **PARTIE 2** | **/25** | QCM |
| Section A | 15 pts | Python/JavaScript (12 × 1,25) |
| Section B | 10 pts | Git/GitHub (8 × 1,25) |
| **PARTIE 3** | **/45** | Exercices pratiques |
| Exercice 3.1 | 10 pts | Conversion température |
| Exercice 3.2 | 12 pts | Année bissextile |
| Exercice 3.3 | 10 pts | Table de multiplication |
| Exercice 3.4 | 13 pts | Débogage analyseur (7+6) |
| **TOTAL** | **/100** | |

---

## CONSEILS DE CORRECTION

### Tolérance et barème souple :

1. **Questions de cours :**
   - Accepter les formulations équivalentes
   - Si l'idée est correcte mais mal exprimée : 70% des points
   - Pénaliser les réponses incomplètes proportionnellement

2. **QCM :**
   - Tout ou rien : 1,25 pt ou 0 pt
   - Réponses multiples = 0 pt

3. **Exercices pratiques :**
   - Code fonctionnel mais peu optimisé : points complets
   - Erreurs de syntaxe mineures : -0,5 pt
   - Logique correcte mais non testé : -1 pt
   - Utilisation de fonctions interdites (`sum()`, `min()`, `max()`) : -2 pts

### Points bonus possibles :

- Code particulièrement élégant : +0,5 pt
- Gestion de cas limites non demandés : +0,5 pt
- Commentaires pertinents : +0,5 pt
- **Maximum bonus : +2 points par exercice**

---

## ÉCHELLE DE NOTATION FINALE

| Note /100 | Note /20 | Appréciation | Niveau |
|-----------|----------|--------------|--------|
| 90-100 | 18-20 | Excellent | Maîtrise complète |
| 80-89 | 16-17,9 | Très bien | Très bonne maîtrise |
| 70-79 | 14-15,9 | Bien | Bonne maîtrise |
| 60-69 | 12-13,9 | Assez bien | Maîtrise satisfaisante |
| 50-59 | 10-11,9 | Passable | Connaissances de base |
| < 50 | < 10 | Insuffisant | Lacunes importantes |

---

**Fin de la correction**

*Document préparé par : Mme Méryl BITEE*  
*Green UP Academy - TC101 - Semestre 1*
