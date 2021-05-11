public class MoteurRPN {

    Pile calculatricePile;

    public MoteurRPN()
    {
        calculatricePile =  new Pile(20);
    }

    public void enregistrerOperande(int operande)
    {
        try{
            calculatricePile.empile(operande);
        }
        catch(PileExceptions e)
        {
            System.out.println(e.getMessage());
        }

    }

    public Integer applyOperation(String symbole) throws IllegalArgumentException, MinOperandesNumbre
    {
        Operations operation;

        switch (symbole) {
            case "+" :
                operation = Operations.ADD;
                break;
            case "*" :
                operation = Operations.MULTIPLY;
                break;
            case "-" :
                operation = Operations.SUBTRACT;
                break;
            case "/" :
                operation = Operations.DIVISE;
                break;
            default:
                throw new IllegalArgumentException("Symbole opération incorrect.");
        }

        try
        {
            if( calculatricePile.getSize() >= 2 )
            {
                int operande1 = this.calculatricePile.depile();
                int operande2 = this.calculatricePile.depile();

                int result = operation.eval(operande1, operande2);

                this.calculatricePile.empile(result);

                return result;
            }
            else
                throw new MinOperandesNumbre();
        }
        catch (PileExceptions e)
        {
            System.out.println(e.getMessage());
        }

        return null;
    }

    public void returnOperandes()
    {
        calculatricePile.afficher();
    }
}
