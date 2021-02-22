# Comparaison et alignement de séquences

## Introduction

*Exposition du problème*

* **Le fait**: Je viens de séquencer un génome et d'identifier ses ORF (Open Reading Frame) et "CDS" (gènes potentiels)
* **La question**: existe-t-il des gènes **annotés** et **stockés** dans la Banque qui ressemblent (entièrement ou en partir) à "mes" CDS
* **Hypothèse**: Les gènes qui se ressemblent partagent des "propriétés communes" (fonctions proches). On espère alors que les banques donneront des indications sur les gènes.

## Pourquoi les gènes de différents organismes se ressembleraient-ils ?

### Homologie

Les espèces partagent toujours un ancêtre commun (Le plus ancien étant *LUCA*), ce sont des 'proches parents'. Les espèces ont donc des gènes en commun. Ils sont transmis à la descendance lors des spéciations (gènes et orthologues) et se dupliquent au sein d'un même génome (gène para-logues).

**Les orthologues et les para-logues** sont des gènes apparentés (ils dérivent d'un ancêtre commun). Des gènes apparentés sont dits **homologues**.

### Convergence évolutive

Avec des gènes différents, on obtient phénotypiquement les même choses. On peut prendre l'exemple des taupes (vertébré) et des Grillon-taupes (invertébré) qui ont des pâtes quasi identiques. Des gènes non apparentés finissent par se ressembler du fait  d'une "convergence évolutive". Même si elle est avérée, la convergence est un phénomène considéré comme rare. On suppose donc avant la convergence, que si ressemblance il y a, elles dérivent d'un ancêtre commun.

### Transfert horizontale

Il existe 3 modes de transferts : 

* **Conjugaison** : Le "sexe" chez les bactéries ou elles échangent des plasmides qui héberge des gènes. 
* **Transformation** : Capacité des bactéries à prendre dans le milieu des bactéries. Quand une bactéries meurt, son cytoplasme explose et d'autres bactéries viennent le prendre. 
* **Transduction** : Transfert de gène via les phages.

***

Ces 3 raisons permettent de confirmer qu'il est très probable que le gène étudié soit ressemblant à une ou plusieurs espèces déjà enregistrées.

***

## Comment comparer deux gènes ?

On va partir du principe qu'un gène d'une autre espèce ressemble à peu près à notre séquence. On va chercher à comparer plus scientifiquement ces deux gènes. Pour ça, l'une des manières de faire est d'utiliser le **Dot-Plot**.


### Le Dot-Plot

On a par exemple deux séquences à comparer : { `ACTCGAGCTATCG` } et { `ACTATGAGATATG` }. Ici il est simple de comparer ces deux séquences "à l’œil", mais avec une séquence avec plus de 50 nucléotides, il devient très difficile de faire ça à l’œil.

![dot-plot](data:image/png;base64,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)

Le Dot-Plot est indexé par les caractères des deux séquences. Les ressemblances locales apparaissent le long des segments diagonaux. C'est une méthode simple et rapide pour comparer des chaîne de nucléotides courte mais encore une fois, quand on a des protéines qui font plus de 200 nucléotides, on ne peux utiliser le Dot-Plot. Cette méthode ne fonctionne pas pour faire du "massif".


### Alignement de deux séquences

L'alignement de séquences correspond à la mise en correspondance de deux séquences (ADN ou protéines) pour faire apparaître les similarités (les segments communs). L'idée est d'aligner les séquences en les justifiant à gauche de manière à faire apparaître les similarités et les différences des séquences.

![Alignemnt séquence](https://interstices.info/wp-content/uploads/jalios/alignement/Figb2.gif)

3 évènement sont alors possibles : 

* Correspondance (*match*)
* Substitution (*mismatch*)
* Indel (Insertion / Délétion)

On peut établir un score d'alignement où l'on compte : une correspondance -> 2 points ; Subsitution -> -1 points ; Indel -2 points. Attention néanmoins, le score associé à une substitution ne va pas être le même si on compare deux séquences protéiques, il va dépendre des acides aminés qui sont substitués. Pour ça on a un tableau qu'on appelle *matrice de substitution*.



<img src="https://upload.wikimedia.org/wikipedia/commons/0/02/BLOSUM62.png" style="filter:invert(1); width:900px;"/>



Les acides aminés sont remplacés "préférentiellement" par d'autres. Il possèdent par exemple des propriétés physico-chimique proches. Certains sont plus conservés que d'autres. Ils sont par exemple essentiels dans la structure 3D des protéines (comme Tryptophane/W/Trp).

### Alignement Global

L'alignement Global consiste à évaluer une ressemblance globale entre deux séquences dont on a la séquence de nucléotides ou d'acides aminés via un score qui prend en compte des similarités et des pénalités. Le problème étant : Quel est l'alignement de score maximal, c'est à dire, quelle est l'alignement qui fait correspondre le plus d'éléments.

### Alignement de programmation dynamique

L'idée est de mettre en abscisse et en ordonnée les deux séquences à comparer. On part toujours de 0 en haut à gauche puis on met le score dans la bonne case. Par exemple pour un *indel*, on met le score sur la première ligne et la première colonne. On a pour score :

* Correspondance = +2 / Substitution = -1 (diagonale de haut gauche à bas droit)

* Indel = -2 (de gauche à droite / de haut en bas)

Le déplacement indique le score de la case. Pour les cases autres que celle qui sont sur les bords, on à donc 3 possibilités : soit il y a un déplacement en diagonale, soit de haut en bas, soit de gauche à droite. On va alors chercher le plus grand des 3 scores calculé à partir des scores de correspondances, de substitution et d'indel. Il se calcul comme ça : pour la 3ème colonne, 3ème ligne (le 2), on l'a obtenue en faisant : 

* Indel (de haut en bas) : $(-2)-2=-4$
* Correspondance (de haut gauche à bas droit) : $0+2=2$
* Indel (de gauche à droite) : $(-2)-2=-4$

Ici, la plus grande valeur est 2, on mettre donc 2 dans la case (colonne 3, ligne 3). 

<img src="../../../../../../../tmp/Spectacle.fCeLyU/Screenshot_20210215_095036.png" alt="Screenshot_20210215_095036" style="zoom:50%;" />



**9** est le meilleur score possible pour un alignement. 

L'idée derrière cet algorithme est d'aligner les séquences. On pourra aligner des séquences globales (toute la séquence), et des séquences locales pour voir quel bout match avec une autre séquence.  