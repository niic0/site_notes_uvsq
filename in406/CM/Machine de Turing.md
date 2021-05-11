# Machine de Turing

Quels sont les dispositifs pour faire un calcul ? (algorithmique):

* Automate fini
* Automate fini non-déterministe
* Expression régulière
* Automate à pile déterministe
* Automate  à pile non-déterministe
* Grammaire non contextuelle

Peut-on imaginer des dispositifs plus généraux ? Les automates ne peuvent reconnaître le langage $a^nb^n | n \in \N$. Les automates ne peuvent pas simuler un compteur par exemple. 

Une généralisation du lemme de l'étoile montre que les automates à pile ne peuvent pas reconnaître le langage $\{a^nb^nc^n | n \in \N\}$. Ajouter de la mémoire à un automate le rend plus puissant. On remplace la **pile** par une **liste** (bande infinie vers la droite), c'est la *machine de Turing*.

Elle est définie par :

* Un alphabet $\Sigma$ des caractères d'entrée
* Un alphabet de travail $\Gamma$ avec $\Sigma \subseteq \Gamma$ et un caractère spécial blanc noté $\square$ qui n'est pas dans $\Sigma$
* Un ensemble fini d'état $Q$
* Un état initial $q_0\in Q$, deux états spéciaux $Accept \in Q$ et $REJECT \in Q$
* Une fonction de transtition $\delta$ de $Q\times\Sigma$ vers $Q\times \Sigma \times \{L,S,R \}$ (Left, Stay, Right)

### Configuration d'une machine de Turing

La **configuration** d'une *MT* est un triplet ($B,pos,q$) ou $B$ est la **bande** ou ruban de la machine, $pos$ est un entier désignant la position de la tête de lecture et $q\in Q$. Une bande $B$ est une suite infinie de symboles de $\Gamma$, qu'on peut noter $B_0,B_1,...$ On représente $B$ par un mot fini (les symboles suivant étant $\square$).

![turing_machine](/home/nicof/Desktop/UVSQ/in406/CM/turing_machine.png)

### Configuration initiale

Comme expliqué précédemment, on note $x$ la bande qui contient le mot $x$ sur ses premières case et $\square$ sur ses cases suivantes. La configuration initiale d'une MT et $(x,0,q_0)$

### Transition entre configurations

On définit la transition de la configuration $(B,pos,q)$ à la configuration $(B',pos',q')$ par la fonction de transition $\delta$ :

* On note $(q',c,D) = \delta(q,B_{pos})$ (calcul du nouvel état)
* $B_i = B_i'$ pour $i\neq pos$ et $B'_{pose} = c$ (écriture d'un symbole sur la bande)
* Si $D = L$, $pos'=pos-1$, si $D=S$, $pos'=pos$ et si $D=R$, $pos'=pos+1$.
  Attention si $pos= 0$ et $D=L$, on ne peut pas aller vers la gauche et on a $pos′= 0$. Pour éviter ce problème, on peut faire commencer le ruban par un symbole spécial. (calcul du mouvement de la tête)

### Calcul d'un MT

On définit une suite de configuration $C_i(x)$ par :

* $C_0(x)$ est la configuration initiale avec $x$ sur la bande
* $C_i(x)$ est obtenue de $C_{i-1}(x)$ par transition

Une suite de configurations est finie et terminé par une configuration contenant **ACCEPT** ou **REJECT**, ou infinie et contient pas **ACCEPT** ou **REJECT**. La suite de configurations représente le calcul de la machine de Turing et donc sa taille correspond au *temps de calcul*.

Une configuration est d'une certaine manière finie. En partant d'une configuration initiale finie, on obtient que des configurations finies. Cela justifie la représentation de la bande par un *mot fini*. Si on a un mot créer sur la bande de taille 1000, la partie intéressante ce trouvera dans ces 1000 caractères, le reste qui est infinie, ne contient que des $\square$.

### Langage reconnu

### Exemple

Donnons ici une machine qui accepte les mots finissant par $a$ :

*  $\Sigma = \{a,b\}$
* $\Gamma = \{a,b,\square\}$
* $Q=\{q_0,q_a,q_b, ACCEPT,REJECT \}$
*  $\delta(q_0,a) = \delta(q_a,a) = \delta(q_b,a) = \delta(q_a,a,R)$
   $\delta(q_0,bb) = \delta(q_a,b) = \delta(q_b,b) = \delta(q_b,b,R)$
   $\delta(q_a,\square) = (ACCEPT,\square,S)$

### Représentation graphique d'une MT

La représentation est similaire aux automates finis et automates à pile :

* Un sommet est représenté par un cercle contenant son nom.
* Une flèche entrante dénote le sommet initial
* Une transition $\delta(q_1,a) = (q_2,b,R)$ se note par un arc entre $q_1$ et $q_2$ avec comme label $(a,b,R)$

### Les fonctions d'une MT

On peut définir $f_M$, la fonction partielle calculée par une machine de Turing $M$ de la manière suivante : 

* La suite de configurations $C_i(x)$ termine sur la configuration $(y,ACCEPT, pos)$, alors $f_M(x) = y$
* La suite de configurations $C_i(x)$ termine sur la configuration $(y,REJECT,pos)$, ou la suite des configurations est infinie, alors $f_M(x)=\bot$ ($f$ n'est pas définie sur $x$)

Au lieu de reconnaître des langages, on calcule des fonctions comme en programmation et en algorithmique. 

[Exemples de machine de Turing](https://turingmachinesimulator.com/). Ce site permet de créer des machine de Turing en voyant l’avancement avec un ruban. La prise en main est facile.

### Autres modèles de calcul

* Machine de Turing à plusieurs rubans
* Machine de Turing non déterministe
* Machine RAM ou de von Newmann (Assembbleur / processeur)
* Pseudo-code (Programmation impérative)
* Fonctions récursives (Programmation fonctionnelle)

### Calculabilité

La **calculabilité** est le domaine de l'informatique qui s'intéresse au pouvoir de calcul des différents modèles de calcul.

> #### Conjecture (Thèse de Church)
>
> *Toute fonction calculable par un dispositif physique est calculable par une machine de Turing.*