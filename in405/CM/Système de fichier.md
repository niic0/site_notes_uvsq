# Système de fichier

L'idée d'un système de fichier est de pouvoir stocker des informations de façon **pérenne**, de manière **organisée** et **abstraite**. On aura alors besoin de stockage de grande quantité, de conserver ces fichiers et pourquoi pas d'avoir un accès simultané (via un serveur par exemple). 

Un système de fichier est une partie du système d'exploitation gérant les fichiers. Dans un système *UNIX* tout est fichier : Fichier, Répertoire,  Liens symboliques, Autres (FIFO, etc...).

Un fichier est une suite d'octets (binaire, ASCII, etc.) caractérisé par :

*  un nom de fichier - label et extension (optionnel sous UNIX)

  ```shell
  $ cat fichier-test.txt
  ```

* Chemin - Emplacement dans la hiérarchie (absolu)

  ```shell
  $ ls /home/user1/doc
  ```

*  Inode – nœud d’informations entre le système de fichiers et le périphérique

*  Méta-données – attributs, ex : créateur, permissions d’accès, etc.

Pour communiquer avec le système, on fait des **appels système**. On cherchera donc à <u>créer</u>, <u>ouvrir</u>, <u>fermer</u> et <u>supprimer</u>, à <u>lire</u>, <u>écrire</u> et à <u>positionner</u> les fichiers. On n'utilise donc pas les librairies type `stdio.h`. Pour ouvrir un fichier par exemple, on  utilisera `open` et pas `fopen` .

```C
int open(const char *pathname, int flags);
int open(const char *pathname, mode_t mode);
int clode(int fg);
int unlink(const char *pathname);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, vois *buf, size_t count);
off_t lseek(int fd, off_t offset, int whence);
```

## Créer un fichier

La création d'un fichier ce fait par la fonction `creatFile` :

```c++
void creatFile(const char *fname, const int size, const char *data) {
    int fd = -1;
    ssize_t sz;
    int rc;
    
    fd = open(fname, O_creat | O_WRONLY, 0666);
    if (fd == -1) {
       fprintf(stderr, "ERR on file creation: %s\n", stderror(errno));
       return;
    }
    
    if (size) {
        sz = write(fd, data, size);
        if (sz != size) 
            fprintf(stderr, "ERR on file writing: %s\n", stderror(errno));
    }
    
    rc = close(fd);
    if (rc)
        fprintf(stderr, "ERR on file closure : %s\n", stderror(errno));
}
```

### Explication du code

`open` prend un fichier (`fname` = *filename*) pour l'ouvrir. S'il n'existe pas, la fonction le créée. Le dernière argument de la fonction open `0666` correspond au mode d'ouverture du fichier. Ici, on l'ouvre en mode lecture/écriture. On écrit ensuite dans ce fichier avec `write` avec `O_CREAT`, `0666` permet au fichier d'être éditable et ouvrable pour tous le monde (*user*, *sudoers* (administrateur), etc...). On vérifie ensuite si le fichier a bien été ouvert (gestion d'erreur) : `stderror(errno)` permet d'afficher de quelle erreur il s'agit grâce au code erreur `errno`. En réalité, `stdrerror` transforme le code erreur `errno` (qui est un entier) en chaîne de caractère compréhensible (parce que si le terminal nous sort `code error : 42` c'est compliqué de savoir ce qui ne va pas). `stderr` permet d'inscrire dans le terminal l'erreur. Pareil, pour `size` on fait une gestion d'erreur.

## Gestion de dossier

La création d'un dossier ce fait dans UNIX par la fonction suivante, elle est aussi disponible en *shell* (c'est à dire qu'on peut entrer `$ mkdir nomDossier` dans le terminal est ça créera un dossier). Ici c'est pareil on cherche à créer, ouvrir, fermer supprimer mais aussi lire et positionner les dossiers.

```c

```

Ici `mkdir` permet de créer un dossier, `opendir` ouvre un dossier, `closedire` ferme un dossier, `dirent` contient les informations sur le fichier, `telldir` permet de dire où on en est dans le dossier (), `seekdir` permet de se positionner dans un répertoire.

### Créer un dossier

```C

```

un pointeur de pointeur de pointeur permet de pointer sur une liste de chaînes de caractère. Toujours pareil pour la gestion d'erreur, si rc alors on retourne une erreur, si l'allocation n'a pas fonctionner, on fait pareil, on retourne une erreur avec `stderr`.

Les 6X ont pour but de créer un fichier. 



### Supprimer un dossier

on lui donne le nom du dossier `dname`, l'idée est de libérer le tableau qu'on a crée 



### Mappiong du fichier

On peut aussi considérer que notre fichier est une chaîne de caractère. 

Le mapping de fichier permet de représenter le contenu d'un fichier dans un tableau : 

* Programmation facilité
* Performences améliorées
* Cohérance à maintenait pluslourde (multi-accés)
* Taille du gichier généré, multiple de la taille d'une page

