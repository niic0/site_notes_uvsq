# IN405 - TD8

## Utilisation

La compilation des fichiers doit se faire simplement à l'aide des commandes
ci-dessous :

```bash
$ gcc -o server server.c
$ gcc -o client client.c
```

L'utilisation, comme décrite dans l'énoncé du TD ainsi que dans les 'usage()'
des fichiers source `client_template.c` et `server_template.c`, se fait comme
ci-dessous :

```bash
$ ./server math 4 &
$ ./client math + pi 3.14
$ ./client math ? pi
$ ./client math !
```

## Création du dictionnaire

La création du dictionnaire se fait dans `server.c` avec la fonction `create_dict`. Cette fonction vient allouer chaque cases du tableau, le nombre de case ayant été entré par l'utilisateur. On fait donc une boucle qui ira de la case 0 jusqu'à la taille max du tableau (qu'on traduit en *int* avec la fonction `atoi`) et on alloue chaque case de la taille d'une `struct dictionary_item`.

On vérifie ensuite que le tableau a bien été alloué, sinon on retourne 1 et un message d'erreur. 

## Communication client -> serveur (`receive_command`)

Le <u>client</u> communique avec le <u>serveur</u> grâce au pipe que le serveur à crée. Une fois que le pipe est ouvert, on vient écrire dedans côté client. Le message est reçu par le serveur grâce à la fonction `receive_command` dans `server.c`. Dans cette fonction on va donc lire le pipe avec la fonction `read` (avec une gestion d'erreur) et mettre dans une chaîne de caractère ce qu'a lut cette même fonction. Le client envoie en premier le type de commande (`+`, `-`, `?`, `!`) donc le premier caractère correspond à la commande voulue. Avec `buf[0]` on peut savoir si l’utilisateur veux ajouter, enlever, demander une valeur ou fermer le serveur.

La fonction prend en argument ne structure `struct command` qui contient la valeur, le nom de cette valeur et l'opération voulue(`OP_ADD`, `OP_REMOVE`,`OP_ASK`, `OP_EXIT`). L'idée est donc de mettre dans le pointeur `struct command *cmd` l'opération ainsi que la valeur et son nom si nécessaire.

On décrira dans les parties suivante le détail de chaque *if* en fonction de l'opération demandée. 

## Ajout de valeurs

### Client `dict_add`

Fonction qui envoie au serveur 3 informations : l'ajout, la valeur à ajouter et son nom. On ouvre d'abord le tube en écriture afin d'utiliser la fonction `write`. La valeur est traduite de *double* à *String* afin de l'envoyer (via écriture dans le pipe) au serveur. On envoie ensuite un à un les éléments en vérifiant que la fonction `write` c'est bien passée (sinon un erreur est affichée).

### Server `receive_command` pour *ADD*

On va utiliser dans ce *if*  la fonction `strtod` qui traduit une chaîne de caractère en double. Cette fonction ne prend que la partie qui correspond au "double" du mot  en indiquant où il s'est arrêté. C'est à dire que dans notre cas, le serveur recevra par exemple `+3.14pi`, le valeur pris par le `strtod` renverra *3.14* et le pointeur pointera sur le reste de la chaîne de caractère don ici *pi*. 

On met ensuite dans notre structure commande toutes les informations nécessaire pour `dict_add` c'est à dire l'opération, la valeur et le nom de la valeur. 

### Server `dict_add`

Cette fonction vient ajouter une valeur et un nom associé au dictionnaire. Pour ça on utilise la `struct command` qu'on vient de remplir dans `receive_command` pour compléter le dictionnaire. Pour ça, il faut remplir le dernière case du tableau ce qui nous ait donné par la variable `dict_count` qui indique le nombre d'élément actuel dans le tableau. Cette variable est un pointeur car on incrémente de 1 à chaque nouvelle valeur dans le dictionnaire dans cette fonction. 

La valeur et le nom son ensuite mis dans le dictionnaire à la case `*dict_count` (la dernière) grâce au pointeur `cmd ` qui contient ces deux informations.

## Enlever des valeurs

### Client `dict_remove`

On utilise ici la même méthode que pour `dict_add` à ceci près qu'on envoie seulement deux informations : le `-` et le nom de la valeur à enlever. 

### Server `receive_command` pour *remove*

On va chercher dans ce *if* à mettre dans la structure `cmd` nos 2 informations, le `-` et la valeur. 

### Server `dict_remove`

Cette fonction va dans un premier temps chercher la position de la valeur dans le tableau de dictionnaire avec une boucle qui va comparer (avec `strcmp`) le nom de la valeur (qu'on vient de mettre dans la variable *cmd* avec la fonction `receive_command`). L'idée est d'ensuite recréer le tableau de dictionnaire en enlevant cette valeur. En effet, une fois qu'on a trouvé la position de la valeur à retirer, il suffit de décaler de 1 tous les items du dictionnaire. C'est  ce que le *for* permet dans cette fonction.

## Demander une valeur

Les fonctions utilisés dans cette partie sont dans cette ordre :

> `dict_ask`(client) --> `receive_command`(server) --> `dict_ask`(server) --> `send_response` (server) --> `dict_ask`(client)

On va donc envoyer une demande au serveur avec la fonction du client `dict_ask`, le serveur reçoit l'information avec la fonction `receive_command` qui va remplir la structure *command* pour l'envoyer à `dict_ask` côté serveur. Une fois qu'on sait si la valeur existe et qu'on connaît sa valeur, on envoie ça au client avec la fonction `send_response`. Finalement la fonction est reçu par notre fonction de départ `dict_ask`, dans le client.

### Client `dict_ask`

Dans un premier temps, on vient écrire dans le pipe le `?` ainsi que le nom de la variable souhaitée. On ferme ensuite le pipe qu'on a ouvert pour en ouvrir un nouveau mais cette fois ci en mode lecture. On vient donc lire ce que le serveur nous a envoyé et l'afficher si la valeur existe.

### Server `receive_command` pour *ask*

Dans ce *if*, on va mettre l'opération ainsi que le nom de la variable à chercher. En effet, la structure `cmd` va ici permettre d'envoyer au client les informations et de donner les informations nécessaire aux autres fonctions.

### Server `dict_ask`

De la même manière que pour `dict_remove` dans *server.c*, on a va chercher la variable demandée (si elle n'existe pas, un message d'erreur s'affiche et NOT FOUND et mis dans le nom du dictionnaire). Une fois trouvé, on met dans la structure `cmd` la variable trouver.

### Server `send_response`

Dans un premier temps, on vérifie que la variable a été trouvée. Si ce n'est pas le cas, on écris dans le pipe "'NOT FOUND".  Si la valeur existe dans le dictionnaire on vient l'écrire dans le pipe en la traduisant d'abord en chaîne de caractère.

## Extinction du serveur

### Client `dict_exit`

On envoie ici au serveur la commande `!` (avec une gestion d'erreur).

### Server `receive_command` pour *exit*

 Ce *if* ne fait qu'assigner la valeur `OP_EXIT` à la structure commande.

## Problèmes du programme

* Dans de rare cas, le programme a du mal à recevoir le message envoyé. C'est pourquoi quand une valeur est ajoutée, il est possible qu'elle ne le soit pas vraiment, il faut donc vérifier qu'elle le soit en faisant un *ask* de cette valeur. Mais là aussi le serveur peut recevoir autre chose, il faut le faire plusieurs fois avant d'arriver à un résultat concluant. Si ce n'est pas le cas, alors la valeur n'a pas été ajoutée. (Je n'ai malheureusement pas trouver la source de ce problème avec toutes les méthodes que je connais (relecture complète du programme, *gdb*, *valgrind*...) ).
* Le programme peut parfois prendre plus de valeur que la taille maximum du tableau. C'est un problème que je ne comprend pas puisque le tableau est alloué. Donc si on va plus loin que la taille maximum du tableau de dictionnaire, on obtient logiquement un *segfault* vu qu'on accède à de la mémoire non alloué.
* Dut au 1er problème, il n'est pas possible d'utiliser ce programme sur de grande donnée (taille du tableau supérieur à ~50) car il y aurait trop d'imprécisions. 