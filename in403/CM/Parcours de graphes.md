# Parcours de graphes

Un algorithme de marquage comme vu précédemment est un algorithme de parcours en soit. On passe de nœud en nœud en regardant les voisins du nœud sur lequel on est puis on choisit d'avancer sur l'un de ces voisins. 

## File

Cet algorithme utilise en réalité une mécanique algorithmique, le *FIFO*. En effet, le voisin non marqué se retrouve dans la file, le sommet actuel sort de la file, on va ensuite sur le sommet non marqué puis on répète jusqu'à ce que tous les sommets soit marqués. 

img graphe avec croix sur les parcours déjà fait

On peut voir cette structure de donnée comme une boite noir qui va stocker des données et qui va indiquer si la boite est vide ou non. 

img boite noir

Avec ce parcours, si graphiquement on trace le parcours, on remarque qu'on obtient un arbre. Ce parcours s'appelle un parcours en largeur. Dans ce type de parcours, la distance à la racine est égale à la hauteur.

img ou on voit que le parcours forme un arbre

## Pile

On utilise toujours le principe de marquage dans une pile (*LIFO*). On va mettre dans la pile les voisins non marqués puis on va dépiler le dernier élément de la pile pour passer à ses voisins qu'on va ajouter à la pile s'il ne sont pas marqué. On va ensuite se placer sur le voisin puis dépiler le dernier élément de la même manière que précédent.

img pile

La pile va chercher à aller loin et profondément dans le graphe. On voit en effet qu'on a tendance à se coller au bord du graphe pour le parcourir. On appellera donc ce parcours un parcours en profondeur.

img pour un parcours en profondeur