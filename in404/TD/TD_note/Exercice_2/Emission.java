import java.util.*;

public class Emission implements Comparable<Emission> {
    String nom;
    int duree;
    int heure;

    Emission (String nom, int duree, int heure) {
        this.nom = nom;
        this.duree = duree;
        this.heure = heure;
    }

    /*
     * On utilise override la méthode compareTo  de Comparable pour pouvoir
     * trier la programmation par la suite
     */
    @Override
    public int compareTo(Emission o){
        return (this.heure - o.heure);
    }
}
