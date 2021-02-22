# Mot, langage et automates

L'idée de ce cours est d'expliquer ce qu'est un modèle théorique d'une machine. En réalité, tous les ordinateur actuels sont des machines de Turing avec quelques expressions comme les ordinateurs Quantiques. Turing avait pour ambition de représenter des éléments de la vrai vie au format machine comme l'alphabet. On définira donc dans un premier temps les éléments qu'on utilisera par la suite.

## Alphabet et Mot

Un alphabet est un ensemble **fini** de symboles, appelés lettre ou caractères. Cet ensemble est généralement noté $\Sigma$. Un mot sur un alphabet $\Sigma$ est une concaténation **finie** de lettres de $\Sigma$.

### Exemple

Soit $\Sigma = \{ a,b,c \}$ un alphabet,

* $w_1 = abc$, est un mot de trois lettres. $w_2 = aabaa$, est un mot de cinq lettres, chaque lettre peut apparaître plusieurs fois.
* $w_1 = abc$ et $w_3 = acb$ sont deux mots différents, la concaténation n'est pas commutative.
* La concaténation est parfois notée : $w=a \cdot b \cdot b$
* $w_4 = c$ est un mot.

Attention, **a** représente à la fois la lettre **a** et le mot d'une seule lettre **a** qui est parfois notée **"a"**

## Concaténation


La concaténation peut être définie entre deux lettres, entre deux mots ou entre un mot et une lettre : 
Soient $\Sigma= {a,b,c}$ un alphabet, et $w_1 = abc$ et $w_2 = aabbaa$ deux mots sur l'alphabet $\Sigma$ alors, la **taille** et la **longueur** d'un mot *w* est le nombre de lettres qui le composent, ce nombre est noté |*w*|. De plus la notation $|w|_a$ est le nombre d’occurrences de la lettre **a** dans le mot **w**.

## Préfixe, suffixe, mot vide

Un mot $w_1$ est un **préfixe** d'un mot $w$ s'il existe un mot $w_2$ tel que $w=w_1 w_2$. Un préfixe correspond à un ensemble de lettres au début d'un mot.
Un mot $w_2$ est un **suffixe** d'un mot $w$ s'il existe un mot $w_1$ tel que $w=w_1 w_2$. Un suffixe correspond à un ensemble de lettres à la fin d'un mot.

Le caractère **$\epsilon$** est le caractère vide, il est tel que pour tout mot $w$, $w \epsilon = \epsilon w = w$. Attention, $\epsilon$ ne fait jamais partie de l'alphabet, $\epsilon$ représente le mot vide.
## Notations

Pour simplifier l'écriture, un mot composé de caractères identiques, $aaa$ peut être noté $a^3$. De même pour des sous mots, $w=aabbaaa = a^2 a^2 a^3$. On peut généraliser aux mots, si $w=abc$ alors $w^2=abcabc$, $w^1 = w$ et $w^0=\epsilon$.

## Langage

Un langage sur un alphabet $\Sigma$ est un ensemble **fini** ou **infini** de mots. 

### Exemple

