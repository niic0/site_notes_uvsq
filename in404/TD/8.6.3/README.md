# README

## Utilisation de la démonstration

La démonstration du programme se fait uniquement à travers le terminal. Un `Makefile` est fait pour rendre l'utilisation de la démonstration plus simple :

* `make` : Compile et lance le programme,
* `make compil` : compile le programme,
* `make clean` : efface les *.class* et le fichier de sauvegarde créé.

## Utilisation du package

### Class Shape

L'utilisation du package tourne autour de la classe mère `Shape` qui contient les propriétés de chaque forme (chaque forme est une extension de la classe `Shape`).

#### Constructeur

Contient les éléments suivant :

* **Le nom** de la forme créée. Il peut être utile de connaître le nom d'une forme, si par exemple on veux dessiner une maison et qu'on veux prendre un triangle pour faire le toit, alors on appellera la forme triangle "toit". Cette variable est de type *String*.
* **Les coordonnées *x* et *y*** de la forme. On considérera que ces coordonnées pointes vers le milieu de la forme. Ce sont des variables de type *int*.
* **La couleur** de la forme. Elle est arbitrairement initialisée à noir. On peut changer sa couleur avec la méthode `changeColor` de cette même classe. Cette variable est une *String*
* **La visibilité** de la forme. Une forme peut être visible ou non sur la fenêtre. Cette variable est *booléenne*.

#### Méthodes

Ces méthodes agiront sur la forme :

* `moveShape(int dx, int dy)` : permet de bouger de dx, x et de dy, y  la forme.
* `draw()` : simule le fait que la forme ce dessine sur le logiciel de dessin 2D. Ici la forme s'affiche dans le terminale.
* `erase()` : Enlève l'attribut visible à la forme pour l'enlever du dessin.
* `changeColor(String colorModify)` : Change la couleur de la forme. Si la couleur choisie ne fait pas partie de la liste, on entre dans une **exception** et un message d'erreur est renvoyé (disant que la couleur choisie n'existe pas).
* `controle(String color)` : contrôle que la couleur existe dans la liste de couleur choisie arbitrairement. Sinon on entre dans une **exception** et un message d’erreur est renvoyé. Cette fonction est uniquement utile pour vérifier la couleur de la méthode `changeColor(String colorModify)`.

***

### Class Circle

Cette classe permet de créer des cercles dans la simulation du logiciel de dessin.

#### Constructeur

Cette classe est, comme dit précédemment, une extension de la classe `Shape`. De ce fait, un seul élément est ajouté en plus de ce qui existe déjà pour les attribut que donne `Shape`. 

* **radius** : permet d'ajouter un rayon au cercle créé. Variable de type *int*.

#### Méthodes

Cette classe hérite de toute les méthodes de la classe `shape`, une fonction est ajouté :

* `changeRadius(int radiusModify)` : Change le rayon du cercle.

***

### Class Rectangle

Cette classe permet de créer des rectangles dans la simulation du logiciel de dessin.

#### Constructeur

La classe Rectangle hérite des attributs de la classe `Shape` et vient ajouter 2 autres éléments:

* **sizex** : permet de définir la taille x du rectangle. Variable de type *int*.
* **sizey** : permet de définit la taille y du rectangle. Variable de type *int*

#### Méthodes

La classe hérite des méthodes de `Shape`, une seule méthode à été ajoutée :

* `changeSize(int sizexModify, int sizeyModify)` : Permet de modifier la taille du rectangle en changeant *sizex* en *sizexModify* et *sizey* en *sizeyModify*.

***

### Class Triangle

Cette classe permet de créer des triangle dans la simulation du logiciel de dessin 2D.

#### Constructeur

La classe triangle hérite de la classe `Shape` et ajoute un élément :

* **size** : permet de changer la taille du rectangle. On part ici du principe que le triangle est isocèle et que sa taille *size* correspond à la taille entre deux côtés du triangle.

## Utilisation de la class main

C'est dans la classe main qu'est le corps du programme. En effet, c'est ici qu'on instancie les différentes classes crée précédemment. Quatre fonctions ont été ici implémentées. 

### Sérialisation et utilisation de collections

Tout d'abord la sérialisation de notre dessin. Pour pouvoir sauvegarder notre dessin, on peut utiliser la fonction `void saveDrawing(ArrayList<Shape> listShape)`, qui vient implémenter la sérialisation. On sauvegarde ici un dessin qui est sous forme de liste de formes, instancié grâce à la collection `ArrayList` par `ArrayList<Shape> listShape`.

De même, pour charger un dessin, on utilise ce procéder en créer une liste de forme puis en appelant la fonction `ArrayList<Shape> loadDrawing(String draw)`. Celle ci vient mettre dans une liste de `Shape` toutes les formes faites sur le dessin chargé.

### Bouger plusieurs forme et Affichage

Pour faire mouvoir un ensemble de formes, on peut utiliser la collection `ArrayList` utilisé précédemment et utilisé la fonction `moveShapes(ArrayList<Shape> listShape, int dx, int dy)`. Cette fonction vient prendre en paramètre l'ensemble des formes à faire mouvoir et la direction à prendre avec *dx* et *dy*.  La fonction parcours donc toute les formes de l'ensemble et vient ajouter *dx* et *dy* au *x* et *y* de chaque forme respectivement.



