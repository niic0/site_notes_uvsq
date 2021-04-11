# Threads

Un **Thread** est un processus "léger" où contrairement à un processus classique, la mémoire est **partagé** et pas **distribué**. Pour créer un Thread, on utilise la fonction suivante :

```c
int pthread_creat(pthread_t *thread, const pthread_attr *attr, void *(*start_routine) (void *), void *arg);
```

* C'est un équivalent à `fork()` 
* Le thread fils termine son exécution une fois `start_routine()` terminée
* Les attributs `attr` servent à paramétrer la création du thread, `NULL` indique l'utilisation des attributs par défaut
* La fonction `start_function()` est un pointeur de fonction prenant un pointeur en entrée, et retournant un pointeur
* L'argument `arg ` est le pointeur d'entrée de `start_function()`

La fonction pour appeler le thread père pour attendre la fin de l'exécution du fils.



***Exemple d'utilisation de `phthread_creat()`***

```c
void *print_string(void *args) {
    char *str = (char *)arg;
    
    printf("Child says: '%s' \n",str);
	return NULL;
}

void main(void) {
    pthrad_t tid;
    
    pthread_creat(&tid, NULL, print_string, "Hello world!");
    pthread_join(tid, NULL);
}
```

## Mémoire partagée

Soit un programme parallèle calculant la somme des éléments d'un tableau.

```c
int global_sum = 0;

void *compute_array_sum(void *arg) {
    int *tab = (int *)arg; // Convertion de arg en int*
    for (i = start; i<end ; ++i) {
        
    }   
}
```

### Exculsion mutuelle

* **Section critique** -> section de code où une variable est accédée en écriture par plusieurs threads.
* **Exclusion mutuelle** ->