import java.util.*;

public class Divertissement extends Emission{

    Divertissement(String nom, int heure, int duree){
        super(nom, duree, heure);
        if (heure>=18 && heure<=23)  // Vérification de la plage horaire
            this.heure = heure;
        else{                          // Erreur si pas la bonne plage horaire
            System.out.println("Problème pour "+this.nom);
            System.out.println("L'horaire du divertissement doit être comprise entre 18h et 23h...");
            System.out.println("Arret du programme");
            System.exit(1);
        }
        if (duree != 2) {
            System.out.println("Problème pour "+this.nom);
            System.out.println("La durée est obligatoirement de 2 heures pour un Divertissement...");
            System.out.println("Arret du programme");
            System.exit(1);
        }
        else
            this.duree = 2;            // La duree est obligatoirement de 2 heures
    }
}
