# Protocole Phantom

> Nicolas Fond-Massany (21908626) TD2a

Le TD consiste à créer un répertoire *'phantom'* à partir de méta-données récupérées sur un dossier existant en utilisant la structure de donnée donnée. 

## Internals

`internals` contient les fonctions essentiels à l'`api`. On cherche ici à créer des types de fichiers spécifiques, à implémenter les méta-données et à entrer dans un répertoire en utilisant la structure de donnée. La structure de donnée permettra de faciliter l’accès aux méta-données pour avoir un code plus lisible pour l'`api` et la fonction principale `main`.

### capture_file()

Fonction permettant de remplir la structure de donnée des méta données du *path* pris en argument. Elle retourne 0 si elle réussi, 1 sinon avec le code erreur associé. Les commentaires dans les conditions de type sont à dé-commenter pour afficher le type des fichiers traités.

### browse_directory

Fonction permettant d'aller dans un répertoire et de remplir la structure de donnée. Chaque fichier de ce répertoire sera dans la liste chaînée. S'il y a un sous dossier, on répète cette opération. On parcours ce dossier avec la boucle `while ((entry = readdir(pDir)) != NULL)` et on utilise `file->d_name` pour accéder au nom du fichier et pouvoir capturer le fichier et le mettre dans le `current->next`  soit le fichier suivant du répertoire.  

### creat_regular

Fonction permettant de créer un fichier régulier à partir de la structure de donnée correspondante. Toutes les méta données qui sont stockées dans la structure *file* seront "copié" dans un fichier.

### creat_directory

Fonction permettant de créer un dossier à partir de la structure de donnée correspondante. Toutes les méta données qui sont stockées dans la structure *file* seront "copié" dans ce nouveau répertoire.

### create_link

 Fonction permettant de créer un lien symbolique à partir de la structure de donnée correspondante. Toutes les méta données qui sont stockées dans la structure *file* seront "copié" dans ce nouveau lien.

## api

### capture_tree

Cette fonction permet de prendre tous les dossier d'un dossier pris en argument et de créer une structure *file* à partir de cette arborescence. La fonction contient une gestion d'erreurs et ce base sur le même principe que `browse_directory()` en capturant tous les fichiers à l'aide de la boucle `while ((entry = readdir(pDir)) != NULL`).

### create_phantom

Cette fonction permet de créer tout ce que la structure *file* contient.

## main

La fonction main capture la hiérarchie du dossier pris en argument et la recopie dans le répertoire de destination. Elle possède une gestion d'erreurs et libère la mémoire.