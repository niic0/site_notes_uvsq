import java.util.*;
import java.io.*;

public class main {
    public static void main(String args[]) throws IOException, ClassNotFoundException{

        Rectangle rectangle1 = new Rectangle("rectangle1", 30, 54, 100, 100);
        Circle circle1       = new Circle("circle1", 56, 76, 45);
        Triangle triangle1   = new Triangle("triangle1",32, 67, 40);


        // Shape demonstration
        System.out.println("\n   // -- Initialisation --//\n");

        rectangle1.draw();
        circle1.draw();
        triangle1.draw();


        // shape method demonstration
        System.out.println("\n   //-- Method Shape --//\n");

        rectangle1.moveShape(5, 5);
        rectangle1.erase();
        rectangle1.changeColor("red");
        rectangle1.draw();


        // group of shapes demonstration
        System.out.println("\n   //-- Moving a group of shapes --//\n");

        ArrayList<Shape> listShape = new ArrayList<Shape>();
        listShape.add(rectangle1);
        listShape.add(circle1);
        listShape.add(triangle1);
        listShape = moveShapes(listShape, 100, 100);
        printListShape(listShape);


        System.out.println("\n   //-- Testing serialization --//\n");
        // Serialization -- Saving drawing
        saveDrawing(listShape);
        // Deserialization -- load drawing
        ArrayList<Shape> listShapeLoad = new ArrayList<Shape>();
        listShapeLoad = loadDrawing("drawing.ser");
        printListShape(listShapeLoad);
    }

    private static ArrayList<Shape> loadDrawing(String draw) throws IOException, ClassNotFoundException{

        ArrayList<Shape> listShapeLoad = new ArrayList<Shape>();

        FileInputStream fileIn = new FileInputStream(draw);
        ObjectInputStream in = new ObjectInputStream(fileIn);

        listShapeLoad = (ArrayList<Shape>) in.readObject();
        in.close();
        fileIn.close();

        System.out.println("Drawing Loaded !");

        return listShapeLoad;
    }

    private static void saveDrawing(ArrayList<Shape> listShape) throws IOException{
        FileOutputStream fileOut = new FileOutputStream("drawing.ser");
        ObjectOutputStream out = new ObjectOutputStream(fileOut);
        out.writeObject(listShape);
        out.close();
        fileOut.close();

        System.out.println("Drawing saved !");
    }

    private static ArrayList<Shape> moveShapes(ArrayList<Shape> listShape, int dx, int dy) {
        for(int i=0; i<listShape.size(); i++)
            listShape.get(i).moveShape(dx,dy);
        return listShape;
    }

    private static void printListShape(ArrayList<Shape> listShape) {
        for(int k=0; k<listShape.size(); k++)
            listShape.get(k).draw();
    }

}
