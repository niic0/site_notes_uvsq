## Arbres et DAGs

### Cas non-orienté

* Un **arbre** est  un graphe non-orienté connexe sans cycle (élémentaire).
* Un **DAG** est un graphe orienté connexe sans circuit.

### Cas orienté

* Un **DAG** est un graphe orienté connexe sans circuit.
* Un **arbre** est un DAG sans cycle.
* Une **arborescence** est un arbre avec un seul sommet.
* Une **anti arborescence** est un arbre avec un seul sommet de degré sortant nul (la racine) 

**Propriétés :**

* Si un graphe est un DAG, alors il contient au moins un sommet de degré entrant nul.

* Si un graphe est un DAG, alors le graphe obtenu en supprimant un de ces sommets est aussi un DAG. 
