# TD 1

### Exercice 1

On considère ici $\Sigma$ comme un langage. Il contient deux mots, a et b (car une lettre peut être un mot). 

On a $\Sigma = \Sigma^1 {a,b}$

$\Sigma^1$, $\Sigma^2$ et $\Sigma^3$ sont obtenu en concaténant les mots.

$\Sigma^2 = \Sigma \Sigma = {aa,ab,ba,bb}$

$\Sigma^3 = \Sigma \Sigma \Sigma = {aaa,aab, aba, abb, baa,bab,bba,bbb}$

$\Sigma^n$ correspond à tous les mots de n lettres.

$\Sigma^0$ na vaut rien, il vaut donc le mot vide $\epsilon$. $\Sigma^0 = { \epsilon }$

$\Sigma^*$ correspond à l'ensemble de tous les mots.

$\Sigma^* = \Sigma^0 \cup \Sigma^1 \Sigma^2 \cup \:...$

### Exercice 3

1. La concaténation du mot $w_1$ et $w_2$ vaut $abccba$
2. L'associativité, c'est par exemple l'addition où $3+(4+2) = (3+4)+2$. On a donc $(w1 w_2)w_3 = w_1(w_2 w_3)$. La concaténation est donc associative.
3. $w_1 w_2=abccba$ et $w_2 w_1 = cbaabc$ la concaténation n'est donc pas commutative car $w_1 w_2 != w_2 w_1$ 
4. Avec $w_1=a, w_2=aa$

## Exercice 7

Un Alphabet est composé d'un état de départ, d'un état final, de lettres et de transitions. $A_1 = (\Sigma,Q,q_0,F,T)$

* $L_1 = \{a,aa, ab, ac, aaa, aab, aac, aba, abb, abc, aca, ...\}$

  $\Sigma = {a,b,c} q_0 = 1$

* $L_3$ Ici on cherche à avoir au moins un a. la première idée qu'on puisse avoir est la suivante : C'est un automate non déterministe car il peut très bien finir dans un état non final

* $L_4$ L'idée est de faire autant de faire b et c qu'il y a, s'il y a un a on passe dans l'état 2 puis pareil que dans l'état 1, tant qu'il y a un b ou un c on tourne en boucle jusqu'à la fin du mot. Il faut aussi prendre en compte $\epsilon$ donc on met l'état 1 en état final.

* $L_5$
  * $L_51$ Ici on met abc en boucle sur l'état initiale et on met l'état initiale en état finale. L'idée est que quelque soit la lettre, tout est accepté.
  * $L_52$ Ici on ne change rien car l'automate ne prend rien, même pas $\epsilon$.
  * $L_53$ Ici l'automate ne prend en compte que $\epsilon$, on a simplement à mettre

* $L_6$ Pour savoir si on a un nombre pair de a, on met une "boucle" de a entre l'état initiale et l'état 2 puis on met en état finale l'état iniale de façon à ce que si un a revient vers l'état finale, il y en ait déjà un qui soit partis de l'état 1. De cette façon, on sait que a est une multiple de 2 quand il revient à l'état initiale.

* $L_7$ C'est un peut la même mécanique que $L_6$, à la différence qu'on remplace les a pas des b et que l'état final soit l'état 2. De cette manière, si on est dans l'état 2, c'est forcément qu'on est sur un nombre impair.

* $L_8$

* $L_6 \cnp L_7$

* $L_9$ Ici on prend un multiple de 41 mais la méthode est la même pour chaque multiple. L'idée est de faire 40 états qui on chacun une boucle avec $b$ et $c$ et donc la transition est $a$. Une fois arriver à 40, on revient à l'état initiale qui est aussi l'état finale. On a donc : $\Sigma = {a,b,c} \:Q={q_0,q_1,...,q_40 \: q_0=q_0 \:F = {q_0}$
  $T = {\forall i \in 0...40,(q_i,b,q_i)} \cup $
  
  
### Exercice 8

L'idée du problème, c'est qu'on a un fermier qui est d'un cîté d'une rivière, il a un bateau qio permet d'aller de l'autre côté de la rivière. Il a un loup une chèvre et une salade et il veux les amener de l'autre côté de la rive. Les deux contraintes sont :
* Un seul parmis la salade, le loup et la chèvre peuvent être dans le bateau avec le fermier.
* Si le loup et la chèvre sont ensemble, le loup mange la chèvre
* Si la chèvre est avec la salade, elle mange la salade.
Le problème est ici assez simple mais là où il est intéressant, c'est qu'il peut être résolu sans l'utilisation de l'homme. On peut résoudre ce poblème avec un automate.

#### Construction de l'automate

Pour faciliter on va dire que Chèvre = C ; Salade = S ; Loup = L. Les états correspondent aux endroits où se situe l'élèment, soit l'élèment est d'un côté de la rivière soit il est de l'autre. On a donc $2 \times 2 \times 2 \times 2$ états (en comptant le fermier) soit 16 états.

