# Expression régulière

Une **expression régulière** est une chaîne de caractère qui définit un langage. Dans une expression arithmétique on a $(2+3) -4$ par exemple, et dans une expression régulière, on a $(a+b)-c$. Pour tout alphabet $\Sigma$, $\mathcal L(e)$ est le langage défini par l'**expression régulière (e.r) <u>$e$</u>** :

*  $e = \emptyset$ est une **e.r** et $\mathcal L(e) = \empty$ ;
* $e = \epsilon$ est une **e.r** et $\mathcal L(e) = \{\epsilon\}$ ;
* $e = a$ pour tout $a\in \Sigma$ est une **e.r.** et $\mathcal L(e) = \{a\}$ ;

Soit $x$ et $y$ deux **e.r** :

* $e=(x)$ est une **e.r** et $\mathcal L(e) = \mathcal L(x)$ ;
* $e=x^*$ est une **e.r** et $\mathcal L(e) = \mathcal L(x)^*$ ;
* $e=x+y$ est une **e.r** et $\mathcal L(e) = L(x) \cup \mathcal(y)$ (commutatif) ;
* $e=xy = x \cdot y$ est une **e.r** et $\mathcal L(e)=\mathcal L(x) \cdot \mathcal L(y)$ (non comutatig) ;

Comme dans les expressions arithmétique, on a des opération d'opérateur. $() > * > \cdot>+$ . On aura par exemple : Soit un $\Sigma = \{a,b,c\}$ un alphabet et les e.r suivantes :

* $e_1 = (b+ab^*aa)^*ab^* = ((b+((a\cdot(b^*))\cdot a \cdot a))^*)\cdot a\cdot a(b^*)$
* $e_2 = (a+b+c)^*$ : tous les mots sur $\Sigma, $ $\mathcal L(e_2) = \Sigma^*$ ,  ($+$ est en effet à comprendre comme un <u>ou</u>) ;
* $e_3 = ab(a+b+c)^*$ : tous les mots qui commencent par $ab$ ;
* $e_4 = (a+b+c)^*ac$ : tous les mots qui se terminent par $ac$ ;
* $e_5 = ((a+b+c)(a+b+c))^*$ : tous les mots avec un nombre pair de lettres.

## Équivalence des représentations

**Définition** : $L$ est un **langage régulier** s'il existe une expression régulière $e$ telle que $\mathcal L(e) = L$ . De plus, pour tout alphabet $\Sigma$, on note :

* $Rat(\Sigma^*)$ : l'ensemble des langages **rat**ionnels ;
* $Rec(\Sigma^*)$ : l'ensemble des langages
* $Reg(\Sigma^*)$ : l'ensemble des 

### Preuves

* Preuve de $Rat(\Sigma^*) = Reg(\Sigma^*)$ : Par définition des expressions régulières.
* Preuve de $Rat(\Sigma^*) \subseteq Rec(\Sigma^*)$ : Par construction d'automates, preuve en TD ;
* Preuve de $Rec(\Sigma^*) \subseteq Reg(\Sigma^*)$ : A partir d'un automate $\mathcal A = (\Sigma, Q, q_0,F,T)$, on va construire une expression régulière $e$, telle que $L(\mathcal A) = \mathcal L(e)$

> **Algorithmes** pour la preuve de $Rec(\Epsilon^*) \subseteq Reg(\Sigma^*)$
>
> <u>Initialisation</u> :
>
> * Modifier la syntaxe de l'automate en transformant chaque caractère sur les transition en e.r. ;
> * Ajouter un état initial $\alpha$ et une transition $(\alpha , \epsilon, q_0)$ ;
> * Ajouter un état final $\omega$ et une transition $(q, \epsilon, \omega)$ pour tout état final $q\in F$ ;
> * $F = \{\omega \}$
>
> **Algorithme de <u>Fusion</u>** : Algo de suppression d'une transition.
> Soient $x$ et $x$ des **e.r**,
>
> img automates
>
> Cet algo supprime une transition de l'automate. S'il y a plusieurs transitions entre les états $p$ et $q$, on peut, bien sûr, les fusionner en une seule étape.
>
> **Algorithme de <u>Contraction</u>** : Algo de suppression d'état.
> Soient $x,\ y$ et $z$ des **e.r**,
>
> ims des automates
>
> Cet algo **supprime** un état mais peut rajouter des transitions. Si $q$ n'a pas de boucle et a $n$ prédécesseurs et $m$ successeurs, l'algo supprime $n+m$ transitions et ajoute $n \times m$ .
>
> img des automates

**nb : La seule façon de décider si deux langages sont égaux est de construire les automates déterministes minimaux et les comparer.**