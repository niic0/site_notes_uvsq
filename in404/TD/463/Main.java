package <463>;

public class Main
{
    public static void main(String[] args) {
        File f1 = new File("f1",10);
        File f2 = new File("f2", 20);

        Directory r1 = new Direcotry("R1");
        Directory r2 = new Direcotry("R2");

        r1.add(f1);

        r2.add(f2);
        r2.add(r1);

        System.out.println("R1 = "+r1.getTaille());
        System.out.println("R2 = "+r2.getTaille());
    }
}
