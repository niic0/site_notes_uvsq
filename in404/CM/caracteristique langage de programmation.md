# Caractéristiques des langages de programmation

## Implémentation des langages

Il existe plusieurs types de langages :

* Avec un **langage compilé**, le code source du programme est transformé en *code machine* par le *compilateur*. C'est notamment le cas du langage *C* avec `gcc` qui permet de compiler un fichier C pour le traduire en *langage machine*. On exécute alors le programme en entrant dans le terminale `$ ./monprog`.
* Dans un **langage interprété**, le code source du programme est exécuté "à la volée" pas l'*interpréteur* (qui sert de compilateur). *PHP* par exemple, n'a pas besoin d’être compilé au préalable, on exécute simplement notre fichier avec `$ php monprog.php`.

A noter qu'il existe des langages à la fois compilés et interprétés et des langages qui utilise une approche intermédiaire *Just In Time* (JIT).  *Java* est un langage *JIT*, il est compilé puis interprété. On peut compile le programme à l'aide de *bytecode* avec la commande `$ javac Main.java` puis on exécute avec *Java Virtual Machine* (*JVM*) `$ java Main`.

 ### Langage de scripts

Un *script* est un programme destiné à automatiser l'enchaînement de tâches dans un environnement particulier. Il est créer à partir d'un *langage de script* qui est un langage de programmation permettant de développer des scripts. Par exemple les *shells* des *OS* comme *bash*, *Zsh* etc mettent en œuvre des scripts tout comme *Javascript* pour les navigateur web.

### Système de typage

Un *système de typage* attribue des types aux éléments du langage. On ne déclare en effet pas de la même manière les variables selon le langage utilisé.

* Le typage est *explicite* si les annotation de **type sont visibles** dans le code source. En C, chaque déclaration de variable précise son type.

  ```c
  int nombre = 1;
  double pi = 3.141592;
  ```

* Le typage est *implicite* si les **types ne sont pas précisés** dans le code source. En PHP, la première affectation crée la variable. Il "déduit" le type de variable.

  ```php
  $nombre = 1;
  $pi = 3.141592;
  ```

### Typage Statique

Le typage est **statique** si l'information de type est associée à l'identificateur. La vérification des types se réalisera alors à la compilation. Le typage statique à pour avantage d'améliorer la fiabilité du programme puisque c'est au programmeur d'initialisé le type de variable. Ce typage offre aussi un meilleur support des outils (IDE) et de meilleurs performances.

> En C, les erreurs de type sont identifiées par le compilateur

```c
double a = "une chaine";
// error: incompatible types when initializing type ‘double’ using type ‘char *’
```

### Typage dynamique

Le typage est **dynamique** si l'information de type est portée par l'objet lui même. La vérification se fait durant l'exécution du programme. Cela à pour avantages d'avoir une certaines souplesse dans l'écriture du code source (*duck typing*, *data as code*, métaprogrammation) et permet un prototypage rapide.

> En PHP, les erreurs de type peuvent passer inaperçues

```php
$a = 1;
$a = "une chaine";
echo $a + 2; // Affiche 2 
```

### Typage fort et faible

* Le typage est *fort* si les manipulations entre données de types différents sont limitées et contrôles
* Le typage est *faible* si les possibilités de trans-typage sont nombreuses et implicites

Ces notations sont relativement floues, elles sont indiquées ici à titre d'information. Le C est à typage fort, néanmoins quelques élément montre que l'initialisation de variable n'est pas contrôlés à 100%.

```c
int a = "une chaine";
printf("%d\n", a);		// Affichera 443215...
```

### Support des paradigmes de programmation

Un *paradigme de programmation* représente la façon d'aborder un problème et d'en concevoir la solution. Grossièrement c'est une "manière de programmer" où un langage est plus apte à aider le programmeur à coder de cette manière. Un langage **supporte un paradigme** quand il fournit les fonctionnalités pour utiliser ce style (de façon simple, sécurisée et efficace).
Quelques paradigmes :

