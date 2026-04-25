# CORRECTION - EXAMEN SEMESTRE 1
## Projet 1 - Conception et développement d'applications sécurisées

**Formatrice : Mme Méryl BITEE**  
**Durée : 3 heures**  
**Barème total : 100 points**

---

## PARTIE 1 : QUESTIONS DE COURS (30 points)

### Question 1 (5 points) - SDLC et ses 5 phases

**SDLC signifie :** Software Development Life Cycle (Cycle de vie du développement logiciel)

**RÉPONSE ATTENDUE :**

**Phase 1 : Analyse des besoins** (0,5 + 0,5 = 1 point)
- Objectif : Comprendre et documenter les besoins des utilisateurs et les exigences du projet

**Phase 2 : Conception (Design)** (0,5 + 0,5 = 1 point)
- Objectif : Définir l'architecture technique et concevoir les solutions (base de données, interfaces)

**Phase 3 : Développement (Implémentation)** (0,5 + 0,5 = 1 point)
- Objectif : Écrire le code et développer les fonctionnalités selon les spécifications

**Phase 4 : Tests (Vérification)** (0,5 + 0,5 = 1 point)
- Objectif : Vérifier que l'application fonctionne correctement et correspond aux besoins

**Phase 5 : Déploiement et Maintenance** (0,5 + 0,5 = 1 point)
- Objectif : Mettre l'application en production et assurer son suivi (corrections, mises à jour)

**BARÈME :**
- 0,5 point pour le nom correct de la phase
- 0,5 point pour l'objectif pertinent

**Variantes acceptables :**
- Planification au lieu d'Analyse
- Codage au lieu de Développement
- Validation au lieu de Tests

---

### Question 2 (5 points) - Sprint et événements Scrum

**RÉPONSE ATTENDUE :**

**Durée d'un Sprint :** 1 à 4 semaines (typiquement 2 semaines) **(1 point)**

**Événement 1 : Daily Stand-up (Daily Scrum)** (1 + 1 = 2 points)
- But : Réunion quotidienne de 15 minutes pour synchroniser l'équipe, partager l'avancement et identifier les obstacles

**Événement 2 : Sprint Review** (1 + 1 = 2 points)
- But : Démonstration de l'incrément de produit aux parties prenantes en fin de sprint pour obtenir du feedback

**Autres événements acceptables :**
- **Sprint Planning** : Planifier le travail du sprint et sélectionner les User Stories
- **Sprint Retrospective** : Réfléchir sur le sprint écoulé pour améliorer le processus

**BARÈME :**
- 1 point pour la durée correcte
- 1 point par événement correctement nommé
- 1 point par explication du but

---

### Question 3 (5 points) - Authentification vs Autorisation

**RÉPONSE ATTENDUE :**

**Authentification :** (2,5 points)

**Définition :** (2 points)
- Processus de vérification de l'identité de l'utilisateur (qui êtes-vous ?)
- Confirmer qu'une personne est bien celle qu'elle prétend être

**Exemple :** (0,5 point)
- Se connecter avec email et mot de passe
- Scanner son empreinte digitale
- Présenter sa carte d'identité

---

**Autorisation :** (2,5 points)

**Définition :** (2 points)
- Processus de vérification des droits d'accès d'un utilisateur authentifié (que pouvez-vous faire ?)
- Déterminer quelles ressources et actions sont autorisées pour cet utilisateur

**Exemple :** (0,5 point)
- Un employé peut voir son propre salaire mais pas celui de ses collègues
- Un étudiant peut voir ses notes mais ne peut pas les modifier
- Un administrateur peut supprimer des comptes, un utilisateur normal ne peut pas

**PÉNALITÉ :**
- Si l'étudiant confond les deux concepts = 0 point total

---

### Question 4 (5 points) - Secure by Design

**RÉPONSE ATTENDUE :**

**Définition de Secure by Design :** (2 points)
- Approche qui consiste à intégrer la sécurité dès la conception du projet, pas après
- La sécurité n'est pas une option ajoutée à la fin, mais un principe fondamental dès le début
- Penser à la sécurité à chaque étape du développement

**Bonne pratique 1 :** (1,5 point)

Exemples acceptables :
- **Principe du moindre privilège** : Donner uniquement les permissions minimales nécessaires
- **Validation des entrées** : Vérifier et filtrer toutes les données saisies par les utilisateurs
- **Défense en profondeur** : Multiplier les couches de sécurité
- **Fail securely** : En cas d'erreur, le système doit rester sécurisé

