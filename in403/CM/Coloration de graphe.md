# Coloration de graphe

Dans les problèmes de construction d’emploi du temps, de location de véhicule etc, ce cache très souvent un algorithme de coloration de graphes. Historiquement, cette théorie vient du fait qu'on souhaite colorer une carte en fonction des région avec le moins de couleur possible. Des mathématiciens Français ont modélisé ce problème avec un graphe. Chaque zone de couleur est un sommet et s'il est collé avec une autre couleur, on créer une arête vers le sommet de l'autre couleur. Né alors une **conjecture** : 4 couleurs suffisent pour chaque carte géographique.

On a donc un graphe non orienté $G=(V,E)$ avec les propriétés suivantes :

* **Coloration de G** : Application $f$ de $V$ dans un ensemble de couleurs.
* **Coloration propre** : $(u,v)$ une arête de $E$ implique $f(u)$ différent de $f(v)$
* **Taille d'une coloration (propre)** : cardinal de $f(V)$
* **Nombre chromatique de G** : Taille minimum d'une coloration propre de $G$

**Théorème** : Un graphe est 2-colorable si et seulement si il ne contient pas de cycles de longueur impair.

* Chaque sommet pair a au moins un voisin impair, et inversement. 
* Donc si 2-colorable, tous les sommets pairs on,t une couleurs et les impairs l'autre
* C'est contradictoire pour [2p+1,1].

* **-> Donc il faut 3 couleurs**

## Graphe planaire

4 couleurs suffisent pour chaque graphe planaire.