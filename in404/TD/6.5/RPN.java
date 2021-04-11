import java.util.*;

public class RPN {
    /**
     * La racine de la hiérarchie d'exception pour la pile
     */
    class PileException extends Exception {
        /**
         * Initialise une instance de <code>PileException</code>.
         *
         * @param message le message d'erreur.
         */
        public PileException(String message) {
            super(message);
        }
    }

    /**
     * Si l'élément est vide
     *
     * @param unObjet l'objet à empiler
     * @throws PilePleineException s'il n'y a plus de place
     */
    class empilementVide extends PileException {
        public empilementvide(){
            super("Empilement d'un caractère vide.");
        }
    }

    /**
     * Empile un élément au sommet de la pile.
     *
     * @param unObjet l'objet à empiler
     * @throws PilePleineException s'il n'y a plus de place
     */
    public void empile(char val) {
        if (val == NULL) {
            throw new empilementVide();
        }
        contenu[sommet++] = unObjet;
    }

    public class Collection {

        public Collection() {

        }
        public void add(Document doc){

        }
    }

    public static void main(String[] args) {

    }
}
