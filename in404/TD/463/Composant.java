
public abstract class Composant {
    private String nom;

    public Composant(String nom){
        this.nom = nom;
    }

    public abstract int getSize(){
    }
}
