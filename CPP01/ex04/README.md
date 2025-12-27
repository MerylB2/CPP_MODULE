# Ex04 - Sed is for losers

## Consigne

Créer un programme qui prend trois paramètres dans l'ordre suivant : un nom de fichier et deux chaînes de caractères, s1 et s2.

Le programme doit :
- Ouvrir le fichier `<filename>`
- Copier son contenu dans un nouveau fichier `<filename>.replace`
- Remplacer chaque occurrence de s1 par s2

**Contraintes :**
- L'utilisation des fonctions de manipulation de fichiers C est interdite
- `std::string::replace` est interdit
- Toutes les autres fonctions membres de `std::string` sont autorisées

## Implémentation

### Fichiers
- `main.cpp` : Programme principal
- `Makefile` : Compilation

### Algorithme
1. **Validation des arguments** : Vérifier qu'exactement 3 paramètres sont fournis
2. **Ouverture du fichier** : Utiliser `std::ifstream` pour lire le fichier source
3. **Lecture du contenu** : Lire le fichier ligne par ligne avec `std::getline`
4. **Remplacement** : Utiliser `std::string::find` et `std::string::substr` pour remplacer s1 par s2
5. **Écriture** : Créer le fichier `.replace` avec `std::ofstream`

### Fonction de remplacement
```cpp
std::string replaceString(const std::string& content, const std::string& s1, const std::string& s2)
```
- Parcourt le contenu et trouve chaque occurrence de s1
- Construit une nouvelle chaîne en remplaçant s1 par s2
- Gère le cas où s1 est vide (retourne le contenu original)

### Gestion d'erreurs
- Vérification du nombre d'arguments
- Vérification de l'ouverture des fichiers
- Messages d'erreur appropriés

## Utilisation

```bash
make
./replace <filename> <s1> <s2>
```

Exemple :
```bash
./replace test.txt "hello" "bonjour"
```
Cela créera `test.txt.replace` avec tous les "hello" remplacés par "bonjour".