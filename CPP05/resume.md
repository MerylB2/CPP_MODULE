# CPP Module 05 - Resume

Ce fichier sert de pense-bete pour resumer chaque exercice du module 05
sans surcharger le code avec trop de commentaires.

## Regles generales du module

- Compiler en `c++` avec `-Wall -Wextra -Werror`
- Le code doit rester compatible `-std=c++98`
- Pas de `printf`, `malloc`, `free`
- Pas de `using namespace`
- Pas de STL sur ce module
- Les classes doivent suivre l'Orthodox Canonical Form, sauf les classes
  d'exception
- Les headers doivent etre autonomes et proteges contre les doubles inclusions

---

## ex00 - Bureaucrat

### Objectif

Creer une classe `Bureaucrat` avec un nom constant et un grade compris entre
`1` et `150`.

### Regles importantes

- `1` est le meilleur grade
- `150` est le pire grade
- Un nombre plus petit represente donc un grade plus haut
- Un nombre plus grand represente un grade plus bas

### Ce que la classe doit contenir

- un attribut `const std::string _name`
- un attribut `int _grade`
- des getters
- `incrementGrade()`
- `decrementGrade()`
- une surcharge de `operator<<`
- deux exceptions :
  - `GradeTooHighException`
  - `GradeTooLowException`

### Pourquoi les exceptions ont ces noms

L'echelle est inversee :

- un grade `< 1` est "too high" car il depasse le grade le plus eleve autorise
- un grade `> 150` est "too low" car il descend sous le grade le plus bas autorise

Exemples :

- `0` -> trop haut
- `151` -> trop bas

### Logique des fonctions de grade

- `incrementGrade()` ameliore le bureaucrat
- comme les meilleurs grades sont les plus petits, incrementer veut dire
  diminuer la valeur numerique
- exemple : `3` devient `2`

- `decrementGrade()` baisse le bureaucrat
- cela augmente la valeur numerique
- exemple : `3` devient `4`

### Role de `what()`

Les classes d'exception heritent de `std::exception`.
La fonction `what()` sert a renvoyer un message d'erreur lisible.

Exemple :

```cpp
catch (std::exception& e)
{
    std::cout << e.what() << std::endl;
}
```

Si l'exception est `GradeTooHighException`, `what()` peut afficher :

```cpp
grade too high!
```

### Role de `throw` et `catch`

- `throw` sert a lancer une exception lorsqu'une erreur est detectee
- `catch` sert a recuperer cette exception pour eviter que le programme plante
- `what()` permet ensuite d'afficher un message expliquant l'erreur

Exemple simple :

```cpp
if (grade < 1)
    throw GradeTooHighException();
```

Ici, on signale que l'objet ne peut pas etre cree avec cette valeur.

Puis on intercepte l'erreur plus loin :

```cpp
try
{
    Bureaucrat b("Bob", 0);
}
catch (std::exception& e)
{
    std::cout << e.what() << std::endl;
}
```

Resume du mecanisme :

- `try` : bloc dans lequel une erreur peut arriver
- `throw` : lancement de l'exception
- `catch` : interception de l'exception
- `what()` : message associe a l'exception

### Forme canonique

`Bureaucrat` doit suivre l'Orthodox Canonical Form :

- constructeur par defaut
- constructeur de copie
- operateur d'affectation
- destructeur

Point important :

- `_name` est `const`
- dans l'operateur `=`, on ne peut donc pas recopier `_name`
- on recopie seulement `_grade`

### Ce qu'il faut tester

- creation valide
- grade trop haut a la construction
- grade trop bas a la construction
- overflow avec `incrementGrade()`
- overflow avec `decrementGrade()`
- increment/decrement normaux
- constructeur de copie et operateur d'affectation

### A retenir pour la soutenance

- les exceptions sont attrapees via `catch (std::exception& e)`
- `what()` explique l'erreur
- `1` est le plus haut grade, `150` le plus bas
- `incrementGrade()` diminue la valeur numerique

---

## ex01 - Form

### Objectif

Ajouter une classe `Form` qui peut etre signee par un `Bureaucrat`.

### Particularite de l'exercice

Dans l'ex00, `Bureaucrat` etait une classe seule qui gerait surtout son propre
grade et ses propres exceptions.

Dans l'ex01, on passe a une vraie interaction entre deux classes :

- `Bureaucrat`
- `Form`

Le grade du bureaucrat ne sert plus seulement a exister ou a etre modifie :
il sert maintenant a agir sur un autre objet, ici un formulaire.

Cet exercice introduit donc :

- une relation entre deux classes
- une logique metier entre objets
- une meilleure encapsulation

### Lien entre `Bureaucrat` et `Form`

Le lien est simple :

- un `Form` impose un grade minimum pour etre signe
- un `Bureaucrat` possede un grade
- si le grade du bureaucrat est suffisant, il peut signer le formulaire

Chaque classe garde cependant son role :

- `Bureaucrat::signForm()` tente la signature
- `Form::beSigned()` verifie si cette signature est autorisee

