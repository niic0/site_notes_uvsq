# Système de fichier

L'idée d'un système de fichier est de pouvoir stocker des informations de façon **pérenne**, **organisée** et **abstraite**. On aura alors besoin de stockage en grande quantité, de conserver ces fichiers et pourquoi pas d'y avoir un accès simultané (via un serveur par exemple). 

Un système de fichier est une partie du système d'exploitation gérant les fichiers. Dans un système *UNIX* tout est fichier : Fichier, Répertoire,  Liens symboliques, Autres (*FIFO*, etc...).

Un fichier est une suite d'octets (binaire, ASCII, etc.) caractérisé par :

*  un nom de fichier - label et extension (optionnel sous *UNIX*)

  ```shell
  $ cat fichier-test.txt
  ```

* Chemin - Emplacement dans la hiérarchie (absolu)

  ```shell
  $ ls /home/user1/doc
  ```

*  Inode – nœud d’informations entre le système de fichiers et le périphérique

*  Méta-données – attributs, ex : créateur, permissions d’accès, etc.

Pour communiquer avec le système, on fait des **appels système** ou on cherchera à <u>créer</u>, <u>ouvrir</u>, <u>fermer</u> et <u>supprimer</u>, à <u>lire</u>, <u>écrire</u> et à <u>positionner</u> les fichiers. On n'utilise donc pas les librairies type `stdio.h`. Pour ouvrir un fichier par exemple, on  utilisera `open` et pas `fopen` .

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

`open` prend un fichier (`fname` = *filename*) pour l'ouvrir. S'il n'existe pas, la fonction le créée. Le dernière argument de la fonction open `0666` correspond au mode d'ouverture du fichier. Ici, on l'ouvre en mode lecture/écriture. On écrit ensuite dans ce fichier avec `write` avec `O_CREAT`, `0666` permet au fichier d'être éditable et ouvrable pour tous le monde (*user*, *sudoers* (administrateur), etc...). On vérifie ensuite si le fichier a bien été ouvert (gestion d'erreur) : `stderror(errno)` permet d'afficher de quelle erreur il s'agit grâce au code erreur `errno`. En réalité, `stdrerror` transforme le code erreur `errno` (qui est un entier) en chaîne de caractère compréhensible par l'homme (parce que si le terminal nous sort `code error : 42` c'est compliqué de savoir ce qui ne va pas). `stderr` permet d'inscrire dans le terminal l'erreur. Pareil, pour `size` on fait une gestion d'erreur.

## Gestion de dossier

La création d'un dossier ce fait dans UNIX par la fonction suivante. On utilise en *shell* `$ mkdir` qui permet aussi de créer un dossier (*MAKe DIRectory*)). Ici c'est pareil on cherche à créer, ouvrir, fermer supprimer mais aussi lire et positionner les dossiers.

```c
int creatDir(const char *dname,const int nbEmpyFiles, char ***dirFiles) {
    int rc;
    int i;
    
    rc = mkdir(dname, 0700);
    if(rc) {			// Vérifie que le dossier est crée
        fprintf(stderr, "ERR on dir creation %s\n", strerror(errno));
        return 1;
    }
    
    *dirFiles = malloc(nbEmptyFiles * sizeof(char **));		// Pointe et alloue les fichier du dossier 
    if (nbEmptyFiles && !*dirFiles) {
        fprintf(stderr, "ERR on dir file names allocation: %s\n",strerror(errno));
        return 0;
    }
    
    for (i=0 ; i < nbEmpty ; i++) {
        char *fname;
        int fd;
        
        fname = malloc(16 + strlen(dname));		// Allocation de la chaîne de caractère qui va servir de nom au dossier
        if (!fname) {
            fprintg(stderr, "ERR on file name allocation");
            return 1;
        }
        snprintf(fname, 16 + strlen(dname), "%s/empty_XXXXXX", dname);	// XXXXXX = créer une fichier
        fd = mkstemp(fname);	// Génère un nom de fichier temporaire, créer et ouvre le fichier, retourne la description pour
        						// un fichier
        if (fd ==-1) {
            fprintf(stderr, "ERR on file name creation (%s): %s\n", fname, stderror(errno));
            continue;
        }
        close(fd);				// On ferme le fichier
        (*dirFiles)[i] = fname;
    }
    return 0;
}
```

Dans les arguments de la fonction, on voit `char ***dirFiles`. Un pointeur de pointeur de pointeur permet de pointer sur une liste de chaînes de caractère. 

### Supprimer un dossier

La suppression de dossier se fait par la fonction `deleteDir`. On utilise parfois en *shell* `$ rmdir`, la fonction l'utilise aussi ici.

```c
void deleteDir(const char *dname, const int nbEmptyFiles, char **dirFiles) {
    int i;
    
    for (i = 0; i < nbEmptyFiles; ++i) {// Boucle pour effacer les fichiers du dossier
        unlink(dirFiles[i]);			// Enlève le lient qu'avez un fichier à son repértoire
        free(dirFiles[i]);				// Libère la mémoire du fichier.
    }
    
    free(dirFiles);		// Libère la mémoire du fichier qui permet au dossier d'éxister 
    rmdir(dname);		// Efface le dossier
}
```

### *Mapping* du fichier

Le mécanisme de projection en mémoire (*memory mapping*) d’un fichier ouvert permet à un ou plusieurs processus de gérer son contenu (complet ou seulement certaines zones) directement en mémoire, sans avoir besoin d’utiliser les appels système vus dans ce chapitre.

Le fichier projeté en mémoire peut être en usage exclusif ou partagé pour le processus à l’origine du *mapping*.

```c
void *mmap(void *addr, size_t lenght, int prot, int flags, int fd, off_t offset);
int munmap(void *addr, size_t lenght); 
```

Le *mapping* de fichier permet de représenter le contenu d'un fichier dans un tableau : 

* Programmation facilité
* Performances améliorées
* Cohérence à maintenait plus lourde (multi-accès)
* Taille du fichier généré, multiple de la taille d'une page

### Méta-données

Une méta-donnée est un **attribut** d'un fichier. Il contient se qui caractérise un fichier. Il peut contenir les permissions (si on a accès en mode *sudoers* ou simplement *user* au fichier demandé), la taille du fichier, le périphérique, la date du dernier accès, etc... Ces éléments peuvent être appelés en shell ou même en C :

```c
int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);
```

La structure `stat` est remplie lors de l'appel de l'appel de la fonction, et contient diverses méta-données, dont : 

* Les permissions `st_mode`
* Le nombre de liens matériels pointant sur l'inode `st_nlink`
* L'ID de l'utilisateur `st_uid`
* La taile `st_size`
* La date de dernier accès `st_atime`

#### Les permissions

Il y a plusieurs permissions sur un fichier : l'écriture, la lecture et l'exécution. On peut changer ces données via `chmod()` par le shell et en C  on utilise `chmod()` et `fchmod`. A titre indicatif, `chmod` correspond à **Ch**ange **Mod**e. 

Par exemple en C on peut utilisé cette fonction comme suit `chmod(path, 0760)`. Dans cette exemple on a

* `path` correspond à notre chemin menant au fichier dont l'ont veux changer les permissions d'accès,
* `0` qui indique que la suite est en octale (base 8),
* `760` indique que l'utilisateur  peut lire, écrire et exécuter le fichier en question.

### Les types de liens 

Il existe deux types de lien, les liens symboliques et les liens matériels :

* Un lien symbolique correspond à un fichier A qui pointe vers un autre fichier B. Si le fichier A est supprimé, alors le fichier B devient inexistant. 
* Un lien matériel (parfois appelé lien physique) définit en réalité une multitude de lien. C'est à dire que contrairement au lien symbolique, un fichier est pointé par plusieurs entré de répertoire. On peut très bien, dans un lien matériel, copier les donnée d'un fichier puis supprimer ces données copier, les fichiers initiaux sont inchangés.

<img src="/home/nicof/Desktop/UVSQ/in405/CM/Screenshot_2021-03-01 slides_cm_in405 pdf.png" alt="Screenshot_2021-03-01 slides_cm_in405 pdf" style="zoom:67%;" />

### Inode

L'idone est un bloc d'octet comportant le numéro de l'inode, les méta-données du fichier et les blocs de données du fichier.

<img src="/home/nicof/Desktop/UVSQ/in405/CM/e.png" alt="e" style="zoom:67%;" />

### Allocation de l'espace aux blocs

#### Contiguë

![azer](/home/nicof/Desktop/UVSQ/in405/CM/azer.png)

Cela à pour avantage d'être simple à implémenter et d'avoir de bonnes performances et pour inconvénient de fragmenter l'espace. De plus, on doit connaître le taille du fichier avant de le stocker.

#### Liste chaînée

![fqds](/home/nicof/Desktop/UVSQ/in405/CM/fqds.png)

Cette liste chaîné permet de ne pas perdre de place maispour avoir accès au bloc *n*, il faut lire les blocs précédent ce qui peut être plutôt long si le fichier est gros.

#### *FAT*

![zar](/home/nicof/Desktop/UVSQ/in405/CM/zar.png)

C'est un structure plus utilisé aujourd'hui (d'où le *FAT32* ou le *FAT16*). La ***File Allocation Table*** est une liste chaînée via table en mémoire. On enlève donc l’inconvénient des liste chaînée mais la taille de la table augmente avec le nombre de blocs sur le disque.

***

### Incohérence du système de fichier

Le système de fichiers peut présenter des incohérences si il tombe en panne lors d'une écriture de fichier :

* Blocs libres présents plusieurs fois dans la liste,
* Blocs manquants (ni utilisés, ni libres),
* Blocs utilisés dans plusieurs fichiers.

Par exemple, quand on retire une clef USB sans l’éjecter alors qu'elle est entrain d'être utilisée, on peut avoir des erreurs, voir péter la clef. La commande `fsck` permet de vérifier la cohérence du système de fichiers, mais ne garantit pas la préservation des données.

