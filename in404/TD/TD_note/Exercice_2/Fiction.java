import java.util.*;

class Fiction extends Emission{
    boolean rediffusion;
    String nomRealisateur;
    int annee;

    Fiction(boolean rediffusion, String nom, String nomRealisateur, int annee, int duree, int heure){
        super(nom, duree, heure);

        this.rediffusion = rediffusion;
        this.nomRealisateur = nomRealisateur;
        this.annee = annee;

        if(rediffusion)
            this.heure = heure;
        else if (!rediffusion && heure != 21){
            System.out.println("Problème pour "+this.nom);
            System.out.println("L'horaire d'une fiction qui n'est pas une rediffusion est 21h...");
            System.out.println("Arret du programme");
            System.exit(1);
        }
        else
            this.heure = heure;
    }
}
