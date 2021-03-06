# TD 2 Manipulation d'automate

## Exercice 16

1. On parle d'un automate infini quand un circuit est une suite de transition qui part d'un état et revient à cet état. Un automate (AFD minimal) sans circuit reconnaît un langage finie. Un automate (AFD minimum) avec circuit reconnaît un langage infini. Cet automate est donc fini car il ne forme pas de circuit.
2. Les $\epsilon$ chemins correspond aux chemins qui contiennent un $\epsilon$. On a donc :
   * $q_0 \rightarrow q_2$ 
   * $q_1 \rightarrow q_3$
   * $q_2 \rightarrow q_3 \rightarrow q_4$
   * $q_1 \rightarrow q_2 \rightarrow q_3$
3. Détermination de l'automate. Q a $2^5$ sous ensembles. On va construire un automate avec $2^5=32$ états. Chaque état sera un sous ensemble de Q. On obtient bien un automate déterministe. On va maintenant le rendre complet en ajoutant un état poubelle.

## Exercice 17

1. C'est un automate fini (pour les raisons évoquées plus haut).
2. $\epsilon$ chemin : 
3. L'automate crée est déjà déterministe. On le rend complet en mettant un état poubelle.

## Exercice 18

1. $\mathcal A = (\Sigma,Q,q_0,F,T)$ avec
   * $\Sigma = \{a,b,c\}$
   * $Q = \{q_0,q_1,q_2\}
   * $q_0 = q_0$
   * $F=\{q_1,q_2\}$
   * $T=\{q_0,a,q_2),(q_0,b,q_1), (q_0,c,q_0), (q_2,a,q_2), (q_2,b,q_1)\}$
2. $aaab$  est reconnu ; le mot $cac$ n'est pas reconnu (manque un $c$ pour $q_2$) ; le mot $cc$ n'est pas reconnu mais ne finit pas dans un état final.
3. Il est déterminisme
4. $\mathcal A = (\Sigma,Q,q_0,F,T)$ avec
   * $\Sigma = \{a,b,c\}$
   * $Q = \{q_0,q_1,q_2\}$
   * $q_0 = q_0$
   * $F=\{q_1,q_2\}$
   * $T=\{q_0,a,q_2),(q_2,c,poub), (poub,a,poub), (q_0,b,q_1), (q_0,c,q_0), (q_2,a,q_2), (q_2,b,q_1)\}$

## Exercice 19

1.  $\mathcal A = (\Sigma,Q,q_0,F,T)$ avec : 
   * $\Sigma = \{a,b,c\}$
   * $Q = \{q_0,q_1,q_2\}$
   * $q_0 = q_0$
   * $F=\{q_1,q_2\}$
   * $T=\{(q_0,c,q_0), (q_0,a,q_1),  (q_1,b,q_2), (q_2,b,q_1), (q_1,b,q_0)\}$
2. le mot $abbb$ est reconnu avec la transition $q_0 \rightarrow q_1 \rightarrow q_2 \rightarrow q_1 \rightarrow q_2$ ; le mot $cabb$ n'est pas reconnu car il finit dans un état non final.
3. L'automate est non déterministe car à l'état $q_1$, on a le choix entre 2 transition avec $b$.

## Exercice 20

1. Les transition diffèrent selon les automates. la transition $(q_0,a,q_0)$ et $(q_0,b,q_0)$ existe pour $\mathcal A_1$ et $\mathcal A_2$ mais pas pour $\mathcal A_3$. Pareil pour la transition $q_1$ de $\mathcal A_2$ et $\mathcal A_3$ qui est identique mais différent de la transition $q_1$ de $\mathcal A_1$.

2. $\mathcal A_3$ est déterministe mais pas $\mathcal A_2$ ni $\mathcal A_1$.

3. On déterminise $\mathcal A_1$ :

   On déterminise $\mathcal A_2$ :

   Les Deux automates sont déjà minimisés, on remarque que $\mathcal A_1$ et $\mathcal A_2$ sont en réalité $\mathcal A_3$.

4. Les mots qui ont au moins un a.



