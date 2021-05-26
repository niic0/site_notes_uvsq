import java.util.*;
import java.io.*;

// Mother class
public class Shape implements Serializable{
    int x;
    int y;
    String shapeName;
    String color;
    boolean visible;

    /*
     * Name the shape and put it in the window with coordinate x, y
     */
    Shape(String shapeName, int x, int y){
        this.shapeName = shapeName;
        this.x = x;
        this.y = y;
        this.visible = true;     // set by default
        this.color = "black";  // set by default
    }

    /*
     * Move the shape by adding dx and dy to x y
     */
    void moveShape(int dx, int dy){
        this.x += dx;
        this.y += dy;
    }

    /*
     * display the shape
     */
    void draw(){
        System.out.println(this.shapeName + " position : x=" + this.x + ", y=" + this.y +"\n"+
                           "           color : " + this.color + "\n" +
                           "      visibility : "+ this.visible + "\n");
    }

    /*
     * Erase the shape of the window
     */
    void erase() {
        visible = false;
    }

    /*
     * Change the color of the shape
     */
    void changeColor(String colorModify){
        try {
            controle(colorModify);
        } catch(colorException e){
            System.out.println("////////////////////////");
            System.out.println("color " + colorModify + " not accepted...");
            System.out.println("////////////////////////");
        }
        this.color = colorModify;
    }

    void controle(String color) throws colorException{
        ArrayList<String> colors = new ArrayList<String>();
        colors.add("white");
        colors.add("black");
        colors.add("blue");
        colors.add("red");
        colors.add("yellow");

        if (!colors.contains(color)){
            throw new colorException();
        }
    }
}