**Bonne pratique 2 :** (1,5 point)

Exemples acceptables :
- **Chiffrement par défaut** : Chiffrer les données sensibles et utiliser HTTPS
- **Ne jamais faire confiance aux entrées utilisateur**
- **Séparation des privilèges** : Diviser les rôles et responsabilités
- **Hashing des mots de passe** : Toujours hasher, jamais stocker en clair

**BARÈME :**
- 2 points pour une définition claire du concept
- 1,5 point par bonne pratique correctement expliquée

---

### Question 5 (5 points) - Injection SQL

**RÉPONSE ATTENDUE :**

**Définition de l'injection SQL :** (2,5 points)
- Vulnérabilité qui permet à un attaquant d'insérer du code SQL malveillant dans une requête
- L'attaquant peut manipuler la base de données (lire, modifier, supprimer des données)
- Se produit quand on concatène directement les entrées utilisateur dans les requêtes SQL

**Explication sur sa dangerosité :** (2,5 points)

**Pourquoi c'est dangereux :**
- L'attaquant peut contourner l'authentification et se connecter sans mot de passe
- Il peut accéder à toutes les données de la base (données personnelles, mots de passe, informations confidentielles)
- Il peut modifier ou supprimer des données critiques
- Il peut exécuter des commandes système dans certains cas
- Risque de fuite massive de données sensibles

**Exemples à mentionner :**
- Connexion sans mot de passe en utilisant `admin' --`
- Extraction de toutes les données avec `' OR '1'='1`
- Suppression de tables entières

**BARÈME :**
- 2,5 points pour la définition claire de l'injection SQL
- 2,5 points pour l'explication de la dangerosité (au moins 2 conséquences graves)

---

### Question 6 (5 points) - OWASP Top 10

**RÉPONSE ATTENDUE (au moins 2 parmi) :**

**Vulnérabilité 1 (2,5 points) :**

Exemples acceptables :

**1. Injection (SQL, LDAP, OS)** (1,5 + 1 = 2,5 points)
- Nom : Injection SQL / Injection de commandes
- Explication : Insertion de code malveillant dans les requêtes pour manipuler la base de données ou exécuter des commandes

**2. Broken Access Control** (1,5 + 1 = 2,5 points)
- Nom : Contrôle d'accès défaillant
- Explication : Les utilisateurs peuvent accéder à des ressources qu'ils ne devraient pas pouvoir voir

**3. Cross-Site Scripting (XSS)** (1,5 + 1 = 2,5 points)
- Nom : XSS
- Explication : Injection de scripts JavaScript malveillants dans des pages web qui seront exécutés par les navigateurs des victimes

**4. Cryptographic Failures** (1,5 + 1 = 2,5 points)
- Nom : Échecs cryptographiques
- Explication : Données sensibles non chiffrées ou mal protégées (mots de passe en clair, transmission sans HTTPS)

