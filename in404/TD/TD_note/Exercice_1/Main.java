import java.util.*;

public class Main {
    public static void main(String[] args){

        ArrayList<Double> listeNotesTheo = new ArrayList<Double>();
        ArrayList<Double> listeNotesLeo = new ArrayList<Double>();
        ArrayList<Double> listeNotesClara = new ArrayList<Double>();
        ArrayList<Stagiaire> stagiaires = new ArrayList<Stagiaire>();

        listeNotesTheo.add(13.0);
        listeNotesTheo.add(7.2);
        listeNotesLeo.add(9.3);
        listeNotesLeo.add(12.0);
        listeNotesClara.add(15.2);
        listeNotesClara.add(11.4);

        Stagiaire theo = new Stagiaire("",listeNotesTheo);
        Stagiaire leo = new Stagiaire("",listeNotesLeo);
        Stagiaire clara = new Stagiaire("",listeNotesClara);

        stagiaires.add(theo);
        stagiaires.add(leo);
        stagiaires.add(clara);

        stagiaires.get(0).setNom("Theo");
        stagiaires.get(0).setNotes(listeNotesTheo);
        stagiaires.get(1).setNom("Leo");
        stagiaires.get(1).setNotes(listeNotesLeo);
        stagiaires.get(2).setNom("Clara");
        stagiaires.get(2).setNotes(listeNotesClara);

        Formation formation = new Formation("", 0, stagiaires);

        formation.setIntitule("Formation 1");
        formation.setNbrJours(4);
        formation.setStagiaires(stagiaires);

        /*
         * Test des Fonctions et affichage dans le terminal
         */
        System.out.println("\n//////// TEST SETTERS ET GETTERS ////////");
        System.out.println("\nStagiaires ->  NOM : "+theo.getNom() +
                           " | NOTES : "+theo.getNotes());
        System.out.println("Formation  -> "+ "INTITULÉ : " + formation.getIntitule() +
                           " | NBR JOURS : " + formation.getNbrJours());

        System.out.println("\n//////// TEST DES MÉTHODES ////////");
        System.out.println("\nMoyenne Theo  : "+theo.calculerMoyenne());
        System.out.println("Moyenne Leo   : "+leo.calculerMoyenne());
        System.out.println("Moyenne Clara : " +clara.calculerMoyenne());
        System.out.println("\nMinimum pour Theo : " +theo.trouverMin());
        System.out.println("Maximum pour Theo : " +theo.trouverMax());
        System.out.println("Moyenne Générale  : " + formation.calculerMoyenneFormation() +"\n");
        formation.afficheNomMax();
        formation.afficheMinMax();
        System.out.println("\nMoyenne par nom (Leo) : " +formation.trouverMoyenneParNom("Leo")+"\n");
     }
}