Point important :

- `Bureaucrat` ne modifie pas directement `_isSigned`
- c'est `Form` qui decide s'il peut changer son propre etat

Cela respecte mieux l'encapsulation.

### Attributs de `Form`

- un nom constant
- un bool indiquant si le formulaire est signe
- un grade necessaire pour signer
- un grade necessaire pour executer

Au depart, un formulaire n'est pas signe.

### A quoi sert `execGrade`

Dans l'ex01, `execGrade` est deja present dans la classe mais il n'est pas encore
utilise dans le comportement.

Son role est de preparer l'ex02 :

- `signGrade` : grade minimum requis pour signer
- `execGrade` : grade minimum requis pour executer

Dans l'ex01, il faut donc :

- le stocker
- le valider
- le retourner avec un getter
- l'afficher avec `operator<<`

Mais il ne sert pas encore a lancer une action.

### Regles sur les grades

Les grades suivent la meme logique que pour `Bureaucrat` :

- `1` = grade le plus haut
- `150` = grade le plus bas

Donc :

- un grade `< 1` -> `GradeTooHighException`
- un grade `> 150` -> `GradeTooLowException`

### Ce que `Form` doit contenir

- getters pour tous les attributs
- `beSigned(const Bureaucrat&)`
- deux exceptions :
  - `Form::GradeTooHighException`
  - `Form::GradeTooLowException`
- une surcharge de `operator<<`

### Role de `beSigned()`

Cette fonction tente de signer le formulaire avec un bureaucrat.

Regle :

- si le grade du bureaucrat est assez haut, le formulaire passe a signe
- sinon, on lance `Form::GradeTooLowException`

Attention a la logique :

- si le formulaire demande le grade `25`
- un bureaucrat de grade `20` peut signer
- un bureaucrat de grade `50` ne peut pas signer

Pourquoi :

- un plus petit nombre represente un meilleur grade

### Role de `signForm()` dans `Bureaucrat`

Le sujet demande aussi d'ajouter `signForm()` dans `Bureaucrat`.

Cette fonction :

- appelle `form.beSigned(*this)`
- affiche un message si la signature reussit
- affiche un message explicite si la signature echoue

Exemple :

- succes : `<bureaucrat> signed <form>`
- echec : `<bureaucrat> couldn't sign <form> because <reason>`

### Point important sur les includes

`Form` a besoin de connaitre `Bureaucrat`, et `Bureaucrat` a besoin de connaitre `Form`.
Pour eviter une inclusion circulaire :

- on utilise souvent une forward declaration dans le header
- puis on inclut le vrai header dans le `.cpp`

### Ce qu'il faut tester

- creation valide d'un formulaire
- exception si le grade de signature est invalide
- exception si le grade d'execution est invalide
- signature reussie avec `signForm()`
- signature refusee avec `signForm()`
- effet de `beSigned()` sur l'etat du formulaire

### A retenir pour la soutenance

- `Form` garde ses grades en attributs constants
- seul `_isSigned` peut changer apres construction
- un bureaucrat peut signer seulement si son grade est suffisant
- `signForm()` ne signe pas lui-meme directement : il delegue a `beSigned()`

---

## ex02 - AForm et formulaires concrets

### Objectif

Transformer `Form` en classe abstraite `AForm` puis creer trois formulaires
concrets capables d'executer une vraie action.

### Particularite de l'exercice

L'ex02 introduit plusieurs notions importantes en meme temps :

- classe abstraite
- heritage
- polymorphisme
- execution conditionnelle d'une action

Ici, un formulaire ne se contente plus d'etre signe :
il peut aussi etre execute.

### Pourquoi `Form` devient `AForm`

Le sujet demande que la classe de base soit abstraite.

Cela veut dire :

- on peut definir une interface commune
- on ne peut pas creer directement un objet `AForm`
- chaque formulaire concret doit fournir sa propre action

Concretement :

- `AForm form;` -> interdit
- `new AForm()` -> interdit

On utilise donc `AForm*` ou `AForm&` pour manipuler les formulaires
de facon polymorphe.

### Role de `execute()`

`AForm` fournit une fonction `execute(Bureaucrat const& executor) const`
qui verifie les preconditions avant de lancer l'action reelle.

Avant execution, il faut verifier :

- que le formulaire est signe
- que le bureaucrat a un grade assez haut pour executer

Si ce n'est pas le cas :

- formulaire non signe -> exception
- grade insuffisant -> exception

Puis la classe concrete execute son action specifique.

### Pourquoi separer verification et action

L'idee elegante consiste a faire :

- les verifications dans la classe de base `AForm`
- l'action concrete dans une fonction virtuelle redefinie dans les classes filles

Cela evite de dupliquer partout les memes controles.

### Les trois formulaires concrets

#### `ShrubberyCreationForm`

- sign grade : `145`
- exec grade : `137`
- action :
  cree un fichier `<target>_shrubbery` et y ecrit des arbres ASCII

#### `RobotomyRequestForm`

