# Base du Java

Le Java a été crée pour être une alternative au C++ qui est un autre langage orienté objet plus complexe. L'idée était de créer quelque chose de simple à prendre en main.

## Caractéristiques

C'est un langage simple qui permet à un programmeur novice de programmer très vite. C'est un langage interprété qui permet d'avoir un exécutable portable c'est à dire qui ne dépend pas de l'architecture de l'ordinateur comme le C. La compilation génère un code intermédiaire qui est interprété et ne dépend donc pas de l'architecture de l'ordinateur à 100%. 

## Compilation et interprétation

Le langage *Java* est, comme dit plus haut, interprété et compilé. *Java* nécessite *JDK* pour être interprété et compilé. Un fichier source `.java` est compilé et est transformé en "byte code" pour ensuite être compris par la machine.

La compilation ce fait comme en C en ligne de commande `$ javac <options <fichiers source>`. Ou les options correspondent à :

* `-g | \-g$:$none` : Gère les informations pour le débogage
* `-classpath | -cp` : Fixe le chemin de recherche des classes compilées (*Classpath*)
* `-source` : Précise la version des fichiers sources
* `-sourcepath` : Fixe le chemin de recherche des sources
* `-encoding` : précise l'encodage des fichiers source ("UTF-8", ...)
* `-d` : Fixe le répertoire de destination pour les classes compilées
* `-target` : Précise la version de la VM cible

On aura parfois besoin de ce qu'on appelle `classpath` qui est en réalité une bibliothèque comme en C mais qui est ici une liste de bibliothèques compilés par l'environnement Java. 

```shell
$ java [-options] class [args...]
$ java [-options] -jar jarfile [args...]
```

* `class` est ici le nom de la classe
* `-cp | -classpath` fixe le chemin de recherche des classes compilées
* `-jar` exécute un programme encapsulé dans un fichier *jar*

## Syntaxe du langage

La syntaxe de base est emprunté au C/C++, ainsi les commentaires, les types et les opérateurs sont les mêmes et chaque instructions se termine par un `;`. Java différencie majuscules et minuscules. 

## Types primitifs

* `boolean `: `true` ou `false`. Le seul type qui n'est pas en C
* `byte` : Entier de -128 à 127 (les types entiers sont signés)
* `short` : entier de -32768 à 32767
* `int` : entier de $-2^{31}$ à $2^{31}-1$
* `long` : entier de $-2{63}$ à $2^{63} -1$
* `char` : caractère Unicode sur 16 bits de `\u0000` à `\uffff`
* `float` : nombre en virgule flottante simple précision (32 bits IEE-754)
* `double` : nombre en virgule flottante double précision (64 bits IEEE-754)

## Notions de référence

* Les variables de type tableau, énumération, objet ou interface sont en fait des références.
* La valeur d'une telle variable est une référence vers (l'adresse de) un donnée
* Dans d'autres langages, un référence est appelée *pointeur* ou adresse mémoire

- En Java, la différence réside dans le fait qu’on ne manipule pas directement l’adresse mémoire: le nom de la variable est utilisé à la place
  - pas d’arithmétique des pointeurs en Java
  - les références assurent une meilleure sécurité (moins d’erreurs de programmation)
- L’association (l’affectation) d’une donnée à une variable *lie* l’identificateur et la donnée

## Gestion de la mémoire dans la *JVM*

La gestion de la mémoire est automatique en Java donc pas besoin de libéré la mémoire. Les variables locales sont créées sur la pile (*stack*) et la mémoire est allouée dans une zone mémoire appelée le tas (*heap*). La libération de la mémoire est automatique et gérée par le *ramasse-miette* (*Garbage Colector*).

## Les tableaux

La déclaration d'une variable tableau se fait en ajoutant `[]` au type des éléments.

```java
int[] unTableau;
```

La création du tableau se fait en utilisant l’opérateur `new` suivi du type des éléments du tableau et de sa taille entre `[]`.

```java
new int[10];
```

La référence retournée par `new` peut être liée à une variable :

```java
int [] unTableau = new int[10];
```

Il est possible de créer et d'initialiser un tableau en une seule étape :

```java
int[] unTableau = {1, 5, 10};
```

L’accès aux éléments d'un tableau se fait en utilisant le nom du tableau suivi de l'indice entre `[]`.

Pour schématiser, lorsqu'on créer un tableau, on créer quelque chose de la sorte : 

![img](file:///home/nicofm/Desktop/UVSQ/S4/CM/IN404/Documentation/Site/figs/tabref1.png)

En C un tableau peut pointer vers un autre tableau, en Java on peut faire la même chose, la terminologie n'est pas la même. On dit alors qu'un tableau ce référencie vers un autre tableau.