**5. Security Misconfiguration** (1,5 + 1 = 2,5 points)
- Nom : Mauvaise configuration
- Explication : Configuration de sécurité inadéquate (messages d'erreur détaillés en production, ports ouverts inutilement)

**6. Vulnerable Components** (1,5 + 1 = 2,5 points)
- Nom : Composants vulnérables
- Explication : Utilisation de bibliothèques ou frameworks obsolètes avec des vulnérabilités connues

**7. Authentication Failures** (1,5 + 1 = 2,5 points)
- Nom : Échecs d'authentification
- Explication : Failles dans l'authentification (pas de limite de tentatives, mots de passe faibles acceptés)

**8. CSRF** (1,5 + 1 = 2,5 points)
- Nom : Cross-Site Request Forgery
- Explication : Force un utilisateur authentifié à exécuter des actions non désirées

**Vulnérabilité 2 (2,5 points) :**
(Même barème, choisir une autre vulnérabilité parmi la liste)

**BARÈME :**
- 1,5 point pour le nom correct de la vulnérabilité
- 1 point pour l'explication claire en 1 phrase

---

## PARTIE 2 : QCM (30 points)

**Chaque question vaut 1,5 point. Total : 30 points (20 questions)**

### Corrections détaillées :

| Question | Réponse(s) correcte(s) | Explication |
|----------|------------------------|-------------|
| **Q0** | **B** | Agile/Scrum favorise les itérations courtes (sprints) |
| **Q1** | **A, C** | Agile permet l'adaptation et les livraisons régulières |
| **Q2** | **B** | Le Product Owner gère et priorise le Product Backlog |
| **Q3** | **B** | Un Sprint dure 1 à 4 semaines, typiquement 2 semaines |
| **Q4** | **B** | Les Story Points mesurent la complexité relative |
| **Q5** | **B, D** | bcrypt et Argon2 sont recommandés, minimum 8 caractères |
| **Q6** | **A** | HTTPS protège les données en transit |
| **Q7** | **B, D** | bcrypt et Argon2 (MD5 est obsolète) |
| **Q8** | **A, B** | Jira et Trello sont des outils Agile |
| **Q9** | **A, C** | RGPD = protection données + droit effacement |
| **Q10** | **A, C** | Requêtes préparées + validation entrées |
| **Q11** | **A** | Burndown Chart = travail restant dans sprint |
| **Q12** | **A** | CIA = Confidentialité, Intégrité, Disponibilité |
| **Q13** | **A, B, C** | Git gère versions, historique, collaboration |
| **Q14** | **A** | commit = enregistrement local |
| **Q15** | **B, C** | GitHub = plateforme hébergement + gestion projet |
| **Q16** | **A** | git pull = récupérer modifications distantes |
| **Q17** | **A, B** | Branche = développement isolé + versions parallèles |
| **Q18** | **A** | XSS = injection scripts malveillants |
| **Q19** | **A** | Vélocité = points réalisés par sprint |

**BARÈME :**
- **1,5 point** si toutes les bonnes réponses sont cochées et aucune mauvaise
- **0,75 point** si la plupart des bonnes réponses mais 1 erreur mineure
- **0 point** si plus d'une erreur ou aucune réponse

---

## PARTIE 3 : EXERCICES PRATIQUES (40 points)

### Exercice 1 : Planification de Sprint (15 points)

#### a) Sélection des User Stories (6 points)

**RÉPONSE ATTENDUE :**

**User Stories recommandées :**
- ☑ US1 - Créer un compte utilisateur (3 points)
- ☑ US2 - Se connecter (3 points)
- ☑ US3 - Ajouter un produit au panier (5 points)
- ☑ US4 - Payer en ligne (8 points)
- ☐ US5 - Voir l'historique des commandes (5 points)
- ☐ US6 - Laisser un avis (5 points)

**Total : 19 points** ✅ (respecte les 20 points de vélocité)

**Justification attendue :** (1 point)
- US1 est obligatoire car c'est un prérequis pour toutes les autres fonctionnalités
- US2 est nécessaire pour que les utilisateurs puissent se connecter
- US3 est une fonctionnalité cœur du e-commerce (haute priorité)
- US4 complète le parcours d'achat (priorité moyenne mais essentielle)
- Total de 19 points respecte la vélocité avec un petit buffer

**BARÈME :**
- 3 points : Sélection cohérente des US (respectant la vélocité 15-22 points)
- 2 points : Total de points correct et calculé
- 1 point : Justification claire et logique

**Alternatives acceptables :**
- US1, US2, US3, US5, US6 = 21 points (acceptable)
- US1, US2, US3 = 11 points (sous-utilisation mais acceptable si justifié)

---

#### b) Ordre de développement (4 points)

**RÉPONSE ATTENDUE :**

**Ordre logique :** (2 points)

1. **US1** - Créer un compte utilisateur
2. **US2** - Se connecter
3. **US3** - Ajouter un produit au panier
4. **US4** - Payer en ligne

**Explication de l'ordre :** (2 points)
- US1 et US2 sont des **prérequis** pour tout le reste (dépendances obligatoires)
- On suit les **dépendances techniques** (on ne peut pas payer sans avoir un panier)
- On développe d'abord les fonctionnalités **de base** puis les fonctionnalités **avancées**
- US3 et US4 forment un **parcours utilisateur complet**

**BARÈME :**
- 2 points pour un ordre logique respectant les dépendances
- 2 points pour l'explication des dépendances et de la logique

---

#### c) Analyse mi-sprint (5 points)

**RÉPONSE ATTENDUE :**

**Est-ce un problème ? Pourquoi ?** (2 points)

**OUI, c'est un problème :**
- Après 1 semaine (50% du sprint), seulement 5 points réalisés sur 20 (25%)
- L'équipe est en **retard significatif**
- Si ce rythme continue, elle ne terminera que 10 points sur 20
- Le Burndown Chart montrerait une ligne au-dessus de la ligne idéale
- Risque de ne pas atteindre l'objectif du sprint

---

**Action 1 à faire :** (1,5 point)

**Organiser un Daily Stand-up immédiat ou réunion d'équipe** pour :
- Identifier les obstacles et blocages
- Comprendre pourquoi le retard (technique, organisationnel, humain)
- Demander l'aide du Scrum Master pour lever les impediments

OU

**Prioriser et se concentrer sur les US essentielles :**
- Focus sur US1 et US2 (prérequis absolus)
- Reporter US3 ou US4 si nécessaire
- Garantir au moins le MVP

---

**Action 2 à faire :** (1,5 point)

**Réduire le scope du sprint :**
- Retirer US4 (8 points) du sprint et la reporter au prochain
- Nouveau total : 11-12 points, plus réalisable
- Informer le Product Owner de l'ajustement

OU

**Demander de l'aide / Réorganiser l'équipe :**
- Pair programming pour débloquer les développeurs
- Demander de l'aide à d'autres équipes si disponible
- Revoir la répartition des tâches

OU

**Analyser les estimations :**
- Les estimations étaient peut-être trop optimistes
- Adapter la vélocité future
- Apprendre de cette expérience

**BARÈME :**
- 2 points pour identifier que c'est un problème et expliquer pourquoi
- 1,5 point par action concrète et pertinente (2 actions = 3 points)

**Actions NON acceptables (0 point) :**
- "Travailler plus" sans analyser
- "Faire des heures supplémentaires"
- "Continuer comme ça et espérer"

---

### Exercice 2 : Trouver les erreurs de sécurité (12 points)

#### a) Identification des problèmes (6 points)

**RÉPONSE ATTENDUE :**

**Problème 1 : Injection SQL** (3 points)

**Nom de la vulnérabilité :** Injection SQL (1 point)

**Pourquoi c'est dangereux :** (1 point)
- Un attaquant peut manipuler la requête SQL pour contourner l'authentification
- Il peut lire, modifier ou supprimer toutes les données de la base de données

**Exemple d'exploitation :** (1 point)
- L'attaquant entre comme username : `admin' --`
- La requête devient : `SELECT * FROM users WHERE username='admin' --'`
- Le `--` commente la fin, permettant de se connecter sans mot de passe

---

**Problème 2 : Mot de passe stocké en clair** (3 points)

**Nom de la vulnérabilité :** Stockage de mot de passe en clair / Absence de hashing (1 point)

**Pourquoi c'est dangereux :** (1 point)
- Si la base de données est compromise, tous les mots de passe sont lisibles immédiatement
- L'attaquant peut se connecter à tous les comptes
- Les utilisateurs qui réutilisent leurs mots de passe ailleurs sont compromis

**Exemple d'exploitation :** (1 point)
- Un attaquant obtient un dump de la base de données
- Il voit directement : `user: john, password: motdepasse123`
- Il peut se connecter immédiatement à tous les comptes
- Il peut tester ces mots de passe sur Gmail, Facebook, etc.

---

#### b) Choix du code corrigé (6 points)

**RÉPONSE CORRECTE : Version A** ✅ (3 points)

**Justification attendue :** (2 points)

La version A est la seule qui corrige les deux problèmes :

1. **Elle corrige l'injection SQL** en utilisant une requête préparée avec placeholder (`?`) et paramètres séparés `(username,)`

2. **Elle corrige le stockage en clair** en utilisant bcrypt pour vérifier le hash du mot de passe avec `bcrypt.checkpw()`

3. **Bonus :** Elle crée une session sécurisée et utilise un message d'erreur générique

---

**Pourquoi les autres versions ne sont PAS correctes :** (1 point)

**Version B n'est pas bonne car :** (0,5 point)
- Elle corrige bien l'injection SQL avec requête préparée
- MAIS elle compare toujours le mot de passe en clair (`user.password == password`)
- Les mots de passe sont donc toujours stockés en texte brut
- Problème 2 NON résolu

**Version C n'est pas bonne car :** (0,5 point)
- Elle utilise une f-string pour la requête SQL → toujours vulnérable à l'injection
- Elle utilise MD5 qui est obsolète et non sécurisé
- AUCUN des deux problèmes n'est correctement résolu

**BARÈME :**
- 3 points : Choix de la version A
- 2 points : Justification complète (explique que A corrige les 2 problèmes)
- 0,5 point : Explication du problème de la version B
- 0,5 point : Explication des problèmes de la version C

---

### Exercice 3 : AU CHOIX (13 points)

## EXERCICE 3-a : Sécuriser une inscription (13 points)

#### a) Critères de validation du mot de passe (5 points)

**RÉPONSE ATTENDUE (3 critères parmi) :**

**Critère 1 : Longueur minimale** (~1,67 point)
- Le mot de passe doit contenir au moins 8 caractères (idéalement 12+)
- Plus long = plus difficile à craquer par force brute

**Critère 2 : Complexité** (~1,67 point)
- Au moins 1 majuscule (A-Z)
- Au moins 1 minuscule (a-z)
- Au moins 1 chiffre (0-9)
- Au moins 1 caractère spécial (!@#$%^&*)

**Critère 3 : Pas de mots du dictionnaire** (~1,67 point)
- Ne pas accepter "password", "123456", "qwerty", etc.
- Vérifier contre une liste de mots de passe courants

**Autres critères acceptables :**
- Pas d'informations personnelles (nom, email, date de naissance)
- Confirmation du mot de passe (saisir deux fois)
- Vérification contre les fuites (Have I Been Pwned)
- Pas de caractères répétitifs

**BARÈME :**
- Environ 1,67 point par critère valide et bien expliqué
- 1 point si critère mentionné mais mal expliqué
- 0,5 point si seulement mentionné sans explication

---

#### b) Stockage du mot de passe (4 points)

**Algorithme à utiliser :** (2 points)

**RÉPONSE CORRECTE :**
- **bcrypt** (recommandé) = 2 points
- **Argon2** (encore mieux) = 2 points
- **PBKDF2** (acceptable) = 1,5 point
- **SHA256/SHA512 avec salt** = 1 point
- **MD5 ou SHA1** = 0 point (obsolètes)

---

**Pourquoi PAS stocker en clair :** (2 points)

**Réponses attendues (au moins 2 raisons) :**

**Raison 1 - Fuite de données :**
- Si la base est piratée, tous les mots de passe sont visibles immédiatement

**Raison 2 - Réutilisation des mots de passe :**
- Les utilisateurs réutilisent leurs mots de passe sur d'autres sites
- Un mot de passe volé compromet tous leurs autres comptes

**Raison 3 - Obligations légales :**
- Le RGPD impose de protéger les données personnelles
- Risque d'amendes importantes

**Raison 4 - Confiance des utilisateurs :**
- C'est une faute professionnelle et éthique
- Perte de réputation

**BARÈME :**
- 2 points pour au moins 2 raisons valides bien expliquées
- 1,5 point pour 2 raisons mentionnées mais peu détaillées
- 1 point pour 1 raison correcte

---

#### c) Processus de connexion sécurisée (4 points)

**RÉPONSE ATTENDUE (3-4 étapes) :**

**Étape 1 : Saisie et envoi des identifiants** (1 point)
- L'utilisateur saisit son email et son mot de passe
- Les données sont envoyées au serveur via HTTPS (chiffré)

**Étape 2 : Validation et recherche en base** (1 point)
- Le serveur valide le format de l'email
- Recherche l'utilisateur avec une requête préparée
- `SELECT id, email, password_hash FROM users WHERE email = ?`

**Étape 3 : Vérification du hash** (1 point)
- Le serveur compare le mot de passe saisi avec le hash stocké
- Utilisation de `bcrypt.checkpw(password_saisi, hash_stocké)`
- Ne JAMAIS comparer en clair

**Étape 4 : Création de session** (1 point)
- Si correct : création d'une session sécurisée avec `session['user_id']`
- Cookie avec flags HttpOnly, Secure, SameSite
- Redirection vers le tableau de bord
- Si incorrect : message d'erreur générique

**BARÈME :**
- 1 point par étape correcte et pertinente
- Bonus +0,5 si mentionne HTTPS
- Bonus +0,5 si mentionne requête préparée ou bcrypt

---

## EXERCICE 3-b : Gestion de versions avec Git (13 points)

#### a) Workflow Git complet (5 points)

**RÉPONSE ATTENDUE :**

**Étape 1 : Mise à jour du code** (1 point)

**Commande(s) :** (0,5 point)
```bash
git pull origin main
```

**Explication :** (0,5 point)
- Récupérer la dernière version du code depuis GitHub
- S'assurer d'avoir les modifications de l'équipe

---

**Étape 2 : Création d'une branche dédiée** (1 point)

**Commande(s) :** (0,5 point)
```bash
git checkout -b feature/email-notifications
```

**Explication :** (0,5 point)
- Créer une nouvelle branche pour isoler le travail
- Ne jamais travailler directement sur main

---

**Étape 3 : Développement et sauvegarde locale** (1 point)

**Commande(s) :** (0,5 point)
```bash
git add .
git commit -m "Ajout du système d'envoi d'emails automatiques"
```

**Explication :** (0,5 point)
- git add : Préparer les fichiers modifiés
- git commit : Sauvegarder localement avec un message descriptif

---

**Étape 4 : Partage du code avec l'équipe** (1 point)

**Commande(s) :** (0,5 point)
```bash
git push origin feature/email-notifications
```

**Explication :** (0,5 point)
- Envoyer la branche et ses commits vers GitHub
- Rendre le code accessible à l'équipe

---

**Étape 5 : Intégration dans le projet principal** (1 point)

**Commande(s) :** (0,5 point)
```bash
# Sur GitHub : créer une Pull Request
# Après validation :
git checkout main
git merge feature/email-notifications
git push origin main
```

**Explication :** (0,5 point)
- Fusionner la branche dans main après revue
- Pull Request permet la revue de code

---

#### b) Comprendre les commandes Git (4 points)

**RÉPONSE ATTENDUE :**

**git add fichier.py :** (1,5 point)

**Où ça se passe :** Local / Staging area

**À quoi ça sert :** Préparer les fichiers modifiés pour le prochain commit / Ajouter à la zone de transit

**Exemple concret :** "Je viens de modifier des fichiers, donc je peux les préparer pour la sauvegarde"

---

**git commit -m "message" :** (1,5 point)

**Où ça se passe :** Local / Dépôt Git local

**À quoi ça sert :** Créer un point de sauvegarde des fichiers préparés / Enregistrer dans l'historique local

**Exemple concret :** "Je viens de finir une fonctionnalité et je veux créer un point de sauvegarde"

---

**git push origin branche :** (1 point)

**Où ça se passe :** Local → Distant (GitHub)

**À quoi ça sert :** Envoyer les commits locaux vers GitHub / Partager le code avec l'équipe

**Exemple concret :** "Je veux que mon équipe puisse voir mon travail, donc je l'envoie sur GitHub"

**BARÈME :**
- Environ 0,5 point pour "Où ça se passe"
- Environ 0,5 point pour "À quoi ça sert"
- Environ 0,5 point pour l'exemple concret

---

#### c) Situations pratiques (4 points)

**Situation 1 :** (1 point)
**Commande :** `git commit --amend -m "Nouveau message correct"`

**Situation 2 :** (1 point)
**Commande :** `git pull` ou `git pull origin main`

**Situation 3 :** (1 point)
**Commande :** `git checkout -b feature-notification` ou `git branch feature-notification`

**Situation 4 :** (1 point)
**Commande :** `git log`

**BARÈME :**
- 1 point par commande correcte
- 0,5 point si syntaxe légèrement incorrecte mais concept correct

---

## BARÈME RÉCAPITULATIF GLOBAL

| Partie | Points | Contenu |
|--------|--------|---------|
| **Partie 1** | 30 | 6 questions × 5 points |
| **Partie 2** | 30 | 20 QCM × 1,5 point |
| **Partie 3** | 40 | 3 exercices (15 + 12 + 13) |
| **TOTAL** | **100** | |

---

## GRILLE DE NOTATION FINALE

| Points obtenus | Note /20 | Appréciation |
|----------------|----------|--------------|
| **90-100** | **18-20** | Excellent - Très bien maîtrisé |
| **75-89** | **15-17** | Bien - Bonne compréhension |
| **60-74** | **12-14** | Assez bien - Bases correctes |
| **50-59** | **10-11** | Passable - À améliorer |
| **< 50** | **< 10** | Insuffisant - Revoir le cours |

---

## ERREURS FRÉQUENTES À ÉVITER

### En Agile :
❌ Confondre Story Points et heures
❌ Dépasser largement la vélocité
❌ Ignorer les dépendances entre US

### En Sécurité :
❌ Proposer MD5 ou SHA1 pour les mots de passe
❌ Concaténer les variables dans SQL
❌ Confondre chiffrement et hashing

### En Git :
❌ Travailler directement sur main
❌ Confondre commit (local) et push (distant)
❌ Oublier git add avant git commit

---

## CONSEILS POUR LA NOTATION

### Soyez bienveillant si :
✅ Logique correcte même si syntaxe imparfaite
✅ Plusieurs solutions valides proposées
✅ Explication claire même sans vocabulaire exact

### Soyez strict sur :
❌ Concepts de sécurité inversés
❌ Mauvaises pratiques graves (MD5, SQL injection non corrigée)
❌ Absence totale de justification

---

**Fin de la correction**

**Bonne notation ! 📝✅**
