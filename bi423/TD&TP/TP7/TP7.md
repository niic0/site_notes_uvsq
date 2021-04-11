# TP7

### Exercice 1

Ecrire un programme permettant de rechercher la position de la première occurrence (si elle existe) d’une courte séquence nucléique dans une séquence stockée dans un fichier. L’utilisateur sera invité à saisir la séquence à rechercher ainsi que le nom du fichier stockant la séquence à cribler.

```python

nom = input("nom du fichier : ")
f = open(nom,'r')
seq = ""
ligne = f.readline()

while ligne!='':
	seq = seq + ligne[0:len(ligne)-1]
    ligne = f.readline()
f.close()

print("Sequence = ", seq)

m = input("Motif = ")
p = seq.find(m)

if p==-1:
	print("Le motif est absent")
else:
	print("sequence trouvé au rang : ", p+1)
```



### Exercice 2

Ecrire un programme permettant de rechercher la position de toutes les occurrences d’une courte séquence nucléique dans une séquence stockée dans un fichier. Comme précédemment, l’utilisateur sera invité à saisir la séquence à rechercher ainsi que le nom du fichier stockant la séquence à cribler. 

```python
def exo2():
    nom = input("nom du fichier : ")
    f = open(nom,'r')
    seq = ""
    ligne = f.readline()

    while ligne!='':
        seq = seq + ligne[0:len(ligne)-1]
        ligne = f.readline()

    f.close()
    print("Sequence = ", seq)

    m = input("Motif = ")

    p = seq.find(m)
    i=0

    if p==-1:
        print("Le motif est absent")

    while p!=-1:
        print("sequence trouvé au rang : ", p+1)
        p=seq.find(m,p+1)
```

### Exercice 3 

programmer la fonction find et mettre le résultat dans un fichier.

```python
def exo3():
    nom = input("Nom du fichier = ")
    f =open(nom, 'r') # lecture
    seq = "" # Séquence sur une seule ligne
    ligne = f.readline()

    while ligne != '': # '' = fin de fichier (EOF)
        seq = seq + ligne[0:len(ligne)-1]
        ligne = f.readline()

    f.close()

    nom = input("Nom du fichier à sauvegarder : ")
    f = open(nom, 'w')
    motif = input("Motif = ")
    f.write("Motif ="+motif+'\n')

    # Recher de toutes les occurrences sans find

    i = 0
    n = 0 # Nbre d'occurrences du motif dans seq

    while i < len(seq):
        if seq[i:i+len(motif)] == motif:
            n += 1
            print(motif,"est en position",str(i+1))
            f.write(motif+" est en position" + str(i+1) + '\n')
        i += 1

    print("Occurence : ",n)
    f.write("Occurence : "+str(n))
```

