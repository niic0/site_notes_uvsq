import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class SaisieRPN {

    private MoteurRPN moteurRPN;

    private ArrayList<String> listOperations;


    public SaisieRPN()
    {
        this.moteurRPN = new MoteurRPN();
        listOperations = new ArrayList<String>(Arrays.asList("+","-","*","/"));
    }


    public void interaction() throws IllegalArgumentException
    {
        Scanner scanner = new Scanner( System.in );
        String entree = "";

        while( entree != "exit" )
        {
            entree = scanner.nextLine();

            try
            {
                if( listOperations.contains(entree) )
                {
                    Integer result = moteurRPN.applyOperation(entree);

                    if( result != null )
                        System.out.println(result);
                }
                else
                {
                    moteurRPN.enregistrerOperande(Integer.parseInt(entree));
                }
            }
            catch(NumberFormatException e)
            {
                System.out.println(e.getMessage());
            }
            catch(IllegalArgumentException e)
            {
                System.out.println(e.getMessage());
            }
            catch(MinOperandesNumbre e)
            {
                System.out.println(e.getMessage());
            }

        }
    }

}
