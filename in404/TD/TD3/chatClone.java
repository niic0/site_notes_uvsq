import java.util.ArrayList;

public class chatClone {

    public class Client {
        private String nom;
        private Serveur s;

        public Client(String nom) {
            this.nom = nom;
         }

        public boolean seConnecter(Serveur s) {
            boolean rep = s.connecter(this);

            if(rep) return true;
            else return false;
        }

        public void envoyer(String msg) {
            this.s.diffuser(msg+"de la part de"+this.nom);
        }

        public void recevoir(String msg) {
            System.out.println(msg);
        }
    }

    public class Serveur {
        ArrayList<Client> listClients;

        public void Serveur() {
            listClients = new ArrayList<Client>();
        }

        public boolean connecter(Client c) {
            this.listClients.add(c);
            return true;
        }

        public void diffuser(String msg) {
            for (int i=0; i<listClients.size() ;i++) {
                listClients.get(i).recevoir(msg);
            }
        }
    }


    public static void main(String[] args) {

        Serveur s = new Serveur();

        Client c1 = new Client("C1");
        Client c2 = new Client("C2");

        c1.seConnecter(s);
        c2.seConnecter(s);

        Client c3 = new Client("C3");

        c3.seConnecter(s);

        c3.envoyer("bonjour");
    }
}
