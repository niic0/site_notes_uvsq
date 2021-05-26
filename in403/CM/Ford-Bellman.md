# Algorithme de Ford-Bellman

La méthode est assez proche dans sa forme générale de celle de Dijkstra. Mais la valeur d d’un sommet déjà traité pouvant être améliorée, il est nécessaire de revenir sur le traitement de ce sommet avec sa nouvelle valeur. Un sommet peut donc être traité plusieurs fois. Par ailleurs, on ne traite pas forcément le sommet ayant la valeur la plus petite (donc pas de recherche du sommet avec la plus petite valeur de $d$) mais un sommet quelconque dans la liste des sommets à traiter. Cet algorithme est notamment utilisé pour traiter des graphes avec des arcs à poids négatif.

### Algorithme

> Initialisations :
>
> * $d_s = 0; pere_s = Nil$;
> * $\forall i \neq s, d_i = \infty; pere_i=Nill$
> * $L=\{s\}$;
>
> Boucle principale : Tant que $L != \emptyset$ faire
>
> * Choisir $t\in L$
> * $L=L-\{t\}$
> * $\forall k \in T^+_t$ faire
>   * Si $(d_k> d_t+w(t, k))$ alors $d_k=d_t+w(t, k); pere_k=t;L=L∪{k};$

### Exemple

On part du sommet $s_1$ puis on additionne le poids du nœuds avec ses successeurs. On créer ensuite un tableau pour chaque itération.

<iframe frameborder="0" style="width:100%;height:325px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Vttl6I2FP41ftRDEt78ODqzfZuebjvntLv9FiUqXTQW4qr99U0gEULQYkVwdWbOGeEGQszz3Pvc3DA9NF7uvovxevEzDUjUg1aw66HnHoQ%2BBPyvMOwzg42GmWEeh0FmArnhLfyHSKMlrZswIIl2IaM0YuFaN07pakWmTLPhOKZb%2FbIZjfSnrvFcPtHKDW9THBHjsj%2FCgC3k13IKV39PwvlCPRlYsmWCp1%2FmMd2s5PN6EMGh%2BM2al1j1Ja9PFjig24IJvfTQOKaUZUfL3ZhEYmrVtGX3fTjSehh3TFaszg1j54dffv%2F1T%2FCT9%2BPotyENX57Jax%2FKsbG9mo%2F0GxFxj9VDIxqzBZ3TFY5eKV1zI%2BDGvwhje4kk3jDKTQu2jGQr2YXsU%2BH4s%2BxKHD%2Fviid7eTILo2hMIxqnI0ABJv5syu0Ji%2BkXUmhxpz6ZzA4tCi8kOlyxeP9J9S5OPqsxiJP8wemZenL27UkwL5Mhn1RpSugmnpITM6m4i%2BM5YSeuQwfouUcRuiR8PPy%2BmESYhV%2F1cWDJ7fnhusOtH2nIRwgt6YZQsVJ6IUKW3kU2LnlXzhJ%2BUBhGbkq5cwaPXINHYlLf5OmKrvjH6CrUAiepZRLlfLJ1QBLnQpJo8J6Lpez3K442RIU2N2Ji7mjKuRxl9%2B8NVQ39JIXtiV%2FAJ2eXN%2FKjufhMVDfJZqJsQNn4SAvmgjV7pjKXSRZFXCcEt7aLkJG3NU6nf8uVSmcOTtaZeMzCnWBgIzFHzhOJGdmdpoYJpZLPktu68nxbkCJpWhRUyLeuhP2wAvsWHPvG3BTVdFO%2FUzf1bjTmVktxLr7VUvyNUgBYXXIAtRiq4YOH6nKKBe2OY7V9MfhgqIPPF1lqMnMj%2BpD%2BmCSx60LP55xVxXsFnQxVRZylCUfhfMVPpxwjwu0jgWDIF29PsmEZBkF0jFR67NNJAZshBbBLAg5NUtgVpIDXIkW7omANnNqrvFwWspvqrtFuTBicmsJw6TrvstwAvudxZ2DVrYgDZGDToIN6sOihAwv5db3U8mwtgRt4LmrBV8VwPpI45JMrQn7%2BlLKxA6JcmvCntz7FMd4XLliLokxi0KiBqozznh52lh7afsfpIaiq4zyeBvhtacB%2F%2BHZ13db2SqyxrBLwWY%2BNhgVFhAIzquu3r3hCopL71c7IY8LDCJ6k%2FQkqyangnTujnvPMLZHofnTYRikvB3i4KHBDrkIyuyQfcE%2F5rtwxkkPoFTaAchad8Jyjnt7n0uj7cg4vrNsDMPBsjQHuYIj0XuhslpCrVO2B3fJqATraemEwBLWzkSH09GwEooPhSDZSmTVUbB1VJBzfRMi6dJfgf0UsVC5Ze21ELOtdy87RsmGX6xloFqbMFU4L8lIWimOCclqGmpcXeCTTyOUF%2BLavO1kjYoMGnqN124cDq9TL9cTGr3Dhay1G0IMvRuxbq1UDv%2BVM4%2BHqkup9qtvetITmjlXFO0gPLA7gCDyye64NNvQ03waNaIPa%2BVedAlE4bEkZDhxvfye7bmh4hMDQbdYIqlL8a%2BUH7nt%2BoLl798XKqheProW%2B%2FeDoO7C0hO%2F6rTNVfiygbyYF5lsETeYDQi4SmQ%2BckR40gUbZFyvQgBVoXO0VApVfFNBwHgYNBEq%2B4XSNhhkZ%2B2a%2BdLdwuHrFAlUIFWoTDmSmKY8TqlD5baeKskKrzoHMPU6z1Hi3aJRkHHYtHAiaocrcYbpXOCDQQ9Uhx%2B4sVJm1FvPtwHtFAzg3llWhOrsi94pGOVQ5Fb7REBr8NP%2BfyqxClf%2FfKnr5Fw%3D%3D"></iframe>

