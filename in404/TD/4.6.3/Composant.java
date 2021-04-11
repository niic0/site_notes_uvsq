public abstract class Composant {
    private String nom;
    private Repertoire parent;

    public Composant (String nom, Repertoire parent) {
        this.parent = parent;
        this.nom = nom;
    }

    public void setParent(Repertoire parent){
        this.parent=parent;
    }

    public Repertoire getParent() {
        return this.parent;
    }

    public abstract int getTaille();


}
