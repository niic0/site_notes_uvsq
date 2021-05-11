#!/usr/bin/env python3
import matplotlib.pyplot as plt


fileSeqx = open('seqx','r')
fileSeqy = open('seqy','r')

ligneX = fileSeqx.readline()
ligneY = fileSeqy.readline()

seqx=''
seqy=''

while ligneX!='' and ligneY!='':
    seqx = seqx+ligneX[0:len(ligneX)-1]
    seqy = seqy+ligneY[0:len(ligneY)-1]

    ligneX = fileSeqx.readline()
    ligneY = fileSeqy.readline()

print("Dotplot with sequences :\n[",seqx,"] of size",len(seqx),
      "\n[",seqy,"] of size",len(seqy))

fileSeqx.close()
fileSeqy.close()

plt.title("DOTPLOT")

plt.xlabel("Séquence X")
plt.ylabel("Séquence Y")

plt.xlim(0, len(seqx))
plt.ylim(0, len(seqy))


fenetre = int(input("Taille de la fenêtre de comparaison: "))
x=0

while x<=len(seqx)-fenetre:
    y=0
    while y<=len(seqy)-fenetre:
        if seqx[x:x+fenetre] == seqy[y:y+fenetre]:
            print("[",x,",",y,"] : ",seqx[x])
            i=0
            while i<fenetre:
                plt.scatter(x+i, y+i, c = "red", s=10)
                i+=1
        y+=1
    x+=1

plt.show()
