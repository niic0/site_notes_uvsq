# TP8

### Exercice 1

Ecrire un programme permettant de calculer le % d’identité entre deux séquences de même longueur. Exemple, la séquence "ATGCATGCAT" a 80% d’identité avec la séquence "TTGCATTCAT" : 
ATGCATGCAT
TTGCATTCAT 
L’utilisateur devra saisir les 2 séquences à comparer. En sortie, on affichera le % d’identité entre les 2 séquences. 

```python
def exo1():
    seq1 = "ATGCATGCAT"
    seq2 = "TTGCATTCAT"

    i=0
    n=0

    while i!=len(seq1):
        if seq1[i] == seq2[i]:
            n+=1
        i+=1

    prct = n/len(seq1)*100

    print ("% d'identite des sequences",seq1, "et", seq2,":", prct, "% avec ",n,"identité(s)")
```

