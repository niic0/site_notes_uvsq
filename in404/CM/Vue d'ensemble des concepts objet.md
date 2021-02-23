# Vue d'ensemble des concepts objet

Dans un système objet, les fonctions n'existent pas en tant que telle, on manipule des objets qui interagissent entre eux. L'idée est d'avoir des objets clairs "de la vrai vie" : des voitures, des étudiants, etc... Plus techniquement, un objet est formé de deux composants : 

* Son **état**, i.e. les valeurs prises par des variables le décrivant (propriétés)
* Son **comportement**, i.e. les opérations qui lui sont applicables

Un objet est une *instance* d'une *classe*, il peut avoir plusieurs type et supporter plusieurs interfaces. On peut prendre l'exemple des points et des cercles : 

- Les objets `point1` et `point2` sont des points, `cercle1` est un cercle 
- L’état de chaque objet est représenté par la valeur de ses propriétés
- Le centre du cercle est une référence sur un objet point
- Le comportement n’est pas représenté au niveau des objets
  - une opération est invoquée par rapport à un objet
  - mais est rattachée à la classe (le code est partagé par tous les objets d’une classe)
- Les objets `point1` et `point2` sont égaux mais pas identiques

En code, la structure peut s'écrire sous la forme : 

```java
Point2D p1 = new Point2D(1.0, 2.0); // new = allocation de mémoire dynamique
Point2D p2 = new Point2D(1.0);
Point2D p3 = new Point2D();
Point2D unAutreP3 = p3;
assert p3 == unAutreP3; // on vérifie que les 2 points identiques

Cercle2D c1 = new Cercle2D(p1, 3.0);
Cercle2D c2 = new Cercle2D(new Point2D(2.0, 4.0), 5.0);
Cercle2D c3 = new Cercle2D();
```

## Notion de *Message* 

Pour envoyé une requête à un objet pour demander l'exécution d'une opération on créer un ***message***. Un ***message*** contient trois composants : 

- **l’objet auquel il est envoyé** (le destinataire du message),
- le nom de l’opération à invoquer,
- les paramètres effectifs.

Par exemple pour déplacer un cercle en *Java*, on peut utiliser la méthode *translate* : `cercle1(cercle1.translate(1.0, 2.0))`. Le message *translate* est alors envoyé au centre du cercle `centre.translate(1.0, 2.0)`. Un message permet de modifier un attribut de l'objet désigné.

## Type

Un type est un modèle abstrait réunissant à un haut degré les traits essentiels de tous les êtres ou de tous les objets de même nature. En informatique, un type de donnée spécifie :

* L'ensemble des valeurs possibles pour cette donnée (définition en extension),
* L'ensemble des opérations applicables à cette donnée (définition en intention)

Un type spécifie l'*interface* par laquelle une donnée peut être manipulée. Par exemple, pour reprendre la méthode *translate* précédente, on peut dire que cette méthode est applicable que si l'objet est déplaçable.

```Java
public interface Deplacable {
    /**
     * Translate l'objet.
     *
     * @param dx deplacement en abscisse
     * @param dy deplacement en ordonnées
     */
    void translate(double dx, double dy);
}
```

 ## Classe

Une *classe* est un "modèle" (un "moule") pour une catégorie d'objets structurellement identiques. Elle définit l'implémentation d'un objet (son état interne et le codage de ses opérations). L'ensemble des classes décrit l'*aspect statique* d'un système Orienté Objet.

Une *classe* comporte :

- la définition des *attributs* (ou *variables d’instance*),
- la *signature* des opérations (ou *méthodes*),
- la *réalisation* (ou *définition*) des méthodes.

Chaque instance aura sa propre copie des attributs (son état). C'est en ça qu'elle se différencie d'une *structure* en *C*. La signature se rapproche d'une structure en C, elle contient son nom et le type de ses paramètres. L'ensemble des signatures de méthodes représente l'interface de la classe (publique). Les définitions d'attributs et de méthode forme l'implémentation de la classe (privé).

En continuant l'exemple, on implémente *Cercle2D* avec le code suivant : 

```Java
public class Cercle2D implements Deplacable {
    /** Le centre du cercle. */
    private Point2D centre;

    /** Le rayon du cercle */
    private double rayon;

    /**
     * Initialise un cercle avec un centre et un rayon.
     * @param centre Le centre
     * @param rayon Le rayon
     */
    public Cercle2D(Point2D centre, double rayon) { /* ... */ }

    /**
     * Initialise un cercle centré à l'origine et de rayon 1.
     */
    public Cercle2D() { /* ... */ }

    public Point2D getCentre() { return centre; }
    public double getRayon() { return rayon; }

    /**
     * Translate le cercle.
     * @param dx déplacement en abscisse.
     * @param dy déplacement en ordonnées.
     */
    public void translate(double dx, double dy) { /* ... */ }
}
```

*private* permet de "protéger" une partie de l'implémentation car ces variables sont accessible uniquement dans la classe. Elle n'est pas accessible en dehors de celle ci.

 ## Instanciation

- Le mécanisme d'*instanciation* permet de créer des objets à partir d’une classe
- Chaque objet est une instance d’une classe
- Lors de l’instanciation,
  - de la mémoire est allouée pour l’objet,
  - l’objet est initialisé (appel du constructeur) afin de respecter l’invariant de la classe.



 
