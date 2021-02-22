# Concepts de base sur les Graphes

## Définition d'un Graphe

Un graphe est un objet mathématique et une structure de donnée modélisant des éléments d'un ensemble de relations. On utilise des graphes dans tout types de réseau, en informatique par exemple on les utilises en base de donnée, en télécoms, en génie logiciel, etc. Les graphes sont aussi utiles en biologie, en chimie, en transport en finance bref, le domaine d'application des graphes est très large.

***

## Relation

Une **relation sur V** est une application $A$ de $V\times V$ dans {Vrai, Faux}
Exemple sur $V={a,b,c,d}$
*Extension* de $V$ :  $A={(a,a),(a,b),(b,c),(c,d),(d,c),(d,a)}$

Avec cette *extension*, on peut créer une **Matrice adjacence** et un **Graphe de relation**.

*Matrice adjacence de $V$*

|       | a    | b    | c    | d    |
| ----- | ---- | ---- | ---- | ---- |
| **a** | 1    | 1    | 0    | 0    |
| **b** | 0    | 0    | 1    | 0    |
| **c** | 0    | 0    | 0    | 1    |
| **d** | 1    | 0    | 1    | 0    |

*Graphe de relation de $V$* avec quelque définition en plus. Un graphe de relation, c'est un graphe qui, comme son nom l'indique, met simplement des relations entre éléments. Ces relations sont indiqué via des traits qu'on appelle des arêtes et les éléments en relation sont appelés sommets.

<img src="https://www.numworks.com/fr/ressources/snt/modelisation-reseau-social/graphe-6464fa2e.png" width=500/>

## Graphe orienté

Un **Graphe orienté G** est un couple $(V,A)$ où :

* $V$ est un ensemble d'éléments appelés **sommets** ou *nœuds* 

* $A$ est une parti de $V \times X$, chaque élément de A est un **arc**

### Arcs

* Pour un arc ($v,w$) d'un graphe orienté, on dit que w est un **successeur** de $v$, et que $v$ est un **prédécesseur** de $w$.

* Deux arcs sont consécutifs si l'extrémité finale de l'un est l'extrémité initiale de l'autre $((u,v),(v,z))$

* Un arc est **entrant (sortant)** d'un sommet si ce sommet est son extrémité initiale (finale).

### Degré d'un sommet 

  * Le **degré sortant** de $v$, noté $d^+(v)$, est le nombre d'arcs dont $v$ est origine.
  * Le **degré entrant** de $v$, noté $d^-(v)$, est le nombre d'arcs dont $v$ est extrémité finale.

### Graphe orienté

* Un **graphe orienté** G est **complet** si pour tout couple de sommets $u$ et $v$, l'arc ($u,v$) existe ou l'arc ($v,u$) existe.

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/23/Directed_graph_no_background.svg/1024px-Directed_graph_no_background.svg.png" width=500/>

Un graphe orienté $G=(V,A)$ est **orienté-symétrique** si est seulement si ($u,v$) est un arc implique que $(v,u)$ est un arc.

<img src="https://ascendances.files.wordpress.com/2011/08/exemple_gao_web.gif" width=350/>

## Graphe non orienté

Un graphe non orienté cache en réalité un arbre orienté. Simplement, le graphe non orienté est plus "simple" car on enlève (les "graphe orienté de fainéant").

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b2/Ungerichteter_Graph_mit_4_Knoten_und_3_Kanten.svg/1200px-Ungerichteter_Graph_mit_4_Knoten_und_3_Kanten.svg.png" width=300 style="filter:invert(1)"/>

Un graphe **non orienté** est un couple $(v,e)$ où :
  * $v$ est un ensemble d'éléments appelés **sommet** ou nœuds
  * $e$ est une partie de l'ensemble des paires (non ordonnées) de sommets. Chaque élément de $e$ est une **arête**

  * Une arête est **incidente** à un sommet si ce sommet est l'une de ses extrémités.
  * Le **degré** d'un sommet $v$, noté $d(v)$, est le nombre d'arêtes qui lui sont incidentes.
  * Le **degré d'un graphe** est le degré maximum de ses sommets.
