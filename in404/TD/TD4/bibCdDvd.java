import java.util.*;

public class bibCdDvd {

    public class Document {
        String titre;
        String auteur;

        public void Document(String titre, String auteur) {
            this.titre = titre;
            this.auteur = auteur;
        }

        public String informations(){
            return "Titre : " + this.titre + "Auteur: " + this.auteur;
        }
    }

    public class Cd extends Document {
        int nbrTitres;

        public void Cd(String titre, String artiste, int nbrTitres) {
            super.Document(titre,artiste);
            this.nbrTitres = nbrTitres;
         }

        @Override
        public String informations () {
            return super.informations()+"Nombres de titres"+this.nbrTitres;
        }
    }

    public class Dvd extends Document {
        int annee;

        public void Dvd(String titre, String realisateur, int annee) {
            super.Documents(titre,realisateur);
            this.annee = annee;
        }

        @Override
        public String informations () {
            return super.informations()+"Annee de publication"+this.annee;
        }
    }

    public class Collection {
        ArrayList<Document> listDoc;

        public Collection() {
            listDoc = new ArrayList<Document>();
        }
        public void add(Document doc){
            listDoc.add(doc);
        }

        public void lister() {
            for (int i=0; i<this.listDocuments.size(); i++){
                System.out.println(listDoc.get(i).informations);
            }
        }

        public Collection search(String motClef){
            Collection c = new Collection();

            for(int i=0; i<listDoc.size(); i++)
                if(listDoc.get(i).titre.contains(motClef) || listDoc.get(i).auteur.contains(motClef))
                    return this.listDocuments.get(i);

            return c;
        }
    }

    public static void main(String[] args) {
        Collection collection = new Collection();

        Cd cd1 = new Cd("cdTitre","cdAuteur",8);
        Dvd dvd1 = new Dvd("dvdTitre","dvdAuteur",2020);

        collection.ajouterDoc(cd1);
        collection.ajouterDoc(dvd1);

        collection.lister();
    }
}
