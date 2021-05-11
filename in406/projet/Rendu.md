# Introduction

Ce projet consiste à évaluer des expressions booléennes en C à l'aide d'automate... [TODO]

# Reconnaissance par automate

Le but de cette partie est de construire un automate à pile permettant de reconnaître une expression booléenne. Pour ça chaque élément de l'expression devient un *token* et l'expression booléenne entière est un mot. Pour construire l'automate, nous pouvons tout d'abord nous intéresser aux propriétés de chaque classe d'élément de l'expression. Pour cela, on va regarder qu'elles sont les éléments qui peuvent venir avant ou après un élément. Par exemple un 1, soit une constante, ne peux pas avoir une parenthèse ouvrante après lui. On peut alors émettre une liste de condition qui indique qu'elle sont les prédécesseurs et les successeurs possibles d'un élément donné:

[TODO]

* **Constantes**
  * *Successeurs* : opérateurs binaires, parenthèse ouvrante, opérateurs unaire
  * *Prédécesseurs* : opérateurs binaire, parenthèse fermante

* **Opérateurs binaire**
  * *Successeurs* : constante, parenthèse fermante
  * *Prédécesseurs* : constante, parenthèse ouvrante, opérateur unaire

* **Parenthèse ouvrante**
  * *Successeurs* : opérateurs binaires, parenthèse ouvrante, opérateurs unaire
  * *Prédécesseurs* : opérateurs binaire, parenthèse fermante

* **Parenthèse fermante**
  * *Successeurs* : opérateurs binaires, parenthèse ouvrante, opérateurs unaire
  * *Prédécesseurs* : opérateurs binaire, parenthèse fermante

* **Opérateurs unaire**
  * *Successeurs* : constante, parenthèse ouvrante
  * *Prédécesseurs* : opérateurs unaire

De cela, on peut créer un tableau qui nous servira de repère à la création des automates :

[TODO] tableau

Chaque croix sur le tableau veux dire que a est prédécesseur de b et donc que b est successeur de a. Le tableau se lit de la façon suivante : si on veux connaître les prédécesseurs, il suffit de regarder sur la colonne en abscisse puis à chaque croix rencontrées dans la colonne correspond un prédécesseur. De la même manière, si on veux connaître les successeurs d'un élément, on regarde en ordonnée où se situe l'élément souhaitait puis à chaque croix rencontré dans la ligne correspond un successeurs. 

Maintenant que nous connaissons les contraintes pour chaque éléments, nous pouvons construire les automates qui nous permettront de construire l'automate final.

Tous les automates seront des automates à reconnaissance par pile vide. On notera $\delta$ la pile vide.

[TODO] trouver une manière de présenter les transitions

### Automate 1

Commençons simplement par un automate qui reconnaît les expressions booléennes contenant uniquement des constantes et des opérateurs binaires. L'idée est de créer une pile permettant de stocker le prédécesseur de l'élément actuel. Ainsi, en connaissant le prédécesseure et en se servant du tableau, on peut créer des transitions possibles après ce token. La pile nous servira par la suite uniquement à regarder qu'elle était le prédécesseur du token actuel. On créer donc une boucle qui permettra de prendre autant d'expression de type 1+1 en compte

[TODO] définition formel de l'automate

[TODO] automate 

### Automate 2

A partir de l'automate précedent, on peut créer l'automate qui reconnaît les expressions booléenne sans les parenthèses. On a donc l'opérateur en plus du précedent automate. On voit dans le tableau que l'opérateur unaire peut avoir pour prédecesseur un 