| Sommet | $s_1$ | $s_2$     | $s_3$     | $s_4$     | $s_5$     | $s_6$     | $L$               |
| ------ | ----- | --------- | --------- | --------- | --------- | --------- | ----------------- |
| Init   | 0     | $\infty$  | $\infty$  | $\infty$  | $\infty$  | $\infty$  | $\{s_1\}$         |
| $s_1$  | 0     | 4 ($s_1$) | $\infty$  | $\infty$  | 7 ($s_1$) | $\infty$  | $\{s_2,s_5\}$     |
| $s_2$  | 0     | 4 ($s_1$) | 7 ($s_2$) | $\infty$  | 7 ($s_1$) | 9 ($s_2$) | $\{s_5,s_3,s_6\}$ |
| $s_5$  | 0     | 3 ($s_5$) | 6 ($s_5$) | $\infty$  | 7 ($s_1$) | 9 ($s_2$) | $\{s_3,s_6,s_2\}$ |
| $s_3$  | 0     | 3 ($s_5$) | 6 ($s_5$) | 9 ($s_3$) | 7 ($s_1$) | 9 ($s_2$) | $\{s_6,s_2,s_4\}$ |
| $s_6$  | 0     | 3 ($s_5$) | 6 ($s_5$) | 9 ($s_3$) | 7 ($s_1$) | 9 ($s_2$) | $\{s_2,s_4\}$     |
| $s_2$  | 0     | 3 ($s_5$) | 6 ($s_5$) | 9 ($s_3$) | 7 ($s_1$) | 8 ($s_2$) | $\{s_4,s_6\}$     |
| $s_4$  | 0     | 3 ($s_5$) | 6 ($s_5$) | 9 ($s_3$) | 7 ($s_1$) | 8 ($s_2$) | $\{s_6\}$         |
| $s_6$  | 0     | 3 ($s_5$) | 6 ($s_5$) | 9 ($s_3$) | 7 ($s_1$) | 8 ($s_2$) | $\empty$          |

### Preuve de l'algorithme

Si le plus court chemin élémentaire de $s$ à un sommet $v$ comporte $k$ arcs, alors après avoir traité au plus $k$ fois ce sommet, on a $d_v$ à sa juste valeur : $d_v=d(s, v)$.
Preuve par récurrence (assez évidente) :

* C’est vrai pour $k= 1$: les sommets reliés directement à $s$ dans l’arborescence des + courts chemins sont directement à leur bonne valeur dès le traitement initial de $s$ . Ils ne sont traités qu’une fois.
* A $k−1$, la propriété est vraie pour le prédécesseur $p$ de $v$ sur le plus court chemin de $s$ à $v$ (le plus court chemin de $s$ à $p$ comportant $k−1$ arcs)

### Circuit absorbant

Du fait de la propriété précédente, l’algorithme nécessite dans le pire des cas : $1 + 1 + 2 +...+n−1  = \frac{n(n−1)}2+ 1$ itérations pour converger(en tout cas $O(n2))$. 
Définition : Un circuit absorbant est un circuit dont la somme des poid $s$ est négative. En cas de circuit absorbant, il n’y a pas de solution au plus court chemin pour les sommets concernés : on a intérêt à parcourir indéfiniment le circuit absorbant. Détection de l’existence d’un circuit absorbant par l’algorithme de BF : si le nombre d’itérations dépasse le nombre maximum possible indiqué ci-dessus, c’est qu’il y a un circuit absorbant : stop.

Complexité

Une autre version de l’algo, basée sur les propriétés précédentes consiste à répéter $n−1$ fois le parcours de chaque arc pour voir s’il améliore le $d$ du sommet final de l’arc :

* Boucle principale : Pour i allant de $1$ à $n-1$ faire
  * Pour chaque arc$(u, v)$ faire
    * Si $(d_v > du+w(u, v))$ alors $d_v=d_u+w(u, v); pere_v=u$

