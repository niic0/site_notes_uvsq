import java.util.*;

public class fraction {

    private int num; // Nominateur
    private int den; // Dénominateur
    private String display = num+"/"+den; // Affichage

    public void initFrac(final int num, final int den) {
        if(den == 0)
            den = 0;
        if(num == null)
            num = 0;
        this.num = num;
        this.den = den;
    }

    final fraction ZERO = new fraction(0,1);
    final fraction ONE = new fraction(1,1);

    public int getDen(fraction f){
        return f.den;
    }
    public int getNum(fraction f){
        return f.num;
    }

    public double getDouble(fraction f){
        return (f.num / f.den);
    }

    public fraction toString(double d){
        String s = String.valueOf(d);
        int digitsDec = s.length() - 1 - s.indexOf('.');

        int den = 1;
        for(int i = 0; i < digitsDec; i++){
            d *= 10;
            den *= 10;
        }
        int num = (int)Math.round(d);
        return (new fraction(num,den));
    }

    public fraction add(fraction f1, fraction f2){
        double tmp = getDouble(f1)+getDouble(f2); // On traduit en double
        // On retranscrit le double en fraction
        fraction result = toString(tmp);
        return result;
    }

    public int isEqual(fraction f1, fraction f2){ // return 1 si c'est égale, 0 sinon
        if(getDouble(f1) == getDouble(f2))
            return 1;
        else return 0;
    }

    // Return -1 si la première fraction est inférieur à la seconde, 1 si l'inverse et 0 si elles sont égales
    public int compareFrac(fraction f1, fraction f2){
        if(getDouble(f1) < getDouble(f2))
            return -1;
        if(getDouble(f1) > getDouble(f2))
            return 1;
        if(getDouble(f1) == getDouble(f2))
            return 0;
    }

    public static void main(String[] args) {
        fraction frac1 = new fraction(3,5);
        fraction frac2 = new fraction(4,10);

        // test de la fonction add
        fraction addition = new add(frac1,frac2);
        System.out.println("Resultat addition :"+addition.display);

        // test de la fonction compareFrac
        if(compareFrac(frac1,frac2) == -1)
            System.out.println("La fraction"+toString(frac1)+"est plus petite que"+toString(frac2));
        else if(compareFrac(frac1,frac2) == -1)
            System.out.println("La fraction"+toString(frac1)+"est plus grande que"+toString(frac2));
        if(compareFrac(frac1,frac2))
            System.out.println("Les fractions sont égales");


    }
}
