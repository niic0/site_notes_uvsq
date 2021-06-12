% IN405 TD11 -- Systèmes d'exploitation
% Pattern Finder

# Recherche de motif dans un fichier - TD11
Le projet consiste à trouver un mot dans un fichier. On utilisera dans un premier temps une méthode sequentielle et dans un second temps une méthode basé sur du parallélisme.

## Utilisation du programme
Le programme s'utilise de la façon suivante : `./pattern-finder x mot fichier`
* `./pattern-finder` est le nom de l'éxcecutable,
* `x` désigne le nombre de thread à créer pour la recherche,
* `mot` est le mot à trouver dans le fichier,
* `fichier` pointe vers le fichier où il faut trouver le mot.

## Détails du programme
Nous allons dans cette partie décrire birévement les différents points importants du programme.

Le programme tourne autour d'une recherche sequentielle du mot. Deux fonctions ont été implémentées : `print_occ_seq` qui affiche les occurences du mot de façon sequentielle et `print_occ_mTh` qui affiche les occurences du mot avec un nombre de threads donné. Les deux fonctions son assez semblables dans leurs méthodes. 

En effet, l'algorithme est quasiement le même pour ces deux fonctions. L'idée générale est de parcourir le texte entier, caractère par caractère. Si la boucle rencontre un caractère qui est identique au premier caractère du motif à rechercher, alors il ira vérifier que la suite est bien égale au motif donné. Si c'est le cas, c'est qu'il y a une occurence, la fonction l'affichera donc. Pour cela nous avons besoin de plusieurs fonctions : 
* Une fonction permettant de transformer le fichier texte donné en chaîne de caractères. En effet, si on veux savoir si un caractère match avec le motif, il faut pouvoir les comparer.
* Une fonction qui donne la taille du fichier. La taille du fichier étant égale au nombre de caractère qu'il contient, il est utile d'avoir cette valeur notamement pour la fonction convertissant le texte en chaîne de caractères.

Avec ces deux fonctions, on peut créer notre recherche de mot.

### size_t size_file(const char* path)
Cette fonction retourne la taille du fichier donné en argument. Elle utilise une méthode assez simple qui consiste à aller chercher le dernier caractère du fichier avec la fonction `lseek` qui renvoie la position du dernier caractère.

### int get_txt(xonst char* path, char** buf_str)
Cette fonction permet, comme dit précédement, de lire un fichier et de mettre dans une chaîne de caractères tous les caractères que contient le fichier. L'idée est ici d'ouvrir un fichier avec `open` en mode lecture et de parcourir le fichier du caractère 0 au dernier caractère (donné par la fonction `size_file`). On lit le le fichier avec `read` et on met dans un buffer le caractère trouvé par la fonction. On ajoute ce caractère à notre chaîne de caractères avec `strncat`.

### Fonction principale
Le multi-threading se fait de la façon suivante : le texte est découpé en *n* partie avec *n* le nombre de threads demandé. De cette façon, chaque thread va traiter sa partie du texte en parrallèle. Par exemple si la recherche demande 2 threads, le premier thread ira du caractère 0 au caractère de milieu de texte et le second ira du caractère de milieu de texte jusqu'au dernier.

Ceci demande d'utiliser la fonction `pthread_create` qui, dans notre cas, demande à créer une structure. En effet, cette fonction prend en argument de la fonction donné un `void*`. On utilise alors une structure contenant toutes les informations dont nous avons besoin pour faire la recherche à savoir :
* Le mot à chercher
* Le texte
* le nombre de thread
* le caractère de départ de recherche
* le caractère de fin de recherche

Avec ces éléments (convertis de `void*` à notre structure) on peut alors procéder au parallèlisme en lançant plusieurs threads qui iront chacun faire une recherche sur leur partie du texte.
