# Communication entre processus

Avec le wait, on peut récupérer un status avec `stat_loc`. C'est un moyen de communication entre un processus père et fils. C'est quelque chose d'assez limité puisqu'on ne communique que par un entier. Excepté le code de retour, il n'y a pas de communication 'native', possible entre deux processus. Mais plusieurs mécanismes peuvent être utilisés à cet effet :

* Signaux
* Fichier (`mmap()` par exemple)
* **Tubes** (meilleur moyen de communication entre processus)
* Mémoire partagé

## Tubes

Un tube est un fichier (dans Linux tout est fichier) où un expéditeur/écrivain peut transmettre des informations à un destinataire/lecteur. On à deux types de tubes :

* Tubes nommés : informations stockés dans un fichier de type ***FIFO***
* Tubes anonymes : informations stockées en mémoire, ne fonctionne que si le créateur 

### Tubes nommés

`int mkfifo(const char *pathname, mode_t mode);`. L'ouverture est bloquante selon le systèmes, tant que les deux extrémités n'ont pas été ouvertes. Suppression du tube avec la fonction `unlink()`.

### Tubes anonymes

`int pipe(int fildes[2])`. Lit sur `fidles[0]` et écrit sur `fildes[1]`.

### Opérations sur les tubes

Les opérations sur les tubes sont identiques aux opérations sur les fichiers.

* writer.c

```c
void main() {
    const char *str = "Hello world";
    int fd;
    
    mkfifo("/tmp/tube-test", 0666);
    
    fd = open("/tmp/tube-test", O_WRONLY);
    write(fd,str,strlen(str));
    close(fd);
}
```

* reader.c

```c
void main() {
    char str[64];
    int fd;
    
    fd = open("/tmp/tube-test", O_RDONLY);
    rest(fd, str, 64);
    close(fd);
    
    printf("Just received : '%s'\n",str);
    unlink();	
}
```

## Mémoire partagés

Les processsus ne possède pas de mémoire partagés, chacun à sa propre mémoire. Mais une fonction permet de partagé de la mémoire entre processus. `int scmget(key_t key, size_t size, int shmflg);`. L'allocation d'un segment de mémoire partagée dont l'identifiant est `key`. `void *shmat(int shmid, const void *shmaddr, int shmflg);` et `int shmdt(const void *shmdar);`