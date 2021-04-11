#!/usr/bin/env python3

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

exo1()
