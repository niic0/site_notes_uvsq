import java.util.ArrayList;

public class Directory extends Composant {
    private ArrayList<Composant> contenu;

    public Composant(String name){
        super(name);
        contenu = new ArrayList<Composant>();
    }

    public void add(Composant c){
        this.contenu.add(c);
    }

    @Override
    public int getSize() {
        int size = 0;
        for(int i=0; i<this.contenu.size(); i++){
            size+=this.contenu.get(i).getSize();
        }
        return size;
    }
}
