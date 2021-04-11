# Processus

Un processus est une abstraction de l'exécution d'un fil d'instructions. Chaque processus a son propre contexte :

* Identifiant unique 
* Compteur ordinal
* Registres (stocker)
* Mémoire (pile, tas)
* Fichiers ouverts (chaque processus à droit d'ouvrir un fichier)

L'ordonnanceur du système possède une table des processus. Nous allons en effet voir comment l'ordinateur fait pour donner cette impression de fluidité quand plusieurs applications sont ouvertes en même temps. Pour l'utilisateur, tous les processus s'exécutent en même temps alors que pour le système, les processus s'exécutent à "tour de rôle". Le système bascule de l'état d'un processus : actif -> bloqué -> prêt. Vient donc la notion de **parallélisme** ou on a programme qui partage plusieurs processus.

## Création d'un processus, la commande `fork()`

On invoque un nouveau processus avec `fork()`. Le principe c'est qu'on clone le père (un peux comme une mitose) pour donner un fils. La valeur de retour de `fork` permet de différencier les deux processus : 

* $ >0$ : Processus père
* $0$ : Processus fils
* $<0$ : erreur

```C
pid_t fork(void);

pid_t p;

p = fork();
if (p) {  // Fait partie du processus père
    ...
} else {  // Fait partir du processus fils
    ...
}
```

Dans l'exemple suivant, `p` contient le `fork` et les 2 fils d’exécutions seront exécutés car `p` contient les conditions du `if` et du `else`. 

```c
int fd = open("toto", O_RDWR);
char a[16] = "Hello World!";
double f = 3.14;
pid_t p;

p = fork();

if (p) 
    f = 1.62;
else 
    close(fd);

a[p%2] = 'C';
```

![Screenshot_2021-03-13 slides_cm_in405 pdf](/home/nicof/Desktop/UVSQ/in405/CM/Screenshot_2021-03-13 slides_cm_in405 pdf.png)

## Fonctions utiles sur les processus

Il y a plusieurs moyen d'arrêter un processus. L'une des manière de faire est d'utiliser la fonction `void exit(int status); `. Pour reprendre le *pid*, on utilise la fonction `pid_t getpid();` pour le processus fils et  `pid_t getppid();` pour le processus père. Pour récupérer le pid du fils du fils, on peut réutiliser la fonction `fork`.

Pour prévenir d'un évènement, on utilise la fonction `int kill(pid_t pid, int sig);`. Cette fonction envoie un signal à un processus donnée. Plusieurs retour sont possible, SIGINT, SIGTERM, SIGKILL, SIGSTOP, SIGCONT, SIGSEGV, etc...

* `unsigned int sleep(unsigned in seconds)` : Endort un processus
* `typedef void (*signhandler_t)(int);`
  `signhandler_t signal(int signum, sighandler_t handler);`
* `int execl(const char *ath, const char *arg, ...,(char *) NULL);` : Remplcement du programme courant par celui ciblé, dans le même processus.
* `$ ps ` et `$ top` : commande shell qui affiche des processus courant.

## L'ordonnanceur

```c
for (i = 0; i<10; ++i) {
    if(!fork())
        break;
    printf("%d\n", i);
}
```

Les processus sont ici lancés dans un ordre indéterminé. L'ordre sera ordonnée au début puis plus il avancera, plus ce sera aléatoire. Cette ordre est donnée par l'ordonnanceur.

* Gère l'accès auprocessur, et sélectionne les processus à exécuter à l'aide d'un algorithme
* Duchoix de l'lgorithme va dépendre l'efficacité de l'ordonnanceur à utiliser le processeur au maximum
* Par exemple, si des processus actifs attendent des entrées/sorties, il faut les mettre en attente et rendre d'autres processus actifs.

**But** : Assurer l'attribution et l'utilisation équitable du processeur.

Lorsqu'un ou des processus changent d'état; 

* Lors de la création de nouveaux processus
* Lors de la terminaison de processus
* Lors de l'attente de ressources
* Lors de l'acquisition des ressources
* Préemption

## Algorithme d’ordonnance

* FIFO : *First In First Oout*  - Premier arrivé premier exécuté. C'est un algorithme siumple à implémenter 

### atre

### *round-robin*

Préemption

### Tirage au sort

### Ajout de la prorité

Certains processus sont plus importants que d'autres. On sélectionne le prochain processus à exécuter en fonction de cette importance -> **priorité**. On affine ensuite la priorité via l'ordonnanceur pour éviter les situations de famine.

