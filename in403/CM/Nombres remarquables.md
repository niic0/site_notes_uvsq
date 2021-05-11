# Nombres remarquables sur les graphes

## Quelques définitions

* un graphe est dit **complet** si toutes les arêtes existent : chaque sommet est relié à tous les autres $=>\frac{n(n-1)}{2}$. Le graphe complet de $n$ sommets est noté $K_n$.
* On note $\Delta$ le plus grand degré du graphe.

### Cliques

* Une **clique** est un sous-ensemble de sommets tel que le sous-graphe réduit à ces sommets est complet : un sous ensemble de sommets tous connectés entre eux.
* Une clique est dite **maximale** si quel que soitle sommet rajouté, ce n'est plus une clique. Il est très facile d'obtenir des cliques maximales.
* Une clique est dite **maximum** si elle a la plus grande cardinalité possible. Il est très difficile de trouer une (la) clique maximum.
* On note $\omega (G)$ le nomre de sommets d'une clique maximum de $G$ (la taille de la plus grosse clique de G).

### Stable

* Un ensemble **stable** (*independent set* en Anglais) est un sous-ensemble de sommets absolument pas connectés entre eux (aucune arête entre deux sommets quelconques d'un stable).
* On note $\alpha(G)$ le nombre de sommets d'un stable maximum de $G$. Ce nombre est appelé **le nombre de stabilité du graphe**. (problème NP-difficile)
* On appelle graphe complémentaire de $G$ que l'on note $\bar A$ le graphe avec les mêmes sommets et les arêtes opposées
* Une clique dans $G$ est un stable dans $\_ G$ et vice et versa.
* $\alpha(G)=\omega(\bar G)$

### Coloration - nombre chromatique

Chaque sommet doit avoir une et une seule couleur.

**Problème** : Trouver le nombre minimum de couleurs pour colorier les sommets tels que é sommets adfacents n'aient pas la même couleur.

* **Nombre chromatique** : Nombre minimum de couleurs pour colorier les sommets d'un graphe $G$ noté $\mathcal X_v(G)$ (problème NP-difficile)

Chaque couleur correspond à un ensemble stable.

* $\mathcal X_v(K_n) = n$ 
* **Théorème des 4 couleurs** : tout graphe planaire a un nombre chromatique inférieur ou égal à 4.
* Un graphe a un nombre chromatique égal à 2 (il est alors dit biparti) si et seulement si il ne contient pas de cycle de longueur impaire.
* Soit $G=(V,E)$ un graphe de degré minimum $\Delta$. Le nombre chromatique de $G$, $\mathcal X_v(G)$ est inférieur ou égal à $\Delta +1$.

> Preuve par récurrence  : $\mathcal X_v (G) \leq \Delta +1$
>
> * <u>Initialisation</u> : Pour $n=2$, nous avons $\Delta = 1$ et $\mathcal X_v(G)=2$
> * <u>Hérédité</u> : Supposons que la propriété est vraie pour $n$. On veut la montrer pour $G = (V,E)$ avec $|V| = n+1$. 
>   Soit $x$ un sommet de G. Considérons le graphe $G′=G−\{x\}$ dont le degré est au plus $\Delta$. On peut donc le colorier avec au plus $\Delta+1$ couleurs (d'après l'hyp. de récurrence). $x$ est adjacent avec au plus $\Delta$ sommets, on peut donc lui attribuer une couleur non utilisée par l'un de ces sommets.
>
> Attention, cette borne peut être très imprécise

### Algorithme de coloriage séquentiel

Méthodes approchées qui donnent une coloration admissible mais pas forcément la meilleure, c'est à dire avec le nombre minimal de couleurs. La plus simple estl a suivante : 

* La couleur représentées par les entiers positifs.
* Coloration **gloutonne**:
  * On considère les sommets les uns aprèsles autres.
  * A chaque sommet on attribue la plus petite couleur non attribbuée à au moins un de ses voisins.
* Complexité : $O(n\times \Delta)$

### Algorithme Welsh-Powell