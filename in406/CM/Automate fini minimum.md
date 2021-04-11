# Automate fini minimum

Un automate est minimal en nombre d'états : 

* Nombre minimum d'états donc stockage minimal.
* L'unicité de l'automate minimal permet de tester l'égalité de langages.

Pour créer un automate fini minimum, on a besoin de 2 nouvelles notions, l'**accessibilité** et la **séparabilité**.

## Accessibilité

Sur l'AFD complet suivant, on voit que $q_5$ n'est pas accessible depuis $q_0$. L'accessibilité d'un état désigne son accessibilité depuis son état initiale $q_0$.

![Screenshot_20210218_102840](../../../site/in406/Screenshot_20210218_102840.png)

Algorithmiquement, l'idée est de chercher une _transition_ $(q,a,q')$ avec $q\in A$, $a\in \Sigma$, et $q' \notin A$. Avec $\mathcal A = (\Sigma,Q,q_0,F,T)$, l'ensemble des états accessibles depuis $q_0$, noté  **A**. Si on trouve, on ajoute  $q'$ à **A**.

>  ### Définition
>
> Soit $\mathcal A = (\Sigma,Q,q_0,F,T)$ un AFD, pour tout $q$, $q'$ éléments de $Q$ et pour tout mot $w$ sur l'alphabet $\Sigma$ si :
>
> * $w=a_1a_2...a_k$ avec $\forall i \in 1..k,a_i \in \Sigma$;
> * $\exists \ q_1,q_2,...q_k,q_{k+1} \in Q$ tels que :
>   * $q=q_1$
>   * $\forall i \in 1...k, \ (q_i,a_i,q_{i+1}) \in T$;
>   * $q' = q_{k+1}$;
>
> On dit que $q'$ est **accessible** depuis $q$ avec $w$ et on note $q \cdot w = q'$.
>
> ### Algorithme
>
> Soit $\mathcal A = (\Sigma,Q,q_0,F,T)$, l'ensemble des états accessibles depuis $q_0$, noté **A** se calule par : 
>
> **DÉBUT**
> 	**A** $\leftarrow \{q_0\}$
> 	**Tant que** il existe $q \in$ **A**, $q' \notin$ **A**, $a \in \Sigma$ tel que $(q,a,q') \in T$ **Faire**
> 		**A** $\leftarrow$ **A** $\cup\ \{q'\}$
> 	**Fin Tant que**
> 	Renvoyer **A**
> **Fin**
>
> C'est simplement un parcours de graphe à partir du sommet $q_0$

## Séparabilité

On reprend l'exemple précédent en supprimant l'état non accessible. L'idée c'est de faire un peu comme dans un *qui est-ce ?*, on va séparer les états finaux des autres états. On a donc deux catégories : $\{q_0,q_1,q_4\} \notin F$ et $\{q_2,q_3\} \in F$ ($F$ étant l'état final). On obtient donc l'automate suivant avec son tableau associé.

<img src="../../../site/in406/Screenshot_20210218_104613.png" alt="Screenshot_20210218_104613" style="zoom:80%;" />

Le tableau à droite représente les états inséparable. Par exemple, $q_0$ et $q_2$ sont des états qui ne sont pas dans la même catégorie, car $q_0 \notin F$ et $q_2 \in F$. L'idée est vraiment de dissocier les états finaux et les états non finaux. 

Ensuite on va créer une autre catégorie qui est l'état initiale. On aura donc 3 catégories : $q_0$ , $\{q_1,q_4\}$ , $\{q_2,q_3\}$. À partir de là on peut créer un autre tableau avec son graphe associé.

<img src="../../../site/in406/Screenshot_20210218_105844.png" alt="Screenshot_20210218_105844" style="zoom:80%;" />

Les croix rouge nouvellement ajoutées représente, comme les croix noir, les états inséparables. Les espaces blancs dans le tableau sont donc les états qui sont séparables. 

> ### Définition
>
> Soit $(\mathcal A = \Sigma,Q,q_0,F,T)$ un AFD deux états **q** et **q'** sont **séparables** ou **distinguables**, si :
> $$
> \exist w \in \Sigma^*, q w \in F \implies q' \cdot w \notin F
> \\ Ou \\
> \exist w \in, qw \notin F \implies q'\cdot w \in F
> $$
> Soit $\mathcal A = ( \Sigma, Q, q_0, F, T)$ un AFD deux état $q$ et $q'$ sont **inséparables** ou **indistinguables**, si : 
> $$
> \forall w \in \Sigma^*, q \cdot w \in F \iff q' \cdot w \in F
> $$
>
> ### Algorithme
>
> Soit un AFD $(\mathcal A = \Sigma,Q,q_0,F,T)$. L'algorithme marque les couples d'états séparables :
>
> **DÉBUT**
> 	$\forall F, \forall q \notin F$ **marquer** $(q,q')$
> 	**Tant que** $\exist (q_1,q_2)$ **non marqué**, $\exist a \in \Sigma, \ \exist (q_1',q_2')$ **marqué** tels que $q_1,a,q_1') \in T$ et $(q_2,a,q_2') \in T$ **Faire**
> 		**marquer** $(q_1,q_2)$
> 	**Fin Tant que**
> **FIN**
>
> À la fin si un couple d'états est **marqué** des deux états sont **séparables** et si un couple d'état est **non marqué** les deux états sont **inséparables**.

## Qu'est ce qu'un automate fini minimum

Maintenant qu'on a tous les outils en poche, la séparabilité et l'accessibilité, il n'y a plus qu'à créer notre automate fini minimuim.

> ### Définition
>
> Un AFD $\mathcal A = (\Sigma,Q,q_0,F,T)$ est **minimum** si pour tout AFD $\mathcal A = \Sigma',Q',q_0',F',T'$, tel que $L(\mathcal A') = L(\mathcal A)$ alors :
> $$
> |Q| \leq |Q'|
> $$
>
> ### Théorème
>
> Un AFD $\mathcal A = \mathcal A = (\Sigma,Q,q_0,F,T)$ est **minimum** si et seulement si :
>
> * Tous les états de Q sont **accessibles** depuis $q_0$ ; 
>
>   **ET**
>
> * Tous les états de Q sont deux à deux **séparables**.

Reprenons l'exemple vu plus haut.

<img src="../../../site/in406/Screenshot_20210218_111834.png" alt="Screenshot_20210218_111834" style="zoom:80%;" />

On a vu que $q_5$ était inaccessible, on va donc le supprimer. On regarde ensuite la séparabilité de l'automate puis on créer notre tableau pour voir quelle états sont inséparables.

<img src="../../../site/in406/Screenshot_20210218_112125.png" alt="Screenshot_20210218_112125" style="zoom:80%;" />

L'idée est maintenant de fusionner les états qui sont marqué par un point rouge dans le tableau. On fusionne donc $q_2$ et $q_3$ ainsi que $q_1$ et $q_4$. Finalement on obtient l'automate fini déterministe minimal complet suivant :

![Screenshot_20210218_112550](../../../site/in406/Screenshot_20210218_112550.png)
