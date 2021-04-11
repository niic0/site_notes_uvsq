import java.util.*;

public class fileSystem {


    public class File{
        String name;
        int size;
        public void File(String name, int size){
            this.name = name;
            this.size = size;
        }
    }

    public class Directory {
        String name;
        ArrayList<File> childs;

        public void Directory(String name, ArrayList<File> childs){
            super(nom,null);
            childs = new ArrayList<File>();
        }
        public void ajouter(File f){
            if(this != f) {
                this.child.add(f);
                f.setParent(this);
            }
        }
    }

    public static void main(String[] args){
        new fileSystem();
        File fichier1 = File("test",2);
    }
}
