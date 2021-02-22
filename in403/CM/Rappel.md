# Rappels
Pour bien comprendre les graphes, il faut tout d'abord avoir des notions en algorithmique. Cette partie ce concentre sur ces notions fondamentales.
## Complexité des algorithmes

Dans une complexité on a tout d'abord une notion de taille, c'est à dire au nombre de donnée à traiter. Par exemple dans un tableau d'entier de *N* cases *T*, on cherche un entier *X*. On a notre donnée qui est notre tableau *T* d'entier et on a notre problème qui est de chercher un entier. On va donc faire un algorithme qui répond au problème:

```
i <- 1
Tant que (i<=N) et (T[i] !=X)
	Faire i <- i+1
Retourner (i<=N)
```

Ici, on parcourt le tableau avec `i<=N` de 1 jusqu'au dernier entier et on vérifie si l'entier `T[i]` n'est pas égale au nombre recherché.  

Pour la complexité, on a simplement à compter les affectations :

```
i <-1			// 1 opération
Tant que (i<=N) et (T[i] !=X)	// 3 opérations, au plus N+1 fois
	Faire i <- i+1				// 2 opérations, au plus N fois	 
Retourner (i<=N)				// 1 opération
```

On a finalement une complexité qui se calcul : $1 + 3(N+1) + 2N + 1 = 5N+5$ donc on est dans une complexité de type $aN+b$  qui se traduit en $0(n)$.

On pourrait se demander si aujourd'hui, avec les processeurs toujours plus puissant et des RAMs toujours plus avancé technologiquement, il est vraiment utile de créer des algorithmes avec la meilleur complexité. Pour répondre à cette question, on va voir la différence de temps en fonction des algorithmes.

| Complexité                            | Nombre de données à traiter / 24h | Processeur $\times1000$ |
| ------------------------------------- | --------------------------------- | ----------------------- |
| **Linéaire** $aN+b$                   | 1 Million                         | $\times1000$            |
| **Polynomiale** ($k=4$) $a_k+...+a_0$ | 4000                              | $\times 2$              |
| **Exponentielle** $c \times a$        | 150                               | $+20$                   |
| **Factorielle** $c\times N!$          | 12                                | +2                      |

La complexité, quelque soit la rapidité du processeur, n'est pas à négliger. La complexité est un élément clef en informatique, les problèmes simples et difficiles sont au centre des interrogations aujourd'hui. Du simple algorithme pour créer des emplois du temps au repliement d'une protéine, la complexité algorithmique touche tous les domaines.
