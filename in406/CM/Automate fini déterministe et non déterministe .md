# Automate fini non-déterministe et déterministe

Soit l'automate qui reconnaît les mots se terminant par *ab* sur l'alphabet $\Sigma = \{a,b,c \}$

La reconnaissance du mot *acab* peut se fait avec la séquence d'états : $q_0,q_0,q_0,q_1,q_2$. On peut aussi prendre la séquence $q_0,q_0,q_0,q_0,q_0$ qui ne termine pas dans état final. Cet automate est **non déterministe** : pour le couple ($q_0,a$) il existe deux transitions différents : $(q_0,a,q_0)$ et $(q_0,a,q_1)$. Ce choix permet de dire que cette automate est no- déterministe.

Pour un automate $\mathcal A = (\Sigma, Q, q_0, F,T)$, pour tout état $q$ et toute lettre $a$, on définit l'**ensemble des successeurs** de  (*q,a*) par :
$$
S(q,a) = \{q' \in Q,(q,a,q') \in T \}
$$
 Dans l'exemple précédent, on a :

| $S(q_0,a) = \{q_0,q_1 \}$ | $S(q_1,a) = \emptyset$     | $S(q_2,a)=\emptyset$       |
| ------------------------- | -------------------------- | -------------------------- |
| $S(q_0,b) = \{q_0\}$      | $S(q_1,b) = \{q_2\}$       | $S(q_2,b) = \{\emptyset\}$ |
| $S(q_0,c) = \{q_0\}$      | $S(q_1,b) = \{\emptyset\}$ | $S(q_2,c) = \{\emptyset\}$ |

## Définitions

Soit un automate finit $\mathcal A =(\Sigma,Q,q_0,F,T)$,

* si $\exists q \in Q, \exist a \in \Sigma, |S(q,a)| >1 \implies \mathcal A$ est **non-déterministe**; 
* si $\exists q \in Q, \exist a \in \Sigma, |S(q,a)| \leq 1 \implies \mathcal A$ est **déterministe**;

* si $\exists q \in Q, \exist a \in \Sigma, |S(q,a)| = 1 \implies \mathcal A$ est **déterministe complet**;

On note **AFN** un **A**utomate **F**ini **Non**-déterministe et **AFD** un **A**utomate **F**ini **D**éterministe.

Une **$\epsilon$-transition** dans un automate désigne le caractère vide et est une transition ($q, \epsilon , q'$). Un **$\epsilon$-chemin** de $q$ à $q'$ existe s'il existe une suite d'$\epsilon$-transition permettant d'aller de $q$ à $q'$.

Pour tout ensemble $E$, l'ensemble des parties (sous-ensembles) de $E$ est noté : $2^E$. Par exemple, si $E=\{x,y,z\}$ alors, 
$$
2^E=\{\emptyset, \{x\}, \{y\}, \{z\}, \{x, y\}, \{x, z\}, \{y, z\}, \{x, y, z\}\}
$$

## Théorèmes

* Pour tout $\mathcal A_1$ AFN avec ε-transition, il existe $\mathcal A_2$ AFN sans $\epsilon$-transition, tel que $L(\mathcal A_1) = L(\mathcal A_1)$.

* Pour tout $\mathcal A_2$ AFN sans ε-transitions , il existe $\mathcal A_3$ AFD , tel que $L(\mathcal A_3) = L(\mathcal A_2)$.

* Pour tout $\mathcal A_3$ AFD , il existe A4 AFD complet , tel que $L(\mathcal A_4) = L(\mathcal A_3)$.

* Pour tout $\mathcal A_4$ AFD , il existe $\mathcal A_5$ AFD minimal complet , tel que $L(\mathcal A_5) = L(\mathcal A_4)$

## Détermination d'automate

Soit $\mathcal A = (\Sigma,Q,q_0,F,T)$ un AFN et soit $\mathcal A = (\Sigma',Q',q_0',F',T')$ un automate fini défini par :

* $\Sigma' = \Sigma$
* $Q' = 2^Q$ (Cahque élément de $Q'$ est un sous-ensembles de $Q$);
* $q_0'= {q_0}$;
* $\forall q' \in Q'$, si $\exist q \in q'$ tel que $q \in F$, alors $q' \in F'$;
* $T'=\{(q_0, a, \cup_{q\in q'}n q' \in Q',a \in \Sigma'$

Alors $\mathcal A'$ est déterministe et $L(\mathcal A')=L(\mathcal A)$.

## Automate fini déterministe complet

Un automate déterministe complet désigne un automate qui aura le choix à chaque états entre toute les lettres du langages. 

### Théorème

Soit $\mathcal A = (\Epsilon, Q, q_0, F, T)$ un AFG et soit $\mathcal A' = \mathcal A = (\Epsilon, Q, q_0, F, T)$ un automate fini défini par :

* $\Sigma' = \Sigma$
* $Q' = Q \cup \{$Poubelle$\}$;
* $q_0'= q_0$;
* $F'=F$;
* $T'= T\cup \{(q,a,$Poubelle$)$ pour $(q,a)$ tel que $|S(q,a)|=0\} \cup_{A\in \Sigma} \{($Poubelle$,a,$Poubelle$) \}$. 

Alors $\mathcal A'$ est déterministe et complet et $L(\mathcal A') = L(\mathcal A)$

## Déterministe vs Non-déterministe

### AFN

Les caractéristiques du **non-déterminisme** sont : 

* Facilité de construction de l’automate ; 
* Nombre d’états généralement polynomial dans la taille du problème ;
* Reconnaissance d’un mot moins aisée, il faut potentiellement essayer tous les chemins possibles. Peut néanmoins se faire en temps polynomial ;
* Certificat polynomial : si on donne la séquence des états qui reconnaît un mot, la vérification est rapide.

### AFD

Les caractéristiques du déterminisme sont : 

* Construction de l’automate difficile ;
* Nombre d’états peut être exponentiel dans la taille du problème ; 
* Reconnaissance d’un mot polynomiale ; 
* Certificat de reconnaissance et de non reconnaissance d’un mot polynomial ; 
* Automate minimum canonique.