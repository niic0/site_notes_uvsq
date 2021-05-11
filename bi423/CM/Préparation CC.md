# Préparation CC

3 parties dont une en python où on doit analyser un programme tout fait. On fait ici la correction du CC:

### Question 1

Un fichier *fasta* commence par un `>INFOS_SEQUENCES` puis après un retour à la ligne, on trouve la séquence voulue. `ligne = f.readline()` permet de se débarrasser des informations de la séquence car on veut uniquement la séquence dans cette variable. 

### Question 2

Mettre sur une ligne toute la séquence en se débarrassant des `\n` grâce au `ligne[0: len(ligne)-1]`

### Question 3

m est vide