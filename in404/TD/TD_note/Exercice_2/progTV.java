import java.util.*;

public class progTV{

    public static void main(String args[]){
        ArrayList<Emission> Program = new ArrayList<>();

        // Créations des emissions
        Reportage rep1 = new Reportage("Animalier", "Reportage animalié", 1,0);
        Reportage rep2 = new Reportage("Théchnologie", "Reportage sur Internet", 1,1);
        Reportage rep3 = new Reportage("Société", "Reportage sur la Chine", 1,2);
        Reportage rep4 = new Reportage("Société", "Reportage sur la France", 1,3);
        Reportage rep5 = new Reportage("Théchnologie", "Reportage sur l'IA", 1,4);
        Fiction f1 = new Fiction(true, "Shinning", "Kubrick", 1980, 2, 5);
        Fiction f2 = new Fiction(true, "E.T", "Spielberg", 1982, 2, 7);
        Fiction f3 = new Fiction(true, "Jurassik Park", "Spielbeg", 1993, 2, 9);
        Fiction f4 = new Fiction(true, "Star Wars IV", "Lucas", 1977, 2, 11);
        Fiction f5 = new Fiction(true, "2001: L'odissey de l'espace", "Kubrick", 1968, 3, 13);
        Fiction f6 = new Fiction(true, "Le seigneur des anneaux: La communauté de l'anneau", "Peter Jackson", 2001, 3, 16);
        Fiction f7 = new Fiction(true, "Le seigneur des anneaux: Les deux tours", "Peter Jackson", 2002, 3, 19);
        Divertissement div1 = new Divertissement("Musique",22,2);

        // Ajout des emissions dans la liste
        Program.add(rep1); Program.add(rep2);
        Program.add(rep3); Program.add(rep4);
        Program.add(rep5); Program.add(f1);
        Program.add(f2);   Program.add(f3);
        Program.add(f4);   Program.add(f5);
        Program.add(f6);   Program.add(f7);
        Program.add(div1);

        // Affichage et Vérification de la programmation (Chevauchement d'horaire / Crénaux pleins)
        verifCrenaux(Program);
        superposition(Program);
        displayProg(Program);
    }

    /*
     * Affiche la programmation dans l'ordre chronologique
     */
    public static void displayProg(ArrayList<Emission> Program){
        Collections.sort(Program);
        int horaireFin;
        for (int i=0;i<Program.size(); i++){
            horaireFin = Program.get(i).heure+Program.get(i).duree;
            System.out.println(Program.get(i).heure+"h : "+horaireFin+"h -> "+Program.get(i).nom);
        }
    }

    /*
     * Vérifie si il y a une superpositions d'horaires entres les programmes
     * Le programme s'arrete s'il trouve une superposition
     */
    public static void superposition(ArrayList<Emission> Program){
        Collections.sort(Program);
        int heurePrev = Program.get(0).heure + Program.get(0).duree; // Stocke l'heure de fin du programme

        for(int i=1; i<Program.size(); i++) {
            if(heurePrev<Program.get(i).heure){
                System.out.println("<"+Program.get(i-1).nom+"> et <"+Program.get(i).nom
                                   +"> ont des horaires qui se chevauchent.");
                System.out.println("Arrêt du programme");
                System.exit(1);
            }
            heurePrev = Program.get(i).heure + Program.get(i).duree;
        }

        System.out.println("Le programme n'a pas de superposition de crénaux");
    }

    /*
     * Vérifie que tous les crénaux sont bien pris (qu'il n'y ai pas de trous entre les programme)
     */
    public static void verifCrenaux(ArrayList<Emission> Program) {
        Collections.sort(Program);
        boolean trou = false;
        int heurePrev = Program.get(0).heure + Program.get(0).duree; // Stocke l'heure de fin du programme

        for (int i=1; i<Program.size(); i++){
            if(heurePrev != Program.get(i).heure){
                System.out.println("Il y a un trou entre " + heurePrev + " et " + Program.get(i).heure);
                trou = true;
            }
            heurePrev = Program.get(i).heure + Program.get(i).duree;
        }
        if (!trou)
            System.out.println("La programmation prend en compte tous les crénaux de la journée");
    }
}
