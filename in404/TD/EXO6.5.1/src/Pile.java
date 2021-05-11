import java.util.ArrayList;

public class Pile {

    private int sommet;
    private int[] pile;

    public Pile(int capacity)
    {
        sommet = -1;
        pile = new int[capacity];
    }

    public int getSize()
    {
        return sommet + 1;
    }

    public int getSommet(){
        return pile[sommet];
    }

    public boolean estVide(){
        if(sommet == -1){
            return true;
        }
        return false;
    }

    public boolean estPleine(){
        if(sommet + 1 == pile.length){
            return true;
        }
        return false;
    }

    public void empile(int element) throws PilePleineException{
        if (estPleine()){
            throw new PilePleineException();
        }
        pile[sommet+1] = element;
        sommet++;
    }

    public int depile() throws PileVideException{
        if (estVide()){
            throw new PileVideException();
        }
        sommet--;
        return pile[sommet+1];
    }

    public String afficher(){ //Pour visualiser ta pile
        if(estVide()){
            return "[]";
        }
        if(sommet == 0){
            return "["+getSommet()+"]";
        }
        return "["+pile[0]+" "+getSommet()+"]";
    }


}
