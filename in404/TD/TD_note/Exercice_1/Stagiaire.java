import java.util.*;

public class Stagiaire {
    private String nom;
    private ArrayList<Double> notes;

    public Stagiaire(String nom, ArrayList<Double> notes){
        this.nom = nom;
        this.notes = notes;
    }


    public void setNom(String nom){
        this.nom = nom;
    }
    public void setNotes(ArrayList<Double> notes){
        this.notes = notes;
    }

    public String getNom() {
        return nom;
    }
    public ArrayList<Double> getNotes() {
        return notes;
    }

    /*
     * Calcule la moyenne du tableau de notes
     */
    public double calculerMoyenne() {
        double sum = 0;
        for (int i=0; i<notes.size(); i++)
            sum +=notes.get(i);

        double ret =sum/notes.size();
        return ret;
    }

    /*
     * Trouve le minimum du tableau de notes
     */
    public double trouverMin() {
        double min = notes.get(0);

        for(int i=1; i<notes.size();i++)
            if (min > notes.get(i))
                min = notes.get(i);

        return min;
    }

    /*
     * Trouve le Maximum du tableau de notes
     */
    public double trouverMax() {
        double max = notes.get(0);

        for(int i=1; i<notes.size();i++)
            if (max < notes.get(i))
                max = notes.get(i);

        return max;
    }
}
