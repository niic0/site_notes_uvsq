import java.util.*;

class Reportage extends Emission{
    String themes;

    Reportage(String themes, String nom, int duree, int heure){
        super(nom,duree,heure);
        this.themes = themes;

        if((heure>=14 && heure<=18) || (heure>=0 && heure<=6))
            this.heure = heure;
        else{
            System.out.println("La plage horaire d'un reportage et en heures creuses...");
            System.out.println("Arret du programme");
            System.exit(1);
        }
        if(duree>1){
            System.out.println("La duree d'un reportage ne dépasse pas 1 heure...");
            System.out.println("Arret du programme");
            System.exit(1);
        }
        else
            this.duree = duree;
    }
}
