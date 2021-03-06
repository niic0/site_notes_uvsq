# TP 4

### Exercice 1

Écrire un programme permettant à un utilisateur de saisir une séquence d'ADN et de la transformer en son « inverse complémentaire ». Le programme affichera la séquence inverse-complémentaire dans les sens 5’ --->3’.
Note : proposer deux solutions différentes à cet exercice !

```python
seq = input("Séquence d'ADN : ")
seq = seq.upper()

# Variable qui parcours la séquence
i = len(seq)-1
# Variable len(seq)-istockant l'inverse complémentaire
invComp = ''

while i >= 0 :
    if (seq[i] == 'A'):   invComp += 'T'
    elif (seq[i] == 'T'): invComp += 'A'
    elif (seq[i] == 'C'): invComp += 'G'
    elif (seq[i] == 'G'): invComp += 'C'
    i-=1

print(invComp)
```

```python
seq = input("Séquence d'ADN : ")
seq = seq.upper()

# Variable qui parcours la séquence
i = 0
# Variable len(seq)-istockant l'inverse complémentaire
invComp = ''

while i < len(seq):
    if seq[i] == 'A':   invComp = 'T' + invComp
    elif seq[i] == 'T': invComp = 'A' + invComp
    elif seq[i] == 'C': invComp = 'G' + invComp
    elif seq[i] == 'G': invComp = 'C' + invComp
    i-=1

print(invComp)
```

### Exercice 2

Ecrire un programme permettant à un utilisateur :
- de saisir une séquence d'ADN,
- de vérifier si la séquence entrée est bien une séquence d'ADN (cf. Aide ci-dessous),
- d’afficher le nombre d’erreurs ainsi que la position de chacune des erreurs.
Aide : on a vu que l’opérateur « in » permettait de tester si une chaîne est (ou n’est pas) présente dans une autre chaîne ; l’opérateur « not in » permet quant à lui de tester si une chaîne n’est pas (ou est) présente dans une autre chaîne.
Exemple : "F" not in "ATGC" renvoie « VRAI » (true). On utilisera cet opérateur avec profit pour traiter la question considérée.

```python
seq = input("Séquence d'ADN : ")
seq = seq.upper()

cnt = 0
i = 0

while i<len(seq):
    if seq[i] not in 'ATCG':
        print(seq[i],"n'est pas un nucléotide ; Position : ", i+1)
        cnt+=1
    i += 1

if cnt == 0: print("C'est une sequence d'ADN")
else :
    print("Ce n'est pas une sequence d'ADN")
    print("Nombre d'erreur(s) : ", cnt)
```

### Ecercice 3

Revoir le programme précédent, en sortant de la boucle dès qu’une erreur est détectée.
Note : utilisation d’un flag.

```python
seq = input("Séquence d'ADN = ")
seq = seq.upper()

erreur = 0 # FLAG 0 on continue, FLAG à 1 on sort de la boucle

i = 0

while i < len(seq) and erreur == 0:
  if seq[i] not in 'ATGC':
    erreur = 1
    print("Erreur en position", i+1, "(", seq[i], ")")
  else:
    i = i + 1

if erreur == 1 :
  print("Ce n'est pas une séquence d'ADN")
else:
  print("C'est une séquence d'ADN ")
```

### Exercice 4

Ecrire un programme permettant à un utilisateur :
- de saisir une chaîne de caractères,
- et de vérifier s’il s’agit d’un palindrome.
Exemple : l’utilisateur entre la chaine "LAVAL" et le programme affiche « il s’agit ‘un palindrome ».

```python
seq = input("Séquence = ")
seq =seq.upper()

m = int(len(seq)/2) # "moitié"

i = 0

erreur = 0 # flag

while i < m and erreur == 0:
  if seq[i]==seq[len(seq)-1-i]:
    i = i + 1
  else:
    erreur = 1

if erreur == 0:
  print("C'est un palindrome")
else:
  print("Ce n'est pas un palindrome")
```