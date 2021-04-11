#!/usr/bin/env python3

ch = input("Chaîne de caractère : ")
num = int(input("Nombre de caractère à afficher : "))
choix = input("Afficher la fin (Press F) / Afficher le début (press D)")

if choix == 'F':
    print(ch[len(ch)-nm:])
elif choix == 'D':
    print[:num+1]
else:
    print("Erreur de saisie)")
