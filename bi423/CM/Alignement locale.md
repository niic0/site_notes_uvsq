# Alignement local

On cherche, dans un alignement local à savoir si un bout de notre séquence correspond à un bout d'une autre séquence. On a vu dans le CM précédent une manière de voir comment on pouvait fait matcher une séquence à une autre. On va maintenant voir l'une des méthode la plus utilisé pour rechercher des similarités dans des séquences.

## *BLAST*

**BLAST** : **B**asic **Local** **A**lignement, il associe à chaque alignement un **score S** d'alignement et la "**significativité**" de ce score (de cet alignement). On appelle cette significativité une **e-value**.

Si la **e-value** est inférieur à $10^{-6}$, elle peut être interprétée comme suit :

* La probabilité d'obtenir *par chance* le score **S** considéré est de l'ordre de la *e-value*
* Plus la *e-value* est petite (proche de 0), meilleur est l'alignement (i.e. , c'est plus dû au hasard)

***

### Type d'analyse proposé par Blast 

* **Nucléique** : On utilisera ***BlastN***, compare une séquence nucléique à une **banque** nucléique.
  * Utile pour étudier une séquence qui ne code pas une protéine, ou localiser un ARNm sur un génome et vice versa.
* **Protéine / Protéine** : ***BlastP***, compare une séquence protéique à une **banque** protéique.
  * Recherche les "homologues" d'une protéine (i.e., les protéines qui lui ressemblent)
* **ADN / Protéine** : On utilise ***BlastX***, compare une séquence nucléique à une **banque** protéique.
  * Recherche si il y a du "codant" sur la séquence nucléique.
    * <u>Génération</u> des brins correspondant aux **6** cadres de lecture.
    * <u>Traduction</u> des **6** brins $\rightarrow$ Obtention de **6** "traduits".
    * <u>Comparaison</u> des **6** traduits avec les protéines d'une banque.

***

*Blast* organise le résultat en sommaire graphique, c'est à dire qu'il va ordonner les protéines de façon à ce que l'utilisateur voit les séquences qui correspondent à d'autre séquences de la banque. L'idée est qu'en un coup d’œil on sache directement quelle séquence correspond à la protéine mis dans *Blast*.

Ici on voit en rouge la séquence exacte de la protéine mis dans *Blast* (car cette protéine existe déjà dans *Blast*).

<img src="/home/nicof/Desktop/UVSQ/bi423/CM/Screenshot_20210215_102613.png" alt="Screenshot_20210215_102613" style="zoom: 67%;" />

*Blast* fournie aussi un affichage plus descriptif : 

<img src="/home/nicof/Desktop/UVSQ/bi423/CM/Screenshot_20210215_102708.png" alt="Screenshot_20210215_102708" style="zoom:67%;" />

Finalement, *Blast* nous dit quelle séquence de sa banque à le plus de correspondance avec notre protéine.

<img src="/home/nicof/Desktop/UVSQ/bi423/CM/Screenshot_20210215_102814.png" alt="Screenshot_20210215_102814" style="zoom:67%;" />

### *e-value*

2 banques sont utilisés quand on calcul une *e-value* à partir de la banque "bio" et d'une banque aléatoire crée à partir de la banque bio qui va mélanger notre séquence. Cette banque aléatoire va servir à faire correspondre notre séquence à une banque "pourrie" (traduit de l'anglais *junk data bank*). Si notre séquence correspond à une séquence de cette banque pourrie, plus que la vrai banque, alors la valeur n'a aucune signification.

La *e-value* n'est pas une probabilité. Par exemple si notre *e-value* = 3, cela veux dire que je m'attend à trouver 3 fois, en moyenne, un alignement de score supérieur à **S** si je fais un *blast* entre ma séquence et une banque de "séquences aléatoires".

Si la **e-value** est inférieur à $10^{-6}$, elle peut être interprétée comme suit : La probabilité d'obtenir un score de valeur supérieure à **S** entre ma séquence et une "séquence aléatoire" est égale à $10^{-6}$.

<u>Plus la e-value est petite, meilleur est l'alignement.</u> 