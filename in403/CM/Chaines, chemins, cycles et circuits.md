# Chaînes, chemins, cycles et circuits

Cette partie se concentre, comme la dernière, sur les notions importantes des graphes. On verra ici qu'une chaîne, un chemin, un cycle et un circuit sont des thermes qui s'emploient selon le type de graphe que l'on utilise, orienté ou non-orienté. Ces notions ne sont pas simples a employé dans le sens où elles différent avec le type de graphes. Une chaîne ne désigne pas exactement la même chose dans un graphe orienté que dans un graphe non orienté. Il y a des chaînes et des cycles dans les graphes orientés et des circuits et des chemins dans les graphes non-orientés.

## Cas d'un graphe Orienté

* Un **chemin** est une suite de sommets $v_0 v_1...v_n$ telle que chaque couple de sommets successifs est sur un arc. La **longueur** du chemin est n.
* Une **chaîne** est une suite de sommets $v_0 v_1...v_n$ telle que $\forall \;0 \leq i<n (v_i,v_{i+1} \in A)$ ou $(v_{i+1},v_i) \in A$. Plus simplement, une chaîne dans un graphe orienté est un chemin dont on est pas obligé de respecté le sens des flèches. 
* un **circuit** est un chemin tel que $v_0=v_n$.

![img](data:image/png;base64,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)

## Cas d'un graphe non orienté
* Une **chaîne** est une suite de sommets $v_0v_1...v_n$ telle que chaque paire de sommets successifs $v_iv_{i+1}$ est soit un arc ($v_iv_{i+1})$, soit un arc ($v_{i+1}v_i$)
* La **longueur** du chemin correspond à $n$.
* Un **cycle** est une chaîne telle que $v_0=v_n$



## Connexités

### Cas orienté

>  Un graphe orienté est fortement connexe si et seulement si pour tout couple de sommets il existe un chemin entre ces deux sommets

* Un graphe orienté *G* est **connexe** si et seulement si pour tout couple de sommets il existe une **chaîne** entre ces deux sommets. C'est à dire qu'on peut aller de A à C et de C à A par exemple.
* Un graphe orienté est **fortement connexe** si et seulement si pour tout couple de sommets il existe un **chemin** entre ces deux sommets.

De ces définitions on peut déduire (**Lemme**) que si *G* est fortement connexe, alors tout sommet appartient à au au moins un circuit.

### Cas non-orienté

> Un graphe orienté *G* est **connexe** si est seulement si pour tout couple de sommets il existe une **chaîne** entre ces deux sommets dans le graphe non orienté obtenu en supprimant l'orientation des arcs de *G*.