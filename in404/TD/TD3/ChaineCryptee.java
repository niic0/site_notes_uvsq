class ChaineCryptee {

    private String chaine;
    private int decalage;

    /*
     * Constructor for objects of class ChaineCryptee
     */

    public static ChaineCryptee deCryptee(String chaine, int decalage) {

    }

    private void chaineCryptee (String chaine, int decalage) {
        this.chaine = crypte(chaine, decalage);
        this.decalage = decalage;

    }

    public String decrypte() {
        return this.chaine;
    }

    private static String crypte(String chaineClaire, int decal) {
        String chaineCrypte = "";

        for(int i=0; i<chaine.length(); i++) {
            chaineCrypte += decaleCaractere(chaineClaire.charAt(i), decal);
        }

        return chaineCrypte;
    }

    private static String crypte(String chaineClaire, int decal) {
        String chaineCrypte = "";

        for(int i=0; i<chaine.length(); i++) {
            chaineCrypte += decaleCaractere(chaineClaire.charAt(i), 26-decal);
        }

        return chaineCrypte;
    }

    private static char decaleCaractere(char c, int decalage) {
        return (c < 'A' || c > 'Z')? c : (char)(((c - 'A' + decalage) % 26) + 'A');
    }

    public static void main(String[] args) {
        chaineCryptee chaine = new chaineCryptee("test",3);
        println(chaine);
    }
}
