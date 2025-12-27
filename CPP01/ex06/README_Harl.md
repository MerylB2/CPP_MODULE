# Exercices Harl - Ex05 et Ex06

## Vue d'ensemble

Ces deux exercices implémentent un système de gestion des plaintes de Harl, un personnage qui se plaint constamment dans un restaurant. L'objectif est d'apprendre les **pointeurs vers fonctions membres** (ex05) et les **switch statements** (ex06).

---

## Ex05 - Harl 2.0

### Objectif
Créer une classe Harl qui utilise des **pointeurs vers fonctions membres** pour éviter les structures `if/else if/else`.

### Contraintes
- Utiliser obligatoirement des pointeurs vers fonctions membres
- Pas de "forêt de if/else if/else" 
- Harl ne réfléchit pas deux fois !

### Implémentation

#### Structure de la classe
```cpp
class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    void complain(std::string level);
};
```

#### Technique des pointeurs vers fonctions membres
```cpp
void Harl::complain(std::string level)
{
    typedef void (Harl::*HarlFunction)(void);
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    HarlFunction functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    for (int i = 0; i < 4; i++)
    {
        while (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    }
    
    std::cout << "[ UNKNOWN ]" << std::endl << "Unknown level: " << level << std::endl;
}
```

### Utilisation
```bash
make
./Harl          # Exécute tous les tests automatiquement
```

### Messages de Harl
- **DEBUG** : "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
- **INFO** : "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!"
- **WARNING** : "I think I deserve to have some extra bacon for free. I've been coming for years..."
- **ERROR** : "This is unacceptable! I want to speak to the manager now."

---

## Ex06 - harlFilter

### Objectif
Implémenter un système de **filtrage** qui affiche tous les messages **du niveau demandé et au-dessus**. Utilisation obligatoire du **switch statement**.

### Contraintes
- Utiliser le switch statement (pas de if/else)
- Filtrer "niveau et au-dessus"
- Exécutable nommé `harlFilter`

### Implémentation

#### Système de filtrage avec switch
```cpp
switch (level)
{
    case 0:  // DEBUG
        harl.complain("DEBUG");
    case 1:  // INFO  
        harl.complain("INFO");
    case 2:  // WARNING
        harl.complain("WARNING"); 
    case 3:  // ERROR
        harl.complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
}
```

#### Technique du Fall-through
Le switch utilise intentionnellement le **fall-through** (absence de `break`) pour exécuter tous les niveaux à partir du niveau demandé.

### Utilisation
```bash
make
./harlFilter DEBUG      # Affiche DEBUG → INFO → WARNING → ERROR
./harlFilter INFO       # Affiche INFO → WARNING → ERROR
./harlFilter WARNING    # Affiche WARNING → ERROR  
./harlFilter ERROR      # Affiche ERROR seulement
./harlFilter invalid    # Affiche message par défaut
```

### Exemple de sortie
```bash
$ ./harlFilter WARNING
[ WARNING ]
I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

---

## Compilation

### Ex05
```bash
cd ex05
make
```

### Ex06  
```bash
cd ex06
make
```

### Makefile spécifique
Le Makefile de ex06 contient une règle spéciale pour désactiver le warning de fall-through sur `main.o` :
```makefile
$(OBJDIR)/main.o: srcs/main.cpp | $(OBJDIR)
    @$(CXX) $(CXXFLAGS) $(CXXADD) -I$(INCDIR) -c $< -o $@
```

---

## Concepts techniques appris

### Ex05 - Pointeurs vers fonctions membres
- **Syntaxe** : `void (Classe::*nom)(void)`
- **Appel** : `(this->*fonction)()`
- **Avantage** : Évite les conditions multiples
- **Usage** : Dispatch de méthodes basé sur des données

### Ex06 - Switch statement et fall-through
- **Fall-through** : Exécution continue sans `break`
- **Intentionnel** : Pour implémenter des filtres en cascade
- **Warning** : Nécessite `-Wno-implicit-fallthrough`
- **Élégance** : Une seule structure pour filtrer

---

## Différences clés

| Aspect | Ex05 | Ex06 |
|--------|------|------|
| **Technique** | Pointeurs vers fonctions membres | Switch statement |
| **Objectif** | Un seul niveau | Niveau et au-dessus |
| **Structure** | Éviter if/else | Utiliser fall-through |
| **Exécutable** | `Harl` | `harlFilter` |
| **Paramètres** | Tests automatiques | Argument ligne de commande |

---

Ces exercices démontrent deux techniques avancées en C++ pour éviter les structures conditionnelles répétitives et implémenter des systèmes de dispatch élégants.

By : Méryl BITEE