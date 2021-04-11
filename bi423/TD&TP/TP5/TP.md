# TP

### Exercice 1

Exercice 1 -
Créer, “ au moyen de geany ”, un fichier nommé “ seq.txt ” et y saisir une séquence d'ADN sur plusieurs lignes.
Ecrire un programme demandant à l'utilisateur de saisir un nom de fichier (ici il s'agira, par exemple, de “ seq.txt ”) et affichant la séquence d'ADN (sur une seule ligne !) contenue dans ce fichier.

```python
nom = input("nom du fichier = ")
f = open(nom,'r')
ligne = f.readline()

while ligne!="" :
  print(ligne[:len(ligne)-1], end='')
  ligne = f.readline()

f.close()
```

### Exercice 2

Ecrire un programme qui :

1. demande à l'utilisateur le nom d'un fichier contenant une séquence d'ADN,
2. lit le fichier,
3. affiche le pourcentage en " A" de la séquence,
4. sauvegarde dans un fichier, dont le nom est spécifié par l’utilisateur, le résultat précédent ainsi que la longueur de la séquence.
Aide : l’instruction “ write ” ne gère que les chaînes de caractères ; pour écrire un entier ou un réel dans un fichier il faut par conséquent le transformer préalablement en une chaîne de caractères ; à cette fin, on utilise l’instruction “ str ” (e.g., str(10) transforme l’entier 10 en chaîne “ 10 ”).

```python
nom = input("Nom du fichier = ")
f = open(nom, "r")
ligne = f.readline()
seq = "" # le résultat la séquence sur une ligne

while ligne != "":
  seq = seq + ligne[0:len(ligne)-1]
  ligne = f.readline()

print("La séquence = ", seq)
f.close()

# Partie 2: calcul du %A

seq = seq.upper()
nA = seq.count('A')
pA = nA*100/len(seq) # % A
print("%A = ", pA)

# Partie 3: sauvegarde dans un fichier

nom = input("Nom du fichier de sauvegarde = ")
f = open(nom, "w")
f.write("% A = " + str(pA) + '\n')
f.write("La longueur est " + str(len(seq)) + '\n')
f.close()
```

