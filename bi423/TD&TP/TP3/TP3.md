# TP 3

### Exercice 1 
Ecrire un programme permettant à un utilisateur de saisir une séquence d'ADN et d’afficher séparément chaque caractère de la séquence.

```python
seq = input("Séquence ADN = ")
i = 0

while i < len(seq):
  print(seq[i])
  i = i + 1
```

### Exercice 2

Ecrire un programme permettant à un utilisateur de saisir une séquence d'ADN et d’afficher chaque caractère suivi de sa position dans la séquence à l’écran.

Exemple : si la chaîne saisie par l’utilisateur vaut « ATGC » votre programme doit afficher :

> A est en position 1
> T est en position 2
> G est en position 3
> C est en position 4

Rq : Nous rappelons que la position est différente de l'index (cf. TP1).

```python
seq = input("Séquence ADN = ")
i = 0

while i < len(seq):
  print(seq[i], "est en position", i)
  i = i + 1
```

### Exercice 3

Ecrire un programme permettant à un utilisateur de saisir une séquence protéique et d’afficher le nombre d’acides aminés soufrés (sans utiliser la méthode « count »).
ex : Si la séquence entrée est : MATYLVKMCPGCRRAIL, alors le programme affiche « 4 acides aminés soufrés ».

```python
seq = input("Séquence d'"ADN = )

i= 0
count = 0

while i< len(seq):
    if (seq[i] == 'M' or seq[i] == 'C'): count+=1;
        i+=1

print("il y a", count,"acide aminé souffré")
```

### Exercice 4

Ecrire un programme permettant à un utilisateur de saisir une séquence d'ADN puis d'afficher le pourcentage en A, T, G et C de la séquence (sans utiliser la méthode « count »).

```python
seq = input("Séquence d'ADN = ")
seq = seq.upper()
#Variable qui va parcourir la séquence
i = 0
# Variable d'accumulation des nucléotides
cntA = 0
cntT = 0
cntC = 0
cntG = 0

while i < len(seq):
    if (seq[i] == 'A'): cntA+=1;
    if (seq[i] == 'T'): cntT+=1;
    if (seq[i] == 'C'): cntC+=1;
    if (seq[i] == 'G'): cntG+=1;
    i+=1

print(cntA/len(seq)*100, "% d'Adénine")
print(cntT/len(seq)*100, "% de Thymine")
print(cntC/len(seq)*100, "% de Cytosine")
print(cntG/len(seq)*100, "% de Guanine")
```

### Exercice 5

Ecrire un programme permettant à un utilisateur de saisir une séquence d'ADN puis de générer, en utilisant une variable d’accumulation, une nouvelle séquence correspondant à la transcription de cette séquence d’ADN.

```python
#!/usr/bin/env python3

seq = input("Séquence d'ADN : ")
seq = seq.upper()

# Variable qui parcours la séquence avec la boucle
i = 0
# Variable contenant l'arn formé
arn = ''

while i < len(seq):
    if (seq[i] == 'T'): arn += 'U'
    else: arn += seq[i]
    i+=1

print(arn)
```

