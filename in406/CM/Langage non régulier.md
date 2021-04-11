# Langage non régulier

## Langage non reconnaissable par un automate fini

> **Théorème **:
> Soit $L=\{a^nb^n,\leq n \}$, il n'éxiste pas d'automate fini reconnaissant exactement $L$.

> **Preuve** : 
> Par l'absurde : Supposons qu'un automate sans $\epsilon$-transition $\mathcal  A$ reconnaisse exactement $L$. Soit $N$ nombre d'états de cet automte et considérons le mot $w=a^Nb^N$, le mot qu'on considère est plus grand que $N$, $|w|>N$ .
> Soient $q_0^{(w)},q_1^{(w)},...,q^{(w)}_{2 \times N}\ (q_0^{(w)}=q_0$ et $ q_{2\times N}^{(w)} \in F)$ la suite des états utiliés lors de la reconnaissance de $w$. $w$ étant
>
>
> La reconnaissance de $w$ peut être factorisée en trois morceaux :
>
> * De l'état initial $q_0^{(w)}$ jusqu-au premier passage par l'état $q$, ce qui reconnait un mot $w_1$.
> * Du premier passage par $q$ jusqu'au deuxième passage par $q$, ce qui reconnait un mot $w_2$.
> * Du deuxième passage par $q$ jusqu'à l'état final $q_{2 \times N}^{(w)}$, ce qui reconnait un mot $w_3$.
>
> Donc $w=w_1w_2w_3$ avec $0<|w_2| \leq N$. Le mot $w'=w_1w_2w_2w_3$ **est également reconnu par le langage** puisque pour on commence par $q$ et on termine par $q$. Ce cycle emprunté autant de fois que l'on veut.
>
> * $w_1 :q_0$ au premier passage en $q$
> * $w_2$ : Premier pasage en $q$ au deuxième passage en $q$
> * $w_3$ : Deuxième passage en $q$ à l'état final.
>
> Si un automate reconnaît un mot plus grand que sa taille, il reconnaît une infinité de mot.

