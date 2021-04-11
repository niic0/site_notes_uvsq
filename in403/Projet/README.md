

# Projet IN403 - Algorithmique
Projet qui consiste à créer une table de routage

## TODO

### Structure de donnée

**Structure Noeud** :

* Liste des noeuds voisins
* Poids associés aux liens de chaque voisins

Exemple d'une implémentation possible en python :

```python
# Graphe g:
g = {'a': {'b': 4, 'c': 2},					# a est lié à b avec un poids de 4 et à c avec un poids de 2
     'b': {'a' : 4,'d': 5, 'c': 1},
     'c': {'a' : 2, 'b' : 1, 'd' : 8,'e': 10},
     'd': {'b': 5, 'c': 8, 'e': 2},
     'e': {'c': 10, 'd' : 2, 'f': 3},
     'f': {'e' : 3,'d' : 6}}
 
>>> g['a']
{'c': 2, 'b': 4}
>>> g['a']['b']
4
>>> 'c' in g['a']
True
```

La structure **dictionaire** de python est intréressante mais c'est un graphe non orienté donc dès qu'on a par exemple `'a':{'b':3}` il faudra obligatoirement `'b':{'a':3}` avec évidement la même valeur sinon on est dans le cas d'un graphe orienté 

### Fonctions

#### Tester la connexité d'un graphe

#### Dijkstra

