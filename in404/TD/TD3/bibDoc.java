import java.util.ArrayList;

public class bibDoc {

    public class Document {
        String titre;
        String auteur;
        int annee;
        String reference;

        public void Document(String titre, String auteur, int annee) {
            this.titre = titre;
            this.auteur = auteur;
            this.annee = annee;
         }

        public void addRef(String reference) {
            this.reference = reference;
        }

        public void affichage() {
            System.out.println(this.titre+", "+this.auteur+"paru en"+this.annee);
        }
    }

    public class Bibiotheque {
        ArrayList<Document> listDocuments;

        public void add(Document doc) {
            this.listDocuments.add(doc);
        }

        public Document search(String searchTitre) {
            Document ret = null;

            for (int i=0; i<this.listDocuments.size() && this.listDocuments.get(i).titre != searchTitre; i++) {
                if(this.listDocuments.get(i).titre == searchTitre)
                    ret = this.listDocuments.get(i);
            }

            return ret;
        }
    }

    public static void main(String[] args) {
        Document doc1 = new Document("titre1","auteur1",2020);
        doc1.affichage();
    }
}
