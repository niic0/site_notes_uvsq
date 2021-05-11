# Décadibilité

## Calculabilité

La calculabilité est le domaine de l'informatique qui s'intéresse au pouvoir de décision des différents modèles de calcul.

> ## Conjecture (Thèse de Church)
>
> *Toute donction calculatble par un dispositif physique est calculable par une machine de Turing.*

Cette conjecture est renforcée par l'expérience, les modèles suivants ont la même expressivité (Turing puissant):

* toutes les variantes des machin,es de Turing
* le lambda calcul
* les langage de programmation
* les machines de Von neumann
* les ordinateurs quantiques

## Questions fondamentales

On utilise les termes *langages* et *problème* de manière interchangeable. Le problème associé au langage est de décider si un mot appartient au langage.

> ## Définition
>
> Un problème est dit **décidable** (et une fonction **calculable**) s'il existe une machine de Turing qui le décide.

1. Étant donné un problème, est -il décidable ?
2. Existe-t-il un problème qui n'est pas décidable ?
3. Peut on décider **eficacement** d'un problème ?

## Compilation et pseudo-code

Il existe un langage de programmation minimal qui permet de décrire les fonctions calculables (fonctions récursives) :

1. la fonction constante égale à 0
2. la fonction successeur
3. les compositions de fonctions

## Existance des problèmes indéciables

> #### Théorème
>
> *Il existe un codage des machines de Turing par des entiers (ou des suites de 0 et de 1).*

On notera $<M>$ le code de $M$

> #### Théorème
>
> *Il existe une fonction qui n'est pas calculable par machine de Turing.*

Pour comprendre cela, il faut savoir que les entiers sont **moins nombreux** que les fonctions des entieres vers les entiers. $\aleph$

#### Diagonilsation de *Kantor* $|\N| <|\R|$

Raisonnement pas l'absurde: On peut numéroter les réels de $[0,1]$. Par exemple :

$r_1$ : 0, $a_1^1,a_2^1,a_3^1,a_4^1,a_5^1,a_6^1,...$

$r_2$ : 0, $a_1^2,a_2^2,a_3^2,a_4^2,a_5^2,a_6^2,...$

$r_3$ : 0,$a_1^3,a_2^3,a_3^3,a_4^3,a_5^3,a_6^3,...$

$r_4$ : 0, $a_1^4,a_2^4,a_3^4,a_4^4,a_5^4,a_6^4,...$

$r_5$ : ...

On observe une diagonale $a_1^1$, $a_2^2$, $a_3^3$, $a_4^4$. On peut dédure : $b_i = (a^i_i +1)\mod 10$ où on pourrait avoir $b=0,b_1,b_2,b_3...$ et $\forall i\in \N, b\neq r_i$ . On contredit alors la possibilité d'indéxer les réel ce qui implique qu'il est impossible de représenter les réel en langage machine. 

## Machine universelle

> #### Théorème
>
> Il existe une machine de Turing $U$ à 3 rubans qui simule n'importe quelle machine *M* à un ruban sur l'alphabet $\{0,1, \square \}$. C'est à dire que pour toute entrée $x$ de la machine $M$, le calcul de $U$ sur $<M>$,$x$ est le même que le calcul de $M$ sur $x$.

Cela correspond à la notion d'interpréteur en informatique.

### Descripteur de la machine universelle

L'alphabet de la machine $U$ est $\{ 0,1,\square,\#\}$ et les états de $M$ sont représentés par des entierse dénotés par $<q>$. Les trois rubans contiennent:

* $<M>$, le code de la machine à simuler sur le premier ruban
* Le codage de l'état initial $<q_0>$ sur le deuxième ruban et le symbole sous la tête de lecture du troisième ruban
* $x$, le mot d'netrée sur la troisième ruban

Machine représentée 

### Fonctionnement de la machine universelle

À chaque étape de simulation, est écrit sur le deuxième ruban l'éta courant $<q>$. Le symbole $s$ est sous la tête de lecture dans le troisième ruban. Par recherche linéaire dans $<M>$, on trouve la transition ($<q> \# s\# <q'> \# s'\#D$) qui permet :

* D'écrire de nouvel état $<q'>$ sur le deuxième ruban
* d'écrire le novueau symbole $s'$ suir le troisième bande
* de déplacer la tête de lecture du troisième ruban en suivant $D$

Simulation d'une machine $M$ qui fonctionne en temps $t$ en temps $O(t^2)$. La machine est en effet plus lente du fait des nombreuses transitions, ce qui implique que le temps mis dépend de la taille de la machine. ce raentissement existe sur les OS d'ajourd'hui.

> #### Problème de l'arrêt
>
> On voudrait **détecter automatiquement** les bugs des programme.
>
> <u>Entrée</u> : Une machine de Turing $<M>$ et une entrée $x$.
> <u>Question</u> : Est ce que $M$ s'arête à $x$

### Indécidabilité du problème de l'arrêt

On dit qu'un problème est **indécidable** s'il n'existe aucune machine de Turing qui le décide. 

> #### Théorème
>
> *Le problème de l'arrêt est indécidable*

On ne peut donc pas trouver les bugs d'un programme ou se protéger contre des virus de manière automatique.

#### Éléments de preuve

On va exhiber un problème du même type qui est indécidable.
$$
L = \{ <M>| M\ est\ une\ MT\ qui\ rejette\ l'entrée\ <M>\}
$$
Simple **raisonnement par l'absurde** appliqué à une machine qui reconnait *L*. Paradoxe du barbier.

#### Exemples de problèmes indécidables

1. Problème de **correspondance de Post**. On se donne un jeu de dominos avec des mots sur les deux parties de chaque domino. Peut on trouver une suite de dominos qui compose le même mot en haut et en bas ?
2. Peut-on décider si un théorème d'arithmétique est prouvable dans l'axiomatique de Peano ?
3. Peut on trouver une solution entière à une équation polynomyle ? **Dixième problème de Hilbert**
4. Un ensemble de machines qui vérifient une propriété non triviale, **théorème de Rice**.