enum CalculatriceRPB {

    CALCULATRICE_RPB ();

    private SaisieRPN saisie;

    CalculatriceRPB()
    {
        saisie = new SaisieRPN();
    }

    public void lancer()
    {
        saisie.interaction();
    }


    public static void main(String[] args) {

        CalculatriceRPB.CALCULATRICE_RPB.lancer();
    }
}