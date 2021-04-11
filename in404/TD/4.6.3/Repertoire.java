@override
public int getTaille() {
    int taille = 0;
    for (int i=0; i<this.contenu.size(); i++){
        taille += this.contenu.get(i).getTaille;
    }

    return taille;
}

public boolean checkParents(Repertoire rep) {
    if(this.getParent() == null || (this.getParent() != rep && this.getParent().checkParents(rep)) )
        return true;
    else return false;
}
