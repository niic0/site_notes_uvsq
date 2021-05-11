import java.util.*;

public class Formation {
    String intitule;
    int nbrJours;
    ArrayList<Stagiaire> stagiaires;

    Formation(String intitule, int nbrJours, ArrayList<Stagiaire> stagiaires) {
        this.intitule = intitule;
        this.nbrJours = nbrJours;
        this.stagiaires = stagiaires;
    }

    // Getters
    public String getIntitule(){
        return intitule;
    }
    public int getNbrJours(){
        return nbrJours;
    }
    public ArrayList<Stagiaire> getStagiaires (){
        return stagiaires;
    }
    // Setters
    public void setIntitule(String intitule){
        this.intitule = intitule;
    }
    public void setNbrJours(int nbrJours){
        this.nbrJours = nbrJours;
    }
    public void setStagiaires (ArrayList<Stagiaire> stagiaires){
        this.stagiaires = stagiaires;
    }

    /*
     * Calcule de la moyenne générale de la formation
     */
    public double calculerMoyenneFormation() {
        double sum = 0;

        for (int i=0; i<stagiaires.size(); i++)
            sum +=stagiaires.get(i).calculerMoyenne();

        return sum/stagiaires.size();
    }
    /*
     * Affiche le stagiaire qui a la moyenne la plus élevée
     */
    public void afficheNomMax(){

        Stagiaire stagiaireBuf = stagiaires.get(0);

        for (int i=1; i<stagiaires.size(); i++){
            if (stagiaires.get(i).calculerMoyenne() > stagiaireBuf.calculerMoyenne())
                stagiaireBuf = stagiaires.get(i);
        }

        System.out.println("Stagiaire avec la moyenne la plus haute : "+stagiaireBuf.getNom());
    }
    /*
     * Affiche le stagiaire qui a la moyenne la plus basse
     */
    public void afficheMinMax(){

        Stagiaire stagiaireBuf = stagiaires.get(0);

        for (int i=1; i<stagiaires.size(); i++){
            if (stagiaires.get(i).calculerMoyenne() > stagiaireBuf.calculerMoyenne())
                stagiaireBuf = stagiaires.get(i);
        }

        System.out.println("Note la plus basse du stagiaire qui a la moyenne la plus élevé : "
                           + stagiaireBuf.trouverMin());
    }

    public double trouverMoyenneParNom(String nom){
        Stagiaire stagiaireBuf = stagiaires.get(0);
        int i = 0;

        while(nom != stagiaireBuf.getNom()){
            stagiaireBuf = stagiaires.get(i);
            i++;
        }

        return stagiaireBuf.calculerMoyenne();
    }
}