* **Programmation impérative**
  * **Programmation structurée** (*Pascal*, *Ada*) : Programme structuré par des éléments comme des *if*, des *while*, des *for* etc... L'idée de ce paradigme est d'avoir une lisibilité du programme plus simple. [Wikipedia](https://fr.wikipedia.org/wiki/Programmation_structur%C3%A9e#:~:text=Pour%20l'%C3%A9criture%20de%20fragments,organisation%20hi%C3%A9rarchique%20simple%20du%20code.&text=Les%20programmeurs%20d%C3%A9composent%20leur%20code,en%20entier%20sous%20les%20yeux.)
  * **Programmation modulaire** (modula-2, un langage basé sur Pascal) : L'idée est de construire un programme à partir de composants (qui sont les modules). Cette méthode permet d'avoir des unités de travail logique plutôt que de tout réunir en un bloc. Cela permet la compilation séparée. Les fonctions par exemple nous permettent cette "mise en bloc" des composants du programme. [Wikipedia](https://fr.wikipedia.org/wiki/Programmation_modulaire#:~:text=En%20informatique%2C%20la%20programmation%20modulaire,de%20composants%20(les%20modules).)
  * **Programmation par abstraction de données** : Une abstraction, en informatique, correspond à un regroupement de caractéristiques et de traitements applicable à une entité ou concept varié. Par exemple quand on créer un programme avec plusieurs fonctions qui nous permettent de tout réunir dans un fichier principal qui utilise ces fonctions de façon plus simple. Dans ce cas on a créer des fonctions permettant une abstraction pour notre fichier principal. Dans cet exemple une abstraction ressemble à un framework mais c'est en réalité plus générale, on peut étendre ça au OS, au data base etc... [Wikipedia](https://fr.wikipedia.org/wiki/Abstraction_(informatique)#:~:text=compilateur%20100%20%25%20%C2%BB.-,Programmation%20orient%C3%A9e%20objet,classes%20selon%20des%20caract%C3%A9ristiques%20communes.)  
  * **Programmation objet** (*Java*, *C++*, *Python*) : La programmation orientée objet définit et fait interagir des objets via des class. Un objet est une entité du monde réel physique, ça peut être une voiture, un livre, un ordinateur... [Wikipedia](https://fr.wikipedia.org/wiki/Programmation_orient%C3%A9e_objet)
* **Programmation fonctionnelle** (*Haskell*) : La programmation fonctionnelle se concentre sur la notion de fonction comme son nom l'indique. Tous les éléments peuvent être compris comme des fonctions et le code peut être exécuté par des appels successifs de fonctions. De cette manière, on peut se représenter une fonction comme une variante spéciale d'un sous programme donné. [Wikipédia](https://fr.wikipedia.org/wiki/Programmation_fonctionnelle#:~:text=La%20programmation%20fonctionnelle%20est%20un,qu'%C3%A9valuation%20de%20fonctions%20math%C3%A9matiques.)
* **Programmation logique** (*prolog*) : La programmation logique joue sur une ambivalence représentation déclarative/représentation procédurale : ainsi, un raisonnement régressif associera à l’implication *B1&…&Bn → H* une procédure « pour établir H, établir B1 puis… puis Bn ». [Wikipedia](https://fr.wikipedia.org/wiki/Programmation_logique#:~:text=Prolog%20%3A%20Le%20premier%20langage%20de,utiliser%20pour%20la%20programmation%20logique.)

### Langage impératif

Un *langage impératif* représente un programme comme un séquence d'instructions qui modifient son état au cours de son exécution. Ce type de langage décrit **comment** aboutir à la solution du problème. Il est proche de l'architecture des ordinateurs. Le *C*, le *Java* et le *Python* sont des langage impératifs.

### Langage déclaratif

Un *langage déclaratif* permet de décrire ce que le programme doit faire (le **quoi**) et non pas comment il doit le faire (le **comment**). Par exemple en en *SQL*, on demande au serveur de prendre une information dans une base de donnée mais on ne lui dit pas comment le faire. Certains langages impératifs embraquent des constructions déclaratives.

### Gestion de la mémoire

la gestion de la mémoire dans un langage de programmation décrit comment les objets inutilisés sont identifiés et désalloués. En C on *malloc* et on *free* la mémoire. Ceci est nécessaire pour éviter les *fuites de mémoire* (memory leaks). La plupart des langages ont une gestion automatique de la mémoire et s'appuient sur un *ramasse-miette (garbage collector)*. En Java, le ramasse-miettes est chargé de libérer la mémoire allouée dynamiquement. En langage C/C++, ont a une gestion manuelle de la mémoire.

***

## Conclusion

Toutes ces caractéristiques permettent de comparer les langages afin de les utiliser à bonne escient.

| Langage  | Implémentation      | Scripts | Typage               | Paradigme            | Mémoire  |
| -------- | ------------------- | ------- | -------------------- | -------------------- | -------- |
| *C*      | Compilé             | Non     | explicite, statique  | procédurale          | manuelle |
| *Java*   | Compilé, interprété | Non     | explicite, statique  | OO, fonc, générique  | auto     |
| *PHP*    | Interprété          | Oui     | implicite, dynamique | proc., OO            | auto     |
| *Python* | Compilé, Interprété | Oui     | implicite, dynamique | proc., OO, fonc.     | auto     |
| *cala*   | Compilé, interprété | Oui     | implicite, statique  | OO, fonc., générique | auto     |

### Critères de choix d'un langage

On choisit un langage en adéquation aux besoins. On ne programme pas en C pour faire un site. Il faut connaître le domaine d'application et la plateforme cible. De plus, il faut qu'il y est une bonne lisibilité du code source. La richesse de la bibliothèque standard pèse aussi dans la balance ainsi que ces outils et ces bibliothèques tierces associées.