Soit l'alphabet $\sigma = {a,b,c}$
* $L_0 = \{\emptyset \}$, ce langage ne contient aucun mot;
* $L_1 = \{ \epsilon \}$, ce langage contient un mot qui est le mot vide, dont $L_1 \neq L_0$;
* $L_2 = \{abc,bca,bbb \}$ ensemble fini;
* $L_3 = \{ a^n,\ n \>= 0 \}$, ensemble infini; (c'est à dire ${ \epsilon,a,aa,aaa,aaaa, ...}$)
* $L_4$ l'ensemble des mots qui contiennent un nombre pair de c.

Un langage peut-être défini en français, par une formule ou bien à l'aide d'un formalisme mathématique : expression régulière, grammaire, automate, ...

## Concaténation des langages
La concaténation de deux langages $L_1$ et $L_2$ est notée $L=L_1 L_2$ est définie par :
$$
w \in L \Longleftrightarrow \exists\ w_1 \in L_1, \exists \ w_2 \forall \ L_2 \ pour \ tout \ w=w_1w_2
$$

## Puissance d'un langage

La puissance d'un langage est définie par :
* $L^0 = \{ \epsilon \}$
* $L^n = LL^{n-1}$ pour $n>0$

Par induction, $L^1=L$

## Opération sur les langages

Les langages étant des ensembles, les opérations  ensemblistes (union, intersection, complémentaire) dont naturellement définies.

### Exemple

Soit l'alphabet $\Sigma = {a,b,c}$, $L_1$ l'ensemble des mots qui commencent par $a$ ou $b$ et $L_2$ l'ensemble des mots qui commencent par $b$ ou $c$.

* **Intersection** : $L_1\ \cap \ L_2$ est l'ensemble des mots qui commencent par *b*.
* **Union** : $L_1\ \cup \ L_2$ est l'ensemble de <u>tous</u> les mots sauf $\epsilon$ .
* **Complémentaire** :  $\overline{L_1}= \Sigma^* \backslash L_1$ est l'ensemble des mots qui commencent $c \ \cup \{\epsilon \}$

## Étoile de Kleene

L'étoile de Kleene d'un langage *L* noté *L* * est définie par $L^*= \bigcup^{+\infty}_{n=0}L^n$ .

### Exemple

Soit l'alphabet $\Sigma=\{a,b \}$

* $L= \{a\},\ L^*=\{ a^n, n \leq 0 \}$;

Un alphabet $\Sigma$ peut être vu comme un langage ne contenant que des mots d'une lettre et avec $\Sigma = \{a,b \}$: $\Sigma = \{\epsilon,a,b,aa,ab,ba,bb,... \}$, l'ensemble de tous les mots possible sur l'alphabet $\Sigma$.

## Langage rationnel
Un langage rationnel sur l'alphabet $\Sigma$ est défini par :
* $L = \{\emptyset \}$;
* $L = \{ \epsilon \} $ est rationnel;
* Pour tout $a \in \Sigma, L=\{a\}$ est rationnel;
* Si $L_1$ et $L_2$ sont rationnels alors $L_1L_2$ et $L_1 \cup \ L_2$ sont rationnels;
* Si $L$ est rationnel alors $L^*$ est rationnel. 

**Lemme**: Tout langage fini est rationnel.

***

## Différents types de problèmes

### Problème de calcul
* Multiplier deux nombres;
* Factoriser deux nombres.

### Problème d'optimisation
* Calculer le plus court chemin d'ici à là;
* Découper des pièces dans un morceau de tissu pour minimiser les chutes;
* Affecter les personnels navigant

### Problèmes de décision (oui/non)
* Ce graphes est-il planaire ?
* Ce nombre est-il premier ?
* Cette machine de Turing s'arrête-t-elle toujours ?
* Ce mot appartient-il à ce langage ?

**Tous les problèmes peuvent se ramener à des problèmes de décision ou au moins à une suite de problème de décision.**

### Question fondamentale 

#### Soit $L$ un langage et $w$ un mot, est-ce que $w \in L$ ?

La question peut paraître simple, à tel point qu'on pourrait se demander s'il est possible de construire une machine universelle qui répond à la question fondamentale pour tout langage et tout mot ? Malheureusement **non**, il n'existe pas de *machine universelle*. L'idée est donc de classer les langages et les machines permettant de répondre à la question fondamentale.

***

## Première machine : Automate fini

Un **automate <u>fini</u>** $\mathcal A$ est un quintuplet (défini par 5 éléments) $\mathcal A = (\Sigma, \ Q, \ q_0, \ F,\ T)$ , avec : 

* $\Sigma$ un alphabet <u>fini</u>;
* $Q$ un ensemble <u>fini</u> d'états;
* $q_0 \in Q$ l'état initial;
* $F \subseteq Q$ l'ensemble des états finaux ;
* $T \subseteq Q \times \Sigma \times Q$ l'ensemble des transitions.

### Exemple

* $\Sigma = \{a,b\}$ ,
* $Q=\{q_0,q_1,q_2,q_3\}$ ,
* $F={q_2,q_3}$ ,
* $T = \{(q_0,a,q_0),(q_0,a,q_1),(q_0,b,q_2),(q_1,b,q_1),(q_1,b,q_2),(q_1,a,q_3),(q_1,b,q_3),(q_2,a,q_3),(q_3,b,q_2) \}$ .

![Screenshot_20210214_024342](Screenshot_20210214_024342.png)

### Reconnaissance d'un mot

Un automate fini $\mathcal A =(\Sigma, Q, q_0, F, T)$ **reconnaît** le mot $w=a_1a_2..a_k$, s'<u>il existe</u> une séquence d'états. $q_0^{(w)},q_1^{(w)},...,q_k^{(w)}$ telle que :

* $q_0^{(w)} = q_0$
* $\forall i \in 0...k -1, (q_i^{(w)},a_{i+1},q_{i+1}^{(w)}) \in T$ ;
* $q_k^{(w)} \in F$

![Screenshot_20210214_024510](Screenshot_20210214_024510.png)

* *aaaab* reconnu avec la séquence d'états $q_à,q_1,q_1,q_1,q_1,q_2$ .
* *aba* non reconnu, pas de transition pour la deuxième *a*.
* *aa* non reconnu, fin dans un état non final.

### Reconnaissance d'un langage

Un **langage reconnaissable** par un automate fini $\mathcal A$ est noté $L(\mathcal A)$ et est défini par:
$$
w \in L(\mathcal A) \Longleftrightarrow w\ est\ reconnu\ par\ \mathcal A
$$