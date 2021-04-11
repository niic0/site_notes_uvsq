#!/usr/bin/env python3

seq = input("Entrez un mot :")
seq = seq.upper()

i = 0
error = 0
debut = 0
fin = len(seq)-1

while i <= int(len(seq)/2) and error == 0:
    if seq[debut] != seq[fin]: error = 1
    else :
        debut += 1
        fin -= 1
        i += 1

if error == 1: print("Ce n'est pas un palindrome")
else : print("c'est un palindrome")
