# TD 1

### Exercice 1

1. L'idée est de mettre un 1 quand la liaison est dans le graphe. On connait ainsi les successeurs et les predecesseurs.

3. Ici on calcule le degré entrant et sortant du graphe pour chaque éléments. L'idée c'est de compter le nombre de flèches qui vont sur l'élément (degré entrant) et les flèches qui viennent de élément (degré sortant).

| s        | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:--------:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| $d^+(s)$ | 3 | 2 | 1 | 0 | 1 | 2 | 1 |
| $d^-(s)$ | 1 | 1 | 1 | 2 | 3 | 1 | 2 |

4. Dans l'algorithme suivant on initialise toute les cases du tableau à 0. Ensuite on fait une double boucle ou on vient ajouter en abscisse le degré entrant et en ordonnée le degré sortant. 
```
Pour i allant de 1 à n
    d+[i] = 0; d-[i]=0
fin pour

Pour i allant de 1 à n
    Pour j allant de 1 à n
        d+[i] += MO [i,j]
        d-[j] += MO [i,j]
    fin pour
fin pour
```
On obtient une difficulté en $O(n^2)$.

5. Il n'est pas fortement connexe car n'importe quel sommet ne mène pas à n'importe quel autre sommet. Par exemple, 7 n'a pas de chemin pour aller à 1.

6. 1->3->6>1

7. Un chemin hamiltonien est un chemin qui passe par chaque sommet. On obtient avec le graphe : 3612754

8. Le but est d'obtenir une matrice symétrique à partir de la matrice orienté actuelle. Par exemple si en MO[5,2] on a un 1, alors l'idée est de mettre en MO[2,5] un 1 aussi.
```
Pour i allant de 1 à n 
    Pour j allant de i à n
        MNO[i,j] = MO[i,j] ou MO[j,i]
        MNO[j,i] = MNO[i,j]
    fin pour
fin pour
```

9. 
| s   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:---:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| (s) | 4 | 3 | 2 | 2 | 4 | 3 | 2 |

10. Ce graphe n'est pas connexe.

11. 1365724

### Exercice 2

1. Une séquence de degré est une liste croissante qui donne les degrés des sommets. Il n’existe pas de graphes de séquence de degré (0,0,1,2,2,2,6,7) car pour avoir un sommet de degré 7, il faut que les 7 autres sommets soit liés à celui ci, hors les deux premiers sommets de la séquence valent 0, ils ne sont donc pas liés à d'autres sommets. Il aurait fallut que les autres sommets aient un degré supérieur ou égale à 1.

2. Il existe au moins un graphe avec la séquence (0,0,1,3,3,3,4,4,5,5).


