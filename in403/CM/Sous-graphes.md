# Sous-graphes

## Définitions

Un sous-graphe à 2 définitions : induit et couvrant. 

* **Induit** : tel que pour un graphe $G=(V,E)$, on a $V'\subseteq V$, $G[V']$ se lit G induit $V'$
* **Couvrant** (partiel) : est un graphe $E' \subseteq \{[u,v]\in E : u\in V',v \in V' \}$

L'ensemble des sommets est inclus dans l'ensemble de départ et les arêtes dans l'ensemble d'arrivé.

## Problème Eulérien

Euler se demandait si il pouvait passer une fois par chaque ponts de sa ville (*königsberg*) pour aller chez lui. L'idée est de passer une seule fois par chaque arc. La réponse est non dans son cas non. Mais le problème peut être étendue à tous les graphes : 

> Un graphe orienté fortement connexe contient un circuit eulérien si et seulement si **en chaque sommet le degré entrant est égal au degré sortant**. 

### Problème du postier chinois

Le problème du postier chinois est le même que celui de *Euler* : On cherche ) passer une et une seule fois par chaque arc. On peut avoir pour idée de se promener au hasard sans reprendre une rue déjà prise auparavant. On peux voir assez vie que ce n'est pas la bonne idée, en effet si on passe par le sommet de départ, on se retrouve bloqué. 

On va résoudre ce problème d'une façon algorithmique : 

* Marquer un sommet "racine".
* Tant qu'il y a un arc d'un sommet non marqué vers un sommet marqué, marquer le sommet de départ et l'arc.

Si plusieurs direction sont possibles, on peut se diriger de façon aléatoire. 

<img src="../../../site/in403/Screenshot_20210216_090225.png" alt="Screenshot_20210216_090225" style="zoom:67%;" />

> Quand on prend la topologie des arcs, on se rend compte qu'on est dans un cas d'**anti-arborescence** couvrante.

<img src="../../../site/in403/Screenshot_20210216_090053.png" alt="Screenshot_20210216_090053" style="zoom: 67%;" />

On se déplace maintenant toujours aléatoirement dans le graphe à partir de la racine en respectant la règle : "ne prendre un lien rouge que s'il n'y a pas d'autre choix." On obtient le suite suivante : 

<img src="../../../site/in403/Screenshot_20210216_090449.png" alt="Screenshot_20210216_090449" style="zoom:67%;" />

On remarque qu'on a saturé tous les sommets. C'est donc un circuit eulérien.

### Généralisation du problème du postier chinois

Données :Un graphe G pondéré sur les arêtes (poids strictement positifs)

Problème : Trouver un cycle de poids minimal passant par 