def exo1():
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

    if p==-1:
        print("Le motif est absent")

    while p!=-1:
        print("sequence trouvé au rang : ", p+1)
        p=seq.find(m,p+1)

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

#exo1()
#exo2()
exo3()