- sign grade : `72`
- exec grade : `45`
- action :
  fait des bruits de perceuse puis annonce une reussite une fois sur deux

#### `PresidentialPardonForm`

- sign grade : `25`
- exec grade : `5`
- action :
  annonce que la cible est graciee par Zaphod Beeblebrox

### Role de `executeForm()` dans `Bureaucrat`

Comme pour `signForm()`, `Bureaucrat` fournit une fonction d'aide :

- `executeForm(AForm const& form)`

Cette fonction :

- tente d'executer le formulaire
- affiche un message clair en cas de succes
- affiche la raison de l'echec sinon

### Lien entre `Bureaucrat` et `AForm`

Le lien devient plus riche que dans l'ex01 :

- `Bureaucrat` peut signer un formulaire
- `Bureaucrat` peut executer un formulaire
- `AForm` utilise le grade du bureaucrat pour autoriser ou refuser ces actions

Chaque classe garde son role :

- `Bureaucrat` demande l'action
- `AForm` verifie les regles
- la classe concrete realise l'action

### Ce qu'il faut tester

- qu'on ne peut pas instancier `AForm` directement
- signature puis execution reussies
- execution refusee si le formulaire n'est pas signe
- execution refusee si le grade est trop bas
- action concrete de chaque formulaire
- polymorphisme via `AForm*`

### A retenir pour la soutenance

- `AForm` est abstraite car elle contient une action virtuelle pure
- `execute()` verifie d'abord l'etat du formulaire et le grade de l'executant
- les classes filles redefinissent seulement l'action
- `ShrubberyCreationForm` cree un fichier
- `RobotomyRequestForm` reussit aleatoirement une fois sur deux
- `PresidentialPardonForm` affiche une grace presidentielle

### Mini schema d'appel

Pour la signature :

```text
Bureaucrat::signForm(form)
        |
        v
form.beSigned(bureaucrat)
        |
        v
verifie le grade puis passe le form a signed = true
```

Pour l'execution :

```text
Bureaucrat::executeForm(form)
        |
        v
form.execute(bureaucrat)
        |
        v
AForm::execute() verifie :
- form signe ?
- grade suffisant ?
        |
        v
executeAction() de la classe concrete
```

Exemple avec `ShrubberyCreationForm` :

```text
executeForm()
    -> AForm::execute()
    -> ShrubberyCreationForm::executeAction()
    -> creation du fichier <target>_shrubbery
    -> ecriture de l'arbre ASCII dedans
```

---

## ex03 - Intern

### Objectif

Ajouter une classe `Intern` capable de creer dynamiquement le bon formulaire
en fonction d'un nom passe en parametre.

### Particularite de l'exercice

L'ex03 introduit une logique de fabrique :

- on donne un nom de formulaire
- l'intern choisit la bonne classe concrete
- l'intern renvoie un `AForm*` deja construit

Cela permet de manipuler differents formulaires sans que l'appelant connaisse
leur type concret a l'avance.

### Role de `makeForm()`

Signature attendue :

```cpp
AForm* makeForm(const std::string& formName, const std::string& target) const;
```

Cette fonction :

- compare `formName` avec les noms reconnus
- cree le bon formulaire avec `target`
- retourne un pointeur vers `AForm`
- affiche `Intern creates <form>` si la creation reussit

Si le nom n'existe pas :

- elle affiche un message d'erreur explicite
- elle retourne `0` / `NULL`

### Noms reconnus

En pratique, l'intern doit savoir creer :

- `"shrubbery creation"`
- `"robotomy request"`
- `"presidential pardon"`

### Pourquoi retourner un `AForm*`

Le retour en `AForm*` permet :

- d'utiliser le polymorphisme
- de manipuler tous les formulaires via une interface commune
- de laisser l'appelant utiliser `signForm()` et `executeForm()`
  sans dependre du type concret

### Point important sur la memoire

Comme `makeForm()` cree les formulaires avec `new`,
il faut ensuite faire `delete` sur les pointeurs retournes.

Sinon :

- fuite memoire

### Pourquoi eviter une grosse chaine de `if / else`

Le sujet dit explicitement d'eviter une solution illisible avec trop de
`if / else if / else`.

Une approche plus propre consiste a utiliser :

- un tableau de noms
- un tableau de fonctions de creation associees

Ainsi, on garde un code plus compact et plus lisible.

### Ce qu'il faut tester

- creation d'un `ShrubberyCreationForm` par nom
- creation d'un `RobotomyRequestForm` par nom
- creation d'un `PresidentialPardonForm` par nom
- cas ou le nom n'existe pas
- utilisation du formulaire cree via `AForm*`

### A retenir pour la soutenance

- `Intern` n'a pas de vrai etat important
- son role est uniquement de fabriquer le bon formulaire
- `makeForm()` choisit la bonne classe concrete a partir d'un nom
- le retour est un `AForm*`, donc il faut liberer la memoire apres usage
- l'ex03 montre une logique de factory simple avec polymorphisme